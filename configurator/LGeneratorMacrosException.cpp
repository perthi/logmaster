
// -*- mode: c++ -*-
#include "LGeneratorMacrosException.h"
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>

using namespace LOGMASTER;


LGeneratorMacrosException::LGeneratorMacrosException()
{

}


LGeneratorMacrosException::~LGeneratorMacrosException()
{

}


vector<string>   
LGeneratorMacrosException::Generate( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems  ) const
{
    vector<string> lines;

    for( auto sys : systems )
    {
        FORCE_DEBUG( "sys = %s", sys->fName.c_str()  );
    }

    return lines;

}