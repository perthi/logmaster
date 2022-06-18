// GUICringWidget.cpp
// karl eirik bang fossberg

#include "GUICringWidget.h"

#include "GUICringController180.h"
#include "GUICringController360.h"

// #include <api/api-hmi/APICRingEnums.h>
// #include <api/api-hmi/APICRingInfo.h>

#include <api/api-hmi/APIHmiCRing180.h>
#include <api/api-hmi/APIHmiCRing360.h>

#include "GUICringButtonGroup.h"
#include "GUICringController.h"
#include "GUICringQuadView180.h"
#include "GUICringQuadView360.h"


GUICringWidget::GUICringWidget(QWidget *pParent)
    : QWidget(pParent)
    , m_pRootLayout(nullptr)
{

    // SET_LOGLEVEL("--sequence-all");
    // SET_LOGLEVEL("--hmi-info");
    // SET_LOGLEVEL("--sensor-info");


    m_pRootLayout  = new QGridLayout;
    m_p180API      = new APIHmiCRing180();
    m_p360API      = new APIHmiCRing360();
    m_180Quad      = new GUICringQuadView180();
    m_360Quad      = new GUICringQuadView360();
    m_pControllerA = new GUICringController180(m_p180API, m_180Quad, m_360Quad);
    m_pControllerB = new GUICringController360(m_p360API, m_180Quad, m_360Quad);

    // Connection:
    // Update the Controller UI with incoming data from the API
    std::function<void(APICRingInfo &)> funcController180(
        std::bind(&GUICringController::UpdateValues,
            m_pControllerA, std::placeholders::_1));

    std::function<void(APICRingInfo &)> funcController360(
        std::bind(&GUICringController::UpdateValues,
            m_pControllerB, std::placeholders::_1));

    // Connection:
    // Update the Graphical UI with incoming data from the API
    std::function<void(APICRingInfo &)> funcQuad180(std::bind(
        &GUICringQuadView::UpdateValues, m_180Quad, std::placeholders::_1));
    std::function<void(APICRingInfo &)> funcQuad360(std::bind(
        &GUICringQuadView::UpdateValues, m_360Quad, std::placeholders::_1));


    m_p180API->RegisterCallBack(funcController180);
    m_p360API->RegisterCallBack(funcController360);
    m_p180API->RegisterCallBack(funcQuad180);
    m_p360API->RegisterCallBack(funcQuad360);

    m_pRootLayout->addWidget(m_pControllerB, 0, 0);
    m_pRootLayout->addWidget(m_pControllerA, 0, 1);
    m_pRootLayout->addWidget(m_360Quad, 1, 0);
    m_pRootLayout->addWidget(m_180Quad, 1, 1);

    m_pRootLayout->setRowMinimumHeight(0, 100);
    m_pRootLayout->setRowMinimumHeight(1, 100);
    m_pRootLayout->setColumnMinimumWidth(0, 100);
    m_pRootLayout->setColumnMinimumWidth(1, 100);

    setLayout(m_pRootLayout);
}

GUICringWidget::~GUICringWidget()
{
    delete m_p180API;
    delete m_p360API;
}
