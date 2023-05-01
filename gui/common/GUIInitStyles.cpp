// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "GUIInitStyles.h"
#include <QtCore/QResource>
#include <QtCore/QFileInfo>
#include <QtWidgets/QApplication>
#include <logging/LLogApi.h>

using namespace LOGMASTER;


#include <string>
using std::string;


void
GUIInitStyles::Init(QApplication* /*app*/)
{
	string resource_s = "";
	string style_s = "";

#ifdef _WIN32
	/// TODO should be read from a XML file, not hard coded
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


	QResource::registerResource(resource_s.c_str());
	QFileInfo style(style_s.c_str());

	if (style.exists())
	{
		QFile f(style.filePath());

		if (f.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QString styleContent = f.readAll();
			qApp->setStyleSheet(styleContent);
		}
		else
		{
			// COUT << "TP5" << endl;
		}
	}
	else
	{
		G_ERROR("Could not find stylesheet %s !", resource_s.c_str());
	}

}

