// -*- mode: c++ -*-
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "LMessage2Json.h"
#include "LMessage.h"

#include "LHashMaps.h"

namespace LOGMASTER
{

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
    j["Level"] = lvl_hash->at(msg->fLevel);
    

}


}