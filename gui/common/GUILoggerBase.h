
#pragma once

#include <utilities/GDefinitions.h>
#include <QtCore/QMutex>
#include <QtCore/QMap>
#include <logging/LMessage.h>
using namespace LOGMASTER;
typedef  QMap<int, LMessage> MsgSeries;

#include<vector>
using std::vector;
#include <memory>

class GUILoggerBase
{

public:
    MsgSeries    API   AllMsgs();
    void        API    ClearMsgs();

public :
    virtual  void    API  newMessage(int cnt, const LMessage& msg) = 0;
    virtual  void    API  newMessages(const MsgSeries& msgs) = 0;

protected:
    explicit  API  GUILoggerBase() {};
    virtual  API   ~GUILoggerBase() {};
    GUILoggerBase(const GUILoggerBase& rhs);
    GUILoggerBase& operator=(const GUILoggerBase& rhs);
    void  API  PurgeMessages();

    mutable QMutex fMutex{};
    QMap<int, LMessage> fLoggedMessages;
    QMap<int, LMessage> fNewMessages;
    const int fMaxMessagesInMemory = 2000;
};

