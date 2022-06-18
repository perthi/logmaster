// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUIAlarmGui
///  @brief     Logger GUI for the main window

#pragma once

#include <common/FDefinitions.h>

#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <gui/alarm/GUIAlarm.h>

class GUIAlarmGui : public QWidget
   {
      Q_OBJECT

   public:
      explicit API GUIAlarmGui(QWidget *parent = 0);
      API ~GUIAlarmGui();

   signals:

   private slots :
      void NewMessages(const MsgSeries &msgs);
      void GetAllMessages();
   //   void OpenLogMasterDialog();

   private: // functions
      void InitGui();
      void ConnectStuff();
      void RetranslateUi();
      QWidget* InitRight();

   private: // member objects
      QLabel *fPlainTextEditLabel;
      QPlainTextEdit *fPlainTextEdit;
      QPushButton* fConfigureButton;
      QWidget* fLogMasterGuiDialog = nullptr;
      QString fTEXT_messages;
   };


