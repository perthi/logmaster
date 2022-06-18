// GUICringController189.h
// karl eirik bang fossberg

#ifndef GUI_CRING_CONTROLLER_180_H
#define GUI_CRING_CONTROLLER_180_H

#include "GUICringController.h"



class APIHmiCRing180;

class GUICringController180 : public GUICringController
{
    Q_OBJECT

public:
    GUICringController180(
        APIHmiCRing *pAPI,
        GUICringQuadView* pQuadA,
        GUICringQuadView* pQuadB,
        QWidget *pParent = nullptr);

    void UpdateValues(APICRingInfo &info) override;

};

#endif // GUI_CRING_CONTROLLER_180_H