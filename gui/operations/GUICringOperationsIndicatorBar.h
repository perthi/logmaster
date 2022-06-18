// GUICringOperationsIndicatorBar.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_INDICATOR_BAR_H
#define GUI_CRING_OPERATIONS_INDICATOR_BAR_H

#include <gui/common/GUIGraphicalIndicator.h>

#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <memory>

#include <configuration/KFHMIIndicator.h>

class GUICringOperationsIndicatorBar : public QWidget
{
public:
    GUICringOperationsIndicatorBar(
        const KFHMIIndicator &HMIIndicator,
        QWidget *pParent = nullptr);
    ~GUICringOperationsIndicatorBar();

public slots:
    void slotUpdatePosition(const int &value);

private:
    KFHMIIndicator m_HMIIndicator;

    std::unique_ptr<QVBoxLayout> m_pRootLayout;
    std::unique_ptr<QHBoxLayout> m_pLabelLayout;

    std::unique_ptr<QLabel> m_pCaptionLabel;
    std::unique_ptr<QLabel> m_pLeftLabel;
    // std::unique_ptr<QLabel> m_pCenterLabel;
    std::unique_ptr<QLabel> m_pRightLabel;

    // std::unique_ptr<QProgressBar> m_pIndicatorBar;
    std::unique_ptr<GUIGraphicalIndicator> m_pIndicatorBar;
};

#endif // GUI_CRING_OPERATIONS_INDICATOR_BAR_H
