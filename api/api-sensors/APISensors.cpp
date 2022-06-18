// -*- mode: c++ -*-

/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/


#include "APISensors.h"
#include <configuration/KFFactorySensor.h>
#include <configuration/KFSensor.h>
#include <memory>

#include <intercom/KFInterCom.h>
#include <kf-common/KFDeviceInfo.h>
#include <configuration/KFConfigurationHandler.h>
#include <configuration/KFDeviceAddress.h>

#include <utilities/GString.h>
#include <utilities/GException.h>


APISensors*
APISensors::Instance()
{
	static APISensors* instance = new  APISensors();
	return instance;
}


vector<APISensorInfo>
APISensors::QuerySensorList()
{

	vector<APISensorInfo> tmp;
	std::map<std::string, std::shared_ptr<KFDeviceInfo>> sensorMap = KFInterCom::Instance()->GetSensorMap();
	for (auto it = sensorMap.begin(); it != sensorMap.end(); it++)
	{
		APISensorInfo info;
		std::string deviceid = it->first;
		std::shared_ptr<KFDeviceInfo> sensor = it->second;
		KFDeviceAddress addr = KFConfigurationHandler::Instance()->GetDeviceByID(deviceid)->fAddress;

		info.fID = sensor->fDeviceId;
		info.fIPAddress = addr.fIPAddress;

		// info.fIPAddress = KFInterCom::Instance()->GEt


		tmp.push_back(info);
		printf("[%s]%s\n", deviceid.c_str(), sensor->str().c_str());
	}




	// auto s_list = KFSensorFactory::Instance()->GetSensorList();

	// for (auto it = s_list.begin(); it != s_list.end(); it++)
	// {
	// 	std::shared_ptr<KFSensor> s = it->second;
	// 	APISensorInfo info;
	// 	info.fID = s->GetSensorId();
	// 	info.fIPAddress = s->GetIPAddress();
	// 	string subscript;
	// 	info.fSensorType = SensorType2String( s->GetSensorType(), subscript );
	// 	info.fSubscript = subscript;

	// 	double time = 99;
	// 	double value = 99;

	// 	s->GetLastReading(time, value);

	// 	info.fLastTimeSTamp =  g_string()->ToString( time  );
	// 	info.fLastReading =    g_string()->ToString( value );

	// 	info.fTimeSeries = s->GetXYData();

	// 	tmp.push_back(info);

	// }
	return tmp;
}


void
APISensors::Update()
{
	// KFSensorFactory::Instance()->UpdateAll();
}


void
APISensors::Update(APISensorInfo& info)
{
	// string ip_address = info.fIPAddress;
	// std::shared_ptr<KFSensor> s =  KFSensorFactory::Instance()->GetSensor(ip_address);
	// G_ASSERT_EXCEPTION(s != nullptr, "quering sensor with IP address %s returned a ZERO pointer", ip_address.c_str()  );
	// s->UpdateSensorValue();

	// double t = -1;
	// double val = -1;
	// s->GetLastReading( t, val);
	// info.fLastReading = g_string()->ToString(val);
}



APISensors::APISensors()
{
	// KFSensorFactory::Instance()->GenerateMockSensorList();
	// KFSensorFactory::Instance()->UpdateAll();
}


string
APISensors::SensorType2String(const eSENSOR_TYPE stype, string& subscript)
{
	string tmp;

	switch (stype)
	{
	case eSENSOR_TYPE::CURRENT:
		tmp =  "Current";
		subscript = "mA";
		break;
	case eSENSOR_TYPE::HUMIDITY:
		tmp = "Humidity";
		subscript = "%";
		break;
	case eSENSOR_TYPE::PRESSURE:
		tmp = "Pressure";
		subscript = "Pa";
		break;
	case eSENSOR_TYPE::TEMPERATURE:
		tmp = "Temperature";
		subscript = "C";
		break;
	case  eSENSOR_TYPE::VOLTAGE:
		tmp = "Voltage";
		subscript = "V";
		break;
	default:
		tmp = "UNKNOWN";
		subscript = "UNKNOWN";
		break;
	}

	return tmp;
}
