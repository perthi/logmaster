// -*- mode: c++ -*-
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include  "LMessage2Json.h"
#include  "LMessage.h"
#include  "LHashMaps.h"
#include  "LConfig.h"
#include  "LMessageGenerator.h"
#include  "LEnum2String.h"

#include <utilities/GTime.h>


#include <sstream>


namespace LOGMASTER
{

  LMessage2Json::LMessage2Json() : fJsonUser(), fTime()
  {

  }


  LMessage2Json::~LMessage2Json()
  {

  }


  /** Converts a regular log message to a message on JSON format which is more suitable for
   * interchange and serialization/deserialization
   *  @param[in] msg The log message
   *  @param[in, out] j The json object where the converted message will be stored */
  void
    LMessage2Json::Message2Json( std::shared_ptr<LMessage>  msg, nlohmann::json& j)
  {
    j = fJsonUser;
    j["level"] = LEnum2String::ToString(msg->fLevel);
    j["time"]["mode"] = LConfig::GetTimeMode();
    j["time"]["timestamp"] = (int)msg->fEpochTime;
    j["time"]["dateTime"] =  fTime.GetTime_ISO8601();

    std::stringstream buffer;
    buffer << msg->fPath << "/" << msg->fFileName << "::" << msg->fFunction << ":: line" << msg->fLineNo;

    j["origin"]["path"] = buffer.str();
    j["category"] = LEnum2String::ToString(msg->fSystem);
    j["message"] = msg->fMsgBody;
  }


  /** Set additional information to append to each log message. Typically this can be
   *  additional information need, but that is not directly available
   *  from the logging system
   *  @param[in] j The additional information to append. Please not that this addition
   *  is appended to each and every log message */
  void
    LMessage2Json::SetJsonUser(const nlohmann::json j)
  {
    fJsonUser = j;
  }


}