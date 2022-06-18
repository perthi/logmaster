
#pragma once

#include <utilities/GDefinitions.h>
#include <QtWidgets/QWidget>
#include <QtCore/QObject>
#include <QtCore/QMutex>
#include <QtCore/QMultiMap>
#include <gui/common/GUILoggerBase.h>
#include <logging/LMessage.h>

using namespace LOGMASTER;

class GUIAlarm : public QObject, public GUILoggerBase
{
	Q_OBJECT

public:
	static GUIAlarm* Instance();

public slots:
	virtual  void newMessage(int cnt, const LMessage& msg) override;

signals:
	virtual void newMessages(const MsgSeries& msgs) override;

private: // functions
	explicit GUIAlarm();
	~GUIAlarm() {};
	GUIAlarm(const GUIAlarm& rhs);
	GUIAlarm& operator=(const GUIAlarm& rhs);
	void timerEvent(QTimerEvent* event);
};



