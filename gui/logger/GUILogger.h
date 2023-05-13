// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUILogger
///  @brief     Class to handle registering subscriber to logging system and keep a buffer of messages


#ifndef _GUILOGGER_H_
#define _GUILOGGER_H_

#include <logging/LMessage.h>

using namespace LOGMASTER;

 class GUILogger 
   {
   public:
	   explicit API GUILogger();
	   virtual ~GUILogger() = default;
	   virtual void newMessage(int cnt, const LMessage &msg);

   private: // functions
	   GUILogger(const GUILogger &rhs);
	   GUILogger& operator=(const GUILogger &rhs);
   };


#endif