// -*- mode: c++ -*-


#ifdef _WIN32
#include <Windows.h>
#endif

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
#include <logging/LDatabase.h>
#include <logging/LLogTest.h>

#include <exception/GException.h>
#include <exception>

using namespace LOGMASTER;

#include <json/json.hpp>
#include <utilities/GTime.h>
#include <time.h>



int main ()
{
   LConfig::SetTimeMode("Cloud");
    double t = g_time()->GetEpochTime();
    FORCE_DEBUG("Epoch time = %f", t );
    time_t rawtime  = (long)t ;
    struct tm *info;
   // char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    FORCE_DEBUG("Year = %d",   info->tm_year + 1900 );
    FORCE_DEBUG("Hour = %d",  info->tm_hour );

   try
   {
      nlohmann::json j_test;
      j_test["origin"]["module"] = "ShotCalculation";
      j_test["origin"]["swVersion"] = "1.2.7";
      LMessage2Json::SetJsonUser ( j_test );
     // SET_LOGTARGET("--target-off --target-db --target-stdout --target-file");
    
      SET_LOGTARGET("--target-off --target-db");
    //  SET_LOGTARGET("--target-off --target-db --target-stdout");
      SET_LOGLEVEL("--all-info");
      
      for(int i= 0; i < 5; i++ )
      {
         LLogTest::WriteMessages();
      }

        string   test = "<Info:Fsm>";
        //string   test = "Info";

        COUT << "TP0" << endl;
        
        LDatabase::Instance()->ReadEntriesPrepare( test, 10000 );
        
        COUT << "TP1" << endl;


        std::shared_ptr<LogEntry> msg = std::make_shared< LogEntry >();

      //  LDatabase::Instance()->ReadEntriesGetEntry( msg ) 


        while( LDatabase::Instance()->ReadEntriesGetEntry( msg ) == true  ) 
        {
            COUT << "id = " << msg->LoggingID << "\tmsgtype = " << msg->LoggingType << "\tmsg = " << msg->Description << endl;

    //        ///FORCE_DEBUG("id = %d",  msg->LoggingID );

       }



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

      COUT << "TP2" << endl; 
   LDatabase::Instance()->CloseDatabase();
       COUT << "TP3" << endl;
    return 0;
}


///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
