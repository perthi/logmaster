// -*- mode: c++ -*-

#include "LXmlEntityLogLevel.h"
#include <utilities/GUtilities.h>

#include <sstream>
#include <iostream>

using std::endl;

LXmlEntityLogLevel::LXmlEntityLogLevel()
{

}


LXmlEntityLogLevel::~LXmlEntityLogLevel()
{

}


string 
LXmlEntityLogLevel::str() const
{
    std::stringstream buffer;
    buffer <<  g_utilities()->TabAlign("NAME:") << fName << endl;
    buffer <<  g_utilities()->TabAlign("FORCE_OUTPUT ?:") <<  ( fForecOutput == true ?  "TRUE" : "FALSE" ) << endl;
    return buffer.str();

}
