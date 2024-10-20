// -*- mode: c++ -*-
#pragma once

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

#include <string>
using std::string;
#include <typeinfo>
#include "GDefinitions.h"

#define GLOCATION  GLocation(__FILE__, __LINE__, __FUNCTION__)
#define SETPOS() { location = GLocation(__FILE__, __LINE__, __func__); }

#include <mutex>
#include <thread>


/** @brief Helper class to stor information about source code location */
class GLocation
{
public:
    inline GLocation() {};
    inline GLocation(const string fname, const int lineno, const string funct ) : fFileName(fname), fLineNo(lineno), fFunctName(funct) {}
    string fFileName = "";
    int   fLineNo = -1;
    string fFunctName = "";


    inline const char * c_str() const
    {    
  //    static  thread_local std::mutex m;
  //    std::lock_guard<std::mutex> guard( m );
       static thread_local string str_local;
       str_local = str();
       return str_local.c_str();
   }


    inline string & str() const
    {
//        static  thread_local std::mutex m;
//        std::lock_guard<std::mutex> guard( m );
        //static int max_size = 1024;
        static thread_local char loc[(int)1024] = {0};

        SPRINTF(loc, (int)1024, "%s[line%d]: %s", fFileName.c_str(), fLineNo, fFunctName.c_str());

        static thread_local string str_local;
        str_local = loc;

        return str_local;

        //return  string(loc);
    }

};

