// GUICringOperationsGraph.h
// karl eirik bang fossberg

#include "GUICringOperationsGraph.h"

GUICringOperationsGraph::GUICringOperationsGraph(
    const KFHMIIndicator &HMIIndicator,
    const int &resolution,
    QWidget *pParent)
    : QWidget(pParent)
    , m_ticksPerMS(resolution)
    , m_timeSeriesResolution(600)
    , m_currentTime(0.0f)
    , m_indicator(HMIIndicator)
{
    m_xLimit = m_indicator.fMaxValue;

    m_timeSeriesStepSize = ((float)m_ticksPerMS / 1000.0f);
    m_timeSeriesLength = ((float)m_timeSeriesResolution / m_timeSeriesStepSize);

    m_pRootLayout = std::make_unique<QVBoxLayout>();
    m_pChartData = std::make_unique<QChart>();
    m_pChartData.get()->setTheme(QChart::ChartThemeDark);

    m_pTimeSeries = std::make_unique<QLineSeries>();
    for (int i = 0; i < m_timeSeriesLength; i++)
    {
        m_pTimeSeries.get()->append(0, 0);
    }

    m_pChartData.get()->addSeries(m_pTimeSeries.get());
    m_pChartData.get()->createDefaultAxes();
    m_pChartData.get()->layout()->setContentsMargins(0, 0, 0, 0);
    m_pChartData.get()->axes(Qt::Horizontal).first()->setRange(0, m_timeSeriesResolution);
    m_pChartData.get()->axes(Qt::Vertical).first()->setRange(0, m_xLimit);
    m_pChartData.get()->legend()->hide();

    m_pChartView = std::make_unique<QChartView>(m_pChartData.get());
    m_pChartView.get()->setRenderHint(QPainter::Antialiasing);

    m_pRootLayout.get()->addWidget(m_pChartView.get());
    setLayout(m_pRootLayout.get());
    setMinimumHeight(200);
}

GUICringOperationsGraph::~GUICringOperationsGraph()
{
    m_pRootLayout.release();
    m_pChartData.release();
    m_pChartView.release();
    m_pTimeSeries.release();
}

void GUICringOperationsGraph::slotUpdateTimeSeries(const int &force)
{
    // printf("Something: VAL %d\n", force);
    // int currentForce = force;

    // Moves the list of points one step back, and inserts the last position
    for (int i = 0; i < (m_timeSeriesLength - 1); i++)
    {
        m_pTimeSeries.get()->replace(i, m_pTimeSeries.get()->at(i + 1));
    }
    m_pTimeSeries.get()->replace((m_timeSeriesLength - 1), m_currentTime, force);

    // offset the time axis if we've been live for longer than
    // timeSeriesResolution (which is currently 60 s)
    if (m_currentTime > m_timeSeriesResolution)
    {
        m_pChartData.get()->axes(Qt::Horizontal).first()->setMin(m_currentTime - m_timeSeriesResolution + m_timeSeriesStepSize);
        m_pChartData.get()->axes(Qt::Horizontal).first()->setMax(m_currentTime);
    }

    m_currentTime += m_timeSeriesStepSize;
}
