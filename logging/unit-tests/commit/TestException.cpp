

#include "TestException.h"
#include <logging/GException.h>

#include <testlib/TestBase.h>
#include <utilities/GRandom.h>
#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>
#include <utilities/GString.h>

#include <logging/LPublisher.h>

using namespace LOGMASTER;
//#include <logging/LMessageGenerator.h>



void 
TestException::SetUp()
{
	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
    TestBase::SetUp();
}




TEST_F( TestException, simple)
{
    EXPECT_ANY_THROW(EXCEPTION( "a simple exception" ) );
	
	EXPECT_THROW(EXCEPTION("a simple exception"), GException);
    EXPECT_THROW( RANGE_EXCEPTION("a simple ecxeption"), GRangeException );
    EXPECT_THROW(FILE_NOT_FOUND_EXCEPTION("a simple ecxeption"), GFileNotFoundException );
}



 /// Here we check that the expected message is written to the logfile by the logging system 
/** @todo use google mock here */
TEST_F(TestException, fileIO)
 {
     string f1 = g_random()->Name("exception_fileio_test", ".txt");
     string f2 = g_random()->Name("exception_fileio_test", ".txt");

     SET_LOGFILENAME(f1);
     SET_LOGTARGET("0000 --target-file");
     SET_LOGFORMAT("1000001");

     EXPECT_ANY_THROW(EXCEPTION("a simple exception"));
	 EXPECT_EQ(g_file()->ReadFirstLine(f1),  "<Fatal:Exception>        \ta simple exception (class GException)");
     SET_LOGFILENAME(f2);

     string f = "dontexist.txt";
     EXPECT_THROW(FILE_NOT_FOUND_EXCEPTION("Cannot find file: %s", f.c_str()), GFileNotFoundException);
     EXPECT_EQ( g_file()->ReadFirstLine(f2), "<Fatal:Exception>        \tCannot find file: dontexist.txt (class GFileNotFoundException)");

     g_system()->rm(f1);
     g_system()->rm(f2);

     g_system()->rm(f1 + ".json");
     g_system()->rm(f2 + ".json");
  }
 




TEST_F(TestException, assert_macro)
{
	EXPECT_THROW(G_ASSERT_EXCEPTION(false, "Testing the assert macro"), GException);
	EXPECT_NO_THROW(G_ASSERT_EXCEPTION(true, "Testing the assert macro"));

	EXPECT_THROW(FSM_ASSERT_EXCEPTION(false, "Testing the FSM assert macro"), GFsmException);
	EXPECT_NO_THROW(FSM_ASSERT_EXCEPTION(true, "Testing the FSM assert macro"));
}


 TEST_F(TestException, buffer_overwrite_NSR1737)
 {
 	PUSH();
	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
 	SET_LOGFORMAT("0000001");
	SET_LOGTARGET("0000 --target-file --target-stdout");

	char  *msg = nullptr;

 	try
 	{
 		EXCEPTION("lorem ipsum");
 	}
 	catch(GException &e)
 	{
 		msg = G_ERROR( "The exception message is:%s",  e.what( ) )->at(eMSGTARGET::TARGET_EXCEPTION)->fMsgBody;
	}
 	EXPECT_STREQ("The exception message is:\tlorem ipsum (class GException)\n", msg );
	POP();
 }



TEST_F(TestException, disable_execptionNSR1769)
{
	EXPECT_ANY_THROW(EXCEPTION("an exception"));
	EXPECT_ANY_THROW(RANGE_EXCEPTION("an exception"));
	EXPECT_ANY_THROW(FILE_NOT_FOUND_EXCEPTION("an exception"));
	EXPECT_ANY_THROW(INVALID_ARGUMENT_EXCEPTION("an exception"));
	EXPECT_ANY_THROW(MISSING_ARGUMENT_EXCEPTION("an exception"));
	EXPECT_ANY_THROW(FSM_EXCEPTION("an exception"));	

	EXPECT_ANY_THROW(G_ASSERT_EXCEPTION( false, "an exception"));
	EXPECT_ANY_THROW(FSM_ASSERT_EXCEPTION(false, "an exception"));
	
	EXPECT_NO_THROW(G_ASSERT_EXCEPTION(true, "an exception"));
	EXPECT_NO_THROW(FSM_ASSERT_EXCEPTION(true, "an exception"));

	EXPECT_TRUE(GException::IsEnabledException());

	GException::DisableException();
	EXPECT_FALSE(GException::IsEnabledException());
	GException::EnableException();
	EXPECT_TRUE(GException::IsEnabledException());
	GException::DisableException();

	EXPECT_NO_THROW(EXCEPTION("an exception"));
	EXPECT_NO_THROW(RANGE_EXCEPTION("an exception"));
	EXPECT_NO_THROW(FILE_NOT_FOUND_EXCEPTION("an exception"));
	EXPECT_NO_THROW(INVALID_ARGUMENT_EXCEPTION("an exception"));
	EXPECT_NO_THROW(MISSING_ARGUMENT_EXCEPTION("an exception"));
	EXPECT_NO_THROW(FSM_EXCEPTION("an exception"));
	EXPECT_NO_THROW(G_ASSERT_EXCEPTION(false, "an exception"));
	EXPECT_NO_THROW(FSM_ASSERT_EXCEPTION(false, "an exception"));
}


 TEST_F(TestException, missing_messageNSR2366)
 {
 	GException::EnableException();
 	int number = 42;
 	SET_LOGFORMAT("0000001");
	
 	try
 	{
 		EXCEPTION("lorem ipsum, the number is %d", number );
 	}
 	catch (GException &e)
 	{
 		EXPECT_STREQ( "\tlorem ipsum, the number is 42 (class GException)\n", e.what() );
 	}

 	SET_LOGLEVEL("--all-off");

 	try
 	{
 		EXCEPTION("lorem ipsum, the number is %d",  number );
 	}
 	catch (GException &e)
 	{
 		EXPECT_STREQ("\tlorem ipsum, the number is 42 (class GException)\n", e.what());
 	}
 }
 
