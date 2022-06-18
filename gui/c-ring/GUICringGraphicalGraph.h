// GUICringGraphicalGraph.h
// karl eirik bang fossberg

#ifndef GUI_CRING_GRAPHICAL_GRAPH_H
#define GUI_CRING_GRAPHICAL_GRAPH_H

#include <QtCharts/QtCharts>
#include <QtWidgets/QWidget>

class GUICringGraphicalGraph : public QWidget
{

    Q_OBJECT

public:
    GUICringGraphicalGraph(int minY, int maxY, QWidget *pParent = nullptr);
    ~GUICringGraphicalGraph();

public slots:
    void slotUpdateTimeSeries(const double &translation,
        const double &rotation);

private:
    void checkBoundaries(const double &translation, const double &rotation);

private:
    int m_seriesLength;
    int m_xLimit;
    int m_yLimit;
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;

    QLineSeries *m_pLineSeries;
    QLineSeries *m_pCurrentPos;

    QColor m_positionValid;
    QColor m_positionInvalid;
};

#endif // GUI_CRING_GRAPHICAL_GRAPH_H
