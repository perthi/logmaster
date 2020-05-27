// -*- mode: c++ -*-

#pragma once


/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

/* ****************************************************************************
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

///#include "LEnumsLevels.h"


#ifdef __cplusplus
namespace LOGMASTER
{

#include "LEnumGenerated.h" /// NB autognerated


#endif



	/*Enum controling where the logmessages are written*/
#ifdef __cplusplus
	enum class eMSGTARGET
#else
	enum eMSGTARGET
#endif
    {
        TARGET_OFF              =   0x00,    // 00000000     No logging
        TARGET_FILE             =   0x01,    // 00000001     log to file
        TARGET_STDOUT           =   0x02,    // 00000010     log messages to standard output
        TARGET_SUBSCRIBERS      =   0x04,    // 00000100     Send messages to all message subscribers
        TARGET_GUI              =   0x08,    // 00001000     Send messages to the GUI
        TARGET_EXCEPTION        =   0x10,    // 00010000     The exection system, always ON, not configurable
        TARGET_TESTING          =   0x20,    // 00100000     Dedicated targe t for debugging
        TARGET_DATABASE         =   0x40,    // 00100000     Dedicated targe t for debugging
		TARGET_ALL              =   0x3f     // 00111111     Write log messages to all availabel log targets.
    };


	/*Enum controlling the format of the log message*/
#ifdef __cplusplus
	enum class eMSGFORMAT
#else
	enum  eMSGFORMAT
#endif
    {
         ALL_FIELDS_OFF          =	0x00,     // 00000000    No fields. ( Used internally by the logging system  )
         MESSAGE_TYPE            =	0x40,     // 01000000    Prefix starts with <LOGLEVEL:SUBSYSTEM>
         TIME_STAMP_SHORT        =	0x80,     // 10000000    Prefix contains time stamp on short format HH:MM:SS
         TIME_STAMP              =	0x20,     // 00100000    Prefix contains time stamp
         FILE_PATH               =	0x10,     // 00010000    Prefix contains the full system path to the file where the error is generated
         FILE_NAME               =	0x08,     // 00001000    Prefix contains the name of the source file
         FUNCTION_NAME           =	0x04,     // 00000100    Prefix class and function name on the format CLASS::FUNCTION (for global function only the function name is shown)
         LINE_NO                 =	0x02,     // 00000010    Append the line number where the message was generated
         MESSAGE_BODY            =	0x01,     // 00000001    Wether or not to append the message itself
         PREFIX_OFF              =	0x01,     // 00000001    No prefix, only the message body. (same effect as MESSAGE_BODY)
         SHORT_MSG               =	0x4B,     // 01001011    Short message containing just, msg format and function name / line
         USER_SHORT_MSG          =	0x81,     // 10000001    Short User message containing just, Time Stamp short format and message body
         PREFIX_ALL              =	0xff      // 11111111    Prefix contains all options
    };


	inline eMSGSYSTEM operator | ( const eMSGSYSTEM &lhs, const eMSGSYSTEM &rhs )
	{
		return (eMSGSYSTEM)((int)lhs | (int)rhs);
	}

	inline eMSGLEVEL operator | ( const eMSGLEVEL &lhs, const eMSGLEVEL &rhs )
	{
		return (eMSGLEVEL)((int)lhs | (int)rhs);
	}

	inline eMSGFORMAT operator | ( const eMSGFORMAT &lhs, const eMSGFORMAT &rhs )
	{
		return (eMSGFORMAT)((int)lhs | (int)rhs);
	}

	inline eMSGTARGET operator | ( const eMSGTARGET &lhs, const eMSGTARGET &rhs )
	{
		return (eMSGTARGET)((int)lhs | (int)rhs);
	}

	inline eMSGSYSTEM operator & ( const eMSGSYSTEM &lhs, const eMSGSYSTEM &rhs )
	{
		return (eMSGSYSTEM)((int)lhs & (int)rhs);
	}

	inline eMSGLEVEL operator & ( const eMSGLEVEL &lhs, const eMSGLEVEL &rhs )
	{
		return (eMSGLEVEL)((int)lhs & (int)rhs);
	}

	inline eMSGFORMAT operator & ( const eMSGFORMAT &lhs, const eMSGFORMAT &rhs )
	{
		return (eMSGFORMAT)((int)lhs & (int)rhs);
	}

	inline eMSGTARGET operator & ( const eMSGTARGET &lhs, const eMSGTARGET &rhs )
	{
		return (eMSGTARGET)((int)lhs & (int)rhs);
	}


}
