// -*- mode: c++ -*-

#pragma once

/***************************************************
* @copyright Embedded Consulting                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
****************************************************/

#include <string>
using std::string;

#include <utilities/GPrintable.h>
#include <utilities/GDefinitions.h>

//#include "GDefinitions.h"


class  GXmlEntity : public GPrintable
{
public:
	API GXmlEntity();
	virtual API ~GXmlEntity();
	virtual  string API str() const override = 0;


};

