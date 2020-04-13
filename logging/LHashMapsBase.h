// -*- mode: c++ -*-
#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include <logging/LEnums.h>
#include <logging/LHashMapsBase.h>
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

	class LHashMaps;
	class LConfig;
	class LLogging;

	class LHashMapsBase
	{
        friend LHashMaps;
        friend LConfig;
        friend LLogging;

    private:
        API LHashMapsBase();
        API LHashMapsBase(const eMSGLEVEL level);
        API ~LHashMapsBase();
        static void API InitHashLogTags();
        static void API InitHashSystem2String();
        static void API InitHashLevel2String();
        void API InitHashLogLevel(const eMSGLEVEL level);
        static map<string, std::tuple<eMSGSYSTEM, eMSGLEVEL>> fSubCmdHash;
        static map<string, eMSGTARGET> fTargetHash;
        static map<string, eMSGFORMAT> fFormatHash;
        static map<eMSGSYSTEM, string> fSystem2StringHash;
        static map<eMSGLEVEL, string> fLevel2StringHash;
        map<eMSGSYSTEM, eMSGLEVEL> fLogLevelHash;
        eMSGLEVEL fDefaultLevel;
        bool fIsInitialized = false;
    };

}
