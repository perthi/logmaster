// -*- mode: c++ -*-
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LMessage2Json.h"
#include "LMessage.h"
#include "LHashMaps.h"
#include "LConfig.h"

#include <utilities/GTime.h>


#include <sstream>


namespace LOGMASTER
{
  nlohmann::json  LMessage2Json::fJson; 



LMessage2Json::LMessage2Json()
{

}


LMessage2Json::~LMessage2Json()
{

}

// {
//   "level": "error",
//   "time": 
//   {
//     "mode": "CLOUD", 
//     "timestamp": 1014987600000,
//     "datetime": "2002-03-01T13:00:00Z"
//   },
//   "origin": 
//   {
//     "module": "ShotCalculation",
//     "path": "SCModule.cpp::CalculateShot4Sensors::129",
//     "swVersion": "1.2.7"
//   },
//   "category": "Database", 
//   "message": "Error while storing shot (96fce825-d85e-44bd-a5fb-4ff4291c9a8e) in database" 
// }

void 
LMessage2Json::Message2Json(  const std::shared_ptr<LMessage>  msg , nlohmann::json &  j )
{
    auto lvl_hash = LHashMaps::Instance()->GetLevel2StringHash();
    auto sys_hash = LHashMaps::Instance()->GetSystem2StringHash();

    j = fJson;

    j ["Level"] = lvl_hash->at(msg->fLevel);
    j ["time"]["mode"] = LConfig::GetTimeMode();
    j ["time"]["timestamp"] = msg->fEpochTime;
    j ["time"]["dateTime"] = g_time()->GetTime_ISO8601();

    std::stringstream buffer;
    buffer <<   msg->fPath << "/" <<  msg->fFileName << "::" <<  msg->fFunction << "::" << msg->fLineNo;
    //msg->fFileName
    j["origin"]["path"] = buffer.str();


    j ["Category"] = sys_hash->at( msg->fSystem);
    j ["Message"] = msg->fMsgBody;
    

}


}