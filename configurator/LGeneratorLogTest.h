
#pragma once


#include "LGenerator.h"


#include <utilities/GDefinitions.h>


//struct LMacroCallEntry;


class LGeneratorLogTest : public LGenerator
{
public:
	API LGeneratorLogTest(const string filename);
	virtual API ~LGeneratorLogTest() = default;

	virtual vector<string> API Generate(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
		vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause) const override;

private:
	
	/*
	struct LMacroCallEntry
	{

	};
	*/

};

/// FSM_DEBUG("This is a FSM_DEBUG message");