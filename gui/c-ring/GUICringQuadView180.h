// GUICringQuadView180.h
// karl eirik bang fossberg

#ifndef GUI_CRING_QUAD_VIEW_180_H
#define GUI_CRING_QUAD_VIEW_180_H

#include "GUICringQuadView.h"

class GUICringQuadView180 : public GUICringQuadView
{

public:
    GUICringQuadView180(QWidget *pParent = nullptr);
    ~GUICringQuadView180();

    virtual void UpdateValues(APICRingInfo &info) override;
};

#endif // GUI_CRING_QUAD_VIEW_180_H