// -*- mode: c++ -*-

#include <logging/LLogApi.h>
#include <logging/GException.h>
#include <logging/LPublisher.h>

#ifdef _W_IN32
#include <Windows.h>
#endif

#include <string>
using namespace LOGMASTER;

#include <thread>
#include <chrono>
#include <cstring>

void exception_thread(const std::string &message)
{
    CERR << "TP0" << ENDL;
    FORCE_DEBUG("entering thread, message = %s", message.c_str());
    std::string tmp = (std::string("The exception message is:\t") + message + std::string(" (class GException)\n"));
    const char *expected_message = tmp.c_str();
    //expected_message  = message.c_str(); 
    FORCE_DEBUG("Expected message = %s", expected_message);
   // return;
    PUSH();
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::ASYNCHRONOUS);
    SET_LOGFORMAT("0000001");
    SET_LOGTARGET("0000 --target-file");  
    int i=0;
    CERR << "TP2" << ENDL;

    
    try
    {
    
       for(i=0; i < 10000; i++)
       {
          CERR << "i=" << i << "msg =" << message << ENDL;
          char  *msg = nullptr;
          
          FORCE_DEBUG("i = %d", i);
          std::this_thread::sleep_for( std::chrono::microseconds(10) );  
          try
          {
             EXCEPTION(message.c_str());
          }
          catch(GException &e)
          {
             msg = G_ERROR( "The exception message is:%s",  e.what( ) )->at(eMSGTARGET::TARGET_EXCEPTION)->fMsgBody;
          }
          
         // CERR << "MSG = " << msg << ENDL;
         // CERR << "MSG = " << expected_message << ENDL;
          G_ASSERT_EXCEPTION(strcmp(msg, expected_message) == 0, "Expected %s, got %s", expected_message, msg );
          //FORCE_DEBUG("msg = %s", msg);    
        }
          
        }
    catch( GException &e)
    {
        PUSH();
        SET_LOGTARGET("--target-stdout");
        G_FATAL("%s, i = %d", e.what(), i );
        G_FATAL("exiting now");
        POP();
        return;
    }
    POP();  

}


int 
main(int  /*argc*/, const char** /*argv*/)
{


   // std::string msg = "lorem ipsum";
    //exception_thread(msg);
    try
    {
        LPublisher::Instance( )->SetMode(ePUBLISH_MODE::ASYNCHRONOUS);   
        G_FATAL("starting threads");
        std::this_thread::sleep_for( std::chrono::milliseconds(200) );  
        //return 0;
        std::this_thread::sleep_for( std::chrono::milliseconds(100) );  
        std::string msg1 =  "Message from thread one";
        std::string msg2 =  "Message from thread two";
        std::string msg3 =  "Message from thread three";
        std::thread th1(exception_thread, msg1);
        std::thread th2(exception_thread, msg2);
        std::thread th3(exception_thread, msg3 ) ;
        G_INFO("joining threads");
        th1.join();
        th2.join();
        th3.join();
        G_INFO("DONE joining threads"); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
      CERR << "UNKNOWN EXCEPTION CAUGHT" << ENDL;
    } 

    std::this_thread::sleep_for( std::chrono::milliseconds(500) ); 
    
    return 0;
}

