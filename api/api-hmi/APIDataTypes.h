
#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <utilities/GDefinitions.h>
#include <common/MBDataTypes.h> 



class DeviceID_t  : public MBDataType<string> 
{ 
	public:
		DeviceID_t ( ) : MBDataType("") {};
		DeviceID_t ( string val) : MBDataType(val) {};
};

class HmiID_t  : public MBDataType<string> 
{ 
	public:
		HmiID_t ( ) : MBDataType("") {};
		HmiID_t ( string val) : MBDataType(val) {};
};
