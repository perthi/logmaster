// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LCopyright.h"
#include <sstream>

#include <iostream>

using std::endl;


LCopyright::LCopyright()
{

}


LCopyright::~LCopyright()
{

}


string 
LCopyright::Copyrightt()
{
    std::stringstream buffer;
    buffer << "/***************************************************"  << endl;
    buffer << "* @copyright Embedded Consulting AS                *"  << endl;
    buffer << "* @author Per Thomas Hille <pth@embc.no>           *"  << endl;
    buffer << "***************************************************/"  << endl;
    return buffer.str();
}

