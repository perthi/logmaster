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
	class LConfig;
	class LLogging;

	class LHashMaps : public LHashMapsBase
	{
		friend LConfig;
		friend LLogging;

	public:
            API    LHashMaps(  );
          //  API    LHashMaps(const eMSGLEVEL level  );
            API    ~LHashMaps();
            static  LHashMaps API* Instance();
            
            static void		API		InitHash();
          //  void			API		InitHash( const eMSGLEVEL level );
            static void		API		InitHashMsgFormat();
            static void		API		InitHashLogTags();
            static void		API		InitHashLogTargets();
         ////  void			API		InitHashLogLevel(const eMSGLEVEL level, map<eMSGSYSTEM, eMSGLEVEL> *hash );
            
            static	string							API DoxygenDoc(const string filename);
            static	map < string, std::tuple<  eMSGSYSTEM, eMSGLEVEL > >  API * GetSubCmdHash();
            static  map < string, eMSGTARGET>		API *	GetTargetHash();
            static  map < string, eMSGFORMAT>		API	*	GetFormatHash();
            static	map <eMSGSYSTEM, string >		API *	GetSystem2StringHash();
            static	map <eMSGLEVEL, string  >		API	*	GetLevel2StringHash();

            static  eMSGTARGET              API		GetTarget( const string  &hash);
            static  eMSGFORMAT              API		GetFormat( const string  &hash );
            static	vector<eMSGTARGET>		API  	GetTargetEnums();
            static	vector<eMSGFORMAT>		API  	GetFormatEnums();
            static  vector<eMSGSYSTEM>		API  	GetSystemEnums();
            static  vector<eMSGLEVEL>		API  	GetLevelEnums();
            static	vector<string>			API		GetLogLevelTags();
            static	vector<string>			API		GetLogTargetTags();
            static	vector<string>			API		GetLogFormatTags();

            static bool                     API     IsTargetHash( const string &target );
            static bool                     API     IsFormatHash( const string &format );
            static bool                     API     IsSubCmdHash( const string &subcmd );
	};

}
