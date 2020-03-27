// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/
//#include  <common/include/GComponentDummyDatabase.h>
//#include  <common/include/GComponentDummyFactory.h>
#include  <common/GComponentDummyA.h>
#include  <common/MBMessageRequest.h>
#include  <common/MBMessageRequestUserInput.h>
#include  <common/MBMessagePayloadT.h>
#include  <logging/LLogging.h>
#include  <logging/LLogApi.h>
#include  <cmdline/GLogApplication.h>
#include  <common/MBEnums.h>
#include  <common/GComponentTimer.h>
#include  <common/GComponentDummyGuiRequest.h>
#include  <common/GComponentDummyGuiResponse.h>
#include  <common/MBPostOffice.h>

#undef SendMessage
#undef SendMessageW

//GComponentDummyGuiRequest  *request   =  new  GComponentDummyGuiRequest();
GComponentDummyGuiResponse *response =   new  GComponentDummyGuiResponse();
//MBMessageRequestUserInput   msg;
////response->DoSubscribe("API");


int testx()
{
//	response->DoSubscribe("API");
	static GComponentDummyGuiRequest  *request = new  GComponentDummyGuiRequest();
	//GComponentDummyGuiResponse *response = new  GComponentDummyGuiResponse();
//	response->DoSubscribe("API");
	MBMessageRequestUserInput   msg;
	auto reply = request->SendMessageBlocking( msg, "API", 100 );
	MBPostOffice::Instance()->StopPostOffice();

	std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

//	auto reply2 = request->SendMessageBlocking( msg, "API", 10000 );
	//const eUSER_RESPONSE  *payload = reply->ExtractRawPayload< eUSER_RESPONSE >();
	
	/*
	if ( payload == nullptr )
	{
		FORCE_DEBUG("ZERO POINTER");
	}
	else
	{

		FORCE_DEBUG( "Recived reply %s", *(*payload) );
	}
	*/
	return 0;
}


int 
main(int /*argc*/, const char ** /*argv*/  )
{
//	GComponentDummyGuiRequest  *request   =  new  GComponentDummyGuiRequest();
//	GComponentDummyGuiResponse *response =   new  GComponentDummyGuiResponse();
	response->DoSubscribe("API");	
	std::thread th1(testx);
//	std::thread th2(testx);
	///std::thread th2(testx);
	//std::thread th2(testx);
//	std::thread * th1= new thread(test);
	/*
	SET_LOGLEVEL("--all-info");
	auto reply = request->SendMessageBlocking( msg, "API", 10000 );
	FORCE_DEBUG("GOT reply !!");
	const eUSER_RESPONSE  *payload = reply->ExtractRawPayload< eUSER_RESPONSE >();
	FORCE_DEBUG("Recived reply %s", *(*payload) );
	*/

	FORCE_DEBUG("joining threads");
	th1.join();
	//th2.join();

	FORCE_DEBUG("Sleeping for 1000 millisconds");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));		

	FORCE_DEBUG("DONE !!");


	/*
	try
	{
		GLogApplication( argc, argv );
		SET_LOGFORMAT( "11100111" );

		GComponentDummyDatabase *db = new GComponentDummyDatabase();
		GComponentDummyFactory  *factory = new GComponentDummyFactory();
		db->DoSubscribe( "DATABASE" );
		factory->DoSubscribe( "INSTR_FACTORY" );
		MBMessageRequest msg(eMESSAGE_REQUEST::FACTORY_CONFIGDATA);
		FORCE_DEBUG( "Sending message with message ID %s", msg.GetMessageID().c_str() );
		db->SendMessage( msg, "INSTR_FACTORY", "DATABASE", true );
		std::this_thread::sleep_for( std::chrono::milliseconds( 300 ) );

		FORCE_DEBUG( "Sending blocking request request" );
		std::shared_ptr<MBMessage> reply_msg = factory->SendMessageBlocking( msg, "INSTR_FACTORY" );

		if ( reply_msg == nullptr )
		{
			MSG_FATAL( "Recived zero pointer" );
		}
		else
		{
			const vector<KDIConfigData> * const p_test = reply_msg->ExtractRawPayload< vector<KDIConfigData>  >();
			MSG_ASSERT_EXCEPTION( p_test != nullptr, "p_test  == ZERO pointer" );
			FORCE_DEBUG( "Recived promise, size = %d",p_test->size());
			const int * const p_test2 = reply_msg->ExtractRawPayload< int >();
			MSG_ASSERT_EXCEPTION( p_test2 != nullptr, "p_test2 == ZERO pointer" ); // Expecet an exception here since payload is not an int
		}
	}
	catch ( GException &e )
	{
		cout << e.what() << endl;
	}
	*/

}
