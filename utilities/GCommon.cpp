// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/

#include <utilities/GCommon.h>
#include <utilities/GException.h>
#include "GDefinitions.h"
#include "GLocation.h"
#include <logging/LLogApi.h>
///#include <logging/LLogging.h>

using namespace LOGMASTER;

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

void
#ifdef G_STANDALONE
GCommon::HandleError(const string message, const GLocation &, const bool disable_error)
#else
GCommon::HandleError(const string message, const GLocation & l, const bool disable_error)
#endif
{


    if (disable_error == false)
    {
#ifdef G_STANDALONE
		
	#ifdef _WIN32
		throw( std::exception(message.c_str() ) );
	#else
		throw(std::invalid_argument( message.c_str() ));
	#endif

	//	throw(message);
#else
        throw_exception(   GException(l.fFileName, l.fFunctName, l.fLineNo, SYS_EX, "%s", message.c_str( ))  )  ;
#endif
    }
    else
    {
#ifdef G_STANDALONE
        COUT << message << std::endl;
#else
        G_WARNING(message.c_str());
#endif
    }
}


GCommon * g_common()
{
	static GCommon *instance = new GCommon();
	return instance;
}

