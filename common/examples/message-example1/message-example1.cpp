// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include  <common/MBPostOffice.h>
#include  <common/MBMessage.h>
#include  <common/GComponentDummyA.h>
#include  <common/GComponentDummyB.h>
#include  <common/GComponentDummyC.h>
#include  <common/MBPayloadDummyA.h>
#include  <common/MBPayloadDummyB.h>
#include  <common/MBPayloadDummyC.h>
#include  <common/MBMessagePayload.h>
#include  <common/MBMessagePayloadT.h>
#include  <common/GComponentWireTap.h>

#include  <logging/LLogging.h>
#include  <logging/LLogApi.h>
#include  <cmdline/GLogApplication.h>
#include  <common/MBMessageInfo.h>
#include  <common/GComponentTimer.h>


#include <common/GComponentTimer.h>


#include <queue>
#include <deque>
#include <map>
#include <thread>
#include <chrono>
#include <future>
#include <iostream>
#include <memory>

using namespace LOGMASTER;
#include <string>
using std::string;
using std::cout;
using std::endl;

#include <ctime>


std::shared_ptr<MBMessage>  m1(new  MBMessage( "m1 message" ));
std::shared_ptr<MBMessage>  m2(new  MBMessage( "m2 message" ));
std::shared_ptr<MBMessage>  m3(new  MBMessage( "m3 message" ));
std::shared_ptr<MBMessage>  m4(new  MBMessage( "m4 message" ));
std::shared_ptr<MBMessage>  m5(new  MBMessage( "m5 message" ));

std::shared_ptr<MBMessage>  m6 = nullptr;

std::shared_ptr<MBMessageInfo> mi1(new MBMessageInfo(m1, "FSM::MAIN"));
std::shared_ptr<MBMessageInfo> mi2(new MBMessageInfo(m2, "FSM::DRIVER"));
std::shared_ptr<MBMessageInfo> mi3(new MBMessageInfo(m3, "SCHEDULER"));
std::shared_ptr<MBMessageInfo> mi4(new MBMessageInfo(m4, "FSM::MAIN"));
std::shared_ptr<MBMessageInfo> mi5(new MBMessageInfo(m5, "SCHEDULER"));
std::shared_ptr<MBMessageInfo> mi6(new MBMessageInfo(m5, "CONFIG_STORE"));
std::shared_ptr<MBMessageInfo> mi7(new MBMessageInfo(m5, "loremipsum"));

GComponentDummyA  *nodeA = nullptr;
GComponentDummyB  *nodeB = nullptr;
GComponentDummyC  *nodeC = nullptr;


std::mutex m;
bool do_run = true;


#undef SendMessage
#undef SendMessageW



auto po = MBPostOffice::Instance();


void test1(int /*id*/, int   /*sleeptime*/, int * /*inout*/ )
{
	static thread_local int cnt = 0;
//	std::this_thread::sleep_for( std::chrono::microseconds( 100 ) );


	while ( do_run == true )
	{
//		std::this_thread::sleep_for( std::chrono::nanoseconds( 1 ) );
	//	FORCE_DEBUG("cnt2 = %d", cnt2 );
	//	cnt2++;
		nodeA->SendMessage( m6, string( "FSM::DRIVER" ) );
		po->QueMessage( mi1,  ANY_MATCH );
		po->QueMessage( mi2, ANY_MATCH );
		po->QueMessage( mi3,  EXACT_MATCH);
		po->QueMessage( mi4,  ANY_MATCH );
//		m.lock();
		//*inout = cnt;
		cnt++;
	//	m.unlock();
	
	}
}


void test2(int /*id*/, int  /*sleeptime*/, int * /*inout*/ )
{
//	static thread_local int cnt = 0;
	//std::this_thread::sleep_for( std::chrono::microseconds(600 ) );
//	int cnt2 = 0;

	while ( do_run == true )
	{

//		std::this_thread::sleep_for( std::chrono::nanoseconds( 2 ) );
	//	FORCE_DEBUG("cnt2 = %d", cnt2 );
	//	cnt2++;
		nodeA->SendMessage( m6, string( "BLAHHH" ) );
		nodeA->SendMessage( m6, string( "SCHEDULER" ) );
		po->QueMessage( mi5, ANY_MATCH );
		po->QueMessage( mi5,  EXACT_MATCH);
		po->QueMessage( mi6, ANY_MATCH );
		po->QueMessage( mi7, ANY_MATCH );
		po->QueMessage( mi7, ANY_MATCH );
//		m.lock();
		//*inout = cnt;
		//cnt++;
//		m.unlock();
	}
}


bool is_finsihed( GComponent *c1, GComponent *c2, GComponent *c3 )
{
	if ( c1->Size() == 0 && c2->Size() == 0 && c3->Size() == 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}


void init()
{
	nodeA = new GComponentDummyA();
	nodeB = new GComponentDummyB();
	nodeC = new GComponentDummyC();
	new GComponentWireTap();
	m6 =   std::make_shared<MBMessage>( "m5 message" );
}


int main(int argc, const char **argv )
{
//	KMBPostOffice::Instance();
//	return 0;
	init();
	cout << po->str() << endl;
//	return 0;

	GLogApplication(argc, argv);
	SET_LOGFORMAT("11001111");
	int inout1 = 0;
	int inout2 = 0;
	int inout3 = 0;
	int inout4 = 0;

	FORCE_DEBUG( "Generating timer instance" );
	GComponentTimer::Instance();
	FORCE_DEBUG("Done");

	nodeA->DoSubscribe(  "FSM" );
	nodeB->DoSubscribe(  "FSM::MAIN" );
	nodeC->DoSubscribe(  "SCHEDULER" );
	nodeC->DoSubscribe(  "FSM::DRIVER" );
	nodeA->DoSubscribe(  "OUT::TIMER" );
	nodeB->DoSubscribe(  "OUT::TIMER" );

	FORCE_DEBUG("Starting threads");

	std::thread th1 = std::thread(test1, 1, 8,		&inout1 );
	std::thread th2 = std::thread(test1, 2, 4,		&inout2 );
	std::thread th3 = std::thread(test2, 3, 2,		&inout3 );
	std::thread th4 = std::thread(test2, 4, 1,		&inout4 );


	clock_t begin = clock();
	unsigned long n_before = po->GetMsgCountRecived();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	unsigned long n_after = po->GetMsgCountRecived();
	clock_t end = clock();
	unsigned long n_total = n_after - n_before;
	double elapsed_msec = double( end - begin );
	do_run = false;


	cout << po->str() << endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	

	/*
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	*/

//	po->Stop();

//	return 0;

	do
	{
		FORCE_DEBUG( "po msg queue size = %d, nA msg queue size = %d (%s), nB msg queue size = %d (%s), nC msg queue size = %d (%s), ISRUNNING = %s, po->size() = %d, dl.size() = %d, inv.size() = %d", 
			po->Size(),  
			nodeA->Size(), nodeA->IsRunningS().c_str(),
			nodeB->Size(), nodeB->IsRunningS().c_str(),
			nodeC->Size(), nodeC->IsRunningS().c_str(),
			po->IsRunning() == true ? "YES, PO IS RUNNING" : "NO!!, NOT RUNNING!!!", po->Size(), po->SizeDead(), po->SizeInvalid()  );
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	} while ( po->Size() > 0  || ( is_finsihed( nodeA, nodeB ,nodeC ) == false ) );


	clock_t end_processed = clock();
	
	double elapsed_msec_processed = double( end_processed - begin );
	std::this_thread::sleep_for(std::chrono::milliseconds(200));

	unsigned long n_total_processed = po->GetMsgCountProcessed();
	unsigned long n_total_delivered = po->GetMsgCountDelivered();

	FORCE_DEBUG( "po msg queue size = %d, n1 msg queue size = %d, n2 msg queue size = %d, n3 msg queue size = %d",
		          po->Size(), nodeA->Size(), nodeB->Size(), nodeC->Size() );
	FORCE_DEBUG("joining threads");

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	FORCE_DEBUG("elapsed ms = \t%f", elapsed_msec );
	FORCE_DEBUG("n_before = \t\t\t%ld",  n_before );
	FORCE_DEBUG("n_after = \t\t\t%ld",   n_after );
	FORCE_DEBUG("n_total = \t\t\t%ld", n_total);
	FORCE_DEBUG("n_total_delivered = \t%ld", n_total_delivered);
	FORCE_DEBUG("n_total_processed = \t%ld", n_total_processed);

	double freq = n_total / (elapsed_msec / 1000);
	double freq_processed =  n_total_processed / (elapsed_msec_processed / 1000);
	double freq_delivered =  n_total_delivered / (elapsed_msec_processed / 1000);

	FORCE_DEBUG("F = %e  HZ (messages/seconds) recieved  by post office", freq);
	FORCE_DEBUG("F = %e  HZ (messages/seconds) processed by post office", freq_processed );
	FORCE_DEBUG("F = %e  HZ (messages/seconds) delivered by post office", freq_delivered );

//	FORCE_DEBUG("Recieved  =\t%ld", po->GetMsgCountRecived() );
//	FORCE_DEBUG("Processed =\t%ld", po->GetMsgCountProcessed() );
	FORCE_DEBUG("Stopping timer");
	GComponentTimer::Instance()->StopTimer();
//	GComponentTimer::fDoRunTimer = false;
	FORCE_DEBUG("done");
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

}
