// -*- mode: c++ -*-

/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

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



#include "LHashMapsBase.h"
#include <utilities/GNumbers.h>
#include <utilities/GUtilities.h>


map < string, std::tuple< LOGMASTER::eMSGSYSTEM, LOGMASTER::eMSGLEVEL > >  LOGMASTER::LHashMapsBase::fSubCmdHash;
map < string, LOGMASTER::eMSGTARGET>	LOGMASTER::LHashMapsBase::fTargetHash = map < string, LOGMASTER::eMSGTARGET>();
map < string, LOGMASTER::eMSGFORMAT>	LOGMASTER::LHashMapsBase::fFormatHash;
map < LOGMASTER::eMSGSYSTEM, string >	LOGMASTER::LHashMapsBase::fSystem2StringHash = map < LOGMASTER::eMSGSYSTEM, string >();
map < LOGMASTER::eMSGLEVEL, string  >	LOGMASTER::LHashMapsBase::fLevel2StringHash = map < LOGMASTER::eMSGLEVEL, string  >();



namespace LOGMASTER
{
    LHashMapsBase::LHashMapsBase( ) : fLogLevelHash(), fDefaultLevel(eMSGLEVEL::LOG_WARNING)
    {
        ///InitHash( eMSGLEVEL::LOG_WARNING );
    }


    LHashMapsBase::LHashMapsBase( const eMSGLEVEL  level) : fLogLevelHash(), fDefaultLevel( level )
    {

    }

    LHashMapsBase::~LHashMapsBase()
    {
    }




    /** @brief initialization of the hash table for the logginglevel
    *
    *  This hash table holds the current logging level for a given sub-system. This table is checked every time the logging system is asked to log a message, and if logging is enabled for the given level
    *  and sub-system then the message is created. Where the message is actuall written (if at all) is decided by the target configuration, wether or not logging is enabled to to file, to console, etc..
    *  @param l  All system are initialized with logging for this level or higher.  */
    // void
    // LHashMapsBase::InitHashLogLevel(const eMSGLEVEL l)
    // {
    //         fLogLevelHash.clear();
    //         eMSGLEVEL level = (eMSGLEVEL)(PAD((int)l));

    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_EX,      (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_ERROR)  );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER,    level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_FSM,     level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM,   (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_MESSAGE, level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_COM,     level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_API,     level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_XML,     level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL, level );
    //         fLogLevelHash.emplace(eMSGSYSTEM::SYS_NONE,    level );

    // }


void
LHashMapsBase::InitHashLogLevel(const eMSGLEVEL /*l*/)
{
        fLogLevelHash.clear();
//      eMSGLEVEL level = (eMSGLEVEL)(PAD((int)l));
        fLogLevelHash.emplace(eMSGSYSTEM::SYS_FSM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
        fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
        fLogLevelHash.emplace(eMSGSYSTEM::SYS_MESSAGE, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
        fLogLevelHash.emplace(eMSGSYSTEM::SYS_COM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
        fLogLevelHash.emplace(eMSGSYSTEM::SYS_XML, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
}


    void
    LHashMapsBase::InitHashSystem2String()
    {
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_EX,       "Exeption");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_GENERAL,  "General");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_USER,     "User");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_FSM,      "FSM");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_ALL,      "ALL systems");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_ALARM,    "Alarm");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_MESSAGE,  "Message");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_COM,      "COM");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_XML,      "XML");
        fSystem2StringHash.emplace(eMSGSYSTEM::SYS_NONE,     "System Unknown");
    }


    void
    LHashMapsBase::InitHashLevel2String()
    {
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_OFF,         "OFF");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_FATAL,       "Fatal");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_ERROR,       "Error");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_WARNING,     "Warning");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_INFO,        "Info");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_DEBUG,       "Debug");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_FORCE_DEBUG, "Force_Debug");
        fLevel2StringHash.emplace(eMSGLEVEL::LOG_ALL,         "ALL loglevels");
    }


    void
    LHashMapsBase::InitHashLogTags()
    {

        fSubCmdHash.emplace("--fsm-off",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--fsm-fatal",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--fsm-error",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--fsm-warning",		std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--fsm-info",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--fsm-debug",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--fsm-all",			std::make_pair(eMSGSYSTEM::SYS_FSM,			eMSGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--message-off",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--message-fatal",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--message-error",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--message-warning",	std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--message-info",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,     eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--message-debug",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--message-all",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--msg-off",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--msg-fatal",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--msg-error",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--msg-warning",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--msg-info",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,     eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--msg-debug",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--msg-all",			std::make_pair(eMSGSYSTEM::SYS_MESSAGE,		eMSGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--com-off",			std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--com-fatal",	        std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--com-error",		    std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--com-warning",		std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--com-info",		    std::make_pair(eMSGSYSTEM::SYS_COM,         eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--com-debug",		    std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--com-all",			std::make_pair(eMSGSYSTEM::SYS_COM,		    eMSGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--api-off",			std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--api-fatal",	        std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--api-error",		    std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--api-warning",		std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--api-info",		    std::make_pair(eMSGSYSTEM::SYS_API,         eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--api-debug",		    std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--api-all",			std::make_pair(eMSGSYSTEM::SYS_API,		    eMSGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--xml-off",			std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--xml-fatal",	        std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--xml-error",		    std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--xml-warning",		std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--xml-info",		    std::make_pair(eMSGSYSTEM::SYS_XML,         eMSGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--xml-debug",		    std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--xml-all",			std::make_pair(eMSGSYSTEM::SYS_XML,		    eMSGLEVEL::LOG_ALL));

    }
}

