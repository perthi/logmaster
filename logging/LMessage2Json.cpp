// -*- mode: c++ -*-
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "LMessage2Json.h"
#include "LMessage.h"

#include "LHashMaps.h"
#include <utilities/GTime.h>



namespace LOGMASTER
{
  nlohmann::json  LMessage2Json::fJson; 


LMessage2Json::LMessage2Json()
{

}

LMessage2Json::~LMessage2Json()
{

}



void 
LMessage2Json::Message2Json(  const std::shared_ptr<LMessage>  msg , nlohmann::json &  j )
{
    auto lvl_hash = LHashMaps::Instance()->GetLevel2StringHash();
    auto sys_hash = LHashMaps::Instance()->GetSystem2StringHash();

    j = fJson;


    j["Level"] = lvl_hash->at(msg->fLevel);
    j["Category"] = sys_hash->at( msg->fSystem);
    j["Message"] = msg->fMsgBody;
    j["TimeEpcoch"] = msg->fEpochTime;
    j["Time_ISOISO8601"] = g_time()->GetTime_ISO8601();
    
    nlohmann::json j2;
    
    j2["test"]["idx1"] = "ONE";
    j2["test"]["idx2"] = "TWO";

    j["test"] = j2["test"];

   /// j+= j2;


}


}