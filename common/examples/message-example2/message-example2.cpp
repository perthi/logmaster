// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include  <common/MBPostOffice.h>
#include  <common/GComponentDummyA.h>
#include  <logging/LLogging.h>
#include  <logging/LLogApi.h>
#include  <cmdline/GLogApplication.h>

#include <thread>
#include <chrono>
#include <mutex>

#undef SendMessage
#undef SendMessageW

#include <condition_variable>

condition_variable cv;

std::mutex mtx;
std::unique_lock<std::mutex>  lck(mtx);


void test( )
{
	FORCE_DEBUG("Waiting for conditional");
//	cv.notify_one();
	FORCE_DEBUG("running thread: ID = %d", this_thread::get_id() );
	cv.notify_all();
}



int main(int argc, const char **argv )
{
	GLogApplication(argc, argv);
	std::thread * th1= new thread(test);
	std::thread * th2= new thread(test);
	//mtx.unlock();
	cv.wait( lck );
	th1->join();
	th2->join();
}
