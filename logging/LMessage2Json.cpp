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
  nlohmann::json  LMessage2Json::fJsonUser; 



LMessage2Json::LMessage2Json()
{

}


LMessage2Json::~LMessage2Json()
{

}




/** Converts a regluar log messaeg to a message on JSON format which is more suitable for
 * interchange and serialization/deserialization
 *  @param msg[in] The log message
 *  @param j[in, out]  The json object where the converted message will be stored */
void 
LMessage2Json::Message2Json(  const std::shared_ptr<LMessage>  msg , nlohmann::json &  j )
{
    auto lvl_hash = LHashMaps::Instance()->GetLevel2StringHash();
    auto sys_hash = LHashMaps::Instance()->GetSystem2StringHash();

    j = fJsonUser;

    j ["Level"] = lvl_hash->at(msg->fLevel);
    j ["time"]["mode"] = LConfig::GetTimeMode();
    j ["time"]["timestamp"] = msg->fEpochTime;
    j ["time"]["dateTime"] = g_time()->GetTime_ISO8601();

    std::stringstream buffer;
    buffer <<   msg->fPath << "/" <<  msg->fFileName << "::" <<  msg->fFunction << ":: line" << msg->fLineNo;
    //msg->fFileName
    j["origin"]["path"] = buffer.str();

    if( sys_hash->count(  msg->fSystem )  == 0  )
    { 
      j["Category"] = "NOT SET !";
    }
    else
    {
       j ["Category"] = sys_hash->at( msg->fSystem);
    }
    
    j ["Message"] = msg->fMsgBody;

}


/** Set additional information to append to each log message. Typcially this can be 
 *  additional information need, but that is not directly available 
 *  from the logging system 
 *  @param j[in] The additional information to append. Please not that this addition
 *  is appended to each and every log message */
void 
 LMessage2Json::SetJsonUser( const nlohmann::json j ) 
 {  
   fJsonUser = j; 
 }


}