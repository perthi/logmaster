// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <iostream>
#include <common/FSM_Definitions.h>

using std::endl;
using std::cout;


int main()
{
	/*
	SET_LOGLEVEL("--all-error");
	SET_LOGTARGET("000 --target-file --target-subscriber");

	APIFSMControllerDebug * c = APIFSMControllerDebug::Instance();
	c->GenerateMocFSM();
	cout << c->GetFSM()->str() << endl;

	cout << "***** PRINTING STATE INFO FROM MOCK FSM CONTROLLER  *******" << endl;
	print_stateinfo(c->GetNodeInfo() );
	cout << "************************** DONE  ***************************" << endl;
	
	std::shared_ptr<FSMNode>  n = c->GetFSM(); // Gess the top mode

	c->RegisterSubscriber(subs);
	c->Excec("CONNECT");
	c->Excec("GO_READY");
	c->Excec("GO_READY");  //  No state change excpected since GO_READY was allready called
	c->Excec("RESET");
	c->Excec("ABORT");
	*/

	return 0;
}


/*
void 
subs( const vector<APIFSMNodeInfo> &info)
{
    FORCE_DEBUG("statechanged recieved: Number of states that was changed = %d", info.size() );
	print_stateinfo(info);
}


void 
print_stateinfo(const vector<APIFSMNodeInfo>& info)
{
	for (size_t i = 0; i < info.size(); i++)
	{
		cout << "Node:" << info[i].fName << "\tState: " << info[i].fState << endl;
	}
}
*/
