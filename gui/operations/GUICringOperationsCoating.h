// GUICringOperationsCoating.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_COATING_H
#define GUI_CRING_OPERATIONS_COATING_H

#include "GUICringOperationsBase.h"


#include <QtWidgets/QWidget>
#include <memory>

class APIHmiOperationCoating;
class GUICringOperationsIndicatorBar;
class GUICringOperationsSliderBar;

class GUICringOperationsCoating : public GUICringOperationsBase
{
    Q_OBJECT

public:
    GUICringOperationsCoating(
        std::shared_ptr<APIHmiOperation> pAPI,
        QWidget *pParent = nullptr);
    ~GUICringOperationsCoating();

protected:
    virtual void API OnUpdateTick() override;


private slots:
    void slotOnSliderUpdate(const int &value);

signals:
    void signalUpdateCoatingIndicator(const int &value);


private:
    std::unique_ptr<GUICringOperationsSliderBar> m_pCoatingSlider;
    std::unique_ptr<GUICringOperationsIndicatorBar> m_pCoatingBar;
    KFHMIControlGroup *m_pControlGroup;
    DeviceID_t m_coatingDevice;

};

#endif // GUI_CRING_OPERATIONS_COATING_H
