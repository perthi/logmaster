// GUICringOperationsGraph.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_GRAPH_H
#define GUI_CRING_OPERATIONS_GRAPH_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <memory>

#include <configuration/KFHMIIndicator.h>

class GUICringOperationsGraph : public QWidget
{
    Q_OBJECT

public:
    GUICringOperationsGraph(
        const KFHMIIndicator &HMIIndicator,
        const int &resolution,
        QWidget *pParent = nullptr);
    ~GUICringOperationsGraph();

public slots:
    void slotUpdateTimeSeries(const int &force);

private:
    int m_ticksPerMS;
    int m_timeSeriesLength;
    int m_timeSeriesResolution;

    int m_xLimit;
    float m_timeSeriesStepSize;
    float m_currentTime;

    std::unique_ptr<QVBoxLayout> m_pRootLayout;
    std::unique_ptr<QChart> m_pChartData;
    std::unique_ptr<QChartView> m_pChartView;
    std::unique_ptr<QLineSeries> m_pTimeSeries;

    KFHMIIndicator m_indicator;
};

#endif // GUI_CRING_OPERATIONS_GRAPH_H
