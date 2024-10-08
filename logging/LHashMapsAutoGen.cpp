// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Sat 17 August-2024 02:36:27  ***/
/*** Generated from config/logging-ecostor.xml **/
/*** Validated by config/logging.xsd **/

/***************************************************
* @copyright Embedded Consulting AS    2024        *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

/********************************************************************************
*********************************************************************************
*** This file is part of logmaster.                                           ***
*** Copyright (C) 2024 Per Thomas Hille <pth@embc.no>  http:///www.embc.no    ***
*** all rights reserved                                                       ***
***                                                                           ***
*** logmaster is free software: you can redistribute it and/or modify         ***
*** it under the terms of the Lesser GNU General Public License (LGPL)        ***
*** as published by the Free Software Foundation, either version 3 of the     ***
*** License, or (at your option) any later version.                           ***
***                                                                           ***
*** logmaster is distributed in the hope that it will be useful,              ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of            ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             ***
*** GNU General Public License for more details.                              ***
***                                                                           ***
*** You should have received a copy of the Lesser GNU General Public          ***
*** License along with logmaster in the README file in the source code        ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                    ***
*********************************************************************************
*********************************************************************************/

#include "LHashMapsAutoGen.h"
#include <utilities/GNumbers.h>
#include <utilities/GUtilities.h>



namespace LOGMASTER
{
LHashMapsAutoGen::LHashMapsAutoGen( ) : fLogLevelHash() {}
LHashMapsAutoGen::~LHashMapsAutoGen(){ }






/** @brief initialization of the hash table for the logging level     *     *  This hash table holds the current logging level for a given sub-system.     *  This table is checked every time the logging system is asked to log a message, and if logging     *  is enabled for the given level and sub-system then the message is created.     *  Where the message is actually written (if at all) is decided by the target configuration,    *  whether or not logging is enabled to file, to console, etc.. */
   void
   LHashMapsAutoGen::InitHashLogLevel( )
   {
	fLogLevelHash.clear();
//	eLOGLEVEL level = (eLOGLEVEL)(PAD((int)l));
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_EXCEPTION, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_ERROR) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_FSM, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_MESSAGE, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_EMS, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_MBMS, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_BIU, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_RESTAPI, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_XML, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_DATABASE, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM, (eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING) );
   }



   void
   LHashMapsAutoGen::InitHashSystem2String( map<eMSGSYSTEM, string>  *System2StringHash )
   {
	System2StringHash->emplace(eMSGSYSTEM::SYS_NONE,     "System Unknown");
	System2StringHash->emplace(eMSGSYSTEM::SYS_EXCEPTION, 	"Exception");
	System2StringHash->emplace(eMSGSYSTEM::SYS_FSM, 	"Fsm");
	System2StringHash->emplace(eMSGSYSTEM::SYS_MESSAGE, 	"Message");
	System2StringHash->emplace(eMSGSYSTEM::SYS_EMS, 	"Ems");
	System2StringHash->emplace(eMSGSYSTEM::SYS_MBMS, 	"Mbms");
	System2StringHash->emplace(eMSGSYSTEM::SYS_BIU, 	"Biu");
	System2StringHash->emplace(eMSGSYSTEM::SYS_RESTAPI, 	"Restapi");
	System2StringHash->emplace(eMSGSYSTEM::SYS_XML, 	"Xml");
	System2StringHash->emplace(eMSGSYSTEM::SYS_DATABASE, 	"Database");
	System2StringHash->emplace(eMSGSYSTEM::SYS_USER, 	"User");
	System2StringHash->emplace(eMSGSYSTEM::SYS_GENERAL, 	"General");
	System2StringHash->emplace(eMSGSYSTEM::SYS_ALARM, 	"Alarm");
   }



   void
   LHashMapsAutoGen::InitHashLevel2String(  map<eLOGLEVEL, string> *Level2StringHash  )
   {
	Level2StringHash->emplace(eLOGLEVEL::LOG_OFF, "OFF");
	Level2StringHash->emplace(eLOGLEVEL::LOG_FORCE_DEBUG, "Force_Debug");
	Level2StringHash->emplace(eLOGLEVEL::LOG_FATAL,	"Fatal");
	Level2StringHash->emplace(eLOGLEVEL::LOG_ERROR,	"Error");
	Level2StringHash->emplace(eLOGLEVEL::LOG_WARNING,	"Warning");
	Level2StringHash->emplace(eLOGLEVEL::LOG_INFO,	"Info");
	Level2StringHash->emplace(eLOGLEVEL::LOG_DEBUG,	"Debug");
	Level2StringHash->emplace(eLOGLEVEL::LOG_FORCE_DEBUG,	"Force_debug");
	Level2StringHash->emplace(eLOGLEVEL::LOG_ALL, "ALL log-levels");
   }



   void
   LHashMapsAutoGen::InitHashLogTags(  map<string, std::tuple<eMSGSYSTEM, eLOGLEVEL>>  *SubCmdHash   )
   {
	SubCmdHash->emplace("--exception-off",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--exception-fatal",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--exception-error",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--exception-warning",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--exception-info",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--exception-debug",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--exception-force_debug",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--exception-all",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--ex-off",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--ex-fatal",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--ex-error",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--ex-warning",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--ex-info",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--ex-debug",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--ex-force_debug",	std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--ex-all",		std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--fsm-off",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--fsm-fatal",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--fsm-error",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--fsm-warning",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--fsm-info",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--fsm-debug",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--fsm-force_debug",	std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--fsm-all",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--message-off",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--message-fatal",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--message-error",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--message-warning",	std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--message-info",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--message-debug",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--message-force_debug",	std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--message-all",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--msg-off",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--msg-fatal",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--msg-error",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--msg-warning",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--msg-info",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--msg-debug",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--msg-force_debug",	std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--msg-all",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--ems-off",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--ems-fatal",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--ems-error",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--ems-warning",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--ems-info",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--ems-debug",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--ems-force_debug",	std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--ems-all",		std::make_pair(eMSGSYSTEM::SYS_EMS,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--mbms-off",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--mbms-fatal",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--mbms-error",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--mbms-warning",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--mbms-info",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--mbms-debug",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--mbms-force_debug",	std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--mbms-all",		std::make_pair(eMSGSYSTEM::SYS_MBMS,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--biu-off",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--biu-fatal",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--biu-error",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--biu-warning",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--biu-info",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--biu-debug",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--biu-force_debug",	std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--biu-all",		std::make_pair(eMSGSYSTEM::SYS_BIU,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--restapi-off",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--restapi-fatal",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--restapi-error",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--restapi-warning",	std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--restapi-info",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--restapi-debug",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--restapi-force_debug",	std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--restapi-all",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--rest-off",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--rest-fatal",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--rest-error",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--rest-warning",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--rest-info",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--rest-debug",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--rest-force_debug",	std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--rest-all",		std::make_pair(eMSGSYSTEM::SYS_RESTAPI,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--xml-off",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--xml-fatal",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--xml-error",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--xml-warning",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--xml-info",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--xml-debug",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--xml-force_debug",	std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--xml-all",		std::make_pair(eMSGSYSTEM::SYS_XML,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--database-off",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--database-fatal",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--database-error",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--database-warning",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--database-info",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--database-debug",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--database-force_debug",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--database-all",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--db-off",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--db-fatal",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--db-error",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--db-warning",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--db-info",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--db-debug",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--db-force_debug",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--db-all",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--user-off",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--user-fatal",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--user-error",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--user-warning",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--user-info",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--user-debug",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--user-force_debug",	std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--user-all",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--usr-off",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--usr-fatal",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--usr-error",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--usr-warning",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--usr-info",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--usr-debug",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--usr-force_debug",	std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--usr-all",		std::make_pair(eMSGSYSTEM::SYS_USER,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--general-off",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--general-fatal",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--general-error",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--general-warning",	std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--general-info",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--general-debug",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--general-force_debug",	std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--general-all",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_ALL));
	SubCmdHash->emplace("--gen-off",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--gen-fatal",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--gen-error",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--gen-warning",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--gen-info",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--gen-debug",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--gen-force_debug",	std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--gen-all",		std::make_pair(eMSGSYSTEM::SYS_GENERAL,  eLOGLEVEL::LOG_ALL));


	SubCmdHash->emplace("--alarm-off",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_OFF));
	SubCmdHash->emplace("--alarm-fatal",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_FATAL));
	SubCmdHash->emplace("--alarm-error",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_ERROR));
	SubCmdHash->emplace("--alarm-warning",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_WARNING));
	SubCmdHash->emplace("--alarm-info",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_INFO));
	SubCmdHash->emplace("--alarm-debug",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_DEBUG));
	SubCmdHash->emplace("--alarm-force_debug",	std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_FORCE_DEBUG));
	SubCmdHash->emplace("--alarm-all",		std::make_pair(eMSGSYSTEM::SYS_ALARM,  eLOGLEVEL::LOG_ALL));


   }



   void
   LHashMapsAutoGen::InitHashPermissions( map<eMSGSYSTEM, bool>  *permHash )
   {
        permHash->emplace( eMSGSYSTEM::SYS_EXCEPTION,false);
        permHash->emplace( eMSGSYSTEM::SYS_FSM,true);
        permHash->emplace( eMSGSYSTEM::SYS_MESSAGE,true);
        permHash->emplace( eMSGSYSTEM::SYS_EMS,true);
        permHash->emplace( eMSGSYSTEM::SYS_MBMS,true);
        permHash->emplace( eMSGSYSTEM::SYS_BIU,true);
        permHash->emplace( eMSGSYSTEM::SYS_RESTAPI,true);
        permHash->emplace( eMSGSYSTEM::SYS_XML,true);
        permHash->emplace( eMSGSYSTEM::SYS_DATABASE,true);
        permHash->emplace( eMSGSYSTEM::SYS_USER,true);
        permHash->emplace( eMSGSYSTEM::SYS_GENERAL,true);
        permHash->emplace( eMSGSYSTEM::SYS_ALARM,false);
   }
}
