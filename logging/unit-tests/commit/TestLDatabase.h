// -*- mode: c++ -*-
#ifndef TESTLDATABASE_H
#define TESTLDATABASE_H
/**************************************************************************
 * This file is property of and copyright by Embedded Cosnulting  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/


#include <testlib/TestBase.h>

namespace LOGMASTER
{
	class LDatabase;
}

class  TestLDatabase : public TestBase
{
	public:
		TestLDatabase();
		virtual ~TestLDatabase();
		static void SetUpTestCase();
		static void TearDownTestCase();
		
		virtual void SetUp() override;
		virtual void TearDown() override;

	protected:	
		static  LDatabase * fgDatabase;
};

#endif
