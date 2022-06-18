// -*- mode: c++ -*-

#pragma once

/********************************************
* Author: Per Thomas Hille <pth@embc.no> ****
*********************************************/

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <utilities/GPrintable.h>
#include <utilities/GDefinitions.h>
#include <tuple>
#include <vector>
using std::vector;
#include  <string>
using std::string;

struct APIFSMNodeInfo : public GPrintable
{
	virtual API string   str() const override;
	string fName = "<empty>";
	string fMother = "<empty>";	
	string fState = "<empty>";
	vector< std::tuple< string, string > > fValidActions; //!< <actions, target state>
	int fColor = 0;	
	int fLevel = 0;
	size_t fNChildNodes;
	vector<string> fChildNodes;
	size_t fId = -99;

	bool API operator != (APIFSMNodeInfo &);
	bool API operator == (APIFSMNodeInfo &);
};


