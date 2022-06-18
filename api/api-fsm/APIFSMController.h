// -*- mode: c++ -*-

#pragma once

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <common/FDefinitions.h>

#include <string>
using std::string;
#include <vector>
using std::vector;

#include <memory>


class  FSMNode;
class  FSMNode_Main;
struct APIFSMNodeInfo;
class  KDIConfigData;
class  KTCTestSetup;
class GUICringOperationsSequencer;


/**  @brief Control of the Finite State Machine(FSM).Referring to the MCV(Model / Control / Viev) the APIFSMController is the
*    "control" part of this model.
*   @details The controller provides an interface between external user applications, such as for instance a GUI, and the
*   business logic via the FSM. The FSMController thus provides an abstract interface to the business logic.
*   Calling the Excec() command issues an action(or a trigger if you like) to the FSM. The interpretation of the trigger
*   depends on the actual implementation which is transparent to the user.
*
*   Example : issuing the command Excec("GO_READY", "ALL_INSTRUMENTS") will issue the command "GO_READY" to the FSM node with the name "ALL_INSTRUMENTS",
*   and to all its child nodes. This command is then interpreted by the underlying business logic(the model).If for instance a child node is in the
*   state "NOT_READY" the command will initialize the device, and if successful, transition the FSM of the device to the state READY,
*   or alternatively, if not successful, to the state ERROR.If the device is already in the state READY, then no action will be taken,
*   and the device remains in that state */
class APIFSMController
{
public:
	static APIFSMController  API	 *	Instance();
	void					API		InitFSM( );
	void					API		SetMainFSM( std::shared_ptr<FSMNode> );
	void					API		AddChild(  std::shared_ptr<FSMNode> c, const string  mother = "");
//	int						API		PopulateInstruments(  KDIConfigData,   const KDISimulationMode_t sm, const string sim_model = "");
//	int						API		PopulateInstruments(const vector<KDIConfigData> devices, const KDISimulationMode_t sm, const string sim_model = "");
	void					API		RegisterSubscriber(void(*funct)(const vector<APIFSMNodeInfo> &));
	void					API		ClearSubscribers();
	void					API		PublishToSubscribers(const vector<APIFSMNodeInfo>  &msg);
	vector<APIFSMNodeInfo>	API		GetNodeInfo( std::shared_ptr< FSMNode> node = nullptr );
	APIFSMNodeInfo			API		GetNodeInfo(const string node);
	std::shared_ptr<FSMNode>				API	 GetFSM(const string name = "") const;
	int						API		Excec(const string cmnd, const string node = "");
	virtual void			API		Update();
	static void						MonitorNodes();

protected:
	APIFSMController();
	~APIFSMController();

	std::shared_ptr<FSMNode > GetMainFSM() { return fMainFSM; };
	//std::shared_ptr<FSMNode > GetDevicesMainFSM() { return  fDevicesMainFSM; };

	/** We want to use the same instance pointer for the APIFSMController and the APIFSMDebugController APIFSMController
	Controller, so we deviate a little bit from the standard singleton pattern and have a singel pointer to both classes,
	otherwise we would have to declare the singleton as a class member variable*/
	static APIFSMController* fgInstance;

private:
	APIFSMNodeInfo  GenerateNodeInfo(const std::shared_ptr<FSMNode>  node);
	vector< void(*)(const vector<APIFSMNodeInfo>  & ) > fSubscribers; /* !<List of subscriber functions that will be call upon an event> */
			/* !<Pointer to the top level FSM node */

//	std::shared_ptr<FSMNode> fDevicesMainFSM = nullptr;      /* !<Pointer to the top node for all instrument FSMs */
	std::shared_ptr<FSMNode > fMainFSM = nullptr;
	std::shared_ptr<FSMNode > fEnvironment = nullptr;

	std::shared_ptr<FSMNode > fSensors = nullptr;
	std::shared_ptr<FSMNode > fSensorsPressure = nullptr;
	std::shared_ptr<FSMNode > fSensorsHumidity = nullptr;
	std::shared_ptr<FSMNode > fSensorsCurrent = nullptr;

	std::shared_ptr<FSMNode > fEngine = nullptr;
	std::shared_ptr<FSMNode > fPostOffice = nullptr;

	std::shared_ptr<FSMNode>  fOperations = nullptr;
	// std::shared_ptr<FSMNode>  fOperationsSequencer = nullptr;

	//std::shared_ptr<KTCTestSetup> fTestSetupFSM = nullptr; #TOR: Temporary removed
//	std::shared_ptr<FSMNode> fInfrastructureFSM = nullptr;
//	std::shared_ptr<FSMNode> fEnvironmentFSM = nullptr;  /* !<Pointer to the environment FSM node */

};

