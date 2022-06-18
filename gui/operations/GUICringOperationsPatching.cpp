// GUICringOperationsPatching.h
// karl eirik bang fossberg

#include "GUICringOperationsPatching.h"
#include <QtWidgets/QVBoxLayout>

#include <api/api-hmi/APIHmiOperation.h>

#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>


GUICringOperationsPatching::GUICringOperationsPatching(
    std::shared_ptr<APIHmiOperation> pAPI,
    QWidget *pParent)
    : GUICringOperationsBase(pAPI, pParent)
{
    m_pControlGroup  = &m_pHMIOperation.get()->fControls.at(0);
    m_pGlueIndicator = std::make_unique<GUICringOperationsIndicatorBar>(m_pControlGroup->fIndicator);

    connect(this, &GUICringOperationsPatching::signalUpdateGlueIndicator, m_pGlueIndicator.get(), &GUICringOperationsIndicatorBar::slotUpdatePosition);

    m_pRootLayout.get()->addWidget(m_pGlueIndicator.get());
}

GUICringOperationsPatching::~GUICringOperationsPatching()
{
    //
}

void API
GUICringOperationsPatching::OnUpdateTick()
{
    std::shared_ptr<KFDeviceInfo> info = m_pIntercom->GetDeviceInfo(m_pControlGroup->fIndicator.fDeviceID.c_str());
    // if(info)
    // {
    //     if(info->fVal1 != -1)
    //     {
    //         emit signalUpdateCoatingIndicator(info->fVal1);
    //     }
    //     else
    //     {
    //         // FORCE_DEBUG("[%s] value was -1. Dropping value.", m_coatingDevice.c_str());
    //     }
    // }


}