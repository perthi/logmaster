// -*- mode: c++ -*-

#pragma once

/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/


#include <QtCore/QObject>
#include <utilities/GDefinitions.h>

#include <iostream>
using  std::cout;
using  std::endl;

#include <string>
using std::string;


class GUISensors : public QObject
{
	Q_OBJECT

public: 
//	explicit __declspec(dllexport)   GUISensors(const string ip) : fIP(ip) {  };
	API   GUISensors(const string ip) : fIP(ip) {  };

public slots:
	void aslot(  );
	void update();


signals:
	void asignal( );

private:
	string fIP = "";
	


};

