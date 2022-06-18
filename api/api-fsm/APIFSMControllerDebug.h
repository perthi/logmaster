// -*- mode: c++ -*-

#pragma once

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "APIFSMController.h"

class APIFSMControllerDebug : public APIFSMController
{
public:
	static APIFSMControllerDebug  API	 *	Instance();
	void					API		StartRun();
	void					API		StopRun();
	void					API		Run();
	static void				API		fsm_statemonitor();
        static void						RunFSM(FSMNode * /*fsm*/ ) {};
	void					API		GenerateMockFSM();

private:
	APIFSMControllerDebug() {};
	~APIFSMControllerDebug() {};
	static bool fDoRun;
};

