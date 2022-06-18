// -*- mode: c++ -*-

#pragma once

/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           * 
* for Semcon Norge AS                              *  
****************************************************/


#include <string>
using std::string;
#include <vector>
using std::vector;

#include <queue>

class APISensorInfo
{
public:
	string fSensorType = "not set";
	string fIPAddress = "not set";
	string fID = "not set";
	
	string fLastTimeSTamp = "not set";
	string fLastReading = "not set";
	
	string fSubscript = "not set";
	std::queue<std::pair<double, double > > fTimeSeries;

};

