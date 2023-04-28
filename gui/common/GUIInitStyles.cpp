// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "GUIInitStyles.h"
#include <QtCore/QResource>
#include <QtCore/QFileInfo>
#include <QtCore/QtDebug>
#include <QtWidgets/QApplication>
#include <logging/LLogApi.h>

using namespace LOGMASTER;


#include <string>
using std::string;


GUIInitStyles *
GUIInitStyles::Instance()
{
    static  GUIInitStyles* instance = new GUIInitStyles();
    return   instance;

}

void
GUIInitStyles::Init(QApplication * /*app*/)
{
    string resource_s = "";
    string style_s = "";

    #ifdef _WIN32
       // resource_s =  "gui-qt.rcc";
       // style_s =  ":/styles/ferrotech.qmm";
        resource_s = "C:\\work\\logmaster\\gui\\resources\\gui-qt.rcc";
        style_s = "C:\\work\\logmaster\\gui\\resources\\styles\\ferrotech.qmm";

    #else
//        string home = getenv("LOGMASTER_HOME");
        #ifdef GUI_DIR
        string home = GUI_DIR;
        resource_s = home + "/gui/resources/gui-qt.rcc";
        ///style_s = home + "/gui/resources/styles/ferrotech.qmm";
        style_s = home + "/gui/resources/styles/norspace.qmm";
        #else
        G_ERROR("GUI dir is not set, cannot load styles");
        string home = "";
        #endif
        
    #endif


    QResource::registerResource(resource_s.c_str() );
    QFileInfo style(style_s.c_str() );

    COUT << "Style = " << style_s << endl;;

    if (style.exists())
    {
        COUT << "TP0" << endl;
        QFile f(style.filePath());
            
        if (f.open(QIODevice::ReadOnly | QIODevice::Text))
            {
            COUT << "TP1" << endl;
                QString styleContent = f.readAll();
                COUT << "TP2" << endl;
                qApp->setStyleSheet(styleContent);
                COUT << "TP3" << endl;
               // G_DEBUG("Setting style :/styles/ferrotech.qmm");
                COUT << "TP4" << endl;
        }
        else
        {
            COUT << "TP5" << endl;
        }
    }
    else
    {
            COUT << "Style = " << style_s << "DOES NOT EXIST"  << endl;;
            G_ERROR("Could not find stylesheet %s !",  resource_s.c_str()  );
    }

}

