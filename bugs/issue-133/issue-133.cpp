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
logthread(const int nloops, const int sleeptime_us)
{
    for(int i=0; i < nloops; i++)
    { 
        //std::this_thread::sleep_for( std::chrono::milliseconds(sleeptime) );
        std::this_thread::sleep_for( std::chrono::microseconds(sleeptime_us) );   
        SET_LOGTARGET("--target-off --target-file --target-db");
        //LLogTestAutoGen::WriteMessages();
        ALL_INFO("THIS IS A TEST MESSAGE");

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
    std::thread th1(logthread, 1000, 1);
    std::thread th2(logthread, 2000, 2);
    std::thread th3(logthread, 3000, 3);
    G_INFO("joining threads");
    th1.join();
    th2.join();
    th3.join();
    G_INFO("DONE joining threads"); 
}


int 
main(int  /*argc*/, const char** /*argv*/)
{
    SET_LOGLEVEL("--all-info");
    FORCE_DEBUG("Running test in asynchronous mode");
    run_threads(ePUBLISH_MODE::ASYNCHRONOUS);
    FORCE_DEBUG("Done running tests in asynch mode");
    FORCE_DEBUG("Now running test in synchronous mode");
    run_threads(ePUBLISH_MODE::SYNCHRONOUS);
    FORCE_DEBUG("Done running tests in synch mode");
    return 0;
}

