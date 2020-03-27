// -*- mode: c++ -*-

// fsm-example1.cpp : Defines the entry point for the console application.
//


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <common/FSM_Definitions.h>
#include <cmdline/GLogApplication.h>
#include <logging/LLogging.h>
#include <api/api-fsm/APIFSMControllerDebug.h>
#include <api/api-fsm/APIFSMNodeInfo.h>


using namespace LOGMASTER;

#include <thread>
#include <chrono>
#include <iostream>
using std::cout;
using std::endl;


void run_fsm(FSMNode *fsm);
void monitor_fsm(FSMNode *fsm);

#include <utilities/GRandom.h>
#include <utilities/GException.h>


int main()
{	
	std::shared_ptr<FSMNode>  m =   std::make_shared<FSMNode_Main>("MAIN");
	std::shared_ptr<FSMNode>  c1 =  std::make_shared<FSMNode_Debug>("CHILD1");
	std::shared_ptr<FSMNode>  c2 = std::make_shared<FSMNode_Debug>("CHILD2");

	m->AddChild(c1);
	m->AddChild( c2 );

	//KDIInstr *instr = new KDIInstrDummy("RFGEN_1", KDIResetMode_t(DO_RESET), KDISimulationMode_t(DO_SIMULATE), "");
	//cout << "name = " << instr->GetFsmName() << endl;
	SET_LOGLEVEL("--all-debug");
//	instr->StateTransition("READY");
//	cout << "state = "  << instr->GetCurrentState()->GetName() << endl;
//	instr->Update();
	PUSH();
	SET_LOGLEVEL("--off");
	APIFSMControllerDebug *c = APIFSMControllerDebug::Instance();
	c->GetNodeInfo();
	c->GenerateMockFSM();
	c->Excec("CONNECT");
	c->Excec("GO_READY");
	POP();
	c->Update();
	FSMNode_Debug *fsm = new FSMNode_Debug(0);
	delete fsm;
    return 0;
}


void 
run_fsm(FSMNode *fsm)
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("RESET");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("CONFIGURE");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("CONNECT");
	
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("CONFIGURE");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("TURN_ON");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("CONFIGURE");
		
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("START");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
        try
        {
            fsm->Excec("ABORT");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        catch (...)
        {
            CERR << "Exception caught" << endl;
        }
        
        fsm->Excec("START");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        fsm->Excec("TURN_OFF");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}




void monitor_fsm(FSMNode *fsm)
{
	
    string current_state = fsm->GetCurrentState()->GetName();
    string previous_state = "N/A";

    for (int i = 0; i < 100; i++)
    {
        current_state = fsm->GetCurrentState()->GetName();

        if (current_state != previous_state)
        {
            USER_INFO("The state changed from %s to: %s", previous_state.c_str(),   fsm->GetCurrentState()->GetName().c_str() );
            fsm->GetCurrentState()->GetName();
            printf("The state changed from %s to: %s\n", previous_state.c_str(), fsm->GetCurrentState()->GetName().c_str());
        }

        previous_state = current_state;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

