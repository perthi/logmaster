// GUICringController180.cpp
// karl eirik bang fossberg

#include "GUICringController180.h"
#include "GUICringAbsolute180.h"
#include "GUICringQuadView.h"

#include <QtWidgets/QLabel>
#include <api/api-hmi/APIHmiCRing180.h>
///#include <api/api-hmi/APIHmiCRing180.h>

// #include <kf-common/KFDeviceInfo.h>
// #include <configuration/KFEntityHMICRing.h>
// #include <configuration/KFConfigurationHandler.h>
// #include <intercom/KFInterCom.h>


GUICringController180::GUICringController180(
    APIHmiCRing* pAPI,
    GUICringQuadView* pQuadA,
    GUICringQuadView* pQuadB,
    QWidget *pParent)
    : GUICringController(pAPI, pQuadA, pQuadB, pParent)
{
    m_pAbsPosition = new GUICringAbsolute180();

    // Connection:
    // ABSOLUTE POSITION: ApplyAbsolutePosition from textfield
    connect(m_pAbsPosition, &GUICringAbsolutePos::signalApplyAbsolutePositionInternal, this, &GUICringController::slotAbsolutePosition);

    // Connection:
    // ABSOLUTE POSITION: Apply values from the API to the textfield
    connect(this, &GUICringController::signalUpdateTranslationFromAPI, m_pAbsPosition,  &GUICringAbsolutePos::slotUpdateTextfieldTranslation);
    connect(this, &GUICringController::signalUpdateRotationFromAPI,    m_pAbsPosition,  &GUICringAbsolutePos::slotUpdateTextfieldRotation);

    m_pLayout->addWidget(m_pAbsPosition, 2, 2, Qt::AlignCenter);


    // m_pCringHMI = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING180));

}

void
GUICringController180::UpdateValues(APICRingInfo &info)
{
    emit signalUpdateTranslationFromAPI(info.GetXValueC180());
    emit signalUpdateRotationFromAPI(info.GetAngleC180());
    // printf("Updating values from the API\n");
}
