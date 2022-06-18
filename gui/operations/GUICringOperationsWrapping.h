// GUICringOperationsWrapping.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_WRAPPING_H
#define GUI_CRING_OPERATIONS_WRAPPING_H

#include "GUICringOperationsBase.h"
#include "GUICringOperationsGraph.h"
#include "GUICringOperationsIndicatorBar.h"
#include "GUICringOperationsSliderBar.h"

#include <QtCore/QBasicTimer>
#include <QtWidgets/QWidget>

class GUICringOperationsWrapping : public GUICringOperationsBase
{
public:
    GUICringOperationsWrapping(
        std::shared_ptr<APIHmiOperation> pAPI,
        QWidget *pParent = nullptr);
    ~GUICringOperationsWrapping();

protected:
    virtual void API OnUpdateTick() override;

private slots:
    void slotOnForceUpdate(const int &force);
    void slotOnFlowUpdate(const int &flow);

private:
    int   m_forceSliderValue;
    float m_flowSliderValue;


    std::unique_ptr<GUICringOperationsSliderBar> m_pForceBar;
    std::unique_ptr<GUICringOperationsSliderBar> m_pFlowBar;
    std::unique_ptr<GUICringOperationsGraph> m_pForceGraph;
    std::unique_ptr<GUICringOperationsIndicatorBar> m_pResinBar;

    KFHMIControlGroup *m_pForceControl;
    KFHMIControlGroup *m_pFlowControl;

};

#endif // GUI_CRING_OPERATIONS_WRAPPING_H
