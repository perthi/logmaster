// GUICRingGraphicalIndicators.h
// karl eirik bang fossberg

#ifndef GUI_CRING_GRAPHICAL_INDICATORS_H
#define GUI_CRING_GRAPHICAL_INDICATORS_H

#include <QtCore/QBasicTimer>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
///#include <api/api-hmi/APICRingEnums.h>

#include <kf-common/KFCommonEnums.h>

#include <memory>
#include <vector>

class GUICringGraphicalIndicators : public QWidget
{

    Q_OBJECT

public:
    GUICringGraphicalIndicators(eCRING activeCring, QWidget *pParent = nullptr);
    ~GUICringGraphicalIndicators();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    void UpdateRectRegionsDouble(QPainter &painter);
    const QColor RenderActiveColorTranslation(const int &offset);
    const QColor RenderActiveColorRotation(const int &offset);

    void FillRoundedRect(QPainter &painter,
        const QRect &rect,
        const QColor &fillColor = Qt::black,
        const float &opacity    = 1.0);

    QRect &MakeSquare(QRect &rect);

    void RenderCRingIndicator(QPainter &painter,
        const int &offsetC1 = 0,
        const int &offsetC2 = 0);
    void RenderCRingAngle180(QPainter &painter, const int &angle = 0);
    const QPainterPath CreateHomeIndicator(const QRect &region);

    void RenderHomeIndicator(QPainter &painter);

public slots:
    void slotTranslationC1(const double &translation);
    void slotTranslationC2(const double &translation);
    void slotRotation(const double &rotation);

private:
    QBasicTimer m_timer;

    QRect m_rectCanvas;
    QRect m_rectRegionLeft;
    QRect m_rectRegionRight;

    QRect m_c1Rect;
    QRect m_c2Rect;
    QRect m_pipeRect;

    int m_inputPrimaryTranslation;
    int m_inputSecondaryTranslation;
    int m_inputRotation;

    QColor m_activeCringColor;
    QColor m_inactiveCringColor;
    QColor m_movingColor;
    QColor m_pipeColor;
    QColor m_homeColor;
    QColor m_bg1Color;
    QColor m_bg2Color;
    QColor m_gb3Color;
    QColor m_bg4Color;
    QColor m_errorColor;
    QColor m_bgGrayColor;

    int m_previousPosTranslation;
    int m_previousPosRotation;
    int m_nTimeSeries;

    eCRING m_activeCring;
    QColor m_c1Color;
    QColor m_c2Color;
};

#endif // GUI_CRING_GRAPHICAL_INDICATORS_H
