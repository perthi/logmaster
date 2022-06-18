// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <logging/LLogging.h>

#include "GUILogger.h"

using namespace LOGMASTER;


void  logger_callback(const std::shared_ptr<LMessage>  m)
{
	static int cnt = 0;
	GUILogger::GetInstance()->newMessage(cnt, *m);
	cnt++;
}


GUILogger::GUILogger()
	:QObject(0)
{
	qRegisterMetaType<MsgSeries>("MsgSeries");
	this->startTimer(1000);
	LLogging::Instance()->RegisterGuiSubscriber(  logger_callback );
}

void 
GUILogger::timerEvent(QTimerEvent *)
{
    QMutexLocker locker(&fMutex);
	if (fNewMessages.size() == 0)
	{
		return;
	}
	emit newMessages(fNewMessages);
	fLoggedMessages += fNewMessages;
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


GUILogger* 
GUILogger::GetInstance()
{
	static GUILogger* instance = new  GUILogger();
	return instance;
}


void 
GUILogger::newMessage(int cnt, const LMessage &msg)
{
	GUILoggerBase::newMessage(cnt, msg);
}

