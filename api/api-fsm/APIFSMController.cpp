// -*- mode: c++ -*-

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include  "APIFSMController.h"
#include  "APIFSMNodeInfo.h"
#include  <common/FSM_Definitions.h>
/// #include  <common/FSMNodeMainImpl.h>
#include  <utilities/GUtilities.h>
#include  <logging/LLogApi.h>
#include  <common/MBPostOffice.h>

// Sequences
// #include <gui/operations/GUICringOperationsSequencer.h>
// #include <sequence/SequenceCoating.h>
// #include <sequence/SequenceWrapping.h>
// #include <sequence/SequenceSurfacePrep.h>


using namespace LOGMASTER;
APIFSMController* APIFSMController::fgInstance = nullptr;

#include <memory>


APIFSMController::APIFSMController() : fMainFSM(0)
{
	FSMNode::RegisterSubscriber(MonitorNodes);
}


APIFSMController::~APIFSMController()
{
//	delete fMainFSM;
}


APIFSMController  *
APIFSMController::Instance()
{	if (fgInstance == nullptr)
	{
		fgInstance = new APIFSMController();
	}
	return fgInstance;
}


void
APIFSMController::MonitorNodes()
{
	vector<APIFSMNodeInfo>  tmp = Instance()->GetNodeInfo();
	Instance()->PublishToSubscribers(tmp);
}



void
APIFSMController::InitFSM( )
{
    static bool is_initialized = false;

    if ( is_initialized == false )
    {
        fMainFSM =  	std::make_shared<   FSMNode_Main >(  );//FSMNode_Main(0);
        fSensors =  	std::make_shared<   FSMNode_Sensors  >( );//FSMNode_Main(0);
        fEnvironment =  std::make_shared<   FSMNode_Environment  >(  );//FSMNode_Main(0);
        fEngine =  		std::make_shared<   FSMNode_Engine  >(  );//FSMNode_Main(0);
        fPostOffice =  	std::make_shared<   FSMNode_PostOffice  >(  );//FSMNode_Main(0);


		std::shared_ptr<FSMNode > fSensorsPressure = std::make_shared<FSMNode_Sensors>( "HABITAT PRESSURE");
		std::shared_ptr<FSMNode > fSensorsHumidity = std::make_shared<FSMNode_Sensors>( "HABITAT HUMIDITY");
		std::shared_ptr<FSMNode > fSensorsCurrent = std::make_shared<FSMNode_Sensors>(  "CURRENT (MOTORS)");

		fSensors->AddChild(fSensorsPressure );
		fSensors->AddChild( fSensorsHumidity );
		fSensors->AddChild( fSensorsCurrent );

		fSensors->StateTransition("READY");
		fEnvironment->StateTransition("READY");
		fEngine->StateTransition("READY");
		fPostOffice->StateTransition("OK");

		fOperations  = std::make_shared<FSMNode_Operation>();

		fMainFSM->AddChild(fSensors);
		fMainFSM->AddChild(fPostOffice);
		fMainFSM->AddChild(fEnvironment);
		fMainFSM->AddChild(fEngine);

		fMainFSM->AddChild(fOperations);

		size_t tmp = fMainFSM->GetChildNodes().size();

        FSM_ASSERT_EXCEPTION( fMainFSM != nullptr, " fMainFSM is a ZERO pointer" );
        fMainFSM->Excec( "CONNECT" );
        is_initialized = true;
    }
}


void
APIFSMController::SetMainFSM( std::shared_ptr<FSMNode> fsm)
{
	fMainFSM = fsm;
}


void
APIFSMController::AddChild(  std::shared_ptr<FSMNode> c, const string mother )
{
	if (c == 0)
	{
		FSM_FATAL("Node is a ZERO pointer");
		return;
	}

	if (fMainFSM == 0)
	{
		FSM_FATAL("Could not add child, there are no FSM to add to (fMainFSM == ZERO)");
	}
	else
	{

		std::shared_ptr<FSMNode>  n = GetFSM(mother);

		if (n == 0)
		{
			FSM_FATAL("No such mother %s", mother.c_str() );
		}
		else
		{
			FSM_INFO("Sucessfully added child node %s to %s", c->GetName().c_str(), fMainFSM->GetName().c_str() );
			fMainFSM->AddChild(c);
		}
	}
}




std::shared_ptr<FSMNode>
APIFSMController::GetFSM(const string name) const
{
	FSM_DEBUG("name = %s", name.c_str() );

	if (fMainFSM == 0)
	{
	//	FORCE_DEBUG("The main FSM node is a ZERO pointer");
		FSM_FATAL("The main FSM node is a ZERO pointer");
		return 0;
	}
	else
	{
		if (name == "" || name == fMainFSM->GetName())
		{
			return fMainFSM;
		}
		else
		{
			return fMainFSM->GetChildNode(name);
		}
	}
}



int
APIFSMController::Excec(const string cmd, const string node)
{
	try
	{
		vector<APIFSMNodeInfo> nchanged;
		vector<APIFSMNodeInfo> nbefore = GetNodeInfo(fMainFSM);

		if (node == "" || node == fMainFSM->GetName())
		{
			FSM_INFO("Excecuting command %s at %s", cmd.c_str(), node.c_str());
			fMainFSM->Excec(cmd);
		}
		else
		{
			std::shared_ptr<FSMNode> n = GetFSM(node);

			if (n != 0)
			{
				FSM_INFO("Excecuting command %s at %s", cmd.c_str(), node.c_str());
				n->Excec(cmd);
			}
			else
			{
				FSM_FATAL("Could not execute %s, unknown node %s", cmd.c_str(), node.c_str());
			}
		}

		vector<APIFSMNodeInfo> nafter = GetNodeInfo(fMainFSM);
		bool has_changed = false;

		if (nafter.size() != nbefore.size())
		{
			has_changed = true;
			nchanged = nafter;
			FSM_WARNING("Cannot compear nodes one by one because the sizes are different (%d vs %d)", nbefore.size(), nafter.size());
		}
		else
		{
			for (size_t i = 0; i < nbefore.size(); i++)
			{

				if (nafter[i] != nbefore[i])
				{
					has_changed = true;
					nchanged.push_back(nafter[i]);
				}
			}
		}

		if (has_changed == true)
		{
			PublishToSubscribers(nchanged);
		}
	}
	catch(GException &e)
	{
		FSM_FATAL_U("GException caught running command %s on node: %s, msg = %s", cmd.c_str(), node.c_str(), e.what());
		throw(e);
	}
	catch (std::exception &e)
	{
		FSM_FATAL_U("std::excpetion caught running command %s on node: %s, msg = %s", cmd.c_str(), node.c_str(), e.what() );
		throw(e);
	}
	catch (...)
	{
		FSM_FATAL_U("Unknown excpetion caught running command %s on node: %s", cmd.c_str(), node.c_str() );
	}

	return 0;
}



/* Forces the FSM to check all subnodes for changes, for example, it will attempt
to communicate with all devices to see if an error has occured*/
void
APIFSMController::Update()
{
	if (fMainFSM != 0)
	{
		fMainFSM->Update();
	}
}


void
APIFSMController::RegisterSubscriber(void(*funct)(const vector<APIFSMNodeInfo>  & ))
{
	fSubscribers.push_back(funct);
}


void
APIFSMController::ClearSubscribers()
{
	fSubscribers.clear();
}


void
APIFSMController::PublishToSubscribers(const vector<APIFSMNodeInfo>  &message)
{
	FSM_INFO("Updating subscribers");
	for ( size_t i = 0; i < fSubscribers.size(); i++)
	{
		void(*Subscriberfunct)(const vector<APIFSMNodeInfo>  &) = fSubscribers.at(i);
		Subscriberfunct(message);
	}
}



vector<APIFSMNodeInfo>
APIFSMController::GetNodeInfo(std::shared_ptr<FSMNode> node)
{
	if (node == 0)
	{
		node = fMainFSM;
	}

	vector<APIFSMNodeInfo> nvec;

	if (node == 0)
	{
		FSM_WARNING("Cannot retrieve node info because the FSM node is a zero pointer");
		return nvec;
	}
	else
	{
		static int cnt = 0;

		auto node_info = GenerateNodeInfo( node );

		if ( node->GetName() == "MESSAGE_SYSTEM" )
		{
			cnt++;
		}

	//	FORCE_DEBUG("\n%s", node_info.str().c_str()  );

		nvec.push_back(  node_info  );
		auto children = node->GetChildNodes();

		for ( size_t i = 0; i < children.size(); i++)
		{
			vector<APIFSMNodeInfo> nvec_tmp = GetNodeInfo(children[i]);
			for ( size_t j = 0; j < nvec_tmp.size(); j++)
			{
				nvec.push_back(nvec_tmp[j]);
			}
		}
	}
	return nvec;
}


APIFSMNodeInfo
APIFSMController::GetNodeInfo(const string node)
{
	APIFSMNodeInfo n;
	if ( node == "" || node == fMainFSM->GetName())
	{
		return GenerateNodeInfo(fMainFSM);
	}
	else
	{
		std::shared_ptr<FSMNode> child = fMainFSM->GetChildNode(node);

		if (child == 0)
		{
			FSM_WARNING("%s has no children", node.c_str() );
		}
		else
		{
			n = GenerateNodeInfo(child);

		}
		return n;
	}
}



/** Retrieves FSM state information for a given FSM node. This function is intended to be used by a GUI or other applications
 *	In order to display FSM information whic can then be utilized to control the FSM.
 *  The state information comprises
 *  - The name of the FSM
 *  - The name of the state (i.e READY, NOT_READY, RUNNING, etc.. )
 *  - The name of the moter FSM if any
 *  - Which level in the FSM hierarchy this FSM is at
 *  - A vector with the name of child nodes
 *  - A list of available  actions in the current state, and the associated target states.
 *  - The color associated with this state (releveant only for GUI, ERROR = RED, OK = GREEN and so on)
 *  See the documentation for APIFSMNodeInfo for further details
 * @param[in] node A pointer to the FSM node to retrieve information for
 * @return a APIFSMNodeInfo struct containing the node information.  */
APIFSMNodeInfo
APIFSMController::GenerateNodeInfo(const  std::shared_ptr<FSMNode>  node)
{
	APIFSMNodeInfo n;

	if (node == nullptr)
	{
		FSM_ERROR("Cannot generate Node info because the \"node\" is a ZERO pointer");
		return n;
	}
	else
	{
		n.fMother = (node->HasMother() == true ? node->GetMother()->GetName() : "NO MOTHER");
		n.fName = node->GetName();
		n.fState = node->GetCurrentState()->GetName();
		n.fColor = node->GetCurrentState()->GetColor();
		n.fLevel = node->GetLevel();
		auto children = node->GetChildNodes();
		n.fNChildNodes = children.size();

		for ( size_t i = 0; i < children.size(); i++)
		{
			n.fChildNodes.push_back(children[i]->GetName());
		}

		n.fId = (size_t)this;
		n.fValidActions = node->GetCurrentState()->GetValidActions();
		return n;
	}
}

