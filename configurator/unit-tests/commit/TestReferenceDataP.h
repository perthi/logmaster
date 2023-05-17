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

using namespace CONFIGURATOR;

template<typename T>
struct ValuePair
{
	ValuePair(string s) : fFilename(s) {}
	string fFilename = "";
	T fGenerator;
};

//class  TestReferenceDataP : public TestBase, public testing::TestWithParam<string>
class  TestReferenceDataP : public testing::TestWithParam<string>
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();

	void SetUp() override;


protected:
	static string fTestDataDir;

};


