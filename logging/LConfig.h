// -*- mode: c++ -*-

#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


//#include  "LDefinitions.h"
#include  "LEnums.h"
#include  "LHashMaps.h"

#include  <utilities/GDefinitions.h>

#include <string>
using std::string;


class TestLConfig_apply_get_level_Test;

namespace LOGMASTER
{
    class LLogging;
    class LValidateArgs;
    class LPublisher;
    class LHashMaps;


    
    /** Holds the configuration for the logging system. There is one LConfig object for 
     * each log target. The objects hold information about the current loglevel for various sub-systems, 
     * the log format, and where to write the output. When the  a logging macro is called the logging system
     * checks with this object if, how, and where (to which file) a message should be written */
    class LConfig
    {
        friend LLogging;
        friend LValidateArgs;
        friend LPublisher;
        friend TestLConfig_apply_get_level_Test;

   public:
        API LConfig();
        void API InitHash(  );
        string API DoxygenDoc(const string filename) ;
        string          API     GetFilename();
        eMSGFORMAT      API     GetLogFormat()  const  { return fLogFormat; };
        eLOGLEVEL       API     GetLogLevel(const eMSGSYSTEM system) const;
        LHashMaps       API *   GetHash();
        static string   API     GetTimeMode();
        
        void            API     SetLogFormat(const string &format, bool enable);
        void            API     SetLogLevel(const  string  &level );
        void            API     SetLogFileName(const string &filename );
        static void     API     SetTimeMode(const string mode);
        bool            API     IsInitialized() const { return fIsInitialized; };
        void            API     FilterOut( eMSGSYSTEM &sys,  vector<eMSGSYSTEM>  systems);

    private:
        void            API     SetLogFormat(const eMSGFORMAT);
        void            API     SetLogLevel( const eMSGSYSTEM  sys, const eLOGLEVEL level );
        void            API     ApplyLevel( const eLOGLEVEL l, const bool pad = true );
        void            API     ApplyLevel(const eMSGSYSTEM s, const eLOGLEVEL l, const bool pad = true);
        bool fIsInitialized  = false;
        eMSGFORMAT             fLogFormat = eMSGFORMAT::PREFIX_ALL; // 11111111 i.e all fields enabled
        string                 fLogFilename = "mylogfile.log";
        LHashMaps              fHash;
    
        static string fTimeMode;
    
    };
}

