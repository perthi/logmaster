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
#include <QtCore/QThread>
#include <QtWidgets/QMainWindow>


#include <logging/LMessage.h>
#include <gui/common/GUILoggerBase.h>
#include <logging/LLogging.h>
#include <logging/LPublisher.h>

class   QTimer;

using namespace LOGMASTER;


// typedef  QMap<int, LMessage> MsgSeries;

 class GUILogger : public QObject, public GUILoggerBase
//class GUILogger : public GUILoggerBase, public QMainWindow
   {
      Q_OBJECT

   public:
	   explicit API GUILogger(QWidget* parent = 0);
	   ~GUILogger();
	   //static API GUILogger*  Instance();
	   void StartTimer();

   public slots:
	  virtual void newMessage(int cnt, const LMessage &msg) override;
	//  void timerEvent(QTimerEvent* event);

   signals:
	  virtual void newMessages(const MsgSeries &msgs) override;

   private: // functions
	 
	   GUILogger(const GUILogger &rhs);
	   GUILogger& operator=(const GUILogger &rhs);
//	   QThread workerThread;
	 //  void  logger_callback(const std::shared_ptr<LMessage>  m);
	   
	   virtual void timerEvent(QTimerEvent *event) override;

	 //  QTimer* timer;

   };


#endif