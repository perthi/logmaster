// -*- mode: c++ -*-

#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include  "LEnums.h"
#include  "LHashMaps.h"
#include  <utilities/GDefinitions.h>
//#include  <logging/LMessageFactory.h>

#include  <string>


class TestLConfig_apply_get_level_Test;


namespace LOGMASTER
{
    /*
    class LLogging;
    class LValidateArgs;
    class LMessageFactory;
    class LPublisher;
    class LHashMaps;
*/

    
    /** Holds the configuration for the logging system. There is one LConfig object for 
     * each log target. The objects hold information about the current loglevel for various sub-systems, 
     * the log format, and where to write the output. When the  a logging macro is called the logging system
     * checks with this object if, how, and where (to which file) a message should be written */
    class LConfig
    {
        //friend class LMessageFactory;
        friend class LLogging;
        friend class LValidateArgs;
        friend class LPublisher;
        friend class TestLConfig_apply_get_level_Test;
        friend class LMessageFactory;

   public:
        API LConfig();
        void API InitHash(  );
        std::string API DoxygenDoc(const string &filename) ;
        std::string          API     GetFilename();
        eMSGFORMAT      API     GetLogFormat()  const  { return fLogFormat; };
        eLOGLEVEL       API     GetLogLevel(const eMSGSYSTEM system) const;
        LHashMaps       API *   GetHash();
        static string   API     GetTimeMode();
        
        void            API     SetLogFormat(const   std::string &format, bool enable);
        void            API     SetLogLevel(const    std::string  &level );
        void            API     SetLogFileName(const std::string &filename );
        static void     API     SetTimeMode(const    std::string mode);
        bool            API     IsInitialized() const { return fIsInitialized; };
        void            API     FilterOut( eMSGSYSTEM &sys,  vector<eMSGSYSTEM>  systems);

    private:
      //  API LConfig();
        void            API     SetLogFormat(const eMSGFORMAT);
        void            API     SetLogLevel( const eMSGSYSTEM  sys, const eLOGLEVEL level );
        void            API     ApplyLevel( const eLOGLEVEL l, const bool pad = true );
        void            API     ApplyLevel(const eMSGSYSTEM s, const eLOGLEVEL l, const bool pad = true);
        bool fIsInitialized  = false;
        eMSGFORMAT             fLogFormat = eMSGFORMAT::PREFIX_ALL; // 11111111 i.e all fields enabled
        std::string            fLogFilename = "mylogfile.log";
        LHashMaps              fHash;
    
        static string fTimeMode;
    
    };
}

