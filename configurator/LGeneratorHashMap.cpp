// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 

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

    for( auto sys : systems )
    {
        string syst_s = "SYS_" + sys->fName;
        FORCE_DEBUG("name = %s", syst_s.c_str() );
    }


}	