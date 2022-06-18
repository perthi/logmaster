// GUIPainterClass.cpp
// karl eirik bang fossberg

#include "GUIPainterClass.h"


#include <QtGui/QPainterPath>
#include <QtGui/QPainter>


GUIPainterClass::GUIPainterClass(QWidget *pParent)
    : QWidget(pParent)
    , m_bgColor("#c1c1c1")
    , m_fgColor("#7dd1ed")
    , m_activeColor("#599aaf")
    , m_minValue(0)
    , m_maxValue(1000)
    , m_widgetSize(30)
{
    setFixedHeight(m_widgetSize);
}

GUIPainterClass::~GUIPainterClass()
{
    //
}

void
GUIPainterClass::FillRoundedRect(QPainter &painter,
    const QRect &rect,
    const QColor &fillColor)
{
    QPainterPath tmpPath;
    tmpPath.addRoundedRect(rect, 5, 5);

    QPen pen(Qt::black, 1);
    painter.setPen(pen);
    painter.fillPath(tmpPath, fillColor);
    painter.drawPath(tmpPath);
}

QRect
GUIPainterClass::GetHorizontalIndicatorRect(const int &value)
{
    QRect region       = m_canvasRectPadded;
    int width          = (region.width() - region.x());
    int indicatorWidth = (m_minValue + ((value * width) / m_maxValue));

    QRect indicatorRect = {
        region.x(), region.y(), indicatorWidth, region.height()
    };

    return indicatorRect;
}

QRect
GUIPainterClass::GetVerticalIndicatorRect(const int &value)
{
    QRect region        = m_canvasRectPadded;
    int height          = (region.height() - region.y());
    int indicatorHeight = (m_minValue + ((value * height) / m_maxValue));

    QRect indicatorRect = {
        region.x(), region.y(), region.width(), indicatorHeight
    };

    return indicatorRect;
}

QRect
GUIPainterClass::PadRect(const QRect &rect,
    const int &padX,
    const int &padY)
{
    int x = (rect.x() + padX);
    int y = (rect.y() + padY);
    int w = (rect.width() - (padX * 2));
    int h = (rect.height() - (padY * 2));

    return { x, y, w, h };
}

QPoint
GUIPainterClass::FindMidPoint(const QRect &rect,
    const int &xOffset,
    const int &yOffset)
{

    int x = ((rect.width() - rect.x() / 2) + xOffset);
    int y = ((rect.height() - rect.y() / 2) + yOffset);

    return { x, y };
}