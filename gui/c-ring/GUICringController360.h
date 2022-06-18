// GUICringController360.h
// karl eirik bang fossberg

#ifndef GUI_CRING_CONTROLLER_360_H
#define GUI_CRING_CONTROLLER_360_H

#include "GUICringController.h"

class GUICringController360 : public GUICringController
{
    Q_OBJECT

public:
    GUICringController360(
        APIHmiCRing *pAPI,
        GUICringQuadView* pQuadA,
        GUICringQuadView* pQuadB,
        QWidget *pParent = nullptr);

    void UpdateValues(APICRingInfo &info) override;

};

#endif // GUI_CRING_CONTROLLER_180_H