#pragma once




#include <memory>
#include <vector>



namespace CONFIGURATOR
{

	class LXmlEntityLogLevel;
	class LXmlEntitySubSystem;
	class LGenerator;

	using logentity_ptr = std::shared_ptr< LXmlEntityLogLevel >;
	using sysentity_ptr = std::shared_ptr< LXmlEntitySubSystem >;

	using  logentity_vec = std::vector< logentity_ptr >;
	using  sysentity_vec = std::vector <sysentity_ptr >;

	using generator_ptr = std::shared_ptr< LGenerator >;
	using generator_vec = std::vector<std::shared_ptr< LGenerator > >;


}