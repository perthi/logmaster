// -*- mode: c++ -*-

#pragma once

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

#include <testlib/TestBase.h>
#include <cmdline/GArgument.h>

class TestGArgument : public TestBase
{
public:
    TestGArgument();

protected:
    bool CallBackMember_true(const string cmd, const string, const vector<string> subs, const vector<string> pars);
    bool callbackMember_false(const string cmd, const string, const vector<string> subs, const vector<string> pars);
};

  
