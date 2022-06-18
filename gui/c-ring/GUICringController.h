// GUICringController.h
// karl eirik bang fossberg

#ifndef GUI_CRING_CONTROLLER_H
#define GUI_CRING_CONTROLLER_H


#include <memory>

#include <QtWidgets/QWidget>
#include <QtCore/QBasicTimer>


class KFEntityHMICRing;
class QLabel;
class GUICringAbsolutePos;
class GUICringButtonGroup;
class GUICringQuadView;
class QPushButton;
class QGridLayout;

class APICRingInfo;

class APIHmiCRing;
class GUICringController : public QWidget
{
    Q_OBJECT

public:
    GUICringController(
        APIHmiCRing* pAPI,
        GUICringQuadView* pQuadA,
        GUICringQuadView* pQuadB,
        QWidget *pParent = nullptr);
    ~GUICringController();

    virtual void UpdateValues(APICRingInfo &info);
    void UpdateInfoStruct();

private:
    virtual void timerEvent(QTimerEvent *pEvent) override;


signals:
    void signalUpdateTranslationFromAPI(double value);
    void signalUpdateRotationFromAPI(double value);
    void signalUpdateRevolutionsFromAPI(int value);


private slots:
    void slotRelativeMotion(int direction, double value);
    void slotContinousMotion(int direction);

    void slotDemoToggleMotor();
    void slotDemoToggleLED();
    void slotSoftStop();
    void slotHardStop();

public slots:
    void slotAbsolutePosition(const double &translation, const double &rotation);


protected:
    QLabel *m_pLabel = nullptr;
    QGridLayout *m_pLayout = nullptr;
    GUICringAbsolutePos *m_pAbsPosition = nullptr;
    APIHmiCRing *m_pAPI = nullptr;
    GUICringQuadView *m_180Quad = nullptr;
    GUICringQuadView *m_360Quad = nullptr;

    std::shared_ptr<KFEntityHMICRing> m_pCringHMI;

private:
    std::vector<int> m_translationSteps;
    std::vector<int> m_rotationSteps;

    GUICringButtonGroup *m_pControllerLeft = nullptr;
    GUICringButtonGroup *m_pControllerRight = nullptr;
    GUICringButtonGroup *m_pControllerUp = nullptr;
    GUICringButtonGroup *m_pControllerDown = nullptr;
    QPushButton *m_pSoftStop = nullptr;
    QBasicTimer m_timer;

    std::string m_C180NameX = "";
    std::string m_C180NameY = "";
    std::string m_C360NameX = "";
    std::string m_C360NameY = "";

    float last180x = 0;
    float last180y = 0;
    float last360x = 0;
    float last360y = 0;

    int m_debugCounterA = 0;
    int m_debugCounterB = 0;


};

#endif // GUI_CRING_CONTROLLER_H