// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtWidgets/QHBoxLayout>
#include <QtCore/QSettings>

#include "GUILogMasterTab.h"


GUILogMasterTab::GUILogMasterTab(QWidget *parent)
    :QWidget(parent),
    fTab(0)
    
{
    fAPILogMasters = APILogMasters::Instance();
    InitGui();
    RetranslateUi();
    LoadTabs();
}


GUILogMasterTab::~GUILogMasterTab()
{

}


/** @brief      InitGui
*   @details    This Function will make a new QTabWidget, adjust the style sheet, connect the tab bars to CurrentTabChanged() function
                and in the end make a new QVBoxLayout and create the Widget**/
void GUILogMasterTab::InitGui()
{
    fTab = new QTabWidget(this);
    fTab->setStyleSheet("QTabBar::tab {min-width: 30ex; }");

    connect(fTab, SIGNAL(tabBarClicked(int)),
        this, SLOT(CurrentTabChanged(int)));

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(fTab);
    this->setLayout(lay);
}


/** @brief      RetranslateUi
*   @details    This Function will configure the panel according to the stylesheet**/
void GUILogMasterTab::RetranslateUi()
{
    QSettings settings;
    settings.beginGroup("StyleSettings");

    QString currStyle = settings.value("currentStyle").toString();
  //  if (currStyle == "Ferrotech")
    {
        QString ss = QString("font: \"Courier\"; background-color:  #000000;");
    }
}


/** @brief      CurrentTabChanged
*   @details    This Function is a slot that is triggered on tabBarClicked, Based upon returned tab id.
                Correct target from fLogMasterTarget map is sent to the fAPILogMasters
*   @param[in]  id the o based index for the tabs.**/
void
GUILogMasterTab::CurrentTabChanged(int id)
{
    fAPILogMasters->SetCurrent(fLogMasterTarget.find(id).value()->GetTargetInt());
}


/** @brief      LoadTabs
*   @details    This Function will populate a tab for each target in the message system as defined in eMSGTARGET.
                All data is collected from fAPILogMasters->GetLogMasterList(), a map is populated:
                fLogMasterTarget that contains: first value is index for tab, starting at 0, second value is target object as KALogmaster**/
void
GUILogMasterTab::LoadTabs()
{
    int index = 0;
        
    for (auto target : fAPILogMasters->GetLogMasterList())
    {
        fAPILogMasters->SetCurrent(target->GetTargetInt());
        
        GUILogMasterGui *LogMasterGUI = new GUILogMasterGui(target->GetTargetInt(), target, this);
        fLogMasterTarget. insert(index, target);
        fTab->insertTab(index, LogMasterGUI, QString::fromUtf8(target->GetTargetName().c_str()));
        index++;
    }
}