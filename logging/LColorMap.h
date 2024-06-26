// -*- mode: c++ -*-

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#pragma once

#include "LEnums.h"
#include <tuple>
#include <map>
#include <string>
using std::string;

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif


namespace LOGMASTER
{

   /**  @brief Color definitions for the logging system  
    *   @details  this class holds information about
    *   which colors various log messages is displayed with when printing them out to the console  */
   class LColorMap
   {
   public:
      static LColorMap API *Instance();
      std::map<eLOGLEVEL, std::tuple<string, int, int, int>> const API *GetMap() { return &fMap; }
      int API GetRGB(const eLOGLEVEL l);
      int API GetCColor(const eLOGLEVEL l);
      int API GetAnsiColor(const eLOGLEVEL l);

   private:
      LColorMap();
      ~LColorMap(){};
      void API Init();
      std::map<eLOGLEVEL, std::tuple<string, int, int, int>> fMap;
   };

} // namespace LOGMASTER