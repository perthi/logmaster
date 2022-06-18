

#ifndef _SETTINGS_DIALOG_H_
#define _SETTINGS_DIALOG_H_


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <common/FDefinitions.h>
#include <QtWidgets/QDialog>
#include <QtCore/QMap>


class QToolButton;
class QStackedWidget;
class QListWidget;
//class QMap;
class QStatusBar;

   enum SettingChoice 
   {
      UnknownChoice = -1,
      Style = 0,
      Language = 1,
   };

/**  @brief     Dialog class to contain settings for the main app */
   class GUISettingsDialog : public QDialog
   {
      Q_OBJECT

   public:
      explicit API GUISettingsDialog(QWidget *parent = 0);
	   API ~GUISettingsDialog();

   signals:
	  void  DoRetranslateUi() ;
	  void  UpdateStyle();

   public slots:
      void OkClicked();
      void CurrentItemChanged(int settingsChoice);
      void StyleChanged(const QString &style);
	  void LanguageChanged(int language);
      void RetranslateUi();

   private: // functions
      void API InitGui();

   private: // member objects
      QToolButton *fOkButton;
      QStackedWidget *fStackedOptions;
      QListWidget *fOptionsList;
      QStatusBar *fStatus;
      QMap<SettingChoice, QWidget *> fStackedWidgets;
      QString fTEXT__languageChanged;
      QString fTEXT__styleChanged;
   };



#endif