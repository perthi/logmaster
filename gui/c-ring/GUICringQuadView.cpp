// GUICringQuadView.cpp
// karl eirik bang fossberg

#include "GUICringQuadView.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>


#include <api/api-hmi/APICRingInfo.h>


#include "GUICringGraphicalGraph.h"
#include "GUICringGraphicalIndicators.h"


GUICringQuadView::GUICringQuadView( int activeCring, QWidget *pParent)
    : QWidget(pParent)
{

    m_pLayout     = std::make_unique<QVBoxLayout>();
    m_pIndicators = std::make_unique<GUICringGraphicalIndicators>(  (eCRING)activeCring);
    m_pGraph      = std::make_unique<GUICringGraphicalGraph>(-200, 200);

    m_pLayout.get()->addWidget(m_pIndicators.get());
    m_pLayout.get()->addWidget(m_pGraph.get());

    setLayout(m_pLayout.release());
}

GUICringQuadView::~GUICringQuadView()
{
    //
}

void
GUICringQuadView::UpdateValues(APICRingInfo &info)
{
    printf("[!] Please use the overloaded classes. Printing all avalilable "
           "debug info:\n");
    printf("[ ] C180 [%0.2lf, \t %0.2lf] \n",
        info.GetXValueC180(),
        info.GetAngleC180());
    printf("[ ] C380 [%0.2lf, \t %0.2lf] \t (%d revolutions)\n",
        info.GetXValueC360(),
        info.GetAngleC360(),
        info.GetNRotationsC360());
}
