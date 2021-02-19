// -*- mode: c++ -*-

/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

/* ****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/

#include "TestLogging.h"
#include <logging/LMessageGenerator.h>
#include <logging/LMessage.h>
#include <logging/LConfig.h>
#include <logging/LPublisher.h>

#include <utilities/GTime.h>
#include <utilities/GRegexp.h>
#include <utilities/GNumbers.h>
#include <utilities/GTokenizer.h>
#include <utilities/GString.h>
#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>
#include <exception/GException.h>
#include <cmdline/GCmdScan.h>

#include <cmdline/GLogApplication.h>
#include <typeinfo>

#include <chrono>
#include <thread>

string  TestLogging::fMessage = "";
std::streambuf*    TestLogging::fOldBuf;
ostringstream TestLogging::fStrCout;


TestLogging::TestLogging() : TestBase()
{

}


TestLogging::~TestLogging()
{

}

void 
TestLogging::SetUpTestCase()
{
///	FORCE_DEBUG("setting up testcases");
}



void 
TestLogging::SetUp() 
{
	GCmdScan::Instance()->SetIgnoreStrayArgument(false);
	g = new GLogApplication();

	g->InitLogArgs();
	TestBase::SetUp();
	SET_LOGTARGET( "0000 --target-file" );

	fOldBuf = cout.rdbuf();
	cout.rdbuf( fStrCout.rdbuf() );
	fStrCout.str( "" );

}


void TestLogging::TearDown()
{
   TestBase::TearDown();
   cout.rdbuf(fOldBuf);
}


void
TestLogging::Subscriber(const   std::shared_ptr<LOGMASTER::LMessage>  msg  )
{
    fMessage = string( msg->fMsg );
}




TEST_F(TestLogging, set_logtarget_g_logapplication)
{
	///auto l = LLogging::Instance();
	g->ScanArguments("-logtarget --target-off --target-subscriber -logformat 00000001");
	EXPECT_EQ((int)(eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS), (int)l->GetLogTarget());
	g->ScanArguments("-logtarget --target-off -logformat 00000001");
	EXPECT_EQ((int)(eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION), (int)l->GetLogTarget());
}



TEST_F( TestLogging, set_logtarget )
{
///	auto l = LLogging::Instance();

		SET_LOGTARGET("--target-off --target-subscriber");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS);
		SET_LOGTARGET("--target-off --target-subscriber --target-stdout ");
		EXPECT_EQ(l->GetLogTarget(), (eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_STDOUT));
		SET_LOGTARGET("--target-subscriber --target-stdout --target-off");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_OFF);
		SET_LOGTARGET("--target-all");
//		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_ALL);
		EXPECT_EQ(  (int)l->GetLogTarget(),  (int)0x7f );
		SET_LOGTARGET("--target-all --target-off");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_OFF);
		SET_LOGTARGET("--target-off --target-all");
		EXPECT_EQ( (int)l->GetLogTarget(), (int)0x7f  );
		SET_LOGTARGET("--target-off --target-file");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_FILE);
		SET_LOGTARGET("0000 --target-file");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_FILE);
		SET_LOGTARGET("0000 --target-gui");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_GUI);
		SET_LOGTARGET("0000 --target-stdout");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_STDOUT);
		SET_LOGTARGET("0000 --target-subscriber");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS);
		SET_LOGTARGET("0000 0001");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_FILE);
		SET_LOGTARGET("0000 1000");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_GUI);
		SET_LOGTARGET("0000 0010");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_STDOUT);
		SET_LOGTARGET("0000  0100");
		EXPECT_EQ(l->GetLogTarget(), eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS);
		SET_LOGTARGET("0000  0110");
		EXPECT_EQ(l->GetLogTarget(), (eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_STDOUT | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_SUBSCRIBERS));
		SET_LOGTARGET("0000  --target-all");
		EXPECT_EQ( (int)l->GetLogTarget(), (int) 0x7f );
		SET_LOGTARGET("0000");
		SET_LOGTARGET("0000 1001");
		EXPECT_EQ(l->GetLogTarget(), (eMSGTARGET::TARGET_TESTING | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_GUI | eMSGTARGET::TARGET_EXCEPTION | eMSGTARGET::TARGET_FILE));
		SET_LOGTARGET("0000 1000 0100 0010 0001");
		EXPECT_EQ(  (int)l->GetLogTarget(), (int)0x3f );
}




TEST_F(TestLogging, level_to_string )
{
	EXPECT_EQ( "Error",       LEnum2String::ToString( eMSGLEVEL::LOG_ERROR ));
	EXPECT_EQ( "Fatal",       LEnum2String::ToString(eMSGLEVEL::LOG_FATAL));
	EXPECT_EQ( "Fatal|Error", LEnum2String::ToString(eMSGLEVEL::LOG_ERROR | eMSGLEVEL::LOG_FATAL));
}
	




TEST_F(TestLogging, stdoutIO)
{
	LPublisher::Instance()->DisableColor();
    PUSH();
	SET_LOGLEVEL("--all-warning");
	SET_LOGFORMAT("00000001");
	//SET_LOGFORMAT("0000001", eMSGTARGET::TARGET_STDOUT);
	fStrCout.str("");
	SET_LOGTARGET("--target-stdout");
	G_ERROR("Test message with parameters: a = %d, b = %d", 1, 2);

//	EXPECT_EQ(fStrCout.str(), "\tTest message with parameters: a = 1, b = 2\n");
	
	SET_LOGFORMAT("00000000");
	fStrCout.str("");
    G_INFO("Test message with parameters: a = %d, b = %d", 1, 2);
    EXPECT_EQ(fStrCout.str(), "");
	
	SET_LOGFORMAT("00000001");
	fStrCout.str("");
	G_WARNING("Test message with parameters: a = %d, b = %d", 1, 2);
    
///	EXPECT_EQ(fStrCout.str(), "\tTest message with parameters: a = 1, b = 2\n");
    
	fStrCout.str("");
	
	SET_LOGFORMAT("01000001");
    LPublisher::Instance()->EnableColor();
	POP();
}



TEST_F(TestLogging, exeptions)
{
	SET_LOGTARGET("0000 --target-file");
	SET_LOGFORMAT("11111111");
    EXPECT_ANY_THROW( g->ScanArguments("-gibberish"));
    EXPECT_ANY_THROW( g->ScanArguments("-loglevel -gibberish"));
    EXPECT_ANY_THROW( g->ScanArguments("-loglevel --gibberish"));
    EXPECT_ANY_THROW( g->ScanArguments("-loglevel gibberish"));
}



TEST_F(TestLogging, messageBody)
{
    SET_LOGFORMAT("00000001");
	SET_LOGTARGET("--target-off --target-file");
	SET_LOGLEVEL("--off --warning");
	EXPECT_STREQ("\tTest\n", G_ERROR("Test")->at(eMSGTARGET::TARGET_FILE)->fMsg);
//	EXPECT_STREQ("", G_INFO("ignorme")->at(eMSGTARGET::TARGET_STDOUT)->fMsg);
	EXPECT_STREQ( "\tTesting integer parameters: a = 1, b = 3\n", G_ERROR( "Testing integer parameters: a = %d, b = %d", 1, 3 )->at(eMSGTARGET::TARGET_FILE)->fMsg );
	EXPECT_STREQ( "\tTesting float parameters: a = 4.55, b = 3.333\n", G_ERROR( "Testing float parameters: a = %0.2f, b = %0.3f", 4.55, 3.333 )->at(eMSGTARGET::TARGET_FILE)->fMsg );
}






TEST_F(TestLogging, loglevels)
{
	PUSH();
	SET_LOGLEVEL("--all-warning");
	SET_LOGFORMAT( "11111111" ); //We mask out only the mesage typ, all other fields ar empty
	EXPECT_GT( string( G_FATAL( "a message" )->at( eMSGTARGET::TARGET_FILE )->fMsg ).size(), (size_t)0 );
	EXPECT_GT( string( G_ERROR( "a message" )->at( eMSGTARGET::TARGET_FILE )->fMsg ).size(), (size_t)0 );
	EXPECT_GT( string( G_WARNING( "a message" )->at( eMSGTARGET::TARGET_FILE )->fMsg ).size(), (size_t)0 );
//	EXPECT_EQ( (size_t)0, string( G_INFO( "a message" )->at( eMSGTARGET::TARGET_FILE )->fMsg ).size() );
//	EXPECT_EQ( (size_t)0, string( G_DEBUG( "a message" )->at( eMSGTARGET::TARGET_FILE )->fMsg ).size() );
	POP();
}




TEST_F(TestLogging, fileIO)
{
	PUSH();
	SET_LOGTARGET ( "--target-file");
	SET_LOGFORMAT("00000001");
	SET_LOGFILENAME("googletest_logging_file_io.log");
	EXPECT_EQ("googletest_logging_file_io.log", l->GetLogFileName( eMSGTARGET::TARGET_FILE));
	SET_LOGLEVEL("--all-warning");
	
	
	G_ERROR("Test message");
	
	std::this_thread::sleep_for( std::chrono::milliseconds(100) );

	FileIOTest();
	EXPECT_EQ("\tTest message", FileIOTest());
	SET_LOGTARGET("--target-off"); // not really neccessary, maybe test fixture takes care of this ?
	POP();
}




/*
TEST_F(TestLogging, timeStamp)
{
	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS); 
	SET_LOGTARGET( "--target-off");
	SET_LOGTARGET(" --target-stdout --target-file");
	SET_LOGFORMAT("00100000");
    SET_LOGLEVEL("--all-warning");
    
	EXPECT_EQ(true,  g_time()->IsValidDateString(G_FATAL("Ignore")->at(eMSGTARGET::TARGET_FILE)->fTimeStamp ) );
	EXPECT_EQ(true,    g_time()->IsValidDateString( G_ERROR("Ignore")->at(eMSGTARGET::TARGET_FILE)->fMsg  ));
	EXPECT_EQ(true,    g_time()->IsValidDateString( G_WARNING("Ignore")->at(eMSGTARGET::TARGET_FILE)->fMsg ));
	EXPECT_EQ(false,   g_time()->IsValidDateString( G_INFO("Ignore")->at(eMSGTARGET::TARGET_FILE)->fMsg  ));
	EXPECT_EQ(false,   g_time()->IsValidDateString( G_DEBUG("Ignore")->at(eMSGTARGET::TARGET_FILE)->fMsg  ));  
}
*/



/// Testing for feature request NSR-218
TEST_F(TestLogging, NSR218)
{
	EXPECT_NO_THROW( g->ScanArguments( "-loglevel --debug" ) );
	EXPECT_NO_THROW( g->ScanArguments( "-loglevel --info" ) );
	EXPECT_NO_THROW( g->ScanArguments( "-loglevel --warning" ) );
	EXPECT_NO_THROW( g->ScanArguments( "-loglevel --error" ) );
	EXPECT_NO_THROW( g->ScanArguments( "-loglevel --fatal" ) );
	SET_LOGFORMAT("01000001");
 //   EXPECT_STREQ("",  G_ERROR("This is a test" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
    EXPECT_STREQ("<Fatal:General>          \tThis is a test\n", G_FATAL("This is a test")->at(eMSGTARGET::TARGET_FILE)->fMsg );
   }




TEST_F(TestLogging, NSR219)
{
    EXPECT_NO_THROW(SET_LOGFORMAT("01111111" ) );
    EXPECT_NO_THROW(SET_LOGFORMAT("01000001") );
    EXPECT_NO_THROW(SET_LOGFORMAT("00000000") );
    EXPECT_ANY_THROW( SET_LOGFORMAT("0100001" ) );
    EXPECT_ANY_THROW(SET_LOGFORMAT("1111" ));
    EXPECT_ANY_THROW(SET_LOGFORMAT("gibberish"));
    EXPECT_ANY_THROW(SET_LOGFORMAT("0xabc" ));

}


/*
/// SKIP !!!!!!!
// NSR-207 binary commands for log targets
TEST_F(TestLogging, NSR207)
{
    EXPECT_NO_THROW(SET_LOGTARGET("1111"));
    EXPECT_NO_THROW( g->ScanArguments("-logtarget 1111"));
    //EXPECT_NO_THROW(SET_LOGTARGET((eMSGTARGET)0x7));
    EXPECT_ANY_THROW(SET_LOGTARGET("111"));
  //  EXPECT_ANY_THROW(SET_LOGTARGET( (eMSGTARGET)0x123));

    EXPECT_NO_THROW(SET_LOGTARGET("0000"));
   // fStrCout.str("");
	SET_LOGFORMAT("00000001");
    G_ERROR("Hello Dolly");
  //  EXPECT_EQ("", fStrCout.str());
    EXPECT_NE("\t\tHello Dolly\n", FileIOTest());
	EXPECT_EQ("", fMessage);
    l->RegisterSubscriber(Subscriber);
    EXPECT_NO_THROW(SET_LOGTARGET("1111"));    

	SET_LOGLEVEL("--all-debug");
	G_ERROR("\tHello Chuck");
    EXPECT_EQ("\t\tHello Chuck\n", fMessage) << "logfilename = " <<  	l->GetLogFileName() << endl;
 }
*/



TEST_F(TestLogging, NSR790HugeMessage)
{
    SET_LOGFORMAT("--all-off --msg-body");
    SET_LOGLEVEL("--all");
    SET_LOGTARGET("--target-off --target-file ");

    string loremipsum =  "Lorem ipsum dolor sit amet, cu brute habemus has, mei suas debitis ea.Per ex oportere prodesset, per eu tota soleat inimicus.Sint eros menandri quo eu.Cum an inani mundi aliquip, omittam liberavisse an mel, dolorum albucius aliquando nam eu.Sit id expetenda interesset, has placerat invenire eu, ut mea stet nusquam.Pri ad percipit ullamcorper.An sit lucilius delicatissimi, justo consequat ea pro. \
        No unum denique noluisse pro, mei autem nominati iracundia no.Ei eius platonem mea, tota solum detracto cum at, dicam essent et usu.An commune mediocritatem ius, ad erant volutpat rationibus usu.Mei at prima suscipit, ius illud dignissim ne, cu mel assentior democritum reprimique.Vel ex admodum eleifend abhorreant, ius purto impetus ut, detracto aliquando eos ut.Ut sed molestiae intellegat, eos omnes fastidii ex, \
        sea philosophia theophrastus ut.Ad nam omnium facilisi, tritani insolens dissentiet at per. Te vel diam nominati pertinacia, et vix omnes contentiones.Vis cu viderer debitis, sea eripuit tibique epicuri ad.Duo adhuc postea nonumes ex, te discere euripidis mei.Ad ancillae propriae deterruisset vel. \
        Pri at probo sensibus mandamus.Adipisci mandamus qui eu, et quo alia mucius option.Eirmod ancillae id mei, id meis antiopam eam, ius ex congue alienum.Eos eu sale delicata, commune principes adolescens ex his. \
        An vix suscipit voluptua referrentur, mel te tollit bonorum apeirian, et pro esse interpretaris.Vero lobortis forensibus in ius, eu vix dicat etiam consectetuer, per ea luptatum electram interpretaris.Cu sed eius salutatus.Eos meis similique disputando ex.Est quas adipisci signiferumque ea.\n";

    EXPECT_EQ("\t" + loremipsum + "\n",  G_INFO(loremipsum.c_str() )->at(eMSGTARGET::TARGET_FILE)->fMsg );
}




TEST_F(TestLogging, NSR724ForceDebug)
{
    SET_LOGLEVEL("--all");
    SET_LOGFORMAT("01000001");

    //If we use the force debug macro we shall generate a message regardless of the configuration of the logging system
    EXPECT_STREQ("<Force_Debug:General>    \tForcing the logging system to write a message\n",   FORCE_DEBUG("Forcing the logging system to write a message")->at(eMSGTARGET::TARGET_FILE)->fMsg );
}



TEST_F(TestLogging, NSR939Subscribers)
{
    SET_LOGTARGET("--target-off");
    EXPECT_EQ(BIN("0000000000110000"), (int)l->GetLogTarget());
	SET_LOGTARGET("--target-subscriber --target-file");
    EXPECT_EQ(BIN("0000000000110101"), (int)l->GetLogTarget());
    SET_LOGTARGET("--target-off");
    EXPECT_EQ(BIN("0000000000110000"), (int)l->GetLogTarget());
    SET_LOGTARGET("--target-file");
    EXPECT_EQ(BIN("0000000000110001"), (int)l->GetLogTarget());
    SET_LOGTARGET("--target-subscriber");
    EXPECT_EQ(BIN("0000000000110101"), (int)l->GetLogTarget());
    SET_LOGTARGET("--target-stdout");
    EXPECT_EQ(BIN("0000000000110111"), (int)l->GetLogTarget());
 
    SET_LOGTARGET("--target-off --target-subscriber --target-file");
    EXPECT_EQ(BIN("0000000000110101"), (int)l->GetLogTarget());

	SET_LOGTARGET("--target-all");
    EXPECT_EQ(BIN("0000000001111111"), (int)l->GetLogTarget());
    
	SET_LOGTARGET("--target-off");
    EXPECT_EQ(BIN("0000000000110000"), (int)l->GetLogTarget());
 
    SET_LOGTARGET("0011");
    EXPECT_EQ(BIN("0000000000110011"), (int)l->GetLogTarget());
 
    SET_LOGTARGET("0111");
    EXPECT_EQ(BIN("0000000000110111"), (int)l->GetLogTarget());
 
    SET_LOGTARGET("--target-off 0101");
    EXPECT_EQ(BIN("0000000000110101"), (int)l->GetLogTarget());

}



// TEST_F(TestLogging, logBinary)
// {
// //	SET_LOGFORMAT( "01000001"); //
// 	SET_LOGFORMAT( "11111111"); //
// 	SET_LOGLEVEL( "--all-off" );
// 	EXPECT_STREQ( "", ALL_DEBUG( "This is a db DEBUG message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_INFO( "This is a db INFO message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_WARNING( "This is a ALL_WARNING message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_ERROR( "This is a ALL_ERROR message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_FATAL( "This is a ALL_FATAL message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	SET_LOGLEVEL( "000001000000000111000000" );
// }



// TEST_F(TestLogging, logBinary)
// {
// //	SET_LOGFORMAT( "01000001"); //
// 	SET_LOGFORMAT( "11111111"); //
// 	SET_LOGLEVEL( "--all" );
// 	EXPECT_STREQ( "", ALL_DEBUG( "This is a db DEBUG message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_INFO( "This is a db INFO message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_WARNING( "This is a ALL_WARNING message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_ERROR( "This is a ALL_ERROR message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	EXPECT_STREQ( "", ALL_FATAL( "This is a ALL_FATAL message" )->at(eMSGTARGET::TARGET_FILE)->fMsg );
// 	SET_LOGLEVEL( "000001000000000111000000" );
// }




#if defined NDEBUG && defined _WIN64
TEST_F( TestLogging, performance )
{
	int n = 5134032;

	LMessage *l = new LMessage();

	clock_t begin = clock();	
	for ( int i = 0; i < n; i++ )
	{
		/// The LMessage::Clear content is critical to optimize since it is called every time a log macro is used
		l->ClearContent();
	}
	clock_t end = clock();
	double elapsed_secs = double( (double)end - (double)begin );
	double average = 1000000*(elapsed_secs / n);
	//ASSERT_TRUE( average < 0.05 );
	printf("Average time for clear content is %4.8f micro seconds \n", average  );
	ASSERT_TRUE( average < 5 );
}
#endif


#if defined NDEBUG && defined _WIN64
TEST_F( TestLogging, performance2 )
{
	SET_LOGTARGET("0000");
//	SET_LOGFORMAT("1000111");

	clock_t begin = clock();
	int n = 10000;
	int i = 0;
	double time = 50.0; // use this value on local computer
		
	for ( i = 0; i < n; ++i )
	{
		/// A typical eror message that will pass the loglve check, and use all the facilities to generate a message
		//DRIVER_ERROR( "This is atest message, a = %d and b  %d", 1, 2 );
	}

	clock_t end = clock();
	double elapsed_secs = double( (double)end - (double)begin );
	double average = 1000*(elapsed_secs / n);

	
	if ( g_string()->Contains( g_system()->GetHostName(), "UKNW") )
	{
		time = 500.0; // Use longer time for Jenkins as Jenkins might be busy with many opperations at once.
	}

	printf("Average time for loggemacro is %.6f milli seconds, time is %.6f milli seconds\n", average, time);

	ASSERT_TRUE( average < time);
}
#endif



