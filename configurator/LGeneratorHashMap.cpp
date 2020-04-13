// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

LGeneratorHashMap::LGeneratorHashMap()
{

}

LGeneratorHashMap::~LGeneratorHashMap()
{

}

void 
LGeneratorHashMap::Generate(   const string /*outfile*/, 
	                    vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                    vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const
{
    FORCE_DEBUG( "levels.size() = %d",    levels.size() );
    FORCE_DEBUG( "systems.size() = %d",   systems.size() );

    


}	