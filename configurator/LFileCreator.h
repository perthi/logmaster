#pragma once



#include "LDefinitions.h"
#include <utilities/GDefinitions.h>

#include <memory>
#include <vector>

using std::vector;

namespace CONFIGURATOR
{


	class LFileCreator
	{
	public:
		static void API GenerateFiles(const generator_vec& g, const loglevel_vec& l, const subsystem_vec& s);
		static void API GenerateSingleFile(const generator& g, const loglevel_vec& l, const subsystem_vec& s);
	};

}