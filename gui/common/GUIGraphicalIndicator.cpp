// GUIGraphicalIndicator.cpp
// karl eirik bang fossberg

#include "GUIGraphicalIndicator.h"

#include <QtGui/QPainter>
#include <QtWidgets/QGridLayout>
#include <memory>

GUIGraphicalIndicator::GUIGraphicalIndicator()
    : GUIPainterClass()
    , m_indicatorPosition(500)
{
    //
}

GUIGraphicalIndicator::~GUIGraphicalIndicator()
{
    //
}

void
GUIGraphicalIndicator::paintEvent(QPaintEvent * /*event*/ )
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_canvasRect = painter.viewport();

    m_canvasRectPadded = PadRect(m_canvasRect, 0, 0);
    FillRoundedRect(painter, m_canvasRectPadded, m_bgColor);
    QRect indicatorRect = PadRect(GetHorizontalIndicatorRect(m_indicatorPosition), 1, 1);

    FillRoundedRect(painter, indicatorRect, m_fgColor);
    painter.drawText(m_canvasRect, Qt::AlignCenter, (QString::number(m_indicatorPosition) + " mm"));
}

void
GUIGraphicalIndicator::SetPosition(const int &value)
{
    m_indicatorPosition = value;
    update();
}
