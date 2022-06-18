// GUICringGraphicalGraph.cpp
// karl eirik bang fossberg

#include "GUICringGraphicalGraph.h"

#include <QtGui/QFont>
#include <QtWidgets/QGridLayout>

GUICringGraphicalGraph::GUICringGraphicalGraph(int minY, int maxY, QWidget *pParent)
    : QWidget(pParent)
    , m_seriesLength(1000)
    , m_xLimit(500)
    , m_minY(minY)
    , m_maxY(maxY)
    , m_positionValid("#3a9af4")
    , m_positionInvalid("#f43a4d")
{

    QGridLayout *pLayout = new QGridLayout;

    QChart *chart = new QChart();
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(200);

    m_pLineSeries = new QLineSeries();
    for (int i = 0; i < m_seriesLength; i++)
    {
        m_pLineSeries->append(0, 0);
    }

    m_pCurrentPos = new QLineSeries();
    for (int i = 0; i < 8; i++)
    {
        m_pCurrentPos->append(0, 0);
    }

    chart->addSeries(m_pLineSeries);
    chart->addSeries(m_pCurrentPos);

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(-m_xLimit, m_xLimit);
    chart->axes(Qt::Vertical).first()->setRange(m_minY, m_maxY);
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    pLayout->addWidget(chartView);
    setLayout(pLayout);
    setMinimumSize(300, 300);
    setMaximumSize(300, 300);
}

GUICringGraphicalGraph::~GUICringGraphicalGraph()
{
    //
}

void
GUICringGraphicalGraph::slotUpdateTimeSeries(const double &translation,
    const double &rotation)
{

    // Moves the list of points one step back, and inserts the last position
    for (int i = 0; i < (m_seriesLength - 1); i++)
    {
        m_pLineSeries->replace(i, m_pLineSeries->at(i + 1));
    }
    m_pLineSeries->replace((m_seriesLength - 1), translation, rotation);

    // Drawing an X for the current position
    double xSize = 15.0f;
    double ySize = ((xSize * m_maxY) / 500);
    m_pCurrentPos->replace(0, (translation + xSize), (rotation + ySize));
    m_pCurrentPos->replace(1, (translation), (rotation));
    m_pCurrentPos->replace(2, (translation + xSize), (rotation - ySize));
    m_pCurrentPos->replace(3, (translation), (rotation));
    m_pCurrentPos->replace(4, (translation - xSize), (rotation + ySize));
    m_pCurrentPos->replace(5, (translation), (rotation));
    m_pCurrentPos->replace(6, (translation - xSize), (rotation - ySize));
    m_pCurrentPos->replace(7, (translation), (rotation));

    checkBoundaries(translation, rotation);
}

void
GUICringGraphicalGraph::checkBoundaries(const double &translation,
    const double &rotation)
{

    if (((translation <= -m_xLimit) || (translation >= m_xLimit)) ||
        ((rotation <= 0) || (rotation >= m_yLimit)))
    {
        m_pCurrentPos->setColor(m_positionInvalid);
    }
    else
    {
        m_pCurrentPos->setColor(m_positionValid);
    }
}