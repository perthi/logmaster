// GUICringOperationsSurfacePrep.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_SURFACE_PREP_H
#define GUI_CRING_OPERATIONS_SURFACE_PREP_H

#include "GUICringOperationsBase.h"

#include <QtWidgets/QWidget>
#include <memory>

class APIHmiOperation;
class GUICringOperationsSliderBar;
class GUICringOperationsIndicatorBar;
class KFHMIControlGroup;
class GUICringOperationsSurfacePrep : public GUICringOperationsBase
{
    Q_OBJECT

public:
    GUICringOperationsSurfacePrep(
        std::shared_ptr<APIHmiOperation> pAPI,
        QWidget *pParent = nullptr);
    ~GUICringOperationsSurfacePrep();

private slots:
    void slotUpdateMotorSpeedSlider(const int &value);


private:
    std::shared_ptr<GUICringOperationsSliderBar> m_pMotorSpeedSlider = nullptr;
    KFHMIControlGroup *m_pMotorDevice = nullptr;

};

#endif // GUI_CRING_OPERATIONS_SURFACE_PREP_H
