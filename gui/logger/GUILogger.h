// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUILogger
///  @brief     Class to handle registering subscriber to logging system and keep a buffer of messages


#ifndef _GUILOGGER_H_
#define _GUILOGGER_H_

#include <QtCore/QObject>
#include <QtCore/QMutex>
#include <QtCore/QMultiMap>

#include <logging/LMessage.h>


#include <gui/common/GUILoggerBase.h>


using namespace LOGMASTER;

   typedef  QMap<int, LMessage> MsgSeries;

   class GUILogger : public QObject, public GUILoggerBase
   {
      Q_OBJECT

   public:
	  // GUILogger();
	  // ~GUILogger();

	   static API GUILogger*  Instance();
    
	 // ~GUILogger();
      
   public slots:
	  virtual void newMessage(int cnt, const LMessage &msg) override;

   signals:
	  virtual void newMessages(const MsgSeries &msgs) override;

   private: // functions
	     GUILogger();
	     ~GUILogger();
	   GUILogger(const GUILogger &rhs);
	   GUILogger& operator=(const GUILogger &rhs);
	   void timerEvent(QTimerEvent *event);

   };


#endif