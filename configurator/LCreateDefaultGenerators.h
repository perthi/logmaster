#pragma once

#include <configurator/LDefinitions.h>
#include <configurator/LXMLInfo.h>

#include <memory>

#include <string>

using std::string;

class LGenerator;

class LCreateDefaultGenerators
{
public:
	static generator_vec  CreateAll( const LXMLInfo xmlinfo );



};

/*
template<typename T>
inline generator_vec LCreateDefaultGenerators::CreateSingle(const string fname)
{

	return generator_vec();
}
*/
