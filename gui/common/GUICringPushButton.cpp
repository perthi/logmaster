// GUICringPushButton.cpp
// karl eirik bang fossberg

#include "GUICringPushButton.h"

GUICringPushButton::GUICringPushButton(int index)
    : QPushButton()
    , m_index(index)
{
    connect(this, &GUICringPushButton::released, this, &GUICringPushButton::RedirectSignal);
    setText(QString::number(index));
}

GUICringPushButton ::~GUICringPushButton()
{
    //
}

void
GUICringPushButton::RedirectSignal()
{
    emit signalButtonPushed(m_index);
}
