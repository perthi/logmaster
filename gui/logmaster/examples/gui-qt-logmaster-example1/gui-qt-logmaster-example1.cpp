
/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  \file     gui-qt-logmaster-example1.cpp
///  \brief     main loop for test for logmaster test application


#include <QtWidgets/QApplication>
#include <QtCore/QResource>
#include <QtCore/QtDebug>
#include <QtCore/QFileInfo>

#include <gui/logmaster/GUILogMasterTab.h>
#include <gui/common/GUIExecWidget.h>
#include  <gui/common/GUIInitStyles.h>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   
   GUIInitStyles::Instance()->Init(&app, "logmatserGUITest", "Embedded Consulting");


   GUILogMasterTab widget;
   ExecWidget(qobject_cast<QWidget*>(&widget));
}