
#pragma once

#include <utilities/GDefinitions.h>
#include <QtWidgets/QWidget>

#include <QtCore/QObject>
#include <QtCore/QMutex>
#include <QtCore/QMultiMap>
#include <logging/LMessage.h>
using namespace LOGMASTER;
// typedef  QMultiMap<int, LMessage> MsgSeries;
typedef  QMap<int, LMessage> MsgSeries;

class GUILoggerBase
{

public:
//  static GUILoggerBase  * Instance();
    MsgSeries  API   AllMsgs();
    void       API   ClearMsgs();

public :
    virtual  void   API newMessage(int cnt, const LMessage& msg) = 0;
    virtual  void   API newMessages(const MsgSeries& msgs) = 0;

protected:
    explicit API  GUILoggerBase() {};
    API  ~GUILoggerBase() {};
    GUILoggerBase(const GUILoggerBase& rhs);
    GUILoggerBase& operator=(const GUILoggerBase& rhs);
    virtual void timerEvent(QTimerEvent* event) = 0;
    
    void API PurgeMessages();

    mutable QMutex fMutex{};
  
    // MsgSeries fLoggedMessages{};
    // MsgSeries fNewMessages{};
    
  //  QMultiMap<int, LMessage> fLoggedMessages;
  //  QMultiMap<int, LMessage> fNewMessages;

    QMap<int, LMessage> fLoggedMessages;
    QMap<int, LMessage> fNewMessages;

    const int fMaxMessagesInMemory = 2000;

};



