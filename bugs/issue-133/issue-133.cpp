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
logthread(const int nloops, const int /*sleeptime*/)
{
    for(int i=0; i < nloops; i++)
    { 
        //std::this_thread::sleep_for( std::chrono::milliseconds(sleeptime) );    
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



int 
main(int  /*argc*/, const char** /*argv*/)
{
    SET_LOGLEVEL("--all-info");
    LPublisher::Instance( )->SetMode(ePUBLISH_MODE::SYNCHRONOUS);   
  //  LPublisher::Instance( )->SetMode(ePUBLISH_MODE::ASYNCHRONOUS);   
    G_INFO("starting threads");
    std::thread th1(logthread, 100, 10);
    std::thread th2(logthread, 1000, 1);
    std::thread th3(logthread, 103, 11);
    G_INFO("joining threads");
    th1.join();
    th2.join();
    th3.join();
    G_INFO("DONE");
    return 0;
}

