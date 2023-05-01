

#include "GUILoggerBase.h"

QMap<int, LMessage>  GUILoggerBase::fLoggedMessages2 = QMap<int, LMessage>();
QMap<int, LMessage>  GUILoggerBase::fNewMessages2;

#include <utilities/GDefinitions.h>

#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <logging/LLogging.h>

using namespace LOGMASTER;



void 
GUILoggerBase::PurgeMessages()
{
	COUT << "Purging messages, size =  " << std::dec << fNewMessages2.size()  << "  addr = " << std::hex << &fNewMessages2 << endl;
	
	//QMutexLocker locker(&fMutex);
	if (fNewMessages2.size() == 0)
	{
		return;
	}
	emit newMessages(fNewMessages2);
	
	// fLoggedMessages  += fNewMessages;
	// fLoggedMessages.insert(fLoggedMessages.end(), );

	//auto it = fNewMessages.begin();
	for (auto it = fNewMessages2.begin();  it != fNewMessages2.end(); it++)
	{
		fLoggedMessages2.insert(it.key(), it.value());
	}

	fNewMessages2.clear();
	while (fLoggedMessages2.count() > fMaxMessagesInMemory)
	{
		fLoggedMessages2.erase(fLoggedMessages2.begin());
	}
	
}

MsgSeries *
GUILoggerBase::GetLoggedMessages() { return &fLoggedMessages2; };

MsgSeries *
GUILoggerBase::GetNewMessages() { return &fNewMessages2; };

void
GUILoggerBase::newMessage(int cnt, const LMessage& msg)
{
	
	COUT << "New message: cnt =  "<< std::dec << cnt  << endl;
	QMutexLocker locker(&fMutex);
	LMessage newmsg = msg;
	fNewMessages2.insert(cnt, newmsg);
	COUT << "New messages size = " << std::dec << fNewMessages2.size() << "  addr = "<< std::hex << &fNewMessages2 << endl;
	
}


MsgSeries
GUILoggerBase::AllMsgs()
{
	COUT << "New messages size = " << fNewMessages2.size() << endl;
	COUT << "Logged messages size = " << fLoggedMessages2.size() << endl;

	// fNewMessages.begin();
	// fLoggedMessages.begin();

	if (fNewMessages2.size() > 0)
	{
		for (auto it = fNewMessages2.begin(); it != fNewMessages2.end(); it++)
		{
			fLoggedMessages2.insert(it.key(), it.value());
		}
	}
	
	MsgSeries tmp;
	return tmp;
//	return fLoggedMessages;
}


void
GUILoggerBase::ClearMsgs()
{
	COUT << "TP0" << endl;
	QMutexLocker locker(&fMutex);
//	fLoggedMessages.clear();
}