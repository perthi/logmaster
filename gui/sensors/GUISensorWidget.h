// -*- mode: c++ -*-
#ifndef GUISENSORWIDGET_H
#define GUISENSORWIDGET_H


/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/

#include <utilities/GDefinitions.h>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

//class  GUISensorWidget : public QVBoxLayout
class  GUISensorWidget : public QWidget
{
	public:

		API GUISensorWidget();
		virtual API ~GUISensorWidget();
		QVBoxLayout API * GenerateLayout();
};

#endif
