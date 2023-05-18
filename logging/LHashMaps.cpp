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

//#pragma once

#include "LHashMaps.h"
#include <utilities/GNumbers.h>
#include <utilities/GUtilities.h>


namespace LOGMASTER
{
    LHashMaps::LHashMaps( )
    {
        InitHash(  );
        InitHashLogLevel( );
    }


    LHashMaps::~LHashMaps()
    {
    }


    LHashMaps *
    LHashMaps::Instance()
    {
        static   LHashMaps *instance = new LHashMaps();
        return   instance;

    }
 
        
    void
    LHashMaps::InitHash()
    {
        static bool is_initialized = false;

        if ( is_initialized == false )
        {
            InitHashMsgFormat();
            InitHashLogTargets();
            InitHashLogTags();
            InitHashSystem2String( &fSystem2StringHash );
            InitHashLevel2String( &fLevel2StringHash);
         
            is_initialized = true;
        }

    }


    map < string, std::tuple<  eMSGSYSTEM, eLOGLEVEL > >      *
    LHashMaps::GetSubCmdHash()
    {
        InitHash();
        return  &fSubCmdHash;
    }


    map < string, eMSGTARGET>  *
    LHashMaps::GetTargetHash()
    {
        InitHash();
        return  &fTargetHash;
    }

    map < string, eMSGFORMAT>  *
        LHashMaps::GetFormatHash()
    {
        InitHash();
        return  &fFormatHash;
    }


    map<eMSGSYSTEM, string>
        * LHashMaps::GetSystem2StringHash()
    {
        InitHash();
        return &fSystem2StringHash;
    }


    map<eLOGLEVEL, string> *
    LHashMaps::GetLevel2StringHash()
    {
        InitHash();
        return &fLevel2StringHash;
    }


    eMSGTARGET
    LHashMaps::GetTarget( const string & hash )
    {
        InitHash();
        auto it = fTargetHash.find( hash );

        if ( it != fTargetHash.end() )
        {
            return it->second;
        }
        else
        {
            return (eMSGTARGET)0;
        }
    }


    eMSGFORMAT
    LHashMaps::GetFormat( const string & hash )
    {
        InitHash();
        auto it = fFormatHash.find(hash);

        if ( it != fFormatHash.end() )
        {
            return it->second;
        }
        else
        {
            return (eMSGFORMAT)0;
        }

    }


    vector<eMSGTARGET>
    LHashMaps::GetTargetEnums()
    {
        InitHash();
        static vector<eMSGTARGET> tmp;
        static bool is_first = true;

        if ( is_first == true )
        {
            for ( auto it = fTargetHash.begin(); it != fTargetHash.end(); it++ )
            {
                tmp.push_back( it->second );
            }

            is_first = false;
        }

        return tmp;
    }


    vector<eMSGFORMAT>
    LHashMaps::GetFormatEnums()
    {
        InitHash();
        static vector<eMSGFORMAT> tmp;
        static bool is_first = true;

        if ( is_first == true )
        {
            for ( auto it = fFormatHash.begin(); it != fFormatHash.end(); it++ )
            {
                tmp.push_back( it->second );

            }
            is_first = false;
        }
        return tmp;
    }


    vector<eMSGSYSTEM>
    LHashMaps::GetSystemEnums()
    {
        InitHash();
        static vector<eMSGSYSTEM> tmp;
        static bool is_first = true;

        if ( is_first == true )
        {
            for (auto it = fSystem2StringHash.begin(); it != fSystem2StringHash.end(); it++)
            {
                tmp.push_back(it->first );
            }
            is_first = false;
        }

        return tmp;
    }


    vector<eLOGLEVEL>
    LHashMaps::GetLevelEnums()
    {
            InitHash();
            static vector<eLOGLEVEL> tmp;
            static bool is_first = true;

            if ( is_first == true )
            {

        for (auto it = fLevel2StringHash.begin(); it != fLevel2StringHash.end(); it++)
        {
                    tmp.push_back(it->first);
        }

                is_first = false;
            }
            return tmp;
    }




    vector<string>
        LHashMaps::GetLogLevelTags()
    {
            InitHash();
            return g_utilities()->Hash2StringV(&fSubCmdHash);
    }


    vector<string>
    LHashMaps::GetLogTargetTags()
    {
        InitHash();
        return g_utilities()->Hash2StringV(&fTargetHash);
    }


    vector<string>
    LHashMaps::GetLogFormatTags()
    {
        InitHash();
        return g_utilities()->Hash2StringV(&fFormatHash);
    }


    bool
    LHashMaps::IsTargetHash( const string &target )
    {
        InitHash();
        return  fTargetHash.count( target ) > 0 ? true : false;
    }


    bool
    LHashMaps::IsFormatHash( const string &format )
    {
        InitHash();
        return fFormatHash.count( format ) > 0 ? true : false;
    }


    bool
    LHashMaps::IsSubCmdHash( const string &subcmd )
    {
        InitHash();
        return fSubCmdHash.count( subcmd ) > 0 ? true : false;
    }


    string
    LHashMaps::DoxygenDoc(const string filename)
    {
        InitHash();
        FILE *fp;

#ifdef _WIN32
        fopen_s(&fp, filename.c_str(), "w");
#else
        fp =  fopen(filename.c_str(), "w");
#endif
        if (fp == 0)
        {
            CERR << "Could not open file:" << filename << "   for writing" << endl;
            return "";
        }
        else
        {
            fprintf(fp, "%s", "/**  \\page \"Logging System\"\n");
            fprintf(fp, "%s", "* \\section command_line_options Command line options for the logging system\n");
            fprintf(fp, "%s", "* Command | Parameters | Default | Explanation \n");
            fprintf(fp, "%s", "* --------- | ---------- | --------- | --------- \n");

            auto t = &fTargetHash;
            auto f = &fFormatHash;
            auto s = &fSubCmdHash;

            fprintf(fp, "%s", "* -target |");
            for (auto it = t->begin(); it != t->end(); it++)
            {
                fprintf(fp, "%s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " | --file | Where to write the log messages\n");
            fprintf(fp, "%s", "* -format |");

            for (auto it = f->begin(); it != f->end(); it++)
            {
                fprintf(fp, "%s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " |  1111111 | Options controlling the format of the log messages\n");

            fprintf(fp, "%s", "* -loglevel |");
            for (auto it = s->begin(); it != s->end(); it++)
            {
                fprintf(fp, " %s\\n", it->first.c_str());
            }

            fprintf(fp, "%s", " |  --all-error | Which subsystem / loglevel to log information from\n");
            fprintf(fp, "%s", "*/");
            fclose(fp);
        }
        /// TODO return string containing doc
        return string();
    }


    /** @brief initialization of the hash table for the formatting of the messages,  used  on the command line or via the programming API */
    void
    LHashMaps::InitHashMsgFormat()
    {
        fFormatHash.emplace("--all-off",        eMSGFORMAT::ALL_FIELDS_OFF);
        fFormatHash.emplace("--msg-type",        eMSGFORMAT::MESSAGE_TYPE);
        fFormatHash.emplace("--time-stamp",        eMSGFORMAT::TIME_STAMP);
       // fFormatHash.emplace("--time-short",        eMSGFORMAT::TIME_STAMP_SHORT);
        fFormatHash.emplace("--file-path",        eMSGFORMAT::FILE_PATH);
        fFormatHash.emplace("--file-name",        eMSGFORMAT::FILE_NAME);
        fFormatHash.emplace("--func-name",        eMSGFORMAT::FUNCTION_NAME);
        fFormatHash.emplace("--line-no",        eMSGFORMAT::LINE_NO);
        fFormatHash.emplace("--prefix-none",    eMSGFORMAT::PREFIX_OFF);
        fFormatHash.emplace("--msg-body",        eMSGFORMAT::MESSAGE_BODY);
        fFormatHash.emplace("--short",            eMSGFORMAT::SHORT_MSG);
        fFormatHash.emplace("--short-user",        eMSGFORMAT::USER_SHORT_MSG);
        fFormatHash.emplace("--prefix-all",        eMSGFORMAT::PREFIX_ALL);
    }


    /** @brief initialization of the hash table for the logging targets  used  on the command line or via the programming API */
    void
    LHashMaps::InitHashLogTargets()
    {
        fTargetHash.emplace("--target-off",         eMSGTARGET::TARGET_OFF);
        fTargetHash.emplace("--target-file",        eMSGTARGET::TARGET_FILE);
        fTargetHash.emplace("--target-stdout",      eMSGTARGET::TARGET_STDOUT);
        fTargetHash.emplace("--target-subscriber",  eMSGTARGET::TARGET_SUBSCRIBERS);
        fTargetHash.emplace("--target-gui",         eMSGTARGET::TARGET_GUI);
        fTargetHash.emplace("--target-database",    eMSGTARGET::TARGET_DATABASE);
        fTargetHash.emplace("--target-db",          eMSGTARGET::TARGET_DATABASE);
        fTargetHash.emplace("--target-all",         eMSGTARGET::TARGET_ALL);
    }


    /** @brief Initialization of hash tags for the logging system used  on the command line or via the programming API
         *
         * The hash table maps between a string tag (i.e --all, --info etc..) and the corresponding logging level and subsystem on binary format.
         * The second entry is a 32 bit integer where the most significant 8 bits represents the log level and the least significant 16 bits the subsystem.
         * The hash map is static and is initialized only once. The actual log level is contained in the fLogLevelHash hash map. The log level is padded with ones so that if a higher log level is
         * set, all lower levels are set. This is typically the behavior the user expects. For example, if the log level is EXCEPTION_CLASS_CPP(GEngineException)set to WARNING, then one would expect
         * to also get messages with higher severity, that is ERROR and FATAL.
         * The padding is done at the end, after the hash map has been populated.**/
    void
    LHashMaps::InitHashLogTags()
    {
        fSubCmdHash.emplace("--all-off",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--all-fatal",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--all-error",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--all-warning",        std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--all-info",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--all-debug",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--all-all",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_ALL));
        fSubCmdHash.emplace("--all",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_ALL));
        fSubCmdHash.emplace("--off",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--fatal",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--error",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--warning",            std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--info",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--debug",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--all",                std::make_pair(eMSGSYSTEM::SYS_ALL,            eLOGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--ex-fatal",            std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,            eLOGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--ex-error",            std::make_pair(eMSGSYSTEM::SYS_EXCEPTION,            eLOGLEVEL::LOG_ERROR));

        fSubCmdHash.emplace("--gen-off",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--gen-fatal",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--gen-error",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--gen-warning",        std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--gen-info",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--gen-debug",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--gen-all",            std::make_pair(eMSGSYSTEM::SYS_GENERAL,        eLOGLEVEL::LOG_ALL));

        fSubCmdHash.emplace("--user-off",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_OFF));
        fSubCmdHash.emplace("--user-fatal",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_FATAL));
        fSubCmdHash.emplace("--user-error",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_ERROR));
        fSubCmdHash.emplace("--user-warning",        std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_WARNING));
        fSubCmdHash.emplace("--user-info",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_INFO));
        fSubCmdHash.emplace("--user-debug",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_DEBUG));
        fSubCmdHash.emplace("--user-all",            std::make_pair(eMSGSYSTEM::SYS_USER,        eLOGLEVEL::LOG_ALL));
  
        LHashMapsAutoGen::InitHashLogTags( &fSubCmdHash );

        for (auto it = fSubCmdHash.begin(); it != fSubCmdHash.end(); ++it)
        {
            eLOGLEVEL l = std::get<1>(it->second);
            eLOGLEVEL l_padded =  (eLOGLEVEL)PAD((int)l);
            std::get<1>(it->second) = l_padded;
        }

  // }


    }
}


