

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtCore/QSettings>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QListWidget>

#include "GUISettingsLanguage.h"



GUISettingsLanguage::GUISettingsLanguage(QWidget *parent)
   :QWidget(parent)
{
   InitGui();
   LoadSettings();
   RetranslateUi();
}


GUISettingsLanguage::~GUISettingsLanguage()
{

}


void 
GUISettingsLanguage::InitGui()
{
   fLanguageList = new QListWidget(this);
   connect( fLanguageList, SIGNAL(currentRowChanged(int)),
      this, SLOT(currentLanguageChanged(int)));

   QListWidgetItem *nor = new QListWidgetItem;
   nor->setIcon(QIcon(":/images/norway.png"));
   nor->setData(Qt::UserRole, Norwegian);

   QListWidgetItem *eng = new QListWidgetItem;
   eng->setIcon(QIcon(":/images/uk.png"));
   eng->setText("English");
   eng->setData(Qt::UserRole, English);

   fLanguageList->insertItem(Norwegian, nor);
   fLanguageList->insertItem(English, eng);

   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget(fLanguageList);
   lay->setContentsMargins(0, 0, 0, 0);
   this->setLayout(lay);
}


void 
GUISettingsLanguage::currentLanguageChanged(int language)
{
   QSettings settings;
   settings.beginGroup("LanguageSettings");
   settings.setValue("currentLanguage", LanguageChoice_toString(static_cast<LanguageChoice>(language)));
   settings.endGroup();
   emit languageChanged(language);
}


void 
GUISettingsLanguage::RetranslateUi()
{
   // not really translated, after all, this is the gui where you want to change the language, because you dont necessarily understand the current set language
   static QString
      TEXT__nor = "Norsk",
      TEXT__eng = "English";

   for (int i = 0; i < fLanguageList->count(); i++)
   {
      QListWidgetItem *item = fLanguageList->item(i);
      LanguageChoice lang = static_cast<LanguageChoice>(item->data(Qt::UserRole).toInt());
      switch (lang)
      {
      case Norwegian:
         item->setText(TEXT__nor);
         break;
      case English:
         item->setText(TEXT__eng);
         break;
      case UnknownLanguage:
      default:
         break;
      }
   }
}


void 
GUISettingsLanguage::LoadSettings()
{
   QSettings settings;
   settings.beginGroup("LanguageSettings");
   QString currentLanguage = settings.value("currentLanguage").toString();
   if (currentLanguage.size() == 0)
   {
      currentLanguage = "English";
      settings.setValue("currentLanguage", currentLanguage);
   }
   LanguageChoice lang = LanguageChoice_fromString(currentLanguage);
   if (lang != UnknownLanguage)
   {
      fLanguageList->setCurrentRow(lang);
   }
}


QString 
LanguageChoice_toString(LanguageChoice lang)
{
   switch (lang)
   {
   case Norwegian:
      return "Norsk";
      break;
   case English:
      return "English";
      break;
   case UnknownLanguage:
   default:
      return "UnknownLanguage";
   }
}


LanguageChoice 
LanguageChoice_fromString(const QString &lang)
{
   if (lang == "Norsk")
   {
      return Norwegian;
   }
   else if (lang == "English")
   {
      return English;
   }
   else
   {
      return UnknownLanguage;
   }
}