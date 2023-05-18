// -*- mode: c++ -*-

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#pragma once

#include <testlib/TestBase.h>
#include <configurator/LGenerator.h>
#include <configurator/LXMLInfo.h>
#include <configurator/LFileCreator.h>

#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>
#include <utilities/GRandom.h>

using namespace CONFIGURATOR;

#include <memory>

#include <vector>
using std::vector;


class  TestReferenceData : public TestBase
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();

	//void SetUp() override;


protected:
    template<typename T>
    void GenerateData(const string filename_ref );
    void Compare(const int max_errors = 3);
    vector<string> fReferenceData;
    vector<string> fGeneratedData;

	static string fTestDataDir;
    static string fXMLPath;
    static string fXSDPath;
    static std::shared_ptr<LXMLInfo> fXMLInfo;
    static sysentity_vec  fSubSystems;
    static logentity_vec  fLogLevels;

};



/** Helper function to read reference data and to generate new data
* @tparam T The type of generator to use
* @param[in] filename_ref The filename of the reference test data
* @param[in,out] ref vector containing the reference data
* @param[in,out] gen vector containing the generated data that
* will be compared
 with the reference data */
template<typename T>
void 
TestReferenceData::GenerateData(const string filename_ref)
{

    string fname = fTestDataDir + filename_ref;
   // CERR << "fname = " << fname << ENDL;
    ASSERT_TRUE(g_system( )->Exists(fname));
    fReferenceData  = g_file( )->ReadAll(fname);
    auto g = std::make_shared<T>("", "tmp.txt", *fXMLInfo);
    LFileCreator::GenerateSingleFile(g, fLogLevels, fSubSystems);
    fGeneratedData = g_file( )->ReadAll("tmp.txt");
    g_system( )->rm("tmp.txt");
}

