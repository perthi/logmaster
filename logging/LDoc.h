// -*- mode: c++ -*-

#pragma once
/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/


/** @class LOGMASTER::LDoc
*   @brief Class that provides brief documentation, written to the console, for the logging system  
*   
*Basic documentation for the loggings system that is written out to the console 
*   There are 3 main switches for the logging system (please refer to user documentation in Confluence for details ) 
*   -  - -loglevel
*   -  - -logtarget
*   -  - -logformat 
* <br>
*  If any of these command line switches are used incorrectly then this class provides a help menu that is written out to the console */




#include "LLogApi.h"
#include <utilities/GDefinitions.h>
#include <utilities/GUtilities.h>

#include <string>
using std::string;
#include <map>
using std::map;
#include <bitset>
#include <fstream>
using std::ofstream;


namespace LOGMASTER
{
    class LDoc
    {
    public:
        inline  static  string    API  LogLevelDoc();
        inline  static  string    API  LogTargetDoc();
        inline  static  string    API  LogFormatDoc();
        inline  static  void      API  PrintLogLevels(bool toconsole = false);
        inline  static  string    API  Help();
        static string             API UsageError(const string &cmnd, const string &sub, const map <string, std::tuple<  eMSGSYSTEM, eLOGLEVEL > > &m);
    };
}



namespace LOGMASTER
{
    inline string
    LDoc::UsageError(const string &cmnd, const string &sub, const map <string, std::tuple<  eMSGSYSTEM, eLOGLEVEL > >  &m)
    {
        std::stringstream buffer;
        buffer << "Invalid/bad combination command/subcommand: " << sub << " To " << cmnd << ".\nValid subcommands are:" <<  g_utilities()->Hash2String(&m);
        buffer << Help();
        return buffer.str();
    }


    inline string
    LDoc::LogTargetDoc()
    {
        return string("[logtarget]\n")
            + string("\t\tLogtarget can be either a field with 3 bits or any of the following\n\t\t")
            + g_utilities()->Hash2String ( LHashMaps::GetTargetHash( ) );
    }


    inline string
    LDoc::LogLevelDoc()
    {
        return string("[loglevel]\n")
            + string("\t\tLoglevel can be any of the following\n\t\t")
            + g_utilities()->Hash2String(LHashMaps::GetSubCmdHash())
            + "\t\tThe loglevel to use,the subcommand (starting with --) has two terms,\
the first one denotes the\n\t\tsubsystem the second one the loglevel for that subsystem.\n\t\t \
Example 1) --all-debug = All subsystem is using loglevel debug\n\t\tExample 2) --ana-error Error messages from the QA subsystem system, etc..";
    }


    inline string
    LDoc::LogFormatDoc()
    {
        return string("[logformat]\n")
            + string("\t\tlogformat can be any of the following\n\t\t")
            + g_utilities()->Hash2String(LHashMaps::GetFormatHash());
    }


    inline void 
    LDoc::PrintLogLevels(bool toconsole)
    {
        ostringstream s;
        std::ofstream f;
        f.open("loglevels.txt");

        auto hash = LHashMaps::GetSubCmdHash();
    
        for (auto it = hash->begin(); it != hash->end(); it ++ )
        {
            std::bitset<16>  b( (int32_t)std::get<0>(it->second) );

            if (it->first.size() < 8)
            {
                s << it->first  <<  "\t\t\t" <<  b  <<  "\t0x"  <<  std::hex << (int32_t)std::get<0>(it->second) << endl;
            }
            else if (it->first.size() < 16)
            {
                s << it->first  <<  "\t\t"   <<  b  <<  "\t0x"  <<  std::hex <<  (int32_t)std::get<0>(it->second)  << endl;
            }
            else
            {
                s << it->first << "\t" << b << "\t0x" << std::hex << std::hex << (int32_t)std::get<0>(it->second)  << endl;
            }
        }
        if (toconsole == true)
        {
            cout << s.str() << endl;
        }
        f << s.str();
        f.close();
    }


    inline string
    LDoc::Help()
    {
        std::stringstream buffer;
        buffer << "*** USAGE ***" << endl;
        buffer << "1) Either Use any number of subcommands ( starting with --)" << endl;
        buffer << "2) OR: Specify a number indicating the log level" << endl;
        buffer << "3) If on number form the number must be either a string of  ZERO and ONES containing exactly 16 bits" << endl;
        buffer << "\tOr a hex number starting with 0x and  having exactly 4 fields" << endl;
        
        buffer  << "****  SUB COMMANDS CONTROLLING THE LOGLEVEL ***** " << endl;

        buffer  << g_utilities()->Hash2String (LHashMaps::GetSubCmdHash() ) << endl;
        buffer << "           ****   DONE *****                        "    << endl;    
         
        buffer  << "****  SUB COMMANDS CONTROLLING THE FORMAT ***** " << endl;
        buffer  << g_utilities()->Hash2String(LHashMaps::GetFormatHash());
        buffer << "           ****   DONE *****                        "    << endl;    
        buffer  << "****  SUB COMMANDS LOG TARGETS ***** " << endl;
        buffer << g_utilities()->Hash2String (LHashMaps::GetTargetHash( )) << endl;

        buffer << "           ****   DONE *****                        "    << endl;  

        return buffer.str();
    }

}
