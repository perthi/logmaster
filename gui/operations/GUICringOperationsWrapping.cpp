// GUICringOperationsWrapping.h
// karl eirik bang fossberg

#include "GUICringOperationsWrapping.h"

#include <configuration/KFEntityHMIOperation.h>
#include <api/api-hmi/APIHmiOperationWrapping.h>

#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>

GUICringOperationsWrapping::GUICringOperationsWrapping(
    std::shared_ptr<APIHmiOperation> pAPI,
    QWidget *pParent)
    : GUICringOperationsBase(pAPI, pParent)
{

    m_pForceControl = &m_pHMIOperation.get()->fControls.at(0);
    m_pFlowControl  = &m_pHMIOperation.get()->fControls.at(1);

    m_pForceBar       = std::make_unique<GUICringOperationsSliderBar>(m_pForceControl->fControl);
    m_pForceGraph     = std::make_unique<GUICringOperationsGraph>(m_pForceControl->fIndicator, m_timerTickMS);
    m_pFlowBar        = std::make_unique<GUICringOperationsSliderBar>(m_pFlowControl->fControl);
    m_pResinBar       = std::make_unique<GUICringOperationsIndicatorBar>(m_pFlowControl->fIndicator);

    connect(m_pForceBar.get(), &GUICringOperationsSliderBar::signalSliderValue, this, &GUICringOperationsWrapping::slotOnForceUpdate);
    connect(m_pFlowBar.get(),  &GUICringOperationsSliderBar::signalSliderValue, this, &GUICringOperationsWrapping::slotOnFlowUpdate);

    m_pRootLayout.get()->addWidget(m_pForceBar.get());
    m_pRootLayout.get()->addWidget(m_pForceGraph.get());
    m_pRootLayout.get()->addWidget(m_pFlowBar.get());
    m_pRootLayout.get()->addWidget(m_pResinBar.get());

}

GUICringOperationsWrapping::~GUICringOperationsWrapping()
{
    //
}


void
GUICringOperationsWrapping::slotOnForceUpdate(const int &force)
{
    // m_pAPI.get()->SetValue(m_pForceControl->fControl.fDeviceID, force);
    m_pAPI.get()->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_GOTO_POSITION, m_pForceControl->fControl.fDeviceID, force);
}

void
GUICringOperationsWrapping::slotOnFlowUpdate(const int &flow)
{
    // m_pAPI.get()->SetValue(m_pFlowControl->fControl.fDeviceID, flow);
    m_pAPI.get()->SendMessageLocal(eSEM_COMMAND_ID::MOTOR_STEPPER_START_GOTO_POSITION, m_pFlowControl->fControl.fDeviceID, flow);
}

void
GUICringOperationsWrapping::OnUpdateTick()
{

    //
    // FORCEs
    std::shared_ptr<KFDeviceInfo> forceInfo = m_pIntercom->GetDeviceInfo(m_pForceControl->fIndicator.fDeviceID.c_str());
    if(forceInfo)
    {
        if(forceInfo->fVal1 != -1)
        {
            m_forceSliderValue = forceInfo->fVal1;
        }
        else
        {
            // FORCE_DEBUG("[%s] value was -1. Dropping value.", m_pForceControl->fIndicator.fDeviceID.c_str());
        }
    }
    else
    {
        // FORCE_DEBUG("[%s] was a nullptr.", m_pForceControl->fIndicator.fDeviceID.c_str());
    }
    m_pForceGraph->slotUpdateTimeSeries(m_forceSliderValue);


    //
    // FLOW
    std::shared_ptr<KFDeviceInfo> flowInfo = m_pIntercom->GetDeviceInfo(m_pFlowControl->fIndicator.fDeviceID.c_str());
    if(flowInfo)
    {
        if(flowInfo->fVal1 != -1)
        {
            m_flowSliderValue = flowInfo->fVal1;
        }
        else
        {
            // FORCE_DEBUG("[%s] value was -1. Dropping value.", m_pFlowControl->fIndicator.fDeviceID.c_str());
        }
    }
    else
    {
        // FORCE_DEBUG("[%s] was a nullptr.", m_pFlowControl->fIndicator.fDeviceID.c_str());
    }

    m_pResinBar->slotUpdatePosition((int)m_flowSliderValue);


}