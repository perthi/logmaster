// -*- mode: c++ -*-

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#pragma once

#include "TestLogging.h"



class TestSubscriber : public TestLogging
{

protected:
    virtual void SetUp();
    virtual void TearDown();

    static void  Subscriber1( const std::shared_ptr<LMessage> msg );
    static void  Subscriber2( const std::shared_ptr<LMessage> msg );
   
	static std::shared_ptr<LMessage> fMsg1;
	static std::shared_ptr<LMessage> fMsg2;

};




