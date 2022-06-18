// GUICringOperationsSliderBar.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_SLIDER_BAR_H
#define GUI_CRING_OPERATIONS_SLIDER_BAR_H

#include <gui/common/GUIGraphicalSlider.h>
#include <memory>

class QBoxLayout;
class QLabel;
class QScrollBar;
class QWidget;
class QHBoxLayout;
class QVBoxLayout;
class KFHMIControl;

class GUICringOperationsSliderBar : public QWidget
{
    Q_OBJECT

public:
    GUICringOperationsSliderBar(
        const KFHMIControl &indicator,
        const int &startingValue = 0,
        QWidget *pParent = nullptr);
    ~GUICringOperationsSliderBar();

private:
    int ScaleSliderValue(const int &input);

private slots:
    void slotUpdateSlider(const int &value);

signals:
    void signalSliderValue(const int &value);

private:
    std::unique_ptr<QVBoxLayout> m_pRootLayout;
    std::unique_ptr<QHBoxLayout> m_pLabelLayout;

    std::unique_ptr<QLabel> m_pCaptionLabel;
    std::unique_ptr<QLabel> m_pLeftLabel;
    std::unique_ptr<QLabel> m_pCenterLabel;
    std::unique_ptr<QLabel> m_pRightLabel;

    std::unique_ptr<GUIGraphicalSlider> m_pSliderCustom;

    int m_currentValue;
    int m_minValue;
    int m_maxValue;
    std::string m_unit;
};

#endif // GUI_CRING_OPERATIONS_SLIDER_BAR_H
