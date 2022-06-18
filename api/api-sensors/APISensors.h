// -*- mode: c++ -*-

#pragma once


/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/

#include <utilities/GDefinitions.h>
#include "APISensorInfo.h"
#include <kf-common/KFCommonEnums.h>


class APISensors
{
public:
	static APISensors API *  Instance();
	vector< APISensorInfo > API QuerySensorList();
	void API Update();
	void API Update( APISensorInfo & info);

private:
	APISensors();
	string SensorType2String(const eSENSOR_TYPE, string& subscript);

};

