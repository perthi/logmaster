// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "LGenerator.h"
#include <utilities/GString.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;

LGenerator::LGenerator( const string fname ) : fFileName(fname)
{
    fClassName = g_string()->Path2ClassName(fname);
    
    FORCE_DEBUG("classname = %s", fClassName.c_str() );

}

LGenerator::~LGenerator()
{

}

