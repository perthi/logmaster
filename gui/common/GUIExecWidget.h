// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


///  @file GUIExecWidget.h
///  @brief     Convenience functions for running qt widgets from a command line program

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>

#include <chrono>
#include <thread>

#ifndef _EXEC_WIDGET_H_
#define _EXEC_WIDGET_H_


    /*  @brief Start the QWidget inside a QMainWindow and execute it before moving on.
    *
    *   This function will make a a new QMainWindow and execute the QWidget inside it. This will block the execution of the application until the 
    *   window is closed. Call the MakeQApp() function atleast once before using this (or create the QApplication object manually). 
    *
    *   Typical usage:
    * 
    *   -Make the QApplication:
    *       MakeQApp();
    *
    *   -Create the Qt widget you want to show:
    *       GUIChartDWWidget dialog(title, xvalues, yvalues, linenames);
    *
    *   -Execute the widget and continue execution when the window is closed:
    *       ExecWidget(qobject_cast<QWidget*>(&dialog));
    *
    *   
    *   It is also possible to make a static function to execute the widget with one line:
    *   static void ShowDWWidget(const string title, vector<unsigned>* xvalues, vector<unsigned>* yvalues, vector<string> linenames)
    *   {
    *       MakeQApp();
    *       GUIChartDWWidget dialog(title, xvalues, yvalues, linenames);
    *       ExecWidget(qobject_cast<QWidget*>(&dialog));
    *   }
    *
    *   See the gui-qt-charts-example2 for an example of this.
    */
	static void ExecWidget(QWidget* widget, bool start_timer = true, int milliseconds = 1000)
	{
       // MakeQApp();
        QMainWindow* mainWindow = new QMainWindow;
        mainWindow->setCentralWidget(widget);
        mainWindow->show();
        if (start_timer == true)
        {
            widget->startTimer(milliseconds);
        }
        
        qApp->exec();
    }

    /*  @brief Make the QAp<plication object if it does not exist.
    *
    *   This function will make a a new QApplication object if it does not exist. This is neccesary for to call atleast 
    *   once before any Qt objects are created and before the ExecWidget function is used. This function can be called 
    *   multiple times.
    *
    */
    #ifdef _WIN32
    static void MakeQApp()
    {
        if (!qApp)
        {
            int argc = 0;
            char **argv = 0;
            QApplication* app = new QApplication(argc, argv);
        }
    }
    #endif



#endif