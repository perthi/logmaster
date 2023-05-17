// -*- mode: c++ -*-

/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

/* ****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
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


#include "TestReferenceDataP.h"
#include  <configurator/LGeneratorMacrosLogging.h>

#include <utilities/GDefinitions.h>

#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>

#include <configurator/LGeneratorEnum.h>
#include <configurator/LGeneratorHashMap.h>
#include <configurator/LGeneratorLogTest.h>
#include <configurator/LGeneratorMacrosException.h>
#include <configurator/LGeneratorMacrosLogging.h>

string  TestReferenceDataP::fTestDataDir = "";

using namespace CONFIGURATOR;

/*
#ifdef _WIN32
string s = EXPAND(LOGMASTER_HOME);
s.erase(0, 1);
s.erase(s.size() - 2);
fgDatabaseBasePath = s + "\\test-data\\logmaster-test.db";
#else
fgDatabaseBasePath = LOGMASTER_HOME + string("/logging/unit-tests/commit/test-data/logmaster-test.db");
*/


void TestReferenceDataP::SetUpTestCase()
{
#ifdef _WIN32
	/** @todo There must be a better way to do this */
	string s = string(EXPAND(LOGMASTER_HOME));
	s.erase(0,1);
	s.erase(s.size() -2 );
	fTestDataDir = s +  string("reference-data\\");
#else
	/** @todo Implement for Linux */
#endif

	//xsd = string(g_system()->GetHomeDir()) + "\\..\\config\\logging.xsd";
	CERR << "testdir = " << fTestDataDir << ENDL;
}

void TestReferenceDataP::TearDownTestCase()
{
	CERR << "TEARDOWN" << ENDL;
}

void TestReferenceDataP::SetUp()
{
	string testdir = string(EXPAND(LOGMASTER_HOME)) + string("\\reference-data\\");
}

auto v1 = ValuePair<LGeneratorMacrosException>("GExceptionAutoGen.h");
//auto v2 = ValuePair< LGeneratorEnum>(string("LEnumAutoGen.h"));


INSTANTIATE_TEST_CASE_P(
	test,
	TestReferenceDataP, ::testing::Values(v1));


/*
INSTANTIATE_TEST_CASE_P(
	test,
	TestReferenceDataP,::testing::Values( ValuePair<LGeneratorMacrosException>("GExceptionAutoGen.h"),
		                                  ValuePair< LGeneratorEnum>("LEnumAutoGen.h"),
		                                  ValuePair<LGeneratorHashMap>("LHashMapsAutoGen.cpp"),
		                                  ValuePair<LGeneratorMacrosLogging>("LLogApiAutoGen.h"),
		                                  ValuePair<LGeneratorLogTest>"LLogTestAutoGen.cpp"));
*/

TEST_P(TestReferenceDataP, exists)
{
	
	string filepath = fTestDataDir + this->GetParam();
	//string filepath = "";

	CERR << "FILE = " << filepath << ENDL;
	CERR << " fTestDataDir = " << fTestDataDir << ENDL;;

    ASSERT_TRUE(g_system()->Exists(filepath));

	//g_file()->CheckFile("blahhhh", "r");

	//FAIL();
}