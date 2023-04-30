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
#include <QtCore5compat/QRegExp>
#include "GUILogger.h"


class GUILogger;

class GUILoggerGui : public QWidget
   {
      Q_OBJECT

   public:
      explicit API GUILoggerGui(GUILogger *logger,  QWidget *parent = 0);
      API ~GUILoggerGui();
      API void StartTimer();

   signals:

   private slots :
      void NewMessages(const MsgSeries &msgs);
      void GetAllMessages();
      void RegExpUpdated();
      void RegExpSyntaxUpdated();
      void OpenLogMasterDialog();
      void ClearLog();
      void Pause();

   private: 
      void InitGui();
      void ConnectStuff();
      void RetranslateUi();
      QWidget* InitLeft();
      QWidget* InitRight();

   private:
      GUILoggerGui operator=(const GUILoggerGui&);
      GUILoggerGui(const GUILoggerGui&);
      
      GUILogger *fLogger = nullptr;

      QLabel *fPlainTextEditLabel = nullptr;
      QPlainTextEdit *fPlainTextEdit = nullptr;

      QLabel *fLogLevelLabel = nullptr;
      QComboBox *fLogLevelCombo = nullptr;

      QLabel *fSubSystemLabel = nullptr;
      QMap<eMSGSYSTEM, QCheckBox*> fCheckBoxes{};
      QCheckBox *fChecFSM = nullptr;
      QCheckBox *fCheckDriver = nullptr;
      QCheckBox *fCheckDatabase = nullptr;
      QCheckBox *fCheckQa = nullptr;
      QCheckBox *fCheckUser = nullptr;
      QCheckBox *fCheckEx = nullptr;

      QLabel* fRegExpLabel = nullptr;
      QComboBox *fRegExpCombo = nullptr;
      QLineEdit* fRegExpEdit = nullptr;
      QRegExp fRegExp{};

      QPushButton* fConfigureButton = nullptr;
      QPushButton* fClearButton = nullptr;
      QPushButton* fRefreshButton = nullptr;
      QPushButton* fPauseButton = nullptr;

      QWidget* fLogMasterGuiDialog = nullptr;

      QString fTEXT_messages{};
      QString fTEXT_logLevel{};
      QString fTEXT_subSystems{};
      QString fTEXT_regExp{};
      QString fTEXT_configure{};
      QString fTEXT_clear{};
      QString fTEXT_refresh{};
      QString fTEXT_pause{};
      QString fTEXT_unpause{};
   };


#endif
