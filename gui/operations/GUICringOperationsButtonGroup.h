// GUICringOperationsButtonGroup.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_BUTTON_GROUP_H
#define GUI_CRING_OPERATIONS_BUTTON_GROUP_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <memory>
#include <vector>

#include <configuration/KFHMIStepNavigator.h>
#include <kf-common/KFCommonEnums.h>

class GUICringOperationsButtonGroup : public QWidget
{

    Q_OBJECT

public:
    // enum eDIRECTION : int {
    //     POSITIVE,
    //     NEGATIVE
    // };

public:
    GUICringOperationsButtonGroup(
        const KFHMIStepNavigator &navigator,
        QWidget *pParent = nullptr);
    GUICringOperationsButtonGroup(QWidget *pParent = nullptr);
    ~GUICringOperationsButtonGroup();

signals:
    void signalPositionIncrement(const int &value);
    void signalStartContiuous(const eDIRECTION &direction);
    void signalStop();


private:
    void AddVector(std::vector<int> indices);

private slots:
    void slotInternalPositionIncrement(const int &value);
    void slotStartContinousPositive();
    void slotStartContinousNegative();
    void slotInternalStop();



private:
    KFHMIStepNavigator m_navigator;

    std::unique_ptr<QVBoxLayout> m_pRootLayout;
    std::unique_ptr<QHBoxLayout> m_pButtonLayout;
};

#endif // GUI_CRING_OPERATIONS_BUTTON_GROUP_H
