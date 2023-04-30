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
	//:QObject(0)
{
	qRegisterMetaType<MsgSeries>("MsgSeries");
	//this->startTimer(1000);
	// InitTimer();
	
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


/*
void 
GUILogger::InitTimer()
{
	this->moveToThread(&workerThread);

	auto timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	workerThread.start();
	timer->setInterval(1000);
	timer->start();
}
*/


void 
GUILogger::timerEvent(QTimerEvent *)
//GUILogger::timerEvent( )
{
	COUT << "TP0, new nessages size = " << fNewMessages.size()  << endl;
   // QMutexLocker locker(&fMutex);
	if (fNewMessages.size() == 0)
	{
		return;
	}
	
	COUT << "TP1" << endl;
	emit newMessages(fNewMessages);
	//fLoggedMessages += fNewMessages;
	
	for (auto it = fNewMessages.begin(); it != fNewMessages.end(); it++)
	{
		fLoggedMessages.insert(it.key(), it.value() );
	}
	
	fNewMessages.clear();
	while (fLoggedMessages.count() > fMaxMessagesInMemory)
	{
		fLoggedMessages.erase(fLoggedMessages.begin());
	}
}

GUILogger::~GUILogger()
{
	//delete fInstance;
	//fInstance = 0;
}


/*
GUILogger* 
GUILogger::Instance()
{
	static GUILogger* instance = new  GUILogger();
	return instance;
}
*/

void 
GUILogger::newMessage(int cnt, const LMessage &msg)
{
	COUT << "TP0" << endl;
	GUILoggerBase::newMessage(cnt, msg);
}

