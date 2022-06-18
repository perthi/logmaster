#pragma once


#include <testlib/TestBase.h>

class KFConfigurationHandler;

class TestAPICRing : public TestBase
{
public:
	static   void  SetUpTestCase();
	virtual  void  SetUp() override;
	virtual  void  TearDown() override;
	static KFConfigurationHandler *cfg;
};

