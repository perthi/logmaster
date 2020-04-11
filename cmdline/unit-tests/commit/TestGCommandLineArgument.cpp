// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no>  http:///www.embc.no ***
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

#include "TestGCommandLineArgument.h"
#include <utilities/GNumbers.h>
#include <cmdline/GCmdApi.h>
#include <cmdline/GCmdScan.h>

#include <typeinfo>
#include <functional>
using std::function;
using std::bind;

#include <exception/GException.h>


using namespace std::placeholders;

TestGCommandLineArgument::TestGCommandLineArgument() : TestBase() 
{
	std::function< bool( const string , const string ) >    
    testFunc(std::bind(&TestGCommandLineArgument::ValidateFunct2, this, _1, _2 ));
}


TestGCommandLineArgument::~TestGCommandLineArgument()
{

}


void TestGCommandLineArgument::SetUp()
{
 ////  SET_LOGTARGET(eMSGTARGET::TARGET_OFF);
  
	SET_LOGTARGET("0000");
   g->AddArgument(farg);
   g->AddArgument(darg);
   g->AddArgument(ldarg);    
   g->AddArgument(iarg);
   g->AddArgument(liarg);
   g->AddArgument(lliarg);
   g->AddArgument(siarg);
   g->AddArgument(usarg);
   g->AddArgument(uiarg);
   g->AddArgument(uliarg);
   g->AddArgument(ulliarg);
   g->AddArgument(barg);
   g->AddArgument(sarg);
   g->AddArgument(varg);
   g->AddArgument(vsarg);
   g->AddArgument(viarg);
   g->AddArgument(vuiarg);
   g->AddArgument(vdarg);
   g->AddArgument(vldarg);
   g->AddArgument(vfarg);
  
}



void 
TestGCommandLineArgument::TearDown()
{

}


 bool 
 TestGCommandLineArgument::ValidateFunct(  const string /*cmnd*/, const string /*args_s*/, 
                                           const vector<string> /*subs*/, const vector<string> args)
 {
     /*We just make up some artificial conditions*/
     int min = 10;
     int number = -99;
 
     if (args.size() > 0)
     {
         number = g_numbers()->ToInteger<int>(args[0]);
     }
 
     if (number >= min && number <= 100)
     {
         return true;
     }
     else
     { 
         EXCEPTION("number is out of range (%d)", number);
         return false; // not necessary, but just in case previous line is commented out
     }
 
 }
 
 
 
 TEST_F(TestGCommandLineArgument, simpleArgs)
 {
 //	LLogging::Instance()->SetLogTarget("--target-all");
//	 SET_LOGFORMAT("1111111");
 	
// 	try
 //	{    
 		g->ScanArguments("-myint 10");
 		
		EXPECT_EQ(i, 10);
        g->ScanArguments("-mydouble 1.2345");
 		EXPECT_DOUBLE_EQ(d, 1.2345);
 		g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846  -mystring  \"hello world\"");
 		EXPECT_EQ(i, 42);
 		EXPECT_DOUBLE_EQ(d, 3.14159265358979323846);
 		g->ScanArguments("-myfloat 3.14");
 		EXPECT_FLOAT_EQ(f, (float)3.14);
 		EXPECT_NO_THROW(  g->ScanArguments("-myvoid"));
 		EXPECT_ANY_THROW( g->ScanArguments("-myvoid  gibberish --blahh --blahh2"));
 		EXPECT_ANY_THROW( g->ScanArguments("-myint 10.123"));  // we expect an exeption since we give float argument to an int parameter
 
 		g->ScanArguments("-mylint 1234546");
 		EXPECT_EQ(li, 1234546);
       
 		g->ScanArguments("-mysint 1234");
 		EXPECT_EQ(si, 1234);
 
 		g->ScanArguments("-myldouble  3.14159265358979");
 		EXPECT_DOUBLE_EQ(ld, 3.14159265358979);
 		g->ScanArguments("-myldouble  42");
 		EXPECT_DOUBLE_EQ(ld, 42);
 		g->ScanArguments("-myldouble  -42");
 		EXPECT_DOUBLE_EQ(ld, -42);
 
 		g->ScanArguments("-myllint 1234567891011121");
 		EXPECT_EQ(lli, 1234567891011121);
 		g->ScanArguments("-myllint -1234567891011121");
 		EXPECT_EQ(lli, -1234567891011121);
 
 		g->ScanArguments("-myulint 999222333");
 		EXPECT_EQ(uli, 999222333);
 		EXPECT_ANY_THROW(g->ScanArguments("-myulint -999222333"));
 
 		g->ScanArguments("-myullint 111222333");
 		EXPECT_EQ(ulli, 111222333);
 		EXPECT_ANY_THROW(g->ScanArguments("-myullint -111222333"));
        
    //  }
 	// catch(GException &e){
 
 		
    //      cerr << e.what() << endl;
 	// 	throw;
 	// }
 
    
 }
 
 
 
 TEST_F(TestGCommandLineArgument, stringArg)
 {
     g->ScanArguments("-mystring  teststring");
     EXPECT_EQ(s, "teststring");
     s.clear();
     g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846  -mystring  \"hello world\"");
     EXPECT_EQ(s, "hello world");
 }
 
 
 TEST_F(TestGCommandLineArgument, excpetions)
 {
     EXPECT_ANY_THROW(g->ScanArguments("-gibberish"));
     EXPECT_ANY_THROW(g->ScanArguments("--gibberish"));
     EXPECT_ANY_THROW(g->ScanArguments("blahhhhh"));
     EXPECT_ANY_THROW(g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846  -mystring  \"hello world\"  -gibberish"));
 
 
     //The following 3 test cases should also throw an exeption, while actually they dont
     //See bug report  NSR-168 
     EXPECT_ANY_THROW(g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846   -mystring  \"hello world\"  gibberish"));
     EXPECT_ANY_THROW(g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846    gibberish"));
     EXPECT_ANY_THROW(g->ScanArguments("-myint 42 -mydouble 3.14159265358979323846  --gibberish"));
 }
 
 
 
 TEST_F(TestGCommandLineArgument, vectorStringArgs)
 {
 
     g->ScanArguments("-myvector alpha beta gamma");
     EXPECT_EQ(3, vs.size());
     if (vs.size() == 3)
     {
         ASSERT_EQ(vs[0], "alpha");
         EXPECT_EQ(vs[1], "beta");
         EXPECT_EQ(vs[2], "gamma");
     }
 }
 
 
 
TEST_F(TestGCommandLineArgument, boolArgs)
{
	//Testing for bug NSR-168
	g->ScanArguments("-mybool");
	EXPECT_EQ(b, true);
	// Testing for bug NSR-168 and NSR-169
	 EXPECT_NO_THROW(g->ScanArguments("-mybool --true"));
	EXPECT_ANY_THROW(g->ScanArguments("-mybool --false --gibberish"));
	EXPECT_ANY_THROW(g->ScanArguments("-mybool -alpha beta gamma"));
 
	 //* Now we try with a validation function. We use a default validation function for 
	// * boolean argumenst which takes --true and --false as subcommands 
	barg->SetValidationFunction(GCmdApi::bool2);
	g->ScanArguments("-mybool");
	EXPECT_EQ(b, true);
	g->ScanArguments("-mybool --true");
	EXPECT_EQ(b, true);
	g->ScanArguments("-mybool --false");
	EXPECT_EQ(b, false);
	EXPECT_ANY_THROW(g->ScanArguments("-mybool --true gibberish"));
	EXPECT_ANY_THROW(g->ScanArguments("-mybool --false --gibberish"));
	EXPECT_ANY_THROW(g->ScanArguments("-mybool -alpha beta gamm"));
}


TEST_F(TestGCommandLineArgument, mandatoryArgs)
{
    try
    {

    // Adding a mandatory argument to the argument list
    std::shared_ptr<GCommandLineArgument <double> > mdarg =  std::make_shared < GCommandLineArgument <double> >("-mandatory", "-andatory [value]", "This is the documentation", &d, fgkMANDATORY, nullptr);
    g->AddArgument(mdarg);
    ///-myint is  valdi argument, but since -mandatory is missing, we shall still get an exception 
    EXPECT_ANY_THROW(g->ScanArguments("-myint 20"));
    
    g->RemoveArgument( "-myint 30" );
    // fArgs.pop_back(); // now we remove mandatory argument that was last added, then it should work
    g->ScanArguments("-myint 30");
    EXPECT_EQ(i, 30);
    }
    catch( GException &e )
    {
        CERR << e.what() << endl;
    }
    catch(const std::exception& e)
    {
        CERR << e.what() <<  endl;
    }
    catch(...)
    {
        CERR << "UNKNOWN exception caught" << endl;
    }
    
}




TEST_F(TestGCommandLineArgument, validationFunction)
{
    i = -1;
    g->ScanArguments("-myint 30");
    EXPECT_EQ(i, 30);
	std::function< bool( const string cmd, const string args_s, const vector<string> sub, const vector<string> par) >    
	testFunc(std::bind(&TestGCommandLineArgument::ValidateFunct, this, _1, _2, _3, _4 ));
	iarg->SetValidationFunction(testFunc);

    i = -2;
    g->ScanArguments("-myint 33");
    EXPECT_EQ(i, 33);
    g->ScanArguments("-myint 100");
    EXPECT_EQ(i, 100);
    EXPECT_ANY_THROW(g->ScanArguments("-myint 101")); // just above limit
}


TEST_F(TestGCommandLineArgument, vectorIntArgs)
{
    g->ScanArguments("-myivector 11 22 33 0X10 0xabcd 0xabcdef");
	//std::vector test;
    EXPECT_EQ(vi.size(), 6);
   
    if (vi.size() == 6)
    {
        EXPECT_EQ(vi[0], 11);
        EXPECT_EQ(vi[1], 22);
        EXPECT_EQ(vi[2], 33);
        EXPECT_EQ(vi[3], 16);
        EXPECT_EQ(vi[4], 43981);
        EXPECT_EQ(vi[5], 11259375);
    }

    EXPECT_ANY_THROW(g->ScanArguments("-myivector gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myivector 1 2 3 4 5 gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myivector 1 2 3 gibbersih  3 4 5"));
    EXPECT_ANY_THROW(g->ScanArguments("-myivector 3.14"));
}



TEST_F(TestGCommandLineArgument, vectorDoubleArgs)
{
    g->ScanArguments("-mydvector 11 22 33");

    EXPECT_EQ(vd.size(), 3);

    if (vd.size() == 3)
    {
        EXPECT_EQ(vd[0], 11);
        EXPECT_EQ(vd[1], 22);
        EXPECT_EQ(vd[2], 33);
    }

    vd.clear();

    g->ScanArguments("-mydvector 3.14159265358979323846   1.61803399  -1.61803399  42");
    EXPECT_EQ(vd.size(), 4);
    
    if (vd.size() == 4)
    {
        EXPECT_DOUBLE_EQ(vd[0], 3.14159265358979323846);
        EXPECT_DOUBLE_EQ(vd[1], 1.61803399);
        EXPECT_DOUBLE_EQ(vd[2], -1.61803399);
        EXPECT_DOUBLE_EQ(vd[3], 42);
    }

    EXPECT_ANY_THROW(g->ScanArguments("-mydvector gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-mydvector 1.1 2.2 3 4 5 gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-mydvector 1 2 3.3 gibbersih  3 4 5"));
}


TEST_F(TestGCommandLineArgument, vectorLongDoubleArgs)
{
    g->ScanArguments("-myldvector 11 22 33");

    EXPECT_EQ(vld.size(), 3);

    if (vld.size() == 3)
    {
        EXPECT_EQ(vld[0], 11);
        EXPECT_EQ(vld[1], 22);
        EXPECT_EQ(vld[2], 33);
    }

    vld.clear();

    g->ScanArguments("-myldvector 3.14159265358979323846   1.61803399  -1.61803399  42");
    EXPECT_EQ(vld.size(), 4);

    if (vld.size() == 4)
    {
        EXPECT_DOUBLE_EQ(vld[0], 3.14159265358979323846);
        EXPECT_DOUBLE_EQ(vld[1], 1.61803399);
        EXPECT_DOUBLE_EQ(vld[2], -1.61803399);
        EXPECT_DOUBLE_EQ(vld[3], 42);
    }

   // g->ScanArguments("-myldvector gibbersih");

    EXPECT_ANY_THROW(g->ScanArguments("-myldvector gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myldvector 1.1 2.2 3 4 5 gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myldvector 1 2 3.3 gibbersih  3 4 5"));
}



TEST_F(TestGCommandLineArgument, vectorFloatArgs)
{
    g->ScanArguments("-myfvector 11 22 33");
    EXPECT_EQ(vf.size(), 3);

    if (vd.size() == 3)
    {
        EXPECT_EQ(vf[0], 11);
        EXPECT_EQ(vf[1], 22);
        EXPECT_EQ(vf[2], 33);
    }

    vf.clear();

    g->ScanArguments("-myfvector 3.14159265358979323846   1.61803399  -1.61803399");
    EXPECT_EQ(vf.size(), 3);

    if (vf.size() == 3)
    {
        EXPECT_NE(vf[0], 3.14159265358979323846);
        EXPECT_NE(vf[1], 1.61803399);
        EXPECT_NE(vf[2], -1.61803399);
    }

    vf.clear();
    g->ScanArguments("-myfvector 3.14159265358979323846   1.61803399  -1.61803399");
    EXPECT_EQ(vf.size(), 3);

    if (vf.size() == 3)
    {
        // With floating point numbers we only get 5 digits precision after the decimal point
        EXPECT_FLOAT_EQ(vf[0], (float)3.1415927);
        EXPECT_FLOAT_EQ(vf[1], (float)1.618034);
        EXPECT_FLOAT_EQ(vf[2], (float)-1.618034);
    }

    vf.clear();

    EXPECT_ANY_THROW(g->ScanArguments("-myfvector gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myfvector 1.1 2.2 3 4 5 gibbersih"));
    EXPECT_ANY_THROW(g->ScanArguments("-myfvector 1 2 3.3 gibbersih  3 4 5"));
}


TEST_F(TestGCommandLineArgument, vectorUnsigned)
{
    g->ScanArguments("-myuivector  11 22  0X10 0xabcd 0xabcdef 88");
 
    EXPECT_EQ(vui.size(), 6);

    if (vui.size() == 6)
    {
        EXPECT_EQ(vui[0], 11);
        EXPECT_EQ(vui[1], 22);
        EXPECT_EQ(vui[2], 0x10);
        EXPECT_EQ(vui[3], 43981);
        EXPECT_EQ(vui[4], 11259375);
        EXPECT_EQ(vui[5], 88);
    }

    vui.clear();
    EXPECT_ANY_THROW(g->ScanArguments("-myuivector -100 -33 -445")   );
    EXPECT_ANY_THROW(g->ScanArguments("-myuivector gibbersih"));
    vui.clear();
    EXPECT_ANY_THROW(g->ScanArguments("-myuivector 1 2 3 4 5 gibbersih"));
    vui.clear();
    EXPECT_ANY_THROW(g->ScanArguments("-myuivector 1 2 3 gibbersih  3 4 5"));
    vui.clear();
    EXPECT_ANY_THROW(g->ScanArguments("-myuivector 3.14"));
   }


TEST_F(TestGCommandLineArgument, unsignedInt)
{
    g->ScanArguments("-myuint 666");
    EXPECT_EQ(ui, 666);
    EXPECT_ANY_THROW(g->ScanArguments("-myuint -666"); );
    g->ScanArguments("-myusint 123");
    EXPECT_EQ(us, 123);
    EXPECT_ANY_THROW(g->ScanArguments("-myusint -123"));
}


// TEST_F(TestGCommandLineArgument,  duplicatesNSR247)
// {
//     g->AddArgument( farg );
//      g->AddArgument( farg );
//     ////fArgs.push_back(farg); // Duplicate comman that was allready added in the Setup method
//     EXPECT_ANY_THROW ( g->ScanArguments("") );
//  }
 


TEST_F(TestGCommandLineArgument, simpleconstructorNSR216)
{
    int i = 0;
    double f = 0;

    struct Test_t : public Val_t <double >
    {
        Test_t(double n = 0) : Val_t<double>::Val_t(n, -100, 100) {};
        virtual   Test_t & operator = (const Val_t rhs)
        {
            SetValue(rhs.GetValue());
            return *this;
        }
    };
    
    Test_t *t = new  Test_t();
    std::shared_ptr<GCommandLineArgument<int>  >  a  =     std::make_shared < GCommandLineArgument<int> >("-ival", &i);
    std::shared_ptr<  GCommandLineArgument<double> > b  =     std::make_shared < GCommandLineArgument<double> >("-fval", &f);
     std::shared_ptr< GCommandLineArgument<Val_t<double> > > c =    std::make_shared < GCommandLineArgument<Val_t<double> > >("-dummy", t);

    g->ScanArguments("-ival 33", a);
    g->ScanArguments("-fval 2.71828182845", b);
    g->ScanArguments("-dummy 27.1828182845", c);
    EXPECT_EQ(33, i);
    EXPECT_DOUBLE_EQ(2.71828182845, f);
	EXPECT_DOUBLE_EQ(27.1828182845, t->GetValue() );
	EXPECT_ANY_THROW(g->ScanArguments("-dummxxy 200", c ) );

    // delete a;
    // delete b;
    delete t;
 
  }



 TEST_F(TestGCommandLineArgument, stringscanBugNSR808)
 {
     string test;
     
   //  SET_LOGFORMAT("1111111");
 
     std::shared_ptr<GCommandLineArgument<string> > s = std::make_shared< GCommandLineArgument<string> >("-mystring", &test);
     
     
     try
     {
         g->ScanArguments("-mystring \"hello world\"", s);
     }
     catch (GException &e)
     {
         cout << e.what() << endl;
     }
     
     EXPECT_EQ(test, "hello world");
 
     try
     {
         g->ScanArguments("-mystring \"lorem ipsum\"", s);
     }
     catch (GException &e)
     {
         cout << e.what() << endl;
     }
 
     EXPECT_EQ(test, "lorem ipsum");
 }
 
 