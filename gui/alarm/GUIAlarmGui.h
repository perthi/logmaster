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

class GUIAlarm;
class QLabel;
class QPlainTextEdit;
class QPushButton;
class QWidget;
//QString fTEXT_messages{};

class GUIAlarmGui : public QWidget
   {
      Q_OBJECT

   public:
      explicit API GUIAlarmGui(GUIAlarm *alarm, QWidget *parent = 0);
      API ~GUIAlarmGui();

   signals:

   private slots :
    // void NewMessages(MsgSeries *msgs);
      void NewMessages( const QMap<int, LMessage>  &msgs);
    // void NewMessages(const MsgSeries& msgs);
      void GetAllMessages();
   //   void OpenLogMasterDialog();

   private: // functions
      GUIAlarmGui(const GUIAlarmGui&);
     GUIAlarmGui  operator=(const GUIAlarmGui&);

      void  InitGui();
      void  ConnectStuff();
      void  RetranslateUi();
      QWidget*  InitRight();

   private: // member objects
      GUIAlarm* fAlarm = nullptr;
      QLabel *fPlainTextEditLabel = nullptr;
      QPlainTextEdit *fPlainTextEdit = nullptr;
      QPushButton* fConfigureButton = nullptr;
      QWidget* fLogMasterGuiDialog = nullptr;
      QString fTEXT_messages{};
   };


