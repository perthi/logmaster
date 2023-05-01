
#pragma once

#include <utilities/GDefinitions.h>
#include <QtCore/QObject>
#include <gui/common/GUILoggerBase.h>
#include <logging/LMessage.h>

using namespace LOGMASTER;


/*
class GUIAlarm : public QObject, public GUILoggerBase
{
	Q_OBJECT

public:
	//static GUIAlarm* Instance();
	explicit API  GUIAlarm();
	API ~GUIAlarm() {};

	void API StartTimer();

	
public slots:
	virtual  void   __declspec(dllexport) newMessage(int cnt, const LMessage& msg) override;

signals:
	virtual void   __declspec(dllexport) newMessages(const MsgSeries& msgs) override;


private: // functions
	
	GUIAlarm(const GUIAlarm& rhs);
    GUIAlarm& operator=(const GUIAlarm& rhs);
	void API timerEvent(QTimerEvent* event);

	// static QMap<int, LMessage> fLoggedMessages;
	//static QMap<int, LMessage> fNewMessages;
};
*/



