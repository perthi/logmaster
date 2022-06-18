// GUICringOperationsCoating.h
// karl eirik bang fossberg


#include "GUICringOperationsCoating.h"

#include <api/api-hmi/APIHmiOperationCoating.h>
#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>

#include "GUICringOperationsIndicatorBar.h"
#include "GUICringOperationsSliderBar.h"


GUICringOperationsCoating::GUICringOperationsCoating(
    std::shared_ptr<APIHmiOperation> pAPI,
    QWidget *pParent)
    : GUICringOperationsBase(pAPI, pParent)
{
    m_pControlGroup   = &m_pHMIOperation.get()->fControls.at(0);
    m_coatingDevice   = DeviceID_t(m_pControlGroup->fControl.fDeviceID);

    m_pCoatingSlider  = std::make_unique<GUICringOperationsSliderBar>(m_pControlGroup->fControl);
    m_pCoatingBar     = std::make_unique<GUICringOperationsIndicatorBar>(m_pControlGroup->fIndicator);

    // Publish Slider updates to class
    connect(m_pCoatingSlider.get(), &GUICringOperationsSliderBar::signalSliderValue, this, &GUICringOperationsCoating::slotOnSliderUpdate);

    // Update Indicator
    connect(this, &GUICringOperationsCoating::signalUpdateCoatingIndicator, m_pCoatingBar.get(), &GUICringOperationsIndicatorBar::slotUpdatePosition);

    m_pRootLayout.get()->addWidget(m_pCoatingSlider.get());
    m_pRootLayout.get()->addWidget(m_pCoatingBar.get());
}

GUICringOperationsCoating::~GUICringOperationsCoating()
{
    //
}

void
GUICringOperationsCoating::slotOnSliderUpdate(const int &value)
{
    m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_GOTO_POSITION, m_coatingDevice, value);

    // m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_STOP_SOFT, m_coatingDevice);
    // m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_SET_SPEED, m_coatingDevice, value);
    // m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_CONTINIOUS_MOVE, m_coatingDevice, 1);

}

void API
GUICringOperationsCoating::OnUpdateTick()
{
    std::shared_ptr<KFDeviceInfo> info = m_pIntercom->GetDeviceInfo(m_coatingDevice.c_str());
    if(info)
    {
        if(info->fVal1 != -1)
        {
            emit signalUpdateCoatingIndicator(info->fVal1);
        }
        else
        {
            // FORCE_DEBUG("[%s] value was -1. Dropping value.", m_coatingDevice.c_str());
        }
    }


}