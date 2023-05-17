// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Wed 17 May-2023 06:52:23  ***/
/*** Generated from config\logging.xml **/
/*** Validated by config\logging.xsd **/

/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/
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

#pragma once


 #ifdef __cplusplus
enum class eMSGSYSTEM
#else
enum  eMSGSYSTEM
#endif
 {
	SYS_NONE		=  0x0000,    //  00000000 00000000    No sub system
	SYS_EX			=  0x0001,    //  00000000 00000001    The exception handling sub system
	SYS_FSM 		=  0x0002,    //  00000000 00000010
	SYS_MESSAGE 		=  0x0004,    //  00000000 00000100
	SYS_COM 		=  0x0008,    //  00000000 00001000
	SYS_XML 		=  0x0010,    //  00000000 00010000
	SYS_DATABASE 		=  0x0020,    //  00000000 00100000
	SYS_USER 		=  0x0040,    //  00000000 01000000
	SYS_GENERAL 		=  0x0080,    //  00000000 10000000
	SYS_ALARM 		=  0x0100,    //  00000001 00000000
	SYS_ALL			=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)
};



/*Enum controlling the log level*/
#ifdef __cplusplus
enum class  eLOGLEVEL
#else
enum eLOGLEVEL
#endif
{
	LOG_OFF			=  0x00,    //  00000000   No sub system
	LOG_FATAL 		=  0x01,    //  00000001
	LOG_ERROR 		=  0x02,    //  00000010
	LOG_WARNING 		=  0x04,    //  00000100
	LOG_INFO 		=  0x08,    //  00001000
	LOG_DEBUG 		=  0x10,    //  00010000
	LOG_FORCE_DEBUG		= 0x20,  // 00100000
	LOG_ALL			=  0xff,    //  11111111   All sub systems
};
