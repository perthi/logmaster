// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUIAlarmGui
///  @brief     Logger GUI for the main window

#pragma once

#include <QtCore/QMap>
#include <QtWidgets/QWidget>
#include <logging/LMessage.h>

using namespace LOGMASTER;

#include <memory>

class QLabel;
class QPlainTextEdit;
class QPushButton;
class QWidget;

class GUIAlarmGui : public QWidget
   {
   public:
      explicit API GUIAlarmGui(QWidget* parent = 0);
      API ~GUIAlarmGui();
      void API StartTimer();

   public:
      void  API  NewMessage(int cnt, const LMessage& msg);
      void       NewMessages( const QMap<int, LMessage>  &msgs);

   private: 
      GUIAlarmGui(const GUIAlarmGui&);
      GUIAlarmGui  operator=(const GUIAlarmGui&);
      void  InitGui();
      void  RetranslateUi();
      QWidget*  InitRight();

   private:
      void   timerEvent(QTimerEvent* event);
      static QMap<int, LMessage> fLoggedMessages;
      static QMap<int, LMessage> fNewMessages;
      QLabel *fPlainTextEditLabel = nullptr;
      QPlainTextEdit *fPlainTextEdit = nullptr;
   };


