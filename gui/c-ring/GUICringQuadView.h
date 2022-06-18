// GUICringQuadView.h
// karl eirik bang fossberg

#ifndef GUI_CRING_QUAD_VIEW_H
#define GUI_CRING_QUAD_VIEW_H


#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>


class APICRingInfo;
class GUICringGraphicalIndicators;
class GUICringGraphicalGraph;


#include <memory>

class GUICringQuadView : public QWidget
{
    Q_OBJECT

public:
   // GUICringQuadView(eCRING activeCring, QWidget *pParent = nullptr);
     GUICringQuadView(int activeCring, QWidget *pParent = nullptr);
    ~GUICringQuadView();

    virtual void UpdateValues(APICRingInfo &info);

public slots:
    void slotTmpUpdateX(const double &val) { lastKnownX = val; }
    void slotTmpUpdateY(const double &val) { lastKnownY = val; }

protected:
    double lastKnownX;
    double lastKnownY;
    double secondaryX;

    std::unique_ptr<QVBoxLayout> m_pLayout;
    std::unique_ptr<GUICringGraphicalIndicators> m_pIndicators;
    std::unique_ptr<GUICringGraphicalGraph> m_pGraph;
};

#endif // GUI_CRING_QUAD_VIEW_H