
#pragma once

#include <utilities/GDefinitions.h>
#include <QtCore/QMutex>
#include <QtCore/QMap>
#include <logging/LMessage.h>
using namespace LOGMASTER;

//typedef  QMap<int, LMessage> MsgSeries;
typedef  std::map<int, LMessage> MsgSeries;

#include<vector>
using std::vector;
#include <memory>

#include <map>

class GUILoggerBase
{

public:


    MsgSeries    API  AllMsgs();
    void         API  ClearMsgs();

public :
    virtual  void  API  newMessage(int cnt, const LMessage& msg);
    virtual  void  API  newMessages(const MsgSeries& msgs);
    //virtual  void  API  newMessage(int cnt, const LMessage& msg) = 0;
    //virtual  void  API  newMessages(const MsgSeries& msgs) = 0;

   // void API SetLoggedMessage(MsgSeries msg);
   // void API SetNewMessage(MsgSeries msg);


    static MsgSeries API  GetLoggedMessages();
    static MsgSeries API  GetNewMessages();
    static std::map< int, LMessage> API   GetMap();

//protected:
public:
    explicit API  GUILoggerBase();
    virtual  API ~GUILoggerBase() {};
    GUILoggerBase(const GUILoggerBase& rhs);
    GUILoggerBase& operator=(const GUILoggerBase& rhs);
    void     API  PurgeMessages();

    mutable QMutex fMutex{};
    
public:
    
    
   // static QMap<int, LMessage> fLoggedMessages2;
  //  static QMap<int, LMessage> fNewMessages2;
    
    static MsgSeries fLoggedMessages2;
    static MsgSeries fNewMessages2;
    static MsgSeries fMap ;

    const int fMaxMessagesInMemory = 2000;
};

