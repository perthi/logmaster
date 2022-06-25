// GUIGraphicalSlider.h
// karl eirik bang fossberg

#ifndef GUI_GRAPHICAL_SLIDER_H
#define GUI_GRAPHICAL_SLIDER_H

#include <gui/common/GUIPainterClass.h>

#include <QtGui/QMouseEvent>
#include <QtWidgets/QWidget>

class GUIGraphicalSlider : public GUIPainterClass
{

public:
    GUIGraphicalSlider(const int &startingValue);
    ~GUIGraphicalSlider();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;



private:
    QPainterPath DrawArrow(QPainter &painter,
        const QRect &rect,
        const bool &reversed = false);

private:
    int m_tmpSize = 0;
    int m_dx = 0;
    int m_xPos = 0;
    int m_sliderBarXPos = 0;
    bool m_sliderActive = 0;
    bool m_negativeButtonActive = 0;
    bool m_positiveButtonActive = 0;
    QRect m_negativeButton{};
    QRect m_positiveButton{};
    QRect m_sliderSpace{};
    QRect m_sliderBackground{};
    QRect m_sliderBar{};

};

#endif //  GUI_GRAPHICAL_SLIDER_H
