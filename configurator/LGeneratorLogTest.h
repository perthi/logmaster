
#pragma once


#include <utilities/GDefinitions.h>
#include "LGenerator.h"
#include "LXMLInfo.h"


namespace CONFIGURATOR
{

	class LGeneratorLogTest : public LGenerator
	{
	public:
		API LGeneratorLogTest(const string filename, const  LXMLInfo xmlinfo);
		virtual API ~LGeneratorLogTest() = default;

		virtual void  GenerateContent(logentity_vec  levels, sysentity_vec  systems) override;

	};

}

