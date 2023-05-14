// -*- mode: c++ -*-
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

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Sun 14 May-2023 17:21:19  ***/
/*** Generated from config\logging.xml **/
/*** Validated by config\logging.xsd **/


//MANDATORY BEGIN !!
#ifdef _WIN32
#define __func__ __FUNCTION__
#endif
#include  <logging/LEnums.h>
#include  <logging/LLogging.h>
#include  <logging/LOperators.h>
#include  <utilities/GDefinitions.h>



#ifdef ERROR
#undef ERROR
#endif



#ifdef __cplusplus



#include <utilities/GLocation.h>



#define SET_LOGLEVEL(level)          LLogging::Instance()->SetLogLevel(level )
#define SET_LOGFORMAT(format )       LLogging::Instance()->SetLogFormat(format )
#define SET_LOGTARGET(target )       LLogging::Instance()->SetLogTarget(target )
#define SET_LOGFILENAME(filename)    LLogging::Instance()->SetLogFileName(filename )
#define SET_APPLICATION(src)         LLogging::Instance()->SetApplication(src) 



#define PUSH()                       LLogging::Instance()->Push(  )
#define POP()                        LLogging::Instance()->Pop(  )
#define LOG_DATA(data, ...)          LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,  eMSGSYSTEM::SYS_DATA,  GLocation( __FILE__, __LINE__, __func__ ), data,  __VA_ARGS__)
#define G_LOG(level, system, ...)    LLogging::Instance()->Log( level, system,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)



#define FORCE_DEBUG(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_FORCE_DEBUG, eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define EX_ERROR(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define EX_FATAL(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)



#define ALL_DEBUG(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_INFO(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_WARNING(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_ERROR(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_FATAL(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_ASSERT_DEBUG(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_INFO(expr, ...)       if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_WARNING(expr, ...)    if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_ERROR(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_FATAL(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)



//MANDATORY END !!
#define FSM_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define MESSAGE_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define COM_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define XML_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define DATABASE_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_WARNING_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define USER_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define GENERAL_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FATAL_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ERROR_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_WARNING(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_INFO_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_DEBUG_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define ALARM_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)









#endif



