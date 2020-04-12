// -*- mode: c++ -*-
#include "LXmlEntitySubSystem.h"

#include <utilities/GUtilities.h>

#include <sstream>
#include <iostream>

using std::endl;
LXmlEntitySubSystem::LXmlEntitySubSystem()
{

}

LXmlEntitySubSystem::~LXmlEntitySubSystem()
{

}


string 
LXmlEntitySubSystem::str() const
{
    std::stringstream buffer;
    buffer <<  g_utilities()->TabAlign("NAME:") <<      fName     <<   endl;
    buffer <<  g_utilities()->TabAlign("TAG:") <<       fTag      <<   endl;
    buffer <<  g_utilities()->TabAlign("TAG_SHORT:") << fDefault  <<   endl;
    buffer <<  g_utilities()->TabAlign("CAN_MODIFY ?:") <<  ( fCanModify  == true ?  "TRUE" : "FALSE" ) << endl;
    
    return buffer.str();
}