// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LCopyright.h"
#include <utilities/GUtilities.h>

#include <sstream>
#include <iostream>

using std::endl;



// string addendum = "/*** Generated from " + xml + " **/\n";
// addendum += "/*** Validated by " + xsd + " **/\n";
// addendum += "/*** Copyright Per Thomas Hille pth@embc.no ***/\n";
// string clause = g_utilities()->AutoClause(addendum);

string 
LCopyright::str(const string xml, const string xsd)
{
    std::stringstream buffer;
    buffer << "/***************************************************"  << endl;
    buffer << "* @copyright Embedded Consulting AS                *"  << endl;
    buffer << "* @author Per Thomas Hille <pth@embc.no>           *"  << endl;
    buffer << "***************************************************/"  << endl;
    
    buffer << "/*****************************************************************************" << endl;
    buffer << "******************************************************************************" << endl;
    buffer << "*** This file is part of logmaster.                                        ***" << endl;
    buffer << "*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***" << endl;
    buffer << "*** all rights reserved                                                    ***" << endl;
    buffer << "***                                                                        ***" << endl;
    buffer << "*** logmaster is free software: you can redistribute it and/or modify      ***" << endl;
    buffer << "*** it under the terms of the Lesser GNU General Public License (LGPL)     ***" << endl;
    buffer << "*** as published by the Free Software Foundation, either version 3 of the  ***" << endl;
    buffer << "*** License, or (at your option) any later version.                        ***" << endl;
    buffer << "***                                                                        ***" << endl;
    buffer << "*** logmaster is distributed in the hope that it will be useful,           ***" << endl;
    buffer << "*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***" << endl;
    buffer << "*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***" << endl;
    buffer << "*** GNU General Public License for more details.                           ***" << endl;
    buffer << "***                                                                        ***" << endl;
    buffer << "*** You should have received a copy of the Lesser GNU General Public       ***" << endl;
    buffer << "*** License along with logmaster in the README file in the source code     ***" << endl;
    buffer << "*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***" << endl;
    buffer << "******************************************************************************" << endl;
    buffer << "******************************************************************************/" << endl;
    
    string addendum = "/*** Generated from " + xml + " **/\n";
    addendum += "/*** Validated by " + xsd + " **/\n";
    buffer << g_utilities()->AutoClause(addendum);
    
    return buffer.str();
}

