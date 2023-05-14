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


#include "LLogApiAutoGen.h"

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



#endif



