// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUIAlarmGui
///  @brief     Logger GUI for the main window

#pragma once

#include <gui/common/GUIDefenitions.h>
#include <QtWidgets/QWidget>
#include <logging/LMessage.h>

using namespace LOGMASTER;

class QLabel;
class QPlainTextEdit;

class GUIAlarmGui : public QWidget
   {
   public:
      explicit API GUIAlarmGui(QWidget* parent = 0);
      API ~GUIAlarmGui();
      void API StartTimer();

   public:
      void  API  NewMessage(int cnt, const LMessage& msg);
      void       NewMessages( MsgSeries  &msgs);

   private: 
      GUIAlarmGui(const GUIAlarmGui&);
      GUIAlarmGui  operator=(const GUIAlarmGui&);
      void  InitGui();
      void  RetranslateUi();
      QWidget*  InitRight();
      void   timerEvent(QTimerEvent* event);

      static MsgSeries fLoggedMessages;
      static MsgSeries fNewMessages;
      QLabel *fPlainTextEditLabel = nullptr;
      QPlainTextEdit *fPlainTextEdit = nullptr;
   };


