// -*- mode: c++ -*-
#pragma once

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

/* @class GCommon  Helper class for the other utilities classes */




class    GNumbers;
class    GUtilities;
class    GTokenizer;
class    GRandom;
class    GString;
class    GRegexp;
class    GFileIOHandler;
class    GSystem;
class    GLocation;
class    GCrc;

#include <string>
using std::string;


class GCommon;

GCommon * g_common();

#define DISABLE_EXCEPTION true
#define THROW_EXCEPTION  false


/** @brief Some common global defines and functions */
class GCommon
{
	friend    GNumbers;
	friend    GUtilities;
	friend    GTokenizer;
	friend    GRandom;
	friend    GString;
	friend    GRegexp;
	friend    GFileIOHandler;
	friend    GSystem;
    friend    GCrc;
	friend    GCommon * g_common();

private:
	GCommon() {};
	~GCommon() {};
	void  HandleError(const string message, const GLocation l, const bool disable_error );


};




