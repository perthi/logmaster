// -*- mode: c++ -*-
#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include  "LEnums.h"
#include  "LHashMapsAutoGen.h"
#include  <utilities/GDefinitions.h>

#include <map>
#include <tuple>
#include <string>
#include <vector>

using std::string;
using std::map;
using std::vector;


namespace LOGMASTER
{
    namespace
    {
        map<eLOGLEVEL, string> fLevel2StringHash;
        map<string, std::tuple<eMSGSYSTEM, eLOGLEVEL>> fSubCmdHash;
        map<string, eMSGTARGET> fTargetHash;
        map<string, eMSGFORMAT> fFormatHash;
        map<eMSGSYSTEM, string> fSystem2StringHash;
        map<eMSGSYSTEM, bool> fPermissions;
    } 

    class LHashMapsAutoGen
    {
    protected:
        API LHashMapsAutoGen();
        API ~LHashMapsAutoGen();
        
        static void API InitHashLogTags(        map<string, std::tuple<eMSGSYSTEM, eLOGLEVEL>>  *SubCmdHash );
        static void API InitHashSystem2String(  map<eMSGSYSTEM, string>  *System2StringHash );
        static void API InitHashLevel2String(   map<eLOGLEVEL, string> *Level2StringHash  );
        void        API InitHashLogLevel( );
        void        API InitPermissions( );

      

        map<eMSGSYSTEM, eLOGLEVEL> fLogLevelHash;
        bool fIsInitialized = false;
    };

}
