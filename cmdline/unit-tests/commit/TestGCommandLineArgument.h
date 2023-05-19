// -*- mode: c++ -*-

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

#pragma once


#include <testlib/TestBase.h>
#include <cmdline/GCommandLineArgument.h>
#include <utilities/GConstants.h>

#include <functional>
using std::function;


using namespace GCONSTANTS;

class TestGCommandLineArgument : public TestBase
{
public:
    TestGCommandLineArgument();
    virtual ~TestGCommandLineArgument();
    virtual void SetUp();
    virtual void TearDown();
    virtual bool ValidateFunct(const string cmnd, const string args_s, const vector<string> subs, const vector<string> args);
	bool ValidateFunct2( const string /*cmnd*/, const string /*args_s*/ ) { return false;}

protected:
	float f = 0;
    double d = 0;
    long double ld = 0;
    short si = 0;
    int i = 0;
    long int li = 0;
    long long int lli = 0;
    unsigned short us = 0;
    unsigned int ui = 0;
    unsigned long int uli = 0;
    unsigned long long int ulli = 0;
    bool b = false;
    string s = "";
    vector<string> vs =   vector<string>();
    vector<int>  vi = vector<int>();
    vector<unsigned int>  vui =  vector<unsigned int>();
    vector<double> vd =  vector<double>() ;
    vector<long double> vld = vector<long double>();
    vector<float> vf =  vector<float>();

    std::shared_ptr < GCommandLineArgument <float> > farg =   std::make_shared <GCommandLineArgument<float> >("-myfloat", "-myfloat [value]", "This is the documentation", &f, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <double> > darg =   std::make_shared <GCommandLineArgument <double> >("-mydouble", "-mydouble [value]", "This is the documentation", &d, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <long double>  > ldarg =   std::make_shared <GCommandLineArgument <long double> >("-myldouble", "-myldouble [value]", "This is the documentation", &ld, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <short> > siarg =   std::make_shared <GCommandLineArgument <short> > ("-mysint", "-mysint [value]", "This is the documentation", &si, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <int> > iarg =   std::make_shared <GCommandLineArgument <int > >("-myint", "-myint [value]", "This is the documentation", &i, fgkOPTIONAL, nullptr );
	std::shared_ptr < GCommandLineArgument <long int> > liarg =   std::make_shared <GCommandLineArgument <long int> > ("-mylint", "-mylint [value]", "This is the documentation", &li, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <long long int> > lliarg =   std::make_shared <GCommandLineArgument <long long int> >("-myllint", "-myllint [value]", "This is the documentation", &lli, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <unsigned short> > usarg =   std::make_shared <GCommandLineArgument <unsigned short> >("-myusint", "-myusint [value]", "This is the documentation", &us, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <unsigned int> > uiarg =   std::make_shared <GCommandLineArgument <unsigned int> > ("-myuint", "-myuint [value]", "This is the documentation", &ui, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <unsigned long int> > uliarg =   std::make_shared <GCommandLineArgument <unsigned long int> > ("-myulint", "-myulint [value]", "This is the documentation", &uli, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <unsigned long long int> > ulliarg =   std::make_shared <GCommandLineArgument <unsigned long long int> >("-myullint", "-myullint [value]", "This is the documentation", &ulli, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <bool> > barg =   std::make_shared <GCommandLineArgument <bool> >("-mybool", "-mybool [value]", "This is the documentation", &b, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <void> > varg =   std::make_shared <GCommandLineArgument <void> >("-myvoid", "-myvoid [value]", "This is the documentation", nullptr, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <string> > sarg =   std::make_shared <GCommandLineArgument <string> >("-mystring", "-mystring [value]", "This is the documentation", &s, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<string> > >vsarg =   std::make_shared <GCommandLineArgument <vector<string> > >("-myvector", "-myvector [value1] [value2].... [valueN]", "This is the documentation", &vs, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<int> >  > viarg  =   std::make_shared <GCommandLineArgument <vector<int> > >("-myivector", "-myivector [value1] [value2].... [valueN]", "This is the documentation", &vi, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<unsigned int> >>    vuiarg =   std::make_shared <GCommandLineArgument <vector<unsigned int> > >("-myuivector", "-myuivector [value1] [value2].... [valueN]", "This is the documentation", &vui, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<double> > > vdarg  =   std::make_shared <GCommandLineArgument <vector<double> > >("-mydvector", "-mydvector [value1] [value2].... [valueN]", "This is the documentation", &vd, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<long double> > > vldarg =   std::make_shared <GCommandLineArgument <vector<long double> > >("-myldvector", "-myldvector [value1] [value2].... [valueN]", "This is the documentation", &vld, fgkOPTIONAL, nullptr);
    std::shared_ptr < GCommandLineArgument <vector<float> > > vfarg =   std::make_shared <GCommandLineArgument <vector<float> > >("-myfvector", "-myfvector [value1] [value2].... [valueN]", "This is the documentation", &vf, fgkOPTIONAL, nullptr);
  
    };

  



#if GTEST_HAS_TYPED_TEST

using testing::Types;

/** @todo move to separate file(s) */
TYPED_TEST_CASE_P(TestGCommandLineArgumentT);


template <typename T>
class  TestGCommandLineArgumentT : public  TestBase
{
public:
    //TestDataTypesT() ;
    virtual void SetUp() override 
    {
       fArg1 = std::make_shared< GCommandLineArgument<T> >("-myarg", nullptr);
       fArg2 = std::make_shared< GCommandLineArgument<T> >("-myarg", nullptr);
    };

protected:
    std::shared_ptr<GCommandLineArgument<T> >  fArg1 = nullptr;
    std::shared_ptr<GCommandLineArgument<T> >  fArg2 = nullptr;

  //  T first;
  //  T second;

};


typedef Types< string, int, long, unsigned long, short,  double, float, char, Val_t<int> > impl;

//using Types = testing::Types<int, long long, std::size_t>;



TYPED_TEST_P(TestGCommandLineArgumentT, duplicate_arguemnts)
{
    GLogApplication a;
    EXPECT_ANY_THROW(a.AddArgument( this->fArg1).AddArgument( this->fArg2)); // Default behavior is exception if arguments with same tag is added
    ASSERT_TRUE(a.GetArguments().size() > 0);
    a.Purge(); // Removing all argumenst, sixe should be 0
    ASSERT_TRUE(a.GetArguments().size() == 0);

    EXPECT_ANY_THROW(a.AddArgument(this->fArg1).AddArgument( this->fArg2, eDUPLICATE_STRATEGY::THROW_EXEPTION));
    EXPECT_NO_THROW(a.AddArgument(this->fArg1, eDUPLICATE_STRATEGY::IGNORE_DUPLICATE));
    EXPECT_NO_THROW(a.AddArgument(this->fArg1, eDUPLICATE_STRATEGY::REPLACE_DUPLICATE));
}


TYPED_TEST_P(TestGCommandLineArgumentT, duplicate_arguemnts_replace)
{
    GLogApplication a;
    
    ASSERT_NO_THROW(a.AddArgument( this->fArg1));
    uint64_t address1 = (uint64_t)a.GetArgument("-myarg").get();
    ASSERT_NO_THROW(a.AddArgument( this->fArg2, eDUPLICATE_STRATEGY::IGNORE_DUPLICATE));
  
    uint64_t address2 = (uint64_t)a.GetArgument("-myarg").get();
    EXPECT_EQ(address1, address2);
    
    
    ASSERT_NO_THROW(a.AddArgument( this->fArg2, eDUPLICATE_STRATEGY::REPLACE_DUPLICATE));
    address2 = (uint64_t)a.GetArgument("-myarg").get();
    EXPECT_NE(address1, address2); // argument should be replaced, so the pointer address must differ   
  }


REGISTER_TYPED_TEST_CASE_P(TestGCommandLineArgumentT, duplicate_arguemnts, duplicate_arguemnts_replace );
INSTANTIATE_TYPED_TEST_CASE_P(pth2, TestGCommandLineArgumentT, impl);
INSTANTIATE_TYPED_TEST_CASE_P(pth1, TestGCommandLineArgumentT, impl);


#endif
