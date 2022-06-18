// GUICringOperationsSurfacePrep.h
// karl eirik bang fossberg

#include "GUICringOperationsSurfacePrep.h"

#include <api/api-hmi/APIHmiOperation.h>
#include "GUICringOperationsSliderBar.h"
#include "GUICringOperationsIndicatorBar.h"

#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>

GUICringOperationsSurfacePrep::GUICringOperationsSurfacePrep(
    std::shared_ptr<APIHmiOperation> pAPI,
    QWidget *pParent)
    : GUICringOperationsBase(pAPI, pParent)
{

    m_pMotorDevice = &m_pHMIOperation.get()->fControls.at(0);
    m_pMotorSpeedSlider    = std::make_shared<GUICringOperationsSliderBar>(m_pMotorDevice->fControl);

    connect(m_pMotorSpeedSlider.get(), &GUICringOperationsSliderBar::signalSliderValue, this, &GUICringOperationsSurfacePrep::slotUpdateMotorSpeedSlider);

    m_pRootLayout->addWidget(m_pMotorSpeedSlider.get());

}

GUICringOperationsSurfacePrep::~GUICringOperationsSurfacePrep()
{
    //
}

void
GUICringOperationsSurfacePrep::slotUpdateMotorSpeedSlider(const int &value)
{
    m_pAPI->SendMessageLocal(eSEM_COMMAND_ID::PWM_SET, m_pMotorDevice->fControl.fDeviceID, value);
}
