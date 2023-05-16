#pragma once




#include <memory>
#include <vector>



namespace CONFIGURATOR
{

	class LXmlEntityLogLevel;
	class LXmlEntitySubSystem;
	class LGenerator;

	using loglevel = std::shared_ptr< LXmlEntityLogLevel >;
	using subsystem = std::shared_ptr< LXmlEntitySubSystem >;

	using  loglevel_vec = std::vector< loglevel >;
	using  subsystem_vec = std::vector < subsystem >;

	using generator = std::shared_ptr< LGenerator >;
	using generator_vec = std::vector<std::shared_ptr< LGenerator > >;


}