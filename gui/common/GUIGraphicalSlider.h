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
    int m_tmpSize;

    int m_dx;
    int m_xPos;
    int m_sliderBarXPos;
    bool m_sliderActive;
    bool m_negativeButtonActive;
    bool m_positiveButtonActive;
    QRect m_negativeButton;
    QRect m_positiveButton;
    QRect m_sliderSpace;
    QRect m_sliderBackground;
    QRect m_sliderBar;

};

#endif //  GUI_GRAPHICAL_SLIDER_H
