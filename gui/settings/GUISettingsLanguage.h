

#ifndef _MAIN_SETTINGS_LANGUAGE_H_
#define _MAIN_SETTINGS_LANGUAGE_H_



/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtWidgets/QWidget>
#include <QtCore/QObject>


class QListWidget;


#include <utilities/GDefinitions.h>

#include <common/FDefinitions.h>

   enum LanguageChoice
   {
      UnknownLanguage = -1,
      Norwegian = 0,
      English = 1
   };
   QString LanguageChoice_toString(LanguageChoice lang);
   LanguageChoice API  LanguageChoice_fromString(const QString &lang);


   /** @brief     Widget class to contain language-settings for the main app*/
   class GUISettingsLanguage : public QWidget
   {
      Q_OBJECT

   public:
     API GUISettingsLanguage(QWidget *parent = 0);
      ~GUISettingsLanguage();

   signals:
	  void languageChanged(int language);

   private slots:
   void currentLanguageChanged(int language);

   private: // functions
      void InitGui();
      void LoadSettings();
      void RetranslateUi();

   private: // member objects
      QListWidget *fLanguageList;
   };


#endif