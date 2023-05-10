// -*- mode: c++ -*-
#ifndef TESTGCRC_H
#define TESTGCRC_H
/***************************************************
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include <testlib/TestBase.h>


class  TestGLocation : public TestBase
{
	public:
		static void SetUpTestCase();
		static void TearDownTestCase();

		virtual void SetUp() override;
		virtual void TearDown() override;
};

#endif
