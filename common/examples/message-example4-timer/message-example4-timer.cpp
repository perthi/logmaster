// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include  <common/GComponentDummyA.h>
#include  <common/GComponentTimer.h>
#include  <common/MBPostOffice.h>
#include  <logging/LLogging.h>
#include  <logging/LLogApi.h>
#include  <cmdline/GLogApplication.h>

#include <chrono>
#include <thread>

#undef SendMessage
#undef SendMessageW










int main(int argc, const char **argv )
{
	try
	{
		GLogApplication( argc, argv );
		SET_LOGFORMAT( "11100111" );
    //	GComponentTimer *timer = GComponentTimer::Instance();
        SET_LOGLEVEL("--all-debug");
        GComponentTimer::Instance();

		std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
		GComponentDummyA *dummyA = new GComponentDummyA();
		dummyA->DoSubscribe("OUT::TIMER");
		
		FORCE_DEBUG("%s", MBPostOffice::Instance()->str().c_str() );
		
		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );

		delete dummyA;


		FORCE_DEBUG("%s", MBPostOffice::Instance()->str().c_str() );

		std::this_thread::sleep_for( std::chrono::milliseconds( 1000 ) );
		//dummyA->DoSubscribe("OUT::TIMER");


		return 0;
	}
	catch ( GException &e )
	{
		cout << e.what() << endl;
	}
}

