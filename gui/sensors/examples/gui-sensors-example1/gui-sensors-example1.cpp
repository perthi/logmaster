// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include  <gui/sensors/GUISensorWidget.h>
#include  <gui/common/GUIInitStyles.h>

#include <logging/LLogApi.h>

using namespace LOGMASTER;



int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	GUIInitStyles::Instance()->Init(&app);
	QWidget w;
	GUISensorWidget *sw = new GUISensorWidget();
	QVBoxLayout* layout_v1  = sw->GenerateLayout();
	w.setLayout(layout_v1);
	w.show();
	app.exec();
	return 0;
}

