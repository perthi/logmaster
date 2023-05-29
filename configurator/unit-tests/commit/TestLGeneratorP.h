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

using namespace CONFIGURATOR;

#include <memory>

#include <vector>
using std::vector;


string gXMLPath = "C:\\work\\logmaster\\config\\logging.xml";
string gXSDPath = "C:\\work\\logmaster\\config\\logging.xsd";

LXMLInfo gXMLInfo(gXMLPath, gXSDPath);


struct TestParameters
{
    TestParameters(std::shared_ptr<LGenerator> gen, string fname, int max_errors) : fGenerator(gen), fFileame(fname), fMaxErrors(max_errors) { }
    std::shared_ptr<LGenerator> fGenerator = nullptr;
    string fFileame = "";
    int fMaxErrors = 0;
};



class  TestLGeneratorP : public ::testing::WithParamInterface<  TestParameters >, public TestBase
{
public:
    static  void  SetUpTestCase();
    virtual void  SetUp( ) override;

protected:
    void GenerateData(const string filename_ref, std::shared_ptr<LGenerator> g);
    void Compare(const int max_errors = 3);

   // string fTestFileName = "tmp.h";

    vector<string> fReferenceData;
    vector<string> fGeneratedData;

    string fTestFileName = "tmp.h"; //<! Filename where temporary test data will be stored
    static string fgTestDataDir;  //<!
    static sysentity_vec  fgSubSystems;
    static logentity_vec  fgLogLevels;

};





