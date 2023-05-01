// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUIAlarmGui
///  @brief     Logger GUI for the main window

#pragma once

//#include <common/FDefinitions.h>

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtWidgets/QWidget>
#include <logging/LMessage.h>

using namespace LOGMASTER;
//#include <gui/alarm/GUIAlarm.h>

//class GUIAlarm;
class QLabel;
class QPlainTextEdit;
class QPushButton;
class QWidget;
//QString fTEXT_messages{};

class GUIAlarmGui : public QWidget
   {
      Q_OBJECT

   public:
     // explicit API GUIAlarmGui(GUIAlarm *alarm, QWidget *parent = 0);
      explicit API GUIAlarmGui(QWidget* parent = 0);

      API ~GUIAlarmGui();
      void API StartTimer();

   signals:

   public slots :
    // void NewMessages(MsgSeries *msgs);
       virtual  void   __declspec(dllexport) NewMessage(int cnt, const LMessage& msg);

  // signals:
      void   __declspec(dllexport)  NewMessages2( const QMap<int, LMessage>  &msgs);
    // void NewMessages(const MsgSeries& msgs);
      void   __declspec(dllexport) GetAllMessages();
   //   void OpenLogMasterDialog();

   private: // functions
      GUIAlarmGui(const GUIAlarmGui&);
     GUIAlarmGui  operator=(const GUIAlarmGui&);

      void  InitGui();
      void  ConnectStuff();
      void  RetranslateUi();
      QWidget*  InitRight();

   private: // member objects
      void API timerEvent(QTimerEvent* event);

      static QMap<int, LMessage> fLoggedMessages;
      static QMap<int, LMessage> fNewMessages;
    //  GUIAlarm* fAlarm = nullptr;
      QLabel *fPlainTextEditLabel = nullptr;
      QPlainTextEdit *fPlainTextEdit = nullptr;
      QPushButton* fConfigureButton = nullptr;
      QWidget* fLogMasterGuiDialog = nullptr;
      QString fTEXT_messages{};
   };


