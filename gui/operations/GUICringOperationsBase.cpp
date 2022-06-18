// GUICringOperationsBase.cpp
// karl eirik bang fossberg

#include "GUICringOperationsBase.h"

#include <QtWidgets/QLabel>
#include <iostream>
#include <vector>

#include <api/api-hmi/APIHmiOperation.h>
#include <configuration/KFEntityHMIOperation.h>
#include <configuration/KFHMIControlGroup.h>

#include <intercom/KFInterCom.h>
#include "GUICringOperationsButtonGroup.h"
#include "GUICringOperationsIndicatorBar.h"
// #include "GUICringOperationsIndicatorBarCustom.h"
#include <QtWidgets/QVBoxLayout>
#include <QtCore/qcoreevent.h>
#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>

GUICringOperationsBase::GUICringOperationsBase(
    std::shared_ptr<APIHmiOperation> pAPI,
    QWidget *pParent)
    : QWidget(pParent)
    , m_pAPI(pAPI)
    , m_timerTickMS(500)
{

    m_pIntercom = KFInterCom::Instance();

    m_pHMIOperation = m_pAPI->GetOperation();
    m_name = m_pAPI->GetTitle();

    m_controlDevice = m_pHMIOperation->fNavigatorMain.fDeviceID;

    m_pRootLayout  = std::make_unique<QVBoxLayout>();
    m_pRootCaption = std::make_unique<QLabel>(m_name.c_str());
    m_pRootCaption->setStyleSheet("font-weight: bold");

    m_pDistanceController = std::make_unique<GUICringOperationsButtonGroup>(m_pHMIOperation->fNavigatorMain);
    m_pIndicatorBar = std::make_unique<GUICringOperationsIndicatorBar>(m_pHMIOperation->fIndicatorMain);

    // Outgoing data from the buttons to the API
    connect(m_pDistanceController.get(), &GUICringOperationsButtonGroup::signalPositionIncrement, this, &GUICringOperationsBase::slotIncrementPosition);
    connect(m_pDistanceController.get(), &GUICringOperationsButtonGroup::signalStartContiuous,    this, &GUICringOperationsBase::slotContinuousMotion);
    connect(m_pDistanceController.get(), &GUICringOperationsButtonGroup::signalStop,              this, &GUICringOperationsBase::slotStop);

    // Incoming data from the API to the indicator
    connect(this, &GUICringOperationsBase::signalUpdateMainIndicator, m_pIndicatorBar.get(), &GUICringOperationsIndicatorBar::slotUpdatePosition);

    m_pRootLayout->addWidget(m_pRootCaption.get());
    m_pRootLayout->addWidget(m_pDistanceController.get());
    m_pRootLayout->addWidget(m_pIndicatorBar.get());

    setLayout(m_pRootLayout.get());
    setMinimumWidth(500);


    m_timer.start(m_timerTickMS, this);
}

GUICringOperationsBase::~GUICringOperationsBase()
{
    //
}

void
GUICringOperationsBase::slotIncrementPosition(const int &value)
{
    m_pAPI->IncrementPosition(m_controlDevice, value);
}

void
GUICringOperationsBase::slotContinuousMotion(const eDIRECTION &direction)
{
    m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_CONTINIOUS_MOVE, m_controlDevice, (float)direction);
}

void
GUICringOperationsBase::slotStop()
{
    m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_SOFT, m_controlDevice);
}

void
GUICringOperationsBase::timerEvent(QTimerEvent *pEvent)
{
    if (pEvent->timerId() == m_timer.timerId())
    {
        OnUpdateTickBase();
        OnUpdateTick();
    }
    else
    {
        QWidget::timerEvent(pEvent);
    }
}

void
GUICringOperationsBase::OnUpdateTickBase()
{

    std::shared_ptr<KFDeviceInfo> info = m_pIntercom->GetDeviceInfo(m_controlDevice.c_str());


    if(info)
    {
        if(info->fVal1 != -1)
        {
            emit signalUpdateMainIndicator(info->fVal1);
        }
        else
        {
            // FORCE_DEBUG("[%s] value was -1. Dropping value.", m_controlDevice.c_str());
        }
    }

}
