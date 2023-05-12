// -*- mode: c++ -*-
//#pragma once

#ifndef GSYSTEM_HPP
#define GSYSTEM_HPP
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
#include <vector>
using std::vector;
using std::string;

#include "GDefinitions.h"
#include "GLocation.h"
#include <sys/types.h>
#include <sys/stat.h>


class GSystem;

GSystem API * g_system();

//#define  g_system()- ##> GSystem::

/** @brief Simplified interface for various system call for Linux and Windows */
class GSystem
{
    friend GSystem *g_system();

public:
    GSystem(){};
    ~GSystem(){};
    static string         API      pwd(const bool print = false);
    static vector<string> API      ls(const string dir = ".");
    static bool           API      mkdir(const string dirname, const bool print_error = true);

#ifndef _WIN32
    static bool           API      mkdir(const string dirname, const GLocation l,  const int opt = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH, bool overwrite = true);
#else
    static bool           API      mkdir(const string dirname, const GLocation l, const int opt, bool overwrite = true);
#endif // !_WIN32

    static bool           API      mkfile(const string filepath,  const bool print_error = true );
    static void           API      cp(string src, string dest);
    static bool           API      rm(const string filename, bool recursive = false);
    static bool           API      rmdir(const string filename, bool recursive = false);
    static void           API      mv(const string src, const string dest);
    static string         API      exec(const char *cmd);
    static string         API      GetProcessID();
    static string         API      getenv(const string var);

//#ifdef _WIN32
    static string           API  Errno2String(const  int code, const string fname, const string  opt);
//#else
//    static string           API  Errno2String(const  error_t code, const string fname, const string  opt);
//#endif

#ifdef _WIN32
    static string    API   GetCommandLineAll();
    static string    API   GetCommandLineArguments();
#endif

    static char  API *  GetExePath();
    static char  API * GetExeDir();
    static char  API * GetExeName();
    static string API  GetHostName();

    static bool API Exists(const string filepath);
    static string API GetDirectory(const string filepath);

#ifdef _WIN32
    static char API *GetHomeDir();
#endif

    private:
   //   GSystem(){};
   //  ~GSystem(){};
};

#endif

