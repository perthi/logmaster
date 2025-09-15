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
logthread(const int nloops, const int sleeptime_us, const std::string &message)
{
    for(int i=0; i < nloops; i++)
    { 
        std::this_thread::sleep_for( std::chrono::microseconds(sleeptime_us) );   
        SET_LOGTARGET("--target-off --target-file --target-db");
        //LLogTestAutoGen::WriteMessages();
       // ALL_INFO("THIS IS A TEST MESSAGE");
        ALL_INFO(message);

        PUSH();
        SET_LOGLEVEL("--all-off --db-debug");
        POP();
        PUSH();
        SET_LOGLEVEL("--all-off --all-info");
        POP();
        float percent = 100*(float)i/nloops;
        PUSH();
        SET_LOGLEVEL("--all-info");
        G_INFO("progress = %f", percent);
        POP();
    }
    
}

void run_threads( const ePUBLISH_MODE mode )
{
    LPublisher::Instance( )->SetMode(mode);   
    G_INFO("starting threads");
    std::thread th1(logthread, 1000, 1, "Message from thread one");
    std::thread th2(logthread, 2000, 2, "Message from thread two");
    std::thread th3(logthread, 3000, 3, "Message from thread three"  ) ;
    G_INFO("joining threads");
    th1.join();
    th2.join();
    th3.join();
    G_INFO("DONE joining threads"); 
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

    return 0;
}

