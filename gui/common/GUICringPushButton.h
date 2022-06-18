// GUICringPushButton.h
// karl eirik bang fossberg

#ifndef GUI_CRING_PUSHBUTTON_H
#define GUI_CRING_PUSHBUTTON_H

#include <QtWidgets/QPushButton>

class GUICringPushButton : public QPushButton
{
    Q_OBJECT

public:
    GUICringPushButton(int index);
    ~GUICringPushButton();

signals:
    void signalButtonPushed(int index);

private:
    int m_index;

private slots:
    void RedirectSignal();
};

#endif // GUI_C_RING_PUSHBUTTON_H
