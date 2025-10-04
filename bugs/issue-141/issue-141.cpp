// -*- mode: c++ -*-

#include <logging/LLogApi.h>
#include <logging/GException.h>
#include <logging/LPublisher.h>
#include <logging/LLogTestAutoGen.h>

#ifdef _W_IN32
#include <Windows.h>
#endif

#include <string>
using namespace LOGMASTER;

#include <thread>
#include <chrono>
#include <cstring>

void exception_thread(const std::string &message, const std::string name, const int delay)
{
    FORCE_DEBUG("entering thread, message = %s", message.c_str());
    std::string tmp = (std::string("The exception message is:\t") + message + std::string(" (class GException)\n"));
    const char *expected_message = tmp.c_str();
    FORCE_DEBUG("Expected message = %s", expected_message);
    PUSH();
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::ASYNCHRONOUS);
    SET_LOGFORMAT("0000001");
    SET_LOGTARGET("0000 --target-file");  
    int i=0;
    
    try
    {
       for(i=0; i < 10000; i++)
       {
          SET_LOGFORMAT("0000001");
          SET_LOGTARGET("0000 --target-file");  
          char  *msg = nullptr;
          FORCE_DEBUG("i = %d", i);
          std::this_thread::sleep_for( std::chrono::microseconds(delay) );  
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
          //cout << endl << endl;
          if( strcmp(msg, expected_message) != 0 )
          {
            cout << "**********" << endl;
            CERR << "name:" << name << " Expected:" << expected_message << ENDL;
            CERR << "name:" << name << " Got     :" << msg << ENDL;
            cout << "**********" << endl;
          }

          G_ASSERT_EXCEPTION(strcmp(msg, expected_message) == 0, "\nExpected\t%s, \ngot\t%s", expected_message, msg );
          //FORCE_DEBUG("msg = %s", msg);    
          //cout << endl << endl;
         }
          
        }
    catch( GException &e)
    {
        PUSH();
        SET_LOGTARGET("--target-stdout");
        SET_LOGFORMAT("1000111");
        G_WARNING("%s, i = %d", e.what(), i );
        G_WARNING("%s,exiting now", name.c_str() );
        POP();
        return;
    }
    POP();  

}


int 
main(int  /*argc*/, const char** /*argv*/)
{
    try
    {
        LPublisher::Instance( )->SetMode(ePUBLISH_MODE::ASYNCHRONOUS);   
        G_FATAL("starting threads");
        //std::this_thread::sleep_for( std::chrono::milliseconds(200) );  
        //return 0;
        //std::this_thread::sleep_for( std::chrono::milliseconds(100) );  
        std::string msg1 =  "Message from thread one";
        std::string msg2 =  "Message from thread two";
        std::string msg3 =  "Message from thread three";
        std::thread th1(exception_thread, msg1, "thread1",1000);
        std::thread th2(exception_thread, msg2, "thread2",1503);
        std::thread th3(exception_thread, msg3, "thread3",2098 ) ;
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

    std::this_thread::sleep_for( std::chrono::milliseconds(100) ); 

    return 0;
}

