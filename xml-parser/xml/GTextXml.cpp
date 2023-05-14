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

#include "GTextXml.h"
#include <cstdarg>

#define XML_MAX_SIZE 4096

/** @todo Replace. Use the version in the GText class*/
GTextXml::GTextXml(const char * fmt, ...) : fText("")
{
    va_list ap;
    va_start(ap, fmt);
    SetGTextXml(fmt, ap);
    va_end(ap);
 }


/** @todo Replace. Use the version in the GText class*/
GTextXml::GTextXml(const string s ) : fText("")
{   
   fText = s;
}


/** @todo Replace. Use the version in the GText class*/
void
GTextXml::SetGTextXml(const char *fmt, va_list ap)
{
    static char msg[XML_MAX_SIZE];
    vsnprintf(msg, sizeof(msg) -1, fmt, ap);
    fText = string(msg);
}


/** @todo Replace. Use the version in the GText class*/
GTextXml & 
GTextXml::operator  = (const char *rhs)
{
    this->SetGTextXml(rhs);
    return *this;
}


/** @todo Replace. Use the version in the GText class*/
void 
GTextXml::SetGTextXml(const char *txt)
{
    fText =  string(txt);
}



/** @todo Replace. Use the version in the GText class*/
string    
GTextXml::str() const 
{ 
    return fText; 

}


/** @todo Replace. Use the version in the GText class*/
int64_t  
GTextXml::size() const
{
    return fText.size();
}


/** @todo Replace. Use the version in the GText class*/
const char *  
GTextXml::c_str() const 
{ 
    return fText.c_str(); 
}


/** @todo Replace. Use the version in the GText class*/
const char *
GTextXml::what() const
{ 
    return fText.c_str(); 
}

