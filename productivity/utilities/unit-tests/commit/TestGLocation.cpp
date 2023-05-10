// -*- mode: c++ -*-

/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "TestGLocation.h"
#include <utilities/GCrc.h>
#include <utilities/GRandom.h>
#include <memory>

#include <vector>

using std::vector;

#include <thread>
#include <chrono>

void 
 TestGLocation::SetUpTestCase()
 {
    SET_LOGTARGET("--target-stdout");
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
    ///FORCE_DEBUG("SETUP");
    ///FORCE_DEBUG("SETUP2");
 }

void 
 TestGLocation::TearDownTestCase()
 {
    //CERR << "TEARING DOWN" << ENDL;
    /// FORCE_DEBUG("TEARDOWN");

 }


void 
TestGLocation::SetUp()
{
  SET_LOGTARGET("--target-stdout");
  LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
  
 /// FORCE_DEBUG("SETUP");

}

void TestGLocation::TearDown()
{
    
  ///  FORCE_DEBUG("teardown");

}



TEST_F(   TestGLocation , strings )
{
    for(int i=0; i < 100; i++)
    {
        int num = g_random()->Uniform(0, 10000);
        g_string()->ToString(333);
        string expected =   "some/file/path[line" +  g_string()->ToString(num) +  string("]: MyClass::SomeFunction");
        string actual = GLocation("some/file/path",  num, "MyClass::SomeFunction").str();
        //FORCE_DEBUG("expected = %s, size = %d", expected.c_str(), expected.size() );
        //FORCE_DEBUG("actual = %s, size = %d", actual.c_str(), actual.size() );
        EXPECT_EQ(expected, actual );
    }
}


TEST_F(   TestGLocation , charptr )
{
    static int cnt = 0;
    
    for(int i=0; i < 100; i++)
    {
        int num = g_random()->Uniform(0, 10000);
        //g_string()->ToString(333);
        string expected =   "some/file/path[line" +  g_string()->ToString(num) +  string("]: MyClass::SomeFunction");
        const char *actual = GLocation("some/file/path",  num, "MyClass::SomeFunction").c_str();
        FORCE_DEBUG("expected = %s, size = %d", expected.c_str(), expected.size() );
        FORCE_DEBUG("actual = %s, size = %d", actual,  strlen(actual) );
        EXPECT_EQ(expected, actual );
        cnt ++;
    }

//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


TEST_F(   TestGLocation , strings_c_str )
{
    for(int i=0; i < 100; i++)
    {
        int num = g_random()->Uniform(0, 10000);
        //g_string()->ToString(333);
        string expected =   "some/file/path[line" +  g_string()->ToString(num) +  string("]: MyClass::SomeFunction");
        
        const char *actual = GLocation("some/file/path",  num, "MyClass::SomeFunction").str().c_str();
        //FORCE_DEBUG("expected = %s, size = %d", expected.c_str(), expected.size() );
        //FORCE_DEBUG("actual = %s, size = %d", actual.c_str(), actual.size() );
        EXPECT_EQ(expected, string(actual) );
    }
}


///TEST_F(   TestGLocation , strings )
