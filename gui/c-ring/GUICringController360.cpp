// GUICringController360.cpp
// karl eirik bang fossberg

#include "GUICringController360.h"
#include "GUICringAbsolute360.h"
#include "GUICringQuadView.h"

#include <api/api-hmi/APIHmiCRing360.h>

// #include <kf-common/KFDeviceInfo.h>
// #include <configuration/KFEntityHMICRing.h>
// #include <configuration/KFConfigurationHandler.h>
// #include <intercom/KFInterCom.h>




GUICringController360::GUICringController360(
    APIHmiCRing *pAPI,
    GUICringQuadView* pQuadA,
    GUICringQuadView* pQuadB,
    QWidget *pParent)
    : GUICringController(pAPI, pQuadA, pQuadB, pParent)
{

    m_pAbsPosition = new GUICringAbsolute360();

    // Connection:
    // ABSOLUTE POSITION: ApplyAbsolutePosition from textfield
    connect(m_pAbsPosition, &GUICringAbsolutePos::signalApplyAbsolutePositionInternal, this, &GUICringController::slotAbsolutePosition);

    // Connection:
    // ABSOLUTE POSITION: Apply values from the API to the textfield
    connect(this, &GUICringController::signalUpdateTranslationFromAPI, m_pAbsPosition, &GUICringAbsolutePos::slotUpdateTextfieldTranslation);
    connect(this, &GUICringController::signalUpdateRotationFromAPI, m_pAbsPosition, &GUICringAbsolutePos::slotUpdateTextfieldRotation);

    // Connection:
    // N REVOLUTIONS: Apply value from API to revolutions field
    connect(this, &GUICringController::signalUpdateRevolutionsFromAPI, m_pAbsPosition, &GUICringAbsolutePos::slotUpdateRevolutionsInternal);

    m_pLayout->addWidget(m_pAbsPosition, 2, 2, Qt::AlignCenter);

    // m_pCringHMI = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING360));
}

void
GUICringController360::UpdateValues(APICRingInfo &info)
{
    // // Fails with "Could not fine any device with ID XY2"
    // std::shared_ptr<KFDeviceInfo> pos = KFInterCom::Instance()->GetDeviceInfo(m_pCringHMI->fDeviceID);
    // FORCE_DEBUG("xPos[%f] yPos[%f]", pos->fVal1, pos->fVal2);
    // emit signalUpdateTranslationFromAPI(pos->fVal1);
    // emit signalUpdateRotationFromAPI(pos->fVal2);

    // std::shared_ptr<KFDeviceInfo> xPos = KFInterCom::Instance()->GetDeviceInfo(m_pCringHMI->fNavigatorTranslation.fDeviceID);
    // std::shared_ptr<KFDeviceInfo> yPos = KFInterCom::Instance()->GetDeviceInfo(m_pCringHMI->fNavigatorRotation.fDeviceID);
    // FORCE_DEBUG("xPos[%f] yPos[%f]", xPos->fVal1, yPos->fVal1);
    // emit signalUpdateTranslationFromAPI(xPos->fVal1);
    // emit signalUpdateRotationFromAPI(yPos->fVal1);

    emit signalUpdateTranslationFromAPI(info.GetXValueC360());
    emit signalUpdateRotationFromAPI(info.GetAngleC360());
    emit signalUpdateRevolutionsFromAPI(info.GetNRotationsC360());
}
