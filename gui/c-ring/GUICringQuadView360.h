// GUICringQuadView360.h
// karl eirik bang fossberg

#ifndef GUI_CRING_QUAD_VIEW_360_H
#define GUI_CRING_QUAD_VIEW_360_H

#include "GUICringQuadView.h"

class GUICringQuadView360 : public GUICringQuadView
{

public:
    GUICringQuadView360(QWidget *pParent = nullptr);
    ~GUICringQuadView360();

    virtual void UpdateValues(APICRingInfo &info) override;
};

#endif // GUI_CRING_QUAD_VIEW_360_H