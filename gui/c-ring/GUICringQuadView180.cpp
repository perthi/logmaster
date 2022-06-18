// GUICringQuadView180.cpp
// karl eirik bang fossberg

#include "GUICringQuadView180.h"


#include <api/api-hmi/APICRingInfo.h>


#include "GUICringGraphicalGraph.h"
#include "GUICringGraphicalIndicators.h"


GUICringQuadView180::GUICringQuadView180(QWidget *pParent)
    : GUICringQuadView( (int)eCRING::C_RING_1_180, pParent)
{
    //
}

GUICringQuadView180::~GUICringQuadView180()
{
    //
}

void
GUICringQuadView180::UpdateValues(APICRingInfo &info)
{
    lastKnownX = info.GetXValueC180();
    lastKnownY = info.GetAngleC180();
    secondaryX = info.GetXValueC360();

    m_pGraph.get()->slotUpdateTimeSeries(lastKnownX, lastKnownY);
    m_pIndicators.get()->slotRotation(lastKnownY);
    m_pIndicators.get()->slotTranslationC1(lastKnownX);
    m_pIndicators.get()->slotTranslationC2(secondaryX);
}
