// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <QtCore/QTimer>


#include <logging/LLogging.h>
#include <logging/LPublisher.h>

#include "GUILogger.h"


using namespace LOGMASTER;

GUILogger *gui_instance =  new GUILogger(0);

void  logger_callback(const std::shared_ptr<LMessage>  m)
{
	static int cnt = 0;
	COUT << "GOT NEW MESSAGE, cnt = " << cnt << endl;
//	GUILogger::Instance()->newMessage(cnt, *m);
	gui_instance->newMessage(cnt, *m);
	cnt++;
}


GUILogger::GUILogger(QWidget* )
{
	qRegisterMetaType<MsgSeries>("MsgSeries");
	COUT << "Registring subscirber" << endl;
	LLogging::Instance()->RegisterGuiSubscriber(  logger_callback );
	auto subscribers = LLogging::Instance()->GetGuiSubscribers();
	COUT << "Subscribers size = " << subscribers.size() << "\t addr = " << std::hex << &subscribers << endl;;
	COUT << "Address = 0x" << std::hex << LLogging::Instance();
}


void 
GUILogger::StartTimer()
{
	this->startTimer(1000);
}



void 
GUILogger::timerEvent(QTimerEvent *)
//GUILogger::timerEvent( )
{
	MsgSeries * logged_messages = GetLoggedMessages();
	MsgSeries * new_messages  = GetNewMessages();


	FORCE_DEBUG("TP0, new nessages size = %d", new_messages->size());
   
	// QMutexLocker locker(&fMutex);
	if (new_messages->size() == 0)
	{
		return;
	}
	
	COUT << "TP1" << endl;
	emit newMessages(*new_messages);
	//fLoggedMessages += fNewMessages;
	
	for (auto it = new_messages->begin(); it != new_messages->end(); it++)
	{
		logged_messages->insert(it.key(), it.value() );
	}
	
	new_messages->clear();
	while (logged_messages->count() > fMaxMessagesInMemory)
	{
		logged_messages->erase(logged_messages->begin());
	}
	
}

GUILogger::~GUILogger()
{
	//delete fInstance;
	//fInstance = 0;
}


void 
GUILogger::newMessage(int cnt, const LMessage &msg)
{
	COUT << "TP0" << endl;
	GUILoggerBase::newMessage(cnt, msg);
}

