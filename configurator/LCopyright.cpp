// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LGeneratorCopyright.h"
#include <sstream>

#include <iostream>

using std::endl;


LGeneratorCopyright::LGeneratorCopyright()
{

}


LGeneratorCopyright::~LGeneratorCopyright()
{

}


string 
LGeneratorCopyright::Copyrightt()
{
    std::stringstream buffer;
    buffer << "/***************************************************"  << endl;
    buffer << "* @copyright Embedded Consulting AS                *"  << endl;
    buffer << "* @author Per Thomas Hille <pth@embc.no>           *"  << endl;
    buffer << "***************************************************/"  << endl;
    return buffer.str();
}


// string 
// LGeneratorCopyright::GPLShort()
// {

// }

// string 
// LGeneratorCopyright::GPLLong()
// {

// }
