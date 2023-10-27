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


#include "TestLGeneratorP.h"


#include <configurator/LGeneratorMacrosException.h>
#include <configurator/LGeneratorMacrosLogging.h>
#include <configurator/LGeneratorEnum.h>
#include <configurator/LGeneratorHashMap.h>
#include <configurator/LGeneratorLogTest.h>
#include <configurator/LFileCreator.h>
#include <configurator/LFileInfo.h>
#include <configurator/LXMLInfo.h>

#include <configurator/LXmlParser.h>


#include <utilities/GSystem.h>
#include <utilities/GFileIOHandler.h>


string  TestLGeneratorP::fgTestDataDir = "";
sysentity_vec    TestLGeneratorP::fgSubSystems;
logentity_vec  TestLGeneratorP::fgLogLevels;

using namespace CONFIGURATOR;

#define MINIMUM_EXPECTED_LINES 40



void TestLGeneratorP::SetUpTestCase()
{
#ifdef _WIN32
    /** @todo There must be a better way to do this */
    string s = string(EXPAND(LOGMASTER_HOME));
    s.erase(0,1);
    s.erase(s.size() -2 );
    fgTestDataDir = s +  string("reference-data\\");

#else
    /** @todo Implement for Linux */
    fgTestDataDir = string(LOGMASTER_HOME) + string("/configurator/unit-tests/commit/reference-data/");
    CERR << "fgTestDataDirXXXXXX = " << fgTestDataDir << ENDL; 
#endif
    /** @todo this parser should take LXMLInfoStruct as input*/
    LXmlParser( ).ParseXML( LXMLInfo(gXMLPath, gXSDPath), fgLogLevels, fgSubSystems);
}


void 
TestLGeneratorP::SetUp( )
{
    GetParam( ).fGenerator->GetFileInfo()->DisableSuffixes( );

};



/** Helper function to read reference data and to generate new data
* @tparam T The type of generator to use
* @param[in] filename_ref The filename of the reference test data
* @param[in,out] ref vector containing the reference data
* @param[in,out] gen vector containing the generated data that
* will be compared
 with the reference data */
void
TestLGeneratorP::GenerateData(const string filename_ref, std::shared_ptr<LGenerator> gen)
{
    string fname = fgTestDataDir + filename_ref;
    CERR << "fname = " << fname << ENDL;
    ASSERT_TRUE(g_system( )->exists(fname));
    fReferenceData = g_file( )->ReadAll(fname);
    LFileCreator::GenerateSingleFile(gen, fgLogLevels, fgSubSystems);
    fGeneratedData = g_file( )->ReadAll(".tmp");

}


INSTANTIATE_TEST_SUITE_P(
    Compare,
    TestLGeneratorP,
    ::testing::Values(
          TestParameters(std::make_shared<LGeneratorMacrosException>(".", "tmp", gXMLInfo), "GExceptionAutoGen.h", 30),
        TestParameters(std::make_shared<LGeneratorMacrosLogging>(".", "tmp", gXMLInfo), "LLogApiAutoGen.h", 30),
        TestParameters(std::make_shared<LGeneratorEnum>(".", "tmp", gXMLInfo), "LEnumAutoGen.h", 30),
        TestParameters(std::make_shared<LGeneratorHashMap>(".", "tmp", gXMLInfo), "LHashMapsAutoGen.cpp", 30),
        TestParameters(std::make_shared<LGeneratorLogTest>(".", "tmp", gXMLInfo), "LLogTestAutoGen.cpp", 30)));


TEST_P(TestLGeneratorP, exists_xml)
{
    CERR << "XML PATH =" <<  gXMLPath << ENDL;
    ASSERT_TRUE(g_system( )->exists(gXMLPath)) << gXMLPath;
}


TEST_P(TestLGeneratorP, exists_xsd)
{
    CERR << "XSD PATH =" <<  gXSDPath << ENDL;
    ASSERT_TRUE(g_system( )->exists(gXSDPath)) << gXSDPath;
}




/** Compare generated file content with reference data
* line by line. We accept typically 3 lines with errors.
* The time stamp, the location of the XML + XSD file. All the
* rest should be identical. 
* @param ref Reference data read from file
* @param gen The data generated by the test
* @param max_errors  The maximum number of lines that can differ.
* Default is 3 */
void 
TestLGeneratorP::Compare(const int max_errors)
{
   

    ASSERT_TRUE(fReferenceData.size( ) == fGeneratedData.size( ));
    ASSERT_TRUE(fReferenceData.size() > MINIMUM_EXPECTED_LINES);
    int n_eq = 0; // number of lines that is equal
    int n_neq = 0; // number of lines that are identical

    for ( size_t i = 0; i < fGeneratedData.size( ); i++ )
    {
        if ( fGeneratedData.at(i) == fReferenceData.at(i) ) {
            n_eq++;
        }
        else {
            n_neq++;
               CERR << fGeneratedData.at(i) << ENDL;
            CERR << fReferenceData.at(i) << ENDL;
            cout << endl;
        }
    }

    EXPECT_TRUE( n_neq <= max_errors) <<  n_neq;

};



TEST_P(TestLGeneratorP, Compare)
{
    auto t = GetParam( );
    GenerateData(t.fFileame, t.fGenerator);
    ASSERT_TRUE(fReferenceData.size( ) == fGeneratedData.size( ));
    ASSERT_TRUE(fReferenceData.size( ) > MINIMUM_EXPECTED_LINES);
    int n_eq = 0; // number of lines that is equal
    int n_neq = 0; // number of lines that are identical

    for ( size_t i = 0; i < fGeneratedData.size( ); i++ )
    {
        if ( fGeneratedData.at(i) == fReferenceData.at(i) ) {
            n_eq++;
        }
        else 
        {
            CERR << fGeneratedData.at(i) << ENDL;
            CERR << fReferenceData.at(i) << ENDL;
            cout << endl;
            n_neq++;
        }
    }
    
    EXPECT_TRUE(n_neq <= t.fMaxErrors ) << n_neq;
}



