// -*- mode: c++ -*-

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "APIFSMNodeInfo.h"
#include <common/FSMState.h>
#include <utilities/GString.h>


string 
APIFSMNodeInfo::str() const
{
	std::stringstream buffer;

	buffer << "********** Printing info for: " << fName << "*********" << endl;
	buffer << "Name:\t\t"   << fName << endl;
	buffer << "Mother:\t\t" << fMother << endl;
	buffer << "State:\t\t" << fState << endl;
	buffer << FSMState::GetValidActionsString( fValidActions);
	buffer << "Color:\t\t0x" << std::hex  << fColor << endl;
	buffer << "Level:\t\t" << std::dec << fLevel << endl;
	//buffer << "N Child nodes\t" << fNChildNodes << endl;
	buffer << "N Child nodes\t" << fNChildNodes << "\t( "  <<  (fChildNodes.size() == 0 ? "<empty>" :  g_string()->ToString( fChildNodes, ",") )      << " )" << endl;
	buffer << "Unique ID:\t" << std::hex << "0x" << fId << endl;
	buffer << "********** DONE  ***********" << endl;
	return buffer.str();
}


bool 
APIFSMNodeInfo::operator==(APIFSMNodeInfo & rhs)
{

	if (fChildNodes.size() == rhs.fChildNodes.size())
	{
		for (size_t i = 0; i < fChildNodes.size(); i++)
		{
			if (fChildNodes[i] != rhs.fChildNodes[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	if (fName != rhs.fName || fMother != rhs.fMother || fState != rhs.fState)
	{
		return false;
	}


	if (fValidActions.size() == rhs.fValidActions.size())
	{
		for (size_t i = 0; i < fValidActions.size(); i++)
		{
			if (fValidActions[i] != rhs.fValidActions[i])
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}


bool 
APIFSMNodeInfo::operator!=(APIFSMNodeInfo & rhs)
{
	return (*this == rhs ? false : true);
}

