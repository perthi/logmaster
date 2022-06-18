// -*- mode: c++ -*-

#pragma once


/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/


#include <iostream>

using std::cout;
using std::endl;


#include <QtCore/QObject>
#include <QtWidgets/QPushButton>

#include <string>

using std::string;

class GUISensorPushButton : public QPushButton
{
	Q_OBJECT

public slots:
	void aslot();

public:
	GUISensorPushButton(const string name) : QPushButton(name.c_str() ) {};

signals:
	void asignal();
	
};

