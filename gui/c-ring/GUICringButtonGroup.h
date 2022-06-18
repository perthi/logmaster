// GUICringButtonGroup.h
// karl eirik bang fossberg

#ifndef GUI_CRING_BUTTONGROUP_H
#define GUI_CRING_BUTTONGROUP_H

#include <gui/common/GUICringPushButton.h>


#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QWidget>
#include <iostream>
#include <vector>

class GUICringButtonGroup : public QWidget
{
    Q_OBJECT

public:
    GUICringButtonGroup(QBoxLayout::Direction direction,
        std::vector<int> &indices,
        QWidget *pParent = nullptr);
    ~GUICringButtonGroup();

signals:
    void signalRelative(int direction, double value);
    void signalContinous(int direction);

private slots:
    void slotHandleButtonPush(int index);
    void slotHandleContinous();

private:
    QChar SetText();

private:
    bool m_negated;
    std::vector<int> m_indices;
    QBoxLayout::Direction m_direction;
    QBoxLayout *m_pLayout;
};

#endif // GUI_CRING_BUTTONGROUP_H