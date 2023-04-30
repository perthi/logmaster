

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
	
	// fLoggedMessages  += fNewMessages;
	// fLoggedMessages.insert(fLoggedMessages.end(), );

	//auto it = fNewMessages.begin();
	for (auto it = fNewMessages.begin();  it != fNewMessages.end(); it++)
	{
		fLoggedMessages.insert(it.key(), it.value());
	}

	fNewMessages.clear();
	while (fLoggedMessages.count() > fMaxMessagesInMemory)
	{
		fLoggedMessages.erase(fLoggedMessages.begin());
	}
}


void
GUILoggerBase::newMessage(int cnt, const LMessage& msg)
{
	COUT << "New message: cnt =  " << cnt  << endl;
	QMutexLocker locker(&fMutex);
	LMessage newmsg = msg;
	fNewMessages.insert(cnt, newmsg);
}


MsgSeries
GUILoggerBase::AllMsgs()
{
	COUT << "New messages size = " << fNewMessages.size() << endl;
	COUT << "Logged messages size = " << fLoggedMessages.size() << endl;

	// fNewMessages.begin();
	// fLoggedMessages.begin();

	if (fNewMessages.size() > 0)
	{
		for (auto it = fNewMessages.begin(); it != fNewMessages.end(); it++)
		{
			fLoggedMessages.insert(it.key(), it.value());
		}
	}
	

	return fLoggedMessages;
}


void
GUILoggerBase::ClearMsgs()
{
	COUT << "TP0" << endl;
	QMutexLocker locker(&fMutex);
	fLoggedMessages.clear();
}