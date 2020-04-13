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
    return buffer.str();
}
