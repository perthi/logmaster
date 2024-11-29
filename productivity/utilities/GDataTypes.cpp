// -*- mode: c++ -*-


/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
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


#include "GNumbers.h"
#include "GNumberTypes.h"
#include "GDataTypes.h"
#include "GCommon.h"
#include "GLocation.h"
#include "GStackTrace.h"
#include <fmt/format.h>

ostream& operator<<(ostream& os, const Val  &o)
{
    os << o.GetValue(  );   
    return os;
}

/** @todo remove this class */

void 
Val::CheckIsInteger(double t)
{
    if( g_number_types()->IsInteger((long double )t) == false )
    {
        /** @bug magic number */
        GCommon().HandleError(  fmt::format("Number ({}) is NOT an integer, the sensor ID must be an integer between ZERO and {}", t, 16), 
                                         GLOCATION, THROW_EXCEPTION  );
    }
}


void 
Val::GenerateStackFrames()
{
    string stack =  GStackTrace::str();
    std::stringstream msg;
    msg <<"The allowed range for parameter: "<< fName <<"\tis  [min, max] = "<< "["<< fMinValue <<", "<< fMaxValue <<"]  " << fSubscript;    
    msg << ":\tYou attempted to set the value to " << fVal;  
    string s = stack + msg.str() ;
    GCommon().HandleError( s, GLOCATION, THROW_EXCEPTION );
}


void
Val::CheckLimits(const double &t, const double min, const double max)
{
    if(t > max || t < min)
    {
        GenerateStackFrames();
    }
}


void 
Val::SetValue(const double value) 
{ 
    fVal = value; 
    CheckLimits( value, fMinValue, fMaxValue );
}


string 
Val::ParameterInfo() const
{
    std::stringstream buffer;
    buffer << "*******************" << endl;
    buffer << "Name:\t"  << fName << "*****" << endl;
    buffer << "Min:\t"   << fMinValue << endl;
    buffer << "Max:\t"   << fMaxValue << endl;
    buffer << "Value:\t" << fVal << endl;
    buffer   << "*******************" << endl;
    return buffer.str();
}


string 
Val::ParameterUsage() const
{
    std::stringstream buffer;
    buffer << "\t\t\t" << fName << ":" << (fName.size() < 6 ? "\t" : "") << "\t(" << fSubscript << ")"
         << "\t" << fHelpText;
    buffer << endl << "\t\t\t" << (fName.size() < 6 ? "\t" : "");
    return buffer.str();
}


string 
Val::Defaults() const
{ 
    return fmt::format( "\t\tdefault = {}, [{},{}]", (double)fVal, fMinValue, fMaxValue );
}


string 
Val::str() const
{
    std::stringstream buffer;
    buffer << ParameterInfo();
    buffer << Defaults();
    buffer << ParameterUsage();
    return buffer.str();
} 


void
Val::PrintParameterInfo() const
{
    cout << ParameterInfo() << endl;
}


void 
Val::PrintParameterUsage() const
{
    cout << ParameterUsage() << endl;
    PrintDefaults();
}


void
Val::PrintDefaults() const
{
///    fmt::format( "\t\tdefault = {}, [{},{}]", (double)fVal, fMinValue, fMaxValue );
    // printf("\t\tdefault=%0.2G, [min, max] = [%0.2G,%0.2G]\n", (double)fVal, fMinValue, fMaxValue  );    
    cout << Defaults() << endl;
}
