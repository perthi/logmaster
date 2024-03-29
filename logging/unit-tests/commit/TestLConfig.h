// -*- mode: c++ -*-

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#pragma once

#include <testlib/TestBase.h>
#include <logging/LConfig.h>

using namespace LOGMASTER;


class TestLConfig  : public TestBase
{
public:
    virtual void SetUp();
    virtual void TearDown();

protected:
    vector<eMSGTARGET>   t_v  =  vector<eMSGTARGET>();
    vector<eMSGSYSTEM>   s_v  =  vector<eMSGSYSTEM>();
    vector<eLOGLEVEL>    l_v =   vector<eLOGLEVEL>();
    LConfig *fConfig = nullptr;
};

