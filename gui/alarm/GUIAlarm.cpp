

#include "GUIAlarm.h"
#include <utilities/GDefinitions.h>
#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <logging/LLogging.h>
#include "GUIAlarm.h"

using namespace LOGMASTER;

void alarm_subscriber(const std::shared_ptr<LMessage>  m)
{
    static int cnt = 0;
    GUIAlarm::Instance()->newMessage(cnt, *m);
    cnt++;
}


GUIAlarm::GUIAlarm()
    : GUILoggerBase() 
{
    qRegisterMetaType<MsgSeries>("MsgSeries");
    this->startTimer(1000);
    LLogging::Instance()->RegisterGuiSubscriber(alarm_subscriber);
}


GUIAlarm*
GUIAlarm::Instance()
{
    static GUIAlarm *instance = new GUIAlarm();
    return  instance;
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

