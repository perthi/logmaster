
#pragma once


#include "LGenerator.h"
#include <utilities/GDefinitions.h>



class LGeneratorLogTest : public LGenerator
{
public:
	API LGeneratorLogTest(const string filename, const string xml, const string xsd);
	virtual API ~LGeneratorLogTest() = default;

	virtual void  GenerateContent(std::vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
		std::vector< std::shared_ptr<LXmlEntitySubSystem > >  systems) override;

};

/// FSM_DEBUG("This is a FSM_DEBUG message");