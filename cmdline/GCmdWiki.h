// -*- mode: c++ -*-
#ifndef GCMDWIKI_H
#define GCMDWIKI_H


/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/


#include "GArgument.h"

#include <utilities/GDefinitions.h>

#include <string>
using std::string;

#include <deque>
using std::deque;

#include <memory>

class  GCmdWiki
{
    public:
        static void API GenerateWiki( deque < std::shared_ptr< GArgument> > args,  const string  filename  );
};

#endif
