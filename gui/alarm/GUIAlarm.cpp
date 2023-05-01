

#include "GUIAlarm.h"






//QMap<int, LMessage>    GUIAlarm::fLoggedMessages;
//QMap<int, LMessage>    GUIAlarm::fNewMessages;


/*
GUIAlarm::GUIAlarm()
    : GUILoggerBase()
{
    qRegisterMetaType<MsgSeries>("MsgSeries");
   // this->startTimer(1000);
}


void  
GUIAlarm::StartTimer()
{
	this->startTimer(1000);
}


void
GUIAlarm::timerEvent(QTimerEvent*)
{
   // PurgeMessages();
	COUT << "Purging messages, size =  " << std::dec << fNewMessages2.size() << "  addr = " << std::hex << &fNewMessages2 << endl;

	QMutexLocker locker(&fMutex);
	if (fNewMessages2.size() == 0)
	{
		return;
	}

	COUT << "Emitting new messages !!!!!!" << endl;
	emit newMessages(fNewMessages2);
	COUT << "DONE" << endl;
}



void
GUIAlarm::newMessage(int cnt, const LMessage& msg)
{
	COUT << "NEW Message XXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	GUILoggerBase::newMessage(cnt, msg);
}
*/