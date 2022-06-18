// GUICringGraphicalIndicators.cpp
// karl eirik bang fossberg

#include "GUICringGraphicalIndicators.h"

#include <QtCore/QTimerEvent>
#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPainterPath>

#include <iostream>
#include <string>
#include <vector>

GUICringGraphicalIndicators::GUICringGraphicalIndicators(eCRING activeCring,
    QWidget *pParent)
    : QWidget(pParent)
    , m_inputPrimaryTranslation(0)
    , m_inputSecondaryTranslation(0)
    , m_inputRotation(0)
    , m_activeCringColor("#fce57e")
    , m_inactiveCringColor("#eae6d3")
    , m_movingColor("#fcbf6a")
    , m_pipeColor("#a6c6fc")
    , m_homeColor("#9efc67")
    , m_bg1Color("#dbfafc")
    , m_bg2Color("#fcdbfa")
    , m_gb3Color("#fafcdb")
    , m_bg4Color("#e4fcdb")
    , m_errorColor("#f76b59")
    , m_bgGrayColor("#464747")
    , m_previousPosTranslation(0)
    , m_previousPosRotation(0)
    , m_nTimeSeries(10)
    , m_activeCring(activeCring)
{
    m_timer.start(500, this);

    switch (activeCring)
    {
        case eCRING::C_RING_1_180:
            m_c1Color = m_activeCringColor;
            m_c2Color = m_inactiveCringColor;
            break;

        case eCRING::C_RING_2_360:
            m_c1Color = m_inactiveCringColor;
            m_c2Color = m_activeCringColor;
            break;

        default:
            m_c1Color = m_errorColor;
            m_c2Color = m_errorColor;
            break;
    };

    setMinimumSize(400, 200);
}

GUICringGraphicalIndicators::~GUICringGraphicalIndicators()
{
    //
}

void
GUICringGraphicalIndicators::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timer.timerId())
    {
        update();
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void
GUICringGraphicalIndicators::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    UpdateRectRegionsDouble(painter);

    FillRoundedRect(painter, m_rectRegionLeft, m_bgGrayColor);
    FillRoundedRect(painter, m_rectRegionRight, m_bgGrayColor);

    RenderCRingIndicator(
        painter, m_inputPrimaryTranslation, m_inputSecondaryTranslation);
    RenderCRingAngle180(painter, m_inputRotation);

    RenderHomeIndicator(painter);
}

void
GUICringGraphicalIndicators::UpdateRectRegionsDouble(QPainter &painter)
{
    m_rectCanvas = painter.viewport();
    m_rectCanvas.setWidth(m_rectCanvas.width() - 1);
    m_rectCanvas.setHeight(m_rectCanvas.height() - 1);

    m_rectRegionLeft = { m_rectCanvas.x(),
        m_rectCanvas.y(),
        (m_rectCanvas.width() / 2),
        m_rectCanvas.height() };

    m_rectRegionRight = { (m_rectCanvas.width() / 2),
        m_rectCanvas.y(),
        (m_rectCanvas.width() / 2),
        m_rectCanvas.height() };
}

const QColor
GUICringGraphicalIndicators::RenderActiveColorTranslation(const int &offset)
{
    QColor activeColor;
    if (m_previousPosTranslation == offset)
    {
        activeColor = m_c1Color;
    }
    else
    {
        activeColor = m_movingColor;
    }
    m_previousPosTranslation = offset;
    return activeColor;
}

const QColor
GUICringGraphicalIndicators::RenderActiveColorRotation(const int &offset)
{
    QColor activeColor;
    if (m_previousPosRotation == offset)
    {
        activeColor = m_activeCringColor;
    }
    else
    {
        activeColor = m_movingColor;
    }
    m_previousPosRotation = offset;
    return activeColor;
}

void
GUICringGraphicalIndicators::RenderCRingIndicator(QPainter &painter,
    const int &offsetC1,
    const int &offsetC2)
{

    float scalingFactor = 0.15f;

    QRect region = m_rectRegionLeft;

    int rectMidW = region.width() / 1.25;
    int rectMidH = region.height() / 4;
    int rectMidX = ((region.width() / 2) - rectMidW / 2);
    int rectMidY = (region.height() / 2) - rectMidH / 2;
    m_pipeRect   = { rectMidX, rectMidY, rectMidW, rectMidH };

    int rectSidesY = rectMidH;
    int rectSidesW = (region.width() / 12);
    int rectSidesH = (region.height() / 2);

    int rectLeftX  = (region.width() / 4);
    int rectRightX = (region.width() - rectLeftX - rectSidesW);

    int rectLeftPos  = rectLeftX + (offsetC1 * scalingFactor);
    int rectRightPos = rectRightX + (offsetC2 * scalingFactor);

    m_c1Rect = { rectLeftPos, rectSidesY, rectSidesW, rectSidesH };
    m_c2Rect = { rectRightPos, rectSidesY, rectSidesW, rectSidesH };

    FillRoundedRect(painter, m_pipeRect, m_pipeColor);
    FillRoundedRect(painter, m_c1Rect, RenderActiveColorTranslation(offsetC1));
    FillRoundedRect(painter, m_c2Rect, m_c2Color);
}

void
GUICringGraphicalIndicators::FillRoundedRect(QPainter &painter,
    const QRect &rect,
    const QColor &fillColor,
    const float &opacity)
{
    QPainterPath tmpPath;
    tmpPath.addRoundedRect(rect, 5, 5);

    QPen pen(Qt::black, 2);
    painter.setPen(pen);
    painter.setOpacity(opacity);
    painter.fillPath(tmpPath, fillColor);
    painter.drawPath(tmpPath);
    painter.setOpacity(1.0f);
}

QRect &
GUICringGraphicalIndicators::MakeSquare(QRect &rect)
{

    if (rect.width() > rect.height())
    {
        int dx = ((rect.width() - rect.height()) / 2);
        rect.setWidth(rect.height());
        rect.translate(dx, 0);
    }
    else if (rect.height() > rect.width())
    {
        int dx = ((rect.height() - rect.width()) / 2);
        rect.setHeight(rect.width());
        rect.translate(0, dx);
    }
    else
    {
        // printf("Your rectangle is already a square.\n");
        // do nothing
    }
    return rect;
}

void
GUICringGraphicalIndicators::RenderCRingAngle180(QPainter &painter,
    const int &angle)
{
    QRect region = MakeSquare(m_rectRegionRight);

    int rectMargins  = region.height() / 4;
    int circleRadius = 24;
    int angleSpan    = 60;
    int angleOffset  = -90 - (angleSpan / 2);

    QRect outerArcRegion = { region.x() + rectMargins,
        region.y() + rectMargins,
        region.width() - (2 * rectMargins),
        region.height() - (2 * rectMargins) };

    QRect innerArcRegion = { outerArcRegion.x() + circleRadius,
        outerArcRegion.y() + circleRadius,
        outerArcRegion.width() - (2 * circleRadius),
        outerArcRegion.height() - (2 * circleRadius) };

    QPoint center = { (outerArcRegion.x() + (outerArcRegion.width() / 2)),
        (outerArcRegion.y() + (outerArcRegion.height() / 2)) };

    QPainterPath piePath;
    piePath.moveTo(center);
    piePath.arcTo(region, (angle + angleOffset), angleSpan);
    piePath.closeSubpath();

    QPainterPath circlePath;
    circlePath.addEllipse(outerArcRegion);
    circlePath.addEllipse(innerArcRegion);
    circlePath.closeSubpath();

    QPainterPath cRingIndicatorPath = circlePath.subtracted(piePath);
    painter.drawPath(cRingIndicatorPath);
    painter.fillPath(cRingIndicatorPath, RenderActiveColorRotation(angle));

    QPainterPath homeIndicatorPath = CreateHomeIndicator(region);

    painter.drawPath(homeIndicatorPath);
    if (angle == 0)
    {
        painter.fillPath(homeIndicatorPath, m_homeColor);
    }
}

const QPainterPath
GUICringGraphicalIndicators::CreateHomeIndicator(const QRect &region)
{

    int indicatorSize = 15;
    int floorOffset   = 30;

    int xPosition = (region.x() + (region.width() / 2) - (indicatorSize / 2));

    QRect homeIndicator = {
        xPosition, (region.height() - floorOffset), indicatorSize, indicatorSize
    };

    QPainterPath homeIndicatorPath;
    homeIndicatorPath.addEllipse(homeIndicator);
    homeIndicatorPath.closeSubpath();
    return homeIndicatorPath;
}

void
GUICringGraphicalIndicators::slotTranslationC1(const double &translation)
{
    m_inputPrimaryTranslation = (int)translation;
    this->update();
}

void
GUICringGraphicalIndicators::slotTranslationC2(const double &translation)
{
    m_inputSecondaryTranslation = (int)translation;
    this->update();
}

void
GUICringGraphicalIndicators::slotRotation(const double &rotation)
{
    m_inputRotation = (int)rotation;
    this->update();
}

void
GUICringGraphicalIndicators::RenderHomeIndicator(QPainter &painter)
{

    int indicatorSize = 15;
    int floorOffset   = 30;
    int indicatorX    = 0; // This variable might need futher tweaking
    int indicatorY    = (m_rectCanvas.height() - floorOffset);
    int activeOffset  = 0;

    switch (m_activeCring)
    {
        case eCRING::C_RING_1_180:
            indicatorX += m_pipeRect.x();
            activeOffset = m_c1Rect.x();
            break;

        case eCRING::C_RING_2_360:
            indicatorX += (m_pipeRect.x() + m_pipeRect.width() - indicatorSize);
            activeOffset = m_c2Rect.x();
            break;

        default:
            break;
    }

    QRect indicatorRect = {
        indicatorX, indicatorY, indicatorSize, indicatorSize
    };

    QPainterPath homeIndicatorPath;
    homeIndicatorPath.addEllipse(indicatorRect);
    homeIndicatorPath.closeSubpath();
    painter.drawPath(homeIndicatorPath);

    if (activeOffset == indicatorX)
    {
        painter.fillPath(homeIndicatorPath, m_homeColor);
    }
}