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
//#include <QtCore/QMutex>
//#include <QtCore/QMultiMap>
//#include <QtCore/QThread>
//#include <QtWidgets/QMainWindow>


#include <logging/LMessage.h>
#include <gui/common/GUILoggerBase.h>
#include <logging/LLogging.h>
#include <logging/LPublisher.h>

//class   QTimer;

using namespace LOGMASTER;


 class GUILogger : public QObject, public GUILoggerBase
   {
  //    Q_OBJECT

   public:
	   explicit API GUILogger(QWidget* parent = 0);
	   ~GUILogger() = default;
	   virtual void newMessage(int cnt, const LMessage &msg);

   private: // functions
	 
	   GUILogger(const GUILogger &rhs);
	   GUILogger& operator=(const GUILogger &rhs);
   };


#endif