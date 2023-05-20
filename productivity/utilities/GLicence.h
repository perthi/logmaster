#pragma once

#include <sstream>
#include <string>
using std::string;

#include <iostream>
using std::endl;

#include "GTime.h"

class GLicence
{
	public:
        static inline string copyright( );
		static inline string long_version();
        static inline string short_version( );
       
};



string
GLicence::copyright( )
{
    std::stringstream buffer;
    buffer << "/***************************************************" << endl;
    buffer << "* @copyright Embedded Consulting AS    " << GTime().GetYear() << "        *" << endl;
    buffer << "* @author Per Thomas Hille <pth@embc.no>           *" << endl;
    buffer << "***************************************************/" << endl;
    return buffer.str( );
}


string
GLicence::long_version()
{
	std::stringstream buffer;
    buffer << copyright( ) << endl;;

    buffer << "/********************************************************************************" << endl;
    buffer << "**********************************************************************************" << endl;
    buffer << "*** This file is part of logmaster.                                           ***" << endl;
    buffer << "*** Copyright (C)" << GTime().GetYear() << "Per Thomas Hille <pth@embc.no>  http:///www.embc.no     ***" << endl;
    buffer << "*** all rights reserved                                                       ***" << endl;
    buffer << "***                                                                           ***" << endl;
    buffer << "*** logmaster is free software: you can redistribute it and/or modify         ***" << endl;
    buffer << "*** it under the terms of the Lesser GNU General Public License (LGPL)        ***" << endl;
    buffer << "*** as published by the Free Software Foundation, either version 3 of the     ***" << endl;
    buffer << "*** License, or (at your option) any later version.                           ***" << endl;
    buffer << "***                                                                           ***" << endl;
    buffer << "*** logmaster is distributed in the hope that it will be useful,              ***" << endl;
    buffer << "*** but WITHOUT ANY WARRANTY; without even the implied warranty of            ***" << endl;
    buffer << "*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             ***" << endl;
    buffer << "*** GNU General Public License for more details.                              ***" << endl;
    buffer << "***                                                                           ***" << endl;
    buffer << "*** You should have received a copy of the Lesser GNU General Public          ***" << endl;
    buffer << "*** License along with logmaster in the README file in the source code        ***" << endl;
    buffer << "*** directory. If not, see <http://www.gnu.org/licenses/>.                    ***" << endl;
    buffer << "*********************************************************************************" << endl;
    buffer << "*********************************************************************************/" << endl;

    return buffer.str();
}


string
GLicence::short_version( )
{
    std::stringstream buffer;
    buffer << "/****************************************************************************" << endl;
    buffer << "*** Copyright(C) "<< GTime().GetYear() <<"  Per Thomas Hille, pth@embc.no                  ***" << endl;
    buffer << "*** This file is part of logmaster.logmaster is free software : you can   ***" << endl;
    buffer << "*** redistribute it and / or modify it under the terms of the Lesser GNU  ***" << endl;
    buffer << "*** General Public License(LGPL) V3 or later. See.cpp file for details    ***" << endl;
    buffer << "*****************************************************************************" << endl;
    return buffer.str( );
}
