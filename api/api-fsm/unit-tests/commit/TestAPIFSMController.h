
#pragma once

#include <testlib/TestBase.h>

class APIFSMControllerDebug;

class TestAPIFSMController : public TestBase
{
public:
	static void SetUpTestCase();
	static void TearDownTestCase();

protected:
	static APIFSMControllerDebug *fController;

};
