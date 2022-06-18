// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUILoggerGui
///  @brief     Logger GUI for the main window


#ifndef _LOGGET_GUI_H_
#define _LOGGET_GUI_H_


#include <common/FDefinitions.h>

#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "GUILogger.h"

class GUILoggerGui : public QWidget
   {
      Q_OBJECT

   public:
      explicit API GUILoggerGui(QWidget *parent = 0);
      API ~GUILoggerGui();

   signals:

   private slots :
      void NewMessages(const MsgSeries &msgs);
      void GetAllMessages();
      void RegExpUpdated();
      void RegExpSyntaxUpdated();
      void OpenLogMasterDialog();
      void ClearLog();
      void Pause();

   private: // functions
      void InitGui();
      void ConnectStuff();
      void RetranslateUi();
      QWidget* InitLeft();
      QWidget* InitRight();

   private: // member objects
      QLabel *fPlainTextEditLabel;
      QPlainTextEdit *fPlainTextEdit;

      QLabel *fLogLevelLabel;
      QComboBox *fLogLevelCombo;

      QLabel *fSubSystemLabel;
      QMap<eMSGSYSTEM, QCheckBox*> fCheckBoxes;
      QCheckBox *fChecFSM;
      QCheckBox *fCheckDriver;
      QCheckBox *fCheckDatabase;
      QCheckBox *fCheckQa;
      QCheckBox *fCheckUser;
      QCheckBox *fCheckEx;

      QLabel* fRegExpLabel;
      QComboBox *fRegExpCombo;
      QLineEdit* fRegExpEdit;
      QRegExp fRegExp;

      QPushButton* fConfigureButton;
      QPushButton* fClearButton;
      QPushButton* fRefreshButton;
      QPushButton* fPauseButton;

      QWidget* fLogMasterGuiDialog = nullptr;

      QString fTEXT_messages;
      QString fTEXT_logLevel;
      QString fTEXT_subSystems;
      QString fTEXT_regExp;
      QString fTEXT_configure;
      QString fTEXT_clear;
      QString fTEXT_refresh;
      QString fTEXT_pause;
      QString fTEXT_unpause;
   };


#endif
