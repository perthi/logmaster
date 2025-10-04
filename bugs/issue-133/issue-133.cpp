// -*- mode: c++ -*-

#include <logging/LLogApi.h>
#include <logging/GException.h>
#include <logging/LPublisher.h>
#include <logging/LLogTestAutoGen.h>

#ifdef _W_IN32
#include <Windows.h>
#endif

#include <string>
using std::string;
using namespace LOGMASTER;

#include <thread>
#include <chrono>



void 
logthread(const int nloops, const int sleeptime_us, const std::string &name)
{
    for(int i=0; i < nloops; i++)
    { 
        std::this_thread::sleep_for( std::chrono::microseconds(sleeptime_us) );   
        SET_LOGTARGET("--target-off --target-file --target-db");
        //LLogTestAutoGen::WriteMessages();
       // ALL_INFO("THIS IS A TEST MESSAGE");
        ALL_INFO(name);

        PUSH();
        SET_LOGLEVEL("--all-off --db-debug");
        POP();
        PUSH();
        SET_LOGLEVEL("--all-off --all-info");
        POP();
        float percent = 100*(float)i/nloops;
        PUSH();
        SET_LOGLEVEL("--all-info");
        G_INFO("i = %d of %d, progress = %f", i, nloops, percent);
        POP();
    }
    
}
 
void join_thread( std::thread *th, const string &name)
{
      if(th->joinable() == true)
      {
         th->join();
         printf("JOINED %s\n", name.c_str()); 
      }
      else
      {
         printf("%s is not joinable", name.c_str() );   
      }
      
     
}

void run_threads( const ePUBLISH_MODE mode )
{
    LPublisher::Instance( )->SetMode(mode);   
    G_INFO("starting threads");
    std::thread th1(logthread, 1000, 100, "thread one");
    std::thread th2(logthread, 2000, 200, "thread two");
    std::thread th3(logthread, 3000, 300, "thread three"  ) ;
    G_INFO("joining threads");
    
    join_thread(&th1, "thread one");
    join_thread(&th2, "thread two");
    join_thread(&th3, "thread three");

   // th2.join();
   // printf("JOINED THREAD TWO\n");
   // th3.join();
    G_INFO("DONE joining threads\n"); 
   // printf("JOINED THREAD THREE\n");
    std::this_thread::sleep_for( std::chrono::milliseconds(200) );   
}


void turn_on_targets(const int n)
{
    for(int i=0; i < n; i ++)
    {
        LLogging::Instance()->TurnOnfAllTargets();
    }    
}

void turn_off_targets(const int n)
{
    for(int i=0; i < n; i ++)
    {
        LLogging::Instance()->TurnOffAllTargets();
    }    
}


int 
main(int  /*argc*/, const char** /*argv*/)
{
    SET_LOGFORMAT("1000001");
    
    /*
    FORCE_DEBUG("Turning on all targets");
    turn_on_targets(1000);
    FORCE_DEBUG("Turning off all targets");
    turn_off_targets(1000);
    */

    SET_LOGLEVEL("--all-info");
    FORCE_DEBUG("Running test in asynchronous mode");
    run_threads(ePUBLISH_MODE::ASYNCHRONOUS);
    FORCE_DEBUG("Done running tests in asynch mode");
    
    /*
    FORCE_DEBUG("Now running test in synchronous mode");
    run_threads(ePUBLISH_MODE::SYNCHRONOUS);
    FORCE_DEBUG("Done running tests in synch mode");
    */
    printf("DONE !!!!!!\n");   
    std::this_thread::sleep_for( std::chrono::milliseconds(500) );   

    return 0;
}

