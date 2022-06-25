// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

////////////////////////////////////////////////////////////////////////////
//  \file      gui-qt-loggergui-example1.cpp
//  \brief     main loop for test for loggerGui and logger

#include <stdio.h>

#include <QtWidgets/QApplication>
#include <QtCore/QResource>
#include <QtCore/QFileInfo>
#include <QtCore/QtDebug>

#include <logging/LLogging.h>
#include <logging/LLogTest.h>
#include <gui/logger/GUILoggerGui.h>
#include <gui/logger/GUILogger.h>
#include <gui/common/GUIExecWidget.h>
#include <exception/GException.h>
#include <iostream>


using std::endl;
using std::cout;
using std::cerr;






#include  <gui/common/GUIInitStyles.h>

int main(int argc, char* argv[])
{
    try
    {
        QApplication app(argc, argv);

        GUIInitStyles::Instance()->Init(&app);

        app.setApplicationName("loggerGuiTest");
        app.setOrganizationName("Embedded Consulting");
        ///SET_LOGTARGET("1111");
        GUILoggerGui widget;
        ExecWidget(qobject_cast<QWidget*>(&widget));
    }
    catch (GException & e)
    {
        cerr << e.what() << endl;
    }
    catch (std::exception & e)
    {
        cerr << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown exception caught" << endl;
    }
}


