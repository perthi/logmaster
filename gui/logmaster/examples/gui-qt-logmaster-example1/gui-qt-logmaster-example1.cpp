
/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  \file      gui-qt-logmaster-example1.cpp
///  \brief     main loop for test for logmaster test application


#include  <gui/logmaster/GUILogMasterTab.h>
#include  <gui/common/GUIExecWidget.h>
#include  <gui/common/GUIInitStyles.h>
#include  <QtWidgets/QApplication>

#include <utilities/version-info/GMenu.h>

int main(int argc, char *argv[])
{
    GMenu::Instance()->ScanArguments(argc, (const char **)argv);

    QApplication *app = new QApplication(argc, argv);
    GUIInitStyles().Init(app);
    GUILogMasterTab widget;
    ExecWidget(&widget);
}
