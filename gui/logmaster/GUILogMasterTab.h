// -*- mode: c++ -*-


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUILogMasterTab
///  @brief     GUI for controlling the Logmaster Tabs


#ifndef _LOGMASTER_TAB_H_
#define _LOGMASTER_TAB_H_

#include "GUILogMasterGui.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QTabWidget>

class GUILogMasterTab : public QWidget
{
    Q_OBJECT

public:
    // explicit API GUILogMasterTab(QWidget *parent = 0);
    API GUILogMasterTab(QWidget* parent = 0);
    API ~GUILogMasterTab();

    //signals:

private slots:
    void CurrentTabChanged(int id);


private: // functions
    void InitGui();
    void RetranslateUi();
    void LoadTabs();

private:

    GUILogMasterTab(const GUILogMasterTab&);
    GUILogMasterTab operator=(const GUILogMasterTab&);

    QTabWidget* fTab = nullptr;
    QMap<int, APILogmaster*> fLogMasterTarget{}; // first value is index for tab, starting at 0  second value is pointer to correct object
    APILogMasters* fAPILogMasters = nullptr;
};


#endif
