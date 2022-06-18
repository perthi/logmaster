// GUICringQuadView360.cpp
// karl eirik bang fossberg

#include "GUICringQuadView360.h"

#include <api/api-hmi/APICRingInfo.h>




#include "GUICringGraphicalGraph.h"
#include "GUICringGraphicalIndicators.h"


GUICringQuadView360::GUICringQuadView360(QWidget *pParent)
    : GUICringQuadView( (int)eCRING::C_RING_2_360, pParent)
{
    //
}

GUICringQuadView360::~GUICringQuadView360()
{
    //
}

void
GUICringQuadView360::UpdateValues(APICRingInfo &info)
{
    lastKnownX = info.GetXValueC360();
    lastKnownY = info.GetAngleC360();
    secondaryX = info.GetXValueC180();

    // m_pGraph.get()->slotUpdateTimeSeries(lastKnownX, lastKnownY);
    // m_pIndicators.get()->slotRotation(lastKnownY);
    // m_pIndicators.get()->slotTranslationC1(lastKnownX);
    // m_pIndicators.get()->slotTranslationC2(secondaryX);

    // lastKnownX = info.GetXValueC180();
    // lastKnownY = info.GetAngleC180();
    // secondaryX = info.GetXValueC360();

    m_pGraph.get()->slotUpdateTimeSeries(lastKnownX, lastKnownY);
    m_pIndicators.get()->slotRotation(lastKnownY);
    m_pIndicators.get()->slotTranslationC1(secondaryX);
    m_pIndicators.get()->slotTranslationC2(lastKnownX);
}
