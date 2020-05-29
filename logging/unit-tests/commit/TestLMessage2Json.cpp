// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/
#include "TestLMessage2Json.h"


#include <logging/LLogApi.h>
#include <json/json.hpp>
#include <logging/LMessage2Json.h>
#include <logging/LMessage.h>
#include <logging/LLogging.h>
#include <logging/LEnums.h>
using namespace LOGMASTER;

#include  <utilities/GDefinitions.h>

#include <memory>
#include <iostream>

using std::cout;
using std::endl;

#include <json/json.hpp>

TestLMessage2Json::TestLMessage2Json()
{

}


TestLMessage2Json::~TestLMessage2Json()
{

}


TEST_F( TestLMessage2Json,  dummy )
{
    PUSH();
    FORCE_DEBUG("Testing dummy");
    EXPECT_EQ( true, false );
    
 

    SET_LOGTARGET("--target-off --target-db");
    SET_LOGLEVEL("--all-debug");
    COM_FATAL("Testing json conversion");
    std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr< LMessage > > > test = LLogging::Instance()->GetLastMessages();
    
    auto msg =  (*test)[eMSGTARGET::TARGET_DATABASE] ;
    COUT << "msg body = " <<  msg->fMsgBody  << endl;
    nlohmann::json json_dta;

    LMessage2Json().Message2Json( msg, json_dta );

   // json_dta["module"] = "Logging";
   // json_dta["test"]  = "TEST!!";

   cout << "JSON DATA = " << json_dta << endl;



    POP();
}

