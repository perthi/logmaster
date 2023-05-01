

#include "GUILoggerBase.h"

std::map<int, LMessage>  GUILoggerBase::fLoggedMessages2;
std::map<int, LMessage>  GUILoggerBase::fNewMessages2;


std::map<int, LMessage>   GUILoggerBase::fMap;

#include <utilities/GDefinitions.h>

#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <logging/LLogging.h>

using namespace LOGMASTER;


/*
void 
GUILoggerBase::SetLoggedMessage(MsgSeries msg)
{

	fLoggedMessages2 = msg;


}


void 
GUILoggerBase::SetNewMessage(MsgSeries msg)
{
	fNewMessages2 = msg;
}
*/



void 
GUILoggerBase::PurgeMessages()
{
//	COUT << "Purging messages, size =  " << std::dec << fNewMessages2.size()  << "  addr = " << std::hex << &fNewMessages2 << endl;
	
	QMutexLocker locker(&fMutex);
	if (fNewMessages2.size() == 0)
	{
		return;
	}
	
	
	emit newMessages(fNewMessages2);
	
	// fLoggedMessages  += fNewMessages;
	// fLoggedMessages.insert(fLoggedMessages.end(), );

	//auto it = fNewMessages.begin();

	/*
	for (auto it = fNewMessages2.begin();  it != fNewMessages2.end(); it++)
	{
		fLoggedMessages2.insert(it.key(), it.value());
	}
	*/

	/*
	fNewMessages2.clear();
	while (fLoggedMessages2.count() > fMaxMessagesInMemory)
	{
		fLoggedMessages2.erase(fLoggedMessages2.begin());
	}
	*/
	
}

std::map< int, LMessage> API   
GUILoggerBase::GetMap()
{
	return fMap;
}

MsgSeries 
GUILoggerBase::GetLoggedMessages() 
{ 
	//QMutexLocker locker(&fMutex);
	//COUT << "size = " << fLoggedMessages2.size() << endl;
	return fLoggedMessages2; 
};


MsgSeries 
GUILoggerBase::GetNewMessages() 
{ 
	for (auto m : fNewMessages2)
	{
		COUT << "RGBMAP = 0X" << std::hex << m.second.fRgBColor << endl;
	}
	
	//	QMutexLocker locker(&fMutex);
	//COUT << "size = " << fNewMessages2.size() << endl;
	return fNewMessages2; 
};


GUILoggerBase::GUILoggerBase()
{
	// fLoggedMessages2 = QMap<int, LMessage>();
	// fNewMessages2 = QMap<int, LMessage>();;

}

void   
GUILoggerBase::newMessages(const MsgSeries& msgs)
{
	COUT << "TP0" << endl;
}


void
GUILoggerBase::newMessage(int cnt, const LMessage& msg)
{
	QMutexLocker locker(&fMutex);

//	COUT << "New message: cnt =  "<< std::dec << cnt  << endl;
	
	
	LMessage newmsg = msg;

//	COUT << "RGB COLOR =  0X" << std::hex << msg.fRgBColor << endl;
//	COUT << "RGB COLOR =  0X" << std::hex << newmsg.fRgBColor << endl;

	fNewMessages2.emplace(cnt, newmsg);
	
	for (auto m : fNewMessages2)
	{
		// COUT << "RGB MAP = 0x" << std::hex << m.second.fRgBColor << endl;
	}

	
	fMap.emplace(cnt, newmsg);
//	COUT << "New messages size = " << std::dec << fNewMessages2.size() << "  addr = "<< std::hex << &fNewMessages2 << endl;
	
}


MsgSeries
GUILoggerBase::AllMsgs()
{
	// COUT << "New messages size = " << fNewMessages2.size() << endl;
	// COUT << "Logged messages size = " << fLoggedMessages2.size() << endl;

	// fNewMessages.begin();
	// fLoggedMessages.begin();

	if (fNewMessages2.size() > 0)
	{
		for (auto it = fNewMessages2.begin(); it != fNewMessages2.end(); it++)
		{
			fLoggedMessages2.emplace(it->first, it->second);
		}
	}
	
	MsgSeries tmp;
	return tmp;
//	return fLoggedMessages;
}


void
GUILoggerBase::ClearMsgs()
{
	//COUT << "TP0" << endl;
	QMutexLocker locker(&fMutex);
//	fLoggedMessages.clear();
}