// GUIPainterClass.h
// karl eirik bang fossberg

#ifndef GUI_PAINTER_CLASS_H
#define GUI_PAINTER_CLASS_H

#include <QtGui/QPainter>
#include <QtWidgets/QWidget>
#include <memory>

class GUIPainterClass : public QWidget
{
    Q_OBJECT

public:
    GUIPainterClass(QWidget *pParent = nullptr);
    ~GUIPainterClass();

protected:
    virtual void paintEvent(QPaintEvent * /*event*/){};

    void FillRoundedRect(QPainter &painter,
        const QRect &rect,
        const QColor &color);
    QRect GetHorizontalIndicatorRect(const int &value);
    QRect GetVerticalIndicatorRect(const int &value);
    QRect PadRect(const QRect &rect, const int &padX, const int &padY);
    QPoint FindMidPoint(const QRect &rect,
        const int &xOffset = 0,
        const int &yOffset = 0);

signals:
    void signalUpdateSlider(const int &value);

protected:
    QRect m_canvasRect{};
    QRect m_canvasRectPadded{};
    QRect m_indicatorRect{};

    QColor m_bgColor{};
    QColor m_fgColor{};
    QColor m_activeColor{};

    int m_minValue = 0;
    int m_maxValue = 0;
    int m_widgetSize = 0;
};

#endif // GUI_PAINTER_CLASS_H
