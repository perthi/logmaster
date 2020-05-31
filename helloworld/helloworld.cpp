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


      SET_LOGTARGET("--target-off --target-db --target-stdout");
      SET_LOGLEVEL("--all-error");
      FORCE_DEBUG("Hellow world");
      G_DEBUG("Hellow world");
      G_INFO("Hellow world");
      G_WARNING("Hellow world");
      G_ERROR("Hellow world");
      G_FATAL("Hellow world");

      std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage>>> test = LLogging::Instance()->GetLastMessages();

      for (auto m : *test)
      {
       //   cout <<  "target = " <<  (int)m.first << " msg body = "  << m.second->fMsgBody << "\tepcoch time " <<  m.second->fEpochTime  << endl;
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
