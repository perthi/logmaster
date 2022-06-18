


#ifndef _MAIN_SETTINGS_STYLE_H_
#define _MAIN_SETTINGS_STYLE_H_



/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <common/FDefinitions.h>
#include <QtWidgets/QWidget>


///  @brief     Widget class to contain style-settings for the main app
class QListWidget;

   class GUISettingsStyle : public QWidget
   {
    Q_OBJECT

   public:
      explicit API GUISettingsStyle(QWidget *parent = 0);
      ~GUISettingsStyle();

	  
   signals:
      void  StyleChanged(const QString &style);
	  
	 // void API currentStyleChanged(const QString &styleItemText) override;

   private slots:
      void CurrentStyleChanged(const QString &styleItemText);
	  

   private: // functions
      void API  InitGui();
      void API LoadSettings();
	  

   private: // member objects
      QListWidget *fStyleList;
	  
   };


#endif