

#include "GUIAlarm.h"




GUIAlarm::GUIAlarm()
    : GUILoggerBase()
{
    qRegisterMetaType<MsgSeries>("MsgSeries");
    this->startTimer(1000);
}


void
GUIAlarm::timerEvent(QTimerEvent*)
{
    PurgeMessages();
}



void
GUIAlarm::newMessage(int cnt, const LMessage& msg)
{
    GUILoggerBase::newMessage(cnt, msg);
}
