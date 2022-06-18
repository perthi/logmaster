

#include "GUILoggerBase.h"
#include <utilities/GDefinitions.h>

#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <logging/LLogging.h>

using namespace LOGMASTER;


void 
GUILoggerBase::PurgeMessages()
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



void
GUILoggerBase::newMessage(int cnt, const LMessage& msg)
{
	QMutexLocker locker(&fMutex);
	LMessage newmsg = msg;
	fNewMessages.insert(cnt, newmsg);
}


MsgSeries
GUILoggerBase::AllMsgs() const
{
	return(fLoggedMessages + fNewMessages);
}


void
GUILoggerBase::ClearMsgs()
{
	QMutexLocker locker(&fMutex);
	fLoggedMessages.clear();
}