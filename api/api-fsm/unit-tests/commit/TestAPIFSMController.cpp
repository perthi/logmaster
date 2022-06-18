
#include "TestAPIFSMController.h"
#include <api/api-fsm/APIFSMControllerDebug.h>
#include <common/FSMNode.h>
#include <utilities/GException.h>


APIFSMControllerDebug *   TestAPIFSMController::fController = nullptr;


void 
TestAPIFSMController::SetUpTestCase()
{
	PUSH();
	SET_LOGTARGET("--target-off --target-file");
	fController = APIFSMControllerDebug::Instance();

	try
	{
		fController->GenerateMockFSM();
	}
	catch (GException &e)
	{
		cout << e.what() << endl;
		exit(-1);
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
		exit(-1);
	}
	catch (...)
	{
		FORCE_DEBUG("Unknown exception caught");
		exit(-1);
	}
	POP();
}


void 
TestAPIFSMController::TearDownTestCase()
{

}



TEST_F(TestAPIFSMController, fsm_node_check)
{
 	EXPECT_EQ(nullptr, fController->GetFSM("nonexisting"));
	EXPECT_NE(nullptr, fController->GetFSM("MAIN_FSM"));
	EXPECT_NE(nullptr, fController->GetFSM("ENVIRONMENT"));
}


