// -*- mode: c++ -*-
#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include  "LEnums.h"
#include  "LHashMapsBase.h"
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
        map<eMSGLEVEL, string> fLevel2StringHash;
        map<string, std::tuple<eMSGSYSTEM, eMSGLEVEL>> fSubCmdHash;
        map<string, eMSGTARGET> fTargetHash;
        map<string, eMSGFORMAT> fFormatHash;
        map<eMSGSYSTEM, string> fSystem2StringHash;
    } // namespace

    class LHashMapsBase
	{
    protected:
        API LHashMapsBase();
        API LHashMapsBase(const eMSGLEVEL level );
        API ~LHashMapsBase();
        
        static void API InitHashLogTags(        map<string, std::tuple<eMSGSYSTEM, eMSGLEVEL>>  *SubCmdHash );
        static void API InitHashSystem2String(  map<eMSGSYSTEM, string>  *System2StringHash );
        static void API InitHashLevel2String(   map<eMSGLEVEL, string> *Level2StringHash  );
        
        void API InitHashLogLevel(const eMSGLEVEL level );
        map<eMSGSYSTEM, eMSGLEVEL> fLogLevelHash;
        eMSGLEVEL fDefaultLevel;
        bool fIsInitialized = false;

   // private:
    
      
     
    };

}
