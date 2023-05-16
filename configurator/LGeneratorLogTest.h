
#pragma once


#include <utilities/GDefinitions.h>
#include "LGenerator.h"
#include "LXMLInfo.h"




class LGeneratorLogTest : public LGenerator
{
public:
	API LGeneratorLogTest(const string filename, const  LXMLInfo xmlinfo );
	virtual API ~LGeneratorLogTest() = default;

	virtual void  GenerateContent(std::vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
		std::vector< std::shared_ptr<LXmlEntitySubSystem > >  systems) override;

};

/// FSM_DEBUG("This is a FSM_DEBUG message");