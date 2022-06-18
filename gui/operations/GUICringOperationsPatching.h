// GUICringOperationsPatching.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_PATCHING_H
#define GUI_CRING_OPERATIONS_PATCHING_H

#include "GUICringOperationsBase.h"

#include <QtWidgets/QWidget>
#include <memory>

#include "GUICringOperationsIndicatorBar.h"

class APIHmiOperation;
class GUICringOperationsPatching : public GUICringOperationsBase
{
    Q_OBJECT

public:
    GUICringOperationsPatching(
        std::shared_ptr<APIHmiOperation> pAPI,
        QWidget *pParent = nullptr);
    ~GUICringOperationsPatching();

protected:
    virtual void API OnUpdateTick() override;

signals:
    void signalUpdateGlueIndicator(const int &value);


private:
    KFHMIControlGroup *m_pControlGroup;
    std::unique_ptr<GUICringOperationsIndicatorBar> m_pGlueIndicator;
};

#endif // GUI_CRING_OPERATIONS_PATCHING_H
