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

#define HAS_LOGGING

#include <testlib/TestBase.h>
#include <cmdline/GCommandLineArgument.h>
#include <utilities/GConstants.h>

#include <functional>
using std::function;


bool test(const string cmnd, const vector<string> sub, const vector<string> par)
{
    cerr << "hello world" << endl;
    return true;
}


using namespace GCONSTANTS;

class TestGCommandLineArgument : public TestBase
{
public:
    TestGCommandLineArgument();
    virtual ~TestGCommandLineArgument();
    virtual void SetUp();
    virtual void TearDown();
    
//	static bool ValidateFunct(const string cmnd, const string args_s, const vector<string> subs, const vector<string> args);
    virtual bool ValidateFunct(const string cmnd, const string args_s, const vector<string> subs, const vector<string> args);
	bool ValidateFunct2( const string /*cmnd*/, const string /*args_s*/ )
	{
		return false;
	}


	float f;
    double d = 0;
    long double ld = 0;
    short si = 0;
    int i = 0;
    long int li = 0;
    long long int lli = 0;

    unsigned short us;
    unsigned int ui = 0;
    unsigned long int uli = 0;
    unsigned long long int ulli = 0;
    bool b = false;
    string s = "";
    vector<string> vs;
    vector<int>  vi;
    vector<unsigned int>  vui;
    vector<double> vd;
    vector<long double> vld;
    vector<float> vf;

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

  
