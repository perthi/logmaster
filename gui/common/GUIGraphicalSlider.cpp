// GUIGraphicalSlider.cpp
// karl eirik bang fossberg

#include "GUIGraphicalSlider.h"

#include <QtGui/QPainterPath>
#include <QtCore/QString>


GUIGraphicalSlider::GUIGraphicalSlider(const int &startingValue)
    : GUIPainterClass()
    , m_dx(0)
    , m_xPos(startingValue)
    , m_sliderActive(false)
    , m_negativeButtonActive(false)
    , m_positiveButtonActive(false)
{
    //
}

GUIGraphicalSlider::~GUIGraphicalSlider()
{
    //
}

void
GUIGraphicalSlider::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    m_canvasRect = painter.viewport();

    int buttonWidth = m_widgetSize;

    m_negativeButton = {
        m_canvasRect.x(),
        m_canvasRect.y(),
        buttonWidth,
        m_canvasRect.height()
        };

    m_positiveButton = {
        (m_canvasRect.width() - buttonWidth),
        m_canvasRect.y(),
        buttonWidth,
        m_canvasRect.height()
        };

    int sliderPadX     = 0;
    int sliderPadY     = 0;
    m_sliderSpace      = { m_negativeButton.topRight(), m_positiveButton.bottomLeft() };
    m_sliderBackground = PadRect(m_sliderSpace, sliderPadX, sliderPadY);

    FillRoundedRect(painter, m_negativeButton, m_fgColor);
    FillRoundedRect(painter, m_positiveButton, m_fgColor);
    FillRoundedRect(painter, m_sliderBackground, m_bgColor);

    m_xPos += m_dx;
    m_dx = 0;

    int posMin = 0;
    int posMax = 1000;

    // Boundary checking
    m_xPos = (m_xPos <= posMin) ? posMin : m_xPos;
    m_xPos = (m_xPos >= posMax) ? posMax : m_xPos;

    int barWidth   = 30;
    int availWidth = (m_sliderSpace.width() - barWidth);
    int widthRatio = (posMin + ((m_xPos * availWidth) / posMax));
    int barX = (m_sliderSpace.x() + widthRatio);

    m_sliderBar = { barX, m_sliderSpace.y(), barWidth, m_sliderSpace.height() };

    QColor currentColor = m_sliderActive ? m_activeColor : m_fgColor;
    FillRoundedRect(painter, m_sliderBar, currentColor);

    QPainterPath lArrow, rArrow;
    lArrow = DrawArrow(painter, m_negativeButton, true);
    rArrow = DrawArrow(painter, m_positiveButton, false);

    QColor btnRColor = m_positiveButtonActive ? m_activeColor : m_fgColor;
    QColor btnLColor = m_negativeButtonActive ? m_activeColor : m_fgColor;
    painter.fillPath(rArrow, btnRColor);
    painter.fillPath(lArrow, btnLColor);

}

void
GUIGraphicalSlider::mouseMoveEvent(QMouseEvent *event)
{
    // Mouse Drag Event
    // For moving the slider

    QPoint mPoint = event->pos();
    if (m_sliderActive)
    {
        m_dx = (mPoint.x() - m_sliderBar.center().x());

        emit signalUpdateSlider(m_xPos);
        // /printf("Deviation: [%d] : %d\n", m_dx);
    }
    update();
}

void
GUIGraphicalSlider::mousePressEvent(QMouseEvent *event)
{
    QPoint mPoint  = event->pos();
    int offset     = (mPoint.x() - m_sliderBar.center().x());
    int aOffsetMid = 10;
    int aOffsetBtn = 1;

    /*
     *
     * Dragging the slider:
     *      Absolute positioning.
     *
     * Clicking on either side of the slider:
     *      Relative positioning, +- 10
     *
     * Clicking on the buttons:
     *      Relative positioning, +- 1
     *
     */

    if (m_sliderBar.contains(mPoint))
    {
        m_sliderActive = true;
    }
    else if (m_sliderSpace.contains(mPoint))
    {
        m_dx = (offset >= 0) ? aOffsetMid : -aOffsetMid;
    }
    else if (m_negativeButton.contains(mPoint))
    {
        m_negativeButtonActive = true;

        m_dx = -(aOffsetBtn);
    }
    else if (m_positiveButton.contains(mPoint))
    {
        m_positiveButtonActive = true;

        m_dx = (aOffsetBtn);
    }

    update();
}

void
GUIGraphicalSlider::mouseReleaseEvent(QMouseEvent *event)
{
    m_sliderActive = false;
    m_negativeButtonActive   = false;
    m_positiveButtonActive   = false;
    update();

    emit signalUpdateSlider(m_xPos);
}

QPainterPath
GUIGraphicalSlider::DrawArrow(QPainter &painter,
    const QRect &rect,
    const bool &reversed)
{

    QRect region  = rect;
    int triPadX   = (region.width() / 5);
    int triPadY   = (region.height() / 5);
    QRect triRect = PadRect(region, triPadX, triPadY);

    QPoint triStart, triEnd, triMid;
    if (reversed)
    {
        triStart = triRect.topRight();
        triEnd   = triRect.bottomRight();
        triMid   = { triRect.left(), triRect.center().y() };
    }
    else
    {
        triStart = triRect.topLeft();
        triEnd   = triRect.bottomLeft();
        triMid   = { triRect.right(), triRect.center().y() };
    }

    QPainterPath triPath, triPath3D;
    triPath.moveTo(triStart);
    triPath.lineTo(triMid);
    triPath.lineTo(triEnd);
    triPath.closeSubpath();

    triPath3D = triPath;
    triPath3D.translate({ 3, 3 });

    painter.fillPath(triPath3D, m_activeColor);
    painter.setPen({ Qt::black, 2 });
    painter.drawPath(triPath);

    return triPath;
}