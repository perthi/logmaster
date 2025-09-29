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


#include <string>
using std::string;

class GLocation;

#define DISABLE_EXCEPTION true
#define THROW_EXCEPTION  false

#include <utilities/GDefinitions.h>

/** @brief Some common global defines and functions */
class GCommon
{

public:
    API GCommon() = default;
    API ~GCommon() = default;
    void  API  HandleError(const string &message, const GLocation &l, const bool disable_error = false );
    void  API  DisableOutput();
    void  API  EnableOutput();

private:
    static bool fDisableOuput;
};




