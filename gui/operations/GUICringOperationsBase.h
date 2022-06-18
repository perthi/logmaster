// GUICringOperationsBase.h

#ifndef GUI_CRING_OPERATIONS_BASE_H
#define GUI_CRING_OPERATIONS_BASE_H


#include <memory>

#include <QtWidgets/QWidget>
#include <QtCore/QBasicTimer>

#include <utilities/GDefinitions.h>
#include <api/api-hmi/APIDataTypes.h>
#include <kf-common/KFCommonEnums.h>


class APIHmiOperation;
class KFEntityHMIOperation;
class KFHMIControlGroup;
class GUICringOperationsButtonGroup;
class GUICringOperationsIndicatorBar;
class QVBoxLayout;
class QLabel;

class KFInterCom;


class GUICringOperationsBase : public QWidget
{

    Q_OBJECT


public:
    API GUICringOperationsBase(
        std::shared_ptr<APIHmiOperation> pAPI,
        QWidget *pParent = nullptr);
    ~GUICringOperationsBase();

protected:
    virtual void API timerEvent(QTimerEvent *pEvent) override;
    virtual void API OnUpdateTick(){};

private:
    void OnUpdateTickBase();


private slots:
    void slotIncrementPosition(const int &value);
    void slotContinuousMotion(const eDIRECTION &direction); // to be replaced, maybe
    void slotStop();

signals:
    void signalUpdateMainIndicator(const int &value);

protected:
    std::unique_ptr<QVBoxLayout> m_pRootLayout;
    std::unique_ptr<QLabel> m_pRootCaption;
    std::unique_ptr<GUICringOperationsButtonGroup> m_pDistanceController;
    std::unique_ptr<GUICringOperationsIndicatorBar> m_pIndicatorBar;
    std::string m_name;

    std::shared_ptr<APIHmiOperation> m_pAPI;
    std::shared_ptr<KFEntityHMIOperation>  m_pHMIOperation;

    KFInterCom *m_pIntercom;
    QBasicTimer m_timer;
    int m_timerTickMS;


private:
    DeviceID_t m_controlDevice;

};

#endif // GUI_CRING_OPERATIONS_BASE_H
