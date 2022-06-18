// -*- mode: c++ -*-

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "APIFSMControllerDebug.h"
#include  <thread>
#include  <logging/LLogApi.h>
#include  <utilities/GException.h>

using namespace LOGMASTER;
bool  APIFSMControllerDebug::fDoRun = true;


APIFSMControllerDebug  *
APIFSMControllerDebug::Instance()
{
	if (fgInstance == nullptr)
	{
		fgInstance = new APIFSMControllerDebug();
	}

	APIFSMControllerDebug *tmp = dynamic_cast<APIFSMControllerDebug *>(fgInstance);
	G_ASSERT_EXCEPTION(tmp != nullptr, "Pointer to Debug controller is ZERO !!");

	return tmp;
}


void
APIFSMControllerDebug::StartRun()
{
	FSM_INFO("Recieved START_RUN");
	fDoRun = true;
}


void
APIFSMControllerDebug::StopRun()
{
	FSM_INFO("Recieved STOP_RUN");
	fDoRun = false;
}


void
APIFSMControllerDebug::Run()
{
	std::thread t1(fsm_statemonitor);
	t1.join();
}



void
APIFSMControllerDebug::fsm_statemonitor()
{
	while (fDoRun == true)
	{
		static int cnt = 0;
		cnt++;
		FSM_DEBUG("monitoring FSM, cnt = %d", cnt);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}



/** Generates a mockup FSM that can be used for debugging*/
void
APIFSMControllerDebug::GenerateMockFSM()
{
	InitFSM();

}


