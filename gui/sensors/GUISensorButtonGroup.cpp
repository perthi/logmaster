// -*- mode: c++ -*-

/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/


#include "GUISensorButtonGroup.h"
#include <api/api-sensors/APISensors.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;


GUISensorButtonGroup::GUISensorButtonGroup(const APISensorInfo &info ) : fSensorInfo(info)
{
	fIP = new GUISensorPushButton(info.fIPAddress);
	fType = new  GUISensorPushButton(info.fSensorType);
	fValue = new GUISensorPushButton( info.fLastReading );
	fSubscript = new GUISensorPushButton(info.fSubscript);

	fLayout = new QHBoxLayout();

	fLayout->addWidget(fIP);
	fLayout->addWidget(fType);
	fLayout->addWidget(fValue);
	fLayout->addWidget(fSubscript);
}


void
GUISensorButtonGroup::aslot()
{
	G_INFO("update resquest recived");
	APISensors::Instance()->Update(fSensorInfo);
	fValue->setText( fSensorInfo.fLastReading.c_str() );
}