// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

////////////////////////////////////////////////////////////////////////////
//  \file      gui-qt-loggergui-example1.cpp
//  \brief     main loop for test for loggerGui and logger


#include  <gui/common/GUIInitStyles.h>

#include <QtWidgets/QApplication>
#include <gui/logger/GUILoggerGui.h>
#include <gui/logger/GUILogger.h>
#include <gui/common/GUIExecWidget.h>
#include <exception/GException.h>

#include <iostream>

using std::endl;
using std::cout;
using std::cerr;



int main(int argc, char* argv[])
{
    LLogging::Instance();

    try
    {
        QApplication *app = new QApplication(argc, argv);
        GUIInitStyles::Init(app);
        app->setApplicationName("loggerGuiTest");
        app->setOrganizationName("Embedded Consulting");
        SET_LOGTARGET("1111");
        GUILoggerGui *widget = new GUILoggerGui(new GUILogger());
        ExecWidget(widget);
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

