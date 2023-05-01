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
    //GUILoggerBase();
    LLogging::Instance();
    SET_LOGLEVEL("--all-debug");

  //  QMap<int, LMessage> fLoggedMessages2;
  //  QMap<int, LMessage> fNewMessages2;

  //  COUT << "fLoggedMessages2.size() = " << fLoggedMessages2.size()  << endl;
  //  COUT << "fNewMessages2.size() = " << fNewMessages2.size() << endl;

   // GUILoggerBase().SetLoggedMessage(fLoggedMessages2);
   // GUILoggerBase().SetNewMessage(fNewMessages2);

    try
    {
        QApplication *app = new QApplication(argc, argv);
        GUIInitStyles().Init(app);
        app->setApplicationName("loggerGuiTest");
        app->setOrganizationName("Embedded Consulting");
        SET_LOGTARGET("1111");

        auto logger = new GUILogger();
        GUILoggerGui *widget = new GUILoggerGui(logger);
        
        QMainWindow* mainWindow = new QMainWindow;
        mainWindow->setCentralWidget(widget);
        mainWindow->show();
        //widget->startTimer(1000);
        widget->startTimer(900);
        logger->startTimer(600);

        qApp->exec();
        
       // ExecWidget(widget);
    
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

