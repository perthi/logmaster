// GUICringController.cpp
// karl eirik bang fossberg

#include "GUICringController.h"
#include "GUICringAbsolutePos.h"

#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

#include <api/api-hmi/APICRingInfo.h>
#include <api/api-hmi/APIHmiCRing.h>

#include <kf-common/KFDeviceInfo.h>
#include <configuration/KFEntityHMICRing.h>
#include <configuration/KFConfigurationHandler.h>
#include <intercom/KFInterCom.h>

#include "GUICringAbsolutePos.h"
#include "GUICringButtonGroup.h"
#include "GUICringQuadView.h"

#include <QtWidgets/QLabel>
#include <configuration/KFEntityHMICRing.h>
#include <QtCore/qcoreevent.h>



GUICringController::GUICringController(
    APIHmiCRing* pAPI,
    GUICringQuadView* pQuadA,
    GUICringQuadView* pQuadB,
    QWidget *pParent)
    : QWidget(pParent)
    , m_pAPI(pAPI)
    , m_180Quad(pQuadA)
    , m_360Quad(pQuadB)
{
    // SET_LOGLEVEL("--hmi-info");


    m_translationSteps = m_pAPI->GetStepsTranslation();
    m_rotationSteps = m_pAPI->GetStepsRotation();

    m_pLayout = new QGridLayout();
    m_pControllerUp   =  new GUICringButtonGroup(QBoxLayout::BottomToTop, m_rotationSteps);
    m_pControllerLeft  = new GUICringButtonGroup(QBoxLayout::RightToLeft, m_translationSteps);
    m_pControllerRight = new GUICringButtonGroup(QBoxLayout::LeftToRight, m_translationSteps);
    m_pControllerDown  = new GUICringButtonGroup(QBoxLayout::TopToBottom, m_rotationSteps);
    m_pSoftStop = new QPushButton("STOP");
    m_pSoftStop->setFixedSize(40, 30);

    m_pLabel = new QLabel(m_pAPI->GetTitle().c_str());
    m_pLayout->addWidget(m_pLabel, 0, 0, Qt::AlignCenter);


    // CalibrateHome
    // QVBoxLayout *pCalLayout = new QVBoxLayout();
    // QLabel *pCalLabel = new QLabel("Calibrate Home");
    // QSpinBox *pXPos = new QSpinBox();
    // QSpinBox *pYPos = new QSpinBox();
    // pCalLayout->addWidget(pCalLabel);
    // pCalLayout->addWidget(pXPos);
    // pCalLayout->addWidget(pYPos);
    // m_pLayout->addLayout(pCalLayout, 1, 1, Qt::AlignCenter);




    // Connection:
    // Incoming relative and continous motion from the buttongroups (directions)
    connect(m_pControllerUp,    &GUICringButtonGroup::signalRelative,  this, &GUICringController::slotRelativeMotion);
    connect(m_pControllerLeft,  &GUICringButtonGroup::signalRelative,  this, &GUICringController::slotRelativeMotion);
    connect(m_pControllerRight, &GUICringButtonGroup::signalRelative,  this, &GUICringController::slotRelativeMotion);
    connect(m_pControllerDown,  &GUICringButtonGroup::signalRelative,  this, &GUICringController::slotRelativeMotion);
    connect(m_pControllerUp,    &GUICringButtonGroup::signalContinous, this, &GUICringController::slotContinousMotion);
    connect(m_pControllerLeft,  &GUICringButtonGroup::signalContinous, this, &GUICringController::slotContinousMotion);
    connect(m_pControllerRight, &GUICringButtonGroup::signalContinous, this, &GUICringController::slotContinousMotion);
    connect(m_pControllerDown,  &GUICringButtonGroup::signalContinous, this, &GUICringController::slotContinousMotion);
    connect(m_pSoftStop,        &QPushButton::clicked,                 this, &GUICringController::slotSoftStop);

    m_pLayout->addWidget(m_pControllerUp,    0, 1, Qt::AlignCenter);
    m_pLayout->addWidget(m_pControllerLeft,  1, 0, Qt::AlignCenter);
    m_pLayout->addWidget(m_pControllerRight, 1, 2, Qt::AlignCenter);
    m_pLayout->addWidget(m_pControllerDown,  2, 1, Qt::AlignCenter);
    m_pLayout->addWidget(m_pSoftStop,        1, 1, Qt::AlignCenter);

    setLayout(m_pLayout);

    m_timer.start(500, this);

    // Getting the names of the different devices
    std::shared_ptr<KFEntityHMICRing> pHMIC180 = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING180));
    std::shared_ptr<KFEntityHMICRing> pHMIC360 = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING360));
    m_C180NameX = KFConfigurationHandler::Instance()->GetDeviceByID(pHMIC180->fNavigatorTranslation.fDeviceID)->fAddress.fName;
    m_C180NameY = KFConfigurationHandler::Instance()->GetDeviceByID(pHMIC180->fNavigatorRotation.fDeviceID)->fAddress.fName;
    m_C360NameX = KFConfigurationHandler::Instance()->GetDeviceByID(pHMIC360->fNavigatorTranslation.fDeviceID)->fAddress.fName;
    m_C360NameY = KFConfigurationHandler::Instance()->GetDeviceByID(pHMIC360->fNavigatorRotation.fDeviceID)->fAddress.fName;
}

GUICringController::~GUICringController()
{
    //
}

void
GUICringController::slotRelativeMotion(int direction, double value)
{
    switch (direction)
    {
        case 0: // RIGHT
        case 1: // LEFT
            m_pAPI->ApplyTranslationIncrement(value);
            // m_180Quad->slotTmpUpdateX(value);
            // m_360Quad->slotTmpUpdateX(value);
            break;
        case 2: // DOWN
        case 3: // UP
            m_pAPI->ApplyRotaionIncrement(value);
            // m_180Quad->slotTmpUpdateY(value);
            // m_360Quad->slotTmpUpdateY(value);
            break;
        default:
            HMI_INFO("\n[!] UNHANDLED CONDITION:\tDIRECTION: %d, VALUE: %f\n", direction, value);
            // ERROR STATE
            break;
    }
    // m_pAPI->Update();
}

void
GUICringController::slotContinousMotion(int direction)
{
    switch (direction)
    {
        case 0:
            m_pAPI->ApplyContniousTranslation(eDIRECTION::POSITIVE);
            break;
        case 1:
            m_pAPI->ApplyContniousTranslation(eDIRECTION::NEGATIVE);
            break;
        case 2:
            m_pAPI->ApplyContinuousRotaion(eDIRECTION::NEGATIVE);
            break;
        case 3:
            m_pAPI->ApplyContinuousRotaion(eDIRECTION::POSITIVE);
            break;
        default:
            HMI_INFO("\n[!] UNHANDLED CONDITION:\tDIRECTION: %d\n", direction);
            // ERROR STATE
            break;
    }
    // m_pAPI->Update();
}

void
GUICringController::UpdateValues(APICRingInfo &info)
{
    HMI_INFO("[.] Callback\n");
    HMI_INFO("[.] You should probably be instancing the specific controller in use.\n");
    HMI_INFO("[.] Debug info:\n%s", info.str().c_str());
    HMI_INFO("[.] Signals to update the API from UI is not implemented in the generic controller.\n");
}

void
GUICringController::slotDemoToggleMotor()
{
    m_pAPI->ApplyMotorDebugToggle();
}

void
GUICringController::slotDemoToggleLED()
{
    m_pAPI->ApplyBlinkLedToggle();
}

void
GUICringController::slotSoftStop()
{
    m_pAPI->ApplyStopSoft();
}

void
GUICringController::slotHardStop()
{
    m_pAPI->ApplyStopHard();
}
void
GUICringController::slotAbsolutePosition(const double &translation, const double &rotation)
{

    m_pAPI->ApplyPositionAbsolute(translation, rotation);

    m_180Quad->slotTmpUpdateX(translation);
    m_180Quad->slotTmpUpdateY(rotation);
    m_360Quad->slotTmpUpdateX(translation);
    m_360Quad->slotTmpUpdateY(rotation);
}

void
GUICringController::UpdateInfoStruct()
{

    APICRingInfo infoStruct;

    // Getting the HMI Groups
    std::shared_ptr<KFEntityHMICRing> pHMIC180 = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING180));
    std::shared_ptr<KFEntityHMICRing> pHMIC360 = std::dynamic_pointer_cast<KFEntityHMICRing>(KFConfigurationHandler::Instance()->GetByHMIType(eHMI_TYPE::CRING360));

    // C-Ring 180 Translation and Rotation
    std::shared_ptr<KFDeviceInfo> xPos180 = KFInterCom::Instance()->GetDeviceInfo(pHMIC180->fNavigatorTranslation.fDeviceID);
    std::shared_ptr<KFDeviceInfo> yPos180 = KFInterCom::Instance()->GetDeviceInfo(pHMIC180->fNavigatorRotation.fDeviceID);

    // C-Ring 360 Translation and Rotation
    std::shared_ptr<KFDeviceInfo> xPos360 = KFInterCom::Instance()->GetDeviceInfo(pHMIC360->fNavigatorTranslation.fDeviceID);
    std::shared_ptr<KFDeviceInfo> yPos360 = KFInterCom::Instance()->GetDeviceInfo(pHMIC360->fNavigatorRotation.fDeviceID);


    if(xPos180 != nullptr)
    {
        if(xPos180->fVal1 != -1)
        {
            last180x = xPos180->fVal1;
        }
        else
        {
            HMI_WARNING("[%s] value was -1. Dropping value.", xPos180->str().c_str());
            // pHMIC180->fNavigatorTranslation.fDeviceID.c_str());
        }
    }

    if(yPos180 != nullptr)
    {
        if(yPos180->fVal1 != -1)
        {
            last180y = yPos180->fVal1;
        }
        else
        {
            HMI_WARNING("[%s] value was -1. Dropping value.", yPos180->str().c_str());
            // pHMIC180->fNavigatorRotation.fDeviceID.c_str());
        }
    }


    if(xPos360 != nullptr)
    {
        // HMI_WARNING("\n %s", xPos360->str().c_str());
        if(xPos360->fVal1 != -1)
        {
            // m_debugCounterA ++;
            last360x = xPos360->fVal1;
        }
        else
        {
            // m_debugCounterB ++;
            HMI_WARNING("[%s] value was -1. Dropping value.", xPos360->fDeviceId.c_str());
            // pHMIC360->fNavigatorTranslation.fDeviceID.c_str());
        }
    }

    if(yPos360 != nullptr)
    {
        if(yPos360->fVal1 != -1)
        {
            // m_debugCounterA ++;
            last360y = yPos360->fVal1;
        }
        else
        {
            // m_debugCounterB ++;
            HMI_WARNING("[%s] value was -1. Dropping value.", yPos360->fDeviceId.c_str());
            // pHMIC360->fIndicatorRotation.fDeviceID.c_str());
        }
    }



    infoStruct.SetTranslationC180(last180x);
    infoStruct.SetAngleC180(last180y);

    infoStruct.SetTranslationC360(last360x);
    infoStruct.SetAngle360(last360y);

    // m_pAPI->Update();

    UpdateValues(infoStruct);
    m_180Quad->UpdateValues(infoStruct);
    m_360Quad->UpdateValues(infoStruct);

    // HMI_WARNING("Negative 1 readings [%d / %d] [x: %d][y: %d]", m_debugCounterB, m_debugCounterA, (int)last360x, (int)last360y);
}

void
GUICringController::timerEvent(QTimerEvent *pEvent)
{
    if (pEvent->timerId() == m_timer.timerId())
    {
        // OnUpdateTickBase();
        // OnUpdateTick();
        UpdateInfoStruct();

    }
    else
    {
        QWidget::timerEvent(pEvent);
    }
}