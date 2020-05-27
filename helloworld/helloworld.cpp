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

#include <exception/GException.h>
#include <exception>

using namespace LOGMASTER;


int main ()
{
   try
   {

      SET_LOGTARGET("--target-off");
      SET_LOGLEVEL("--all-debug");
      FORCE_DEBUG("Hellow world");

      std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage>>> test = LLogging::Instance()->GetLastMessages();

      for (auto m : *test)
      {
         FORCE_DEBUG("target = %d, msg bodyzz =::: %s", m.first, m.second->fMsgBody);
         // FORCE_DEBUG("msg body = %s",  m.second->fMsgBody  );
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

  return 0;
}


///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
