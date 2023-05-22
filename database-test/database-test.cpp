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
#include <logging/LLogTestAutoGen.h>
#include <logging/LLogEntrySQL.h>

#include <logging/GException.h>
#include <exception>

using namespace LOGMASTER;

#include <json/json.hpp>
#include <utilities/GTime.h>
#include <time.h>


#include <utilities/version-info/GMenu.h>


int main (int argc, const char **argv)
{
   LConfig::SetTimeMode("Cloud");
    double t = GTime().GetEpochTime();
    FORCE_DEBUG("Epoch time = %f", t );
    time_t rawtime  = (long)t ;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );
    FORCE_DEBUG("Year = %d",   info->tm_year + 1900 );
    FORCE_DEBUG("Hour = %d",  info->tm_hour );

 //   LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);

   try
   {
       GMenu::Instance()->ScanArguments(argc, argv);
       
       SET_LOGTARGET("--target-off --target-db --target-file --target-stdout");
      SET_LOGLEVEL("--all-info");
      
      for(int i= 0; i < 10; i++ )
      {
         LLogTestAutoGen::WriteMessages();
      }

        LDatabase::Instance()->InitSQLQuery( 0 );

        LLogEntrySQL msg;

       
       
        while( LDatabase::Instance()->ReadEntriesGetEntry( msg ) == true  ) 
        {
       
            COUT << "id = " << msg.fId << "\ttime_int = " << (long)msg.fTimeI << "\ttime_float"<< msg.fTimeD <<"\tcategory = " << (int)msg.fCategory << "\tmsg = " << msg.fJson << ENDL;
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



    LDatabase::Instance()->CloseDatabase();
    return 0;
}

