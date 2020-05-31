// -*- mode: c++ -*-


#ifdef _WIN32
#include <Windows.h>
#endif




//#include <utilities/GSystem.h>
// auto client = std::make_shared<KFClientMain >(argc, argv);
 //       th1 = thread( &KFClientMain::Run, client  );

#include <stdio.h>

//#include <unistd.h>

#include <string>
using std::string;

#include <iostream>
using std::endl;
using std::cout;

#include <memory>

#include <iostream> 
#include <string>

#include <logging/LLogApi.h>
#include <logging/LLogging.h>
#include <logging/LMessage.h>

#include <logging/LMessage2Json.h>
#include <logging/LConfig.h>

#include <exception/GException.h>
#include <exception>

using namespace LOGMASTER;


#include <json/json.hpp>




int main ()
{
    LConfig::SetTimeMode("Cloud");


   try
   {

      SET_LOGTARGET("--target-off --target-db --target-stdout");
      SET_LOGLEVEL("--all-error");
      FORCE_DEBUG("Hellow world");
      std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage>>> test = LLogging::Instance()->GetLastMessages();
      auto msg = test->at( eMSGTARGET::TARGET_DATABASE );        
      CERR << "msg body = " <<  msg->fMsgBody  << endl;   
      
      nlohmann::json j_test;
      j_test["origin"]["module"] = "ShotCalculation";
      j_test["origin"]["swVersion"] = "1.2.7";
    
    // //  j_test["USER"] = "blahhhhh!";
    //     j_test["unitGuid"] = "e30c392d-3f6a-4184-bf73-80c20a6a6c93";
    //     j_test["unitTypeId"] =  "ETARGET";
    //     j_test["productId"] =  "ITE";
    //     j_test["application"] =  "escore-ite";

      LMessage2Json::SetJsonUser ( j_test );

      nlohmann::json j;
      
      LMessage2Json().Message2Json(msg, j);

      CERR << "JSON = " << j << endl;  


   }
   catch(  GException &e )
   {
       FORCE_DEBUG("%s", e.what() );
   }
   catch( std::exception &e )
   {
       FORCE_DEBUG("%s", e.what() );

   }
   catch(std::string &e)
   {
       FORCE_DEBUG("%s", e.c_str() );
   }
   catch (...)
   {
       FORCE_DEBUG("Unknown exception caught !!");
   }

  return 0;
}


///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
