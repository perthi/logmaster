


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtCore/QSettings>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>

#include "GUISettingsStyle.h"


GUISettingsStyle::GUISettingsStyle(QWidget *parent)
   :QWidget(parent),
   fStyleList(0)
{
   InitGui();
   LoadSettings();
}

GUISettingsStyle::~GUISettingsStyle()
{

}


void 
GUISettingsStyle::InitGui()
{
   fStyleList = new QListWidget(this);

   connect( fStyleList, SIGNAL(currentTextChanged(const QString &)),
      this, SLOT(CurrentStyleChanged(const QString &)));

   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget( fStyleList);
   lay->setContentsMargins(0, 0, 0, 0);

   this->setLayout(lay);
}



void 
GUISettingsStyle::LoadSettings()
{
   QSettings settings;
   settings.beginGroup("StyleSettings");
   QStringList styles = settings.value("styles").toStringList();
   if (styles.size() == 0)
   {
      styles << "Native Windows" << "Ferrotech";
      settings.setValue("styles", styles);
   }
   fStyleList->clear();
   for (int i = 0; i < styles.size(); i++)
   {
      fStyleList->addItem(styles.at(i));
   }

   QString currentStyle = settings.value("currentStyle").toString();
   if (currentStyle.size() == 0)
   {
      currentStyle = "Ferrotech";
      settings.setValue("currentStyle", currentStyle);
   }

   QList<QListWidgetItem *> items = fStyleList->findItems(currentStyle, Qt::MatchExactly);
   if (items.size() > 0)
   {
      fStyleList->setCurrentItem(items[0]);
   }
}



void 
GUISettingsStyle::CurrentStyleChanged(const QString &styleItemText)
{
	
   QSettings settings;
   settings.beginGroup("StyleSettings");
   settings.setValue("currentStyle", styleItemText);
   settings.endGroup();
   emit StyleChanged(styleItemText);
}

