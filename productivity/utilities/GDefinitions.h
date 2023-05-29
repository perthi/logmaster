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

#define WINDOWS_IGNORE_PACKING_MISMATCH

#ifdef _WIN32
#include <Windows.h>
#endif // 

#include <utilities/GColor.h>

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
#include <sstream>
using std::string;

#include <type_traits>

#ifdef __linux__
typedef int errno_t;
#endif


#ifdef _WIN64f
#define __CALL__  _fastcall 
#else
#ifdef _WIN32
#define __CALL__  _stdcall 
#endif
#endif

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif


#ifdef _WIN32
#define SPRINTF sprintf_s
#else
#define SPRINTF snprintf
#endif


#ifdef _WIN32
#define SPRINTF_S(buffer, input) sprintf_s(buffer, sizeof(buffer) -1, "%s", input.c_str() )
#else
#define SPRINTF_S(buffer, input) snprintf(buffer, sizeof(buffer) -1, "%s", input.c_str() ) 
#endif


#if defined(_WIN32) && (_MSC_VER) && _MSC_VER < 1500 || defined(_WIN64) && (_MSC_VER) && _MSC_VER < 1500
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif

#ifdef _WIN32
#define strcasecmp _stricmp	
#endif

#define STRINGLIFY(x) #x
#define EXPAND(x) STRINGLIFY(x)


#define EXCECUTION_ERROR -33
#define ARG_MAX 4096


#undef COUT
#define COUT  cout <<  std::dec << __FUNCTION__ << ":[" << __LINE__  << "]"
#define COUT_HEX  cout <<  std::dec << __FUNCTION__ << ":[" << __LINE__  << "]" << std::hex

#if defined(__unix__)
#define CERR   cerr << "\033[7;1;34m" <<__FILE__ << ":" <<__LINE__ <<":" << __FUNCTION__ <<":" 
#define ENDL   "\033[0m" << endl;
#endif

#ifdef _WIN32
#define CERR \
{\
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
SetConsoleTextAttribute(hConsole, T_CYAN); \
}\
    cerr   << std::dec <<__FUNCTION__ << ":"  << __LINE__ << ":" 
#define ENDL endl;\
{\
    static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
    SetConsoleTextAttribute(hConsole, CONSOLE_DEFAULT);\
}

#define CERR_HEX \
{\
 static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);\
SetConsoleTextAttribute(hConsole, T_CYAN); \
}\
cerr   << std::dec <<__FUNCTION__ << ":"  << __LINE__ << ":" << std::hex 
#endif


#define SHOW(a) COUT << #a << ": " << (a) << std::endl

#if _WIN64
typedef   wchar_t DBCHAR;
#else
typedef  unsigned char    DBCHAR;
#endif


#define  DAY_MIN 1
#define  DAY_MAX 7
#define  DATE_MIN 1
#define  DATE_MAX 31
#define  MONTH_MIN 1
#define  MONTH_MAX 12
#define  YEAR_MIN 2018
#define  YEAR_MAX 9999
#define  HOUR_MIN 0
#define  HOUR_MAX 24
#define  MINUTE_MIN 0
#define  MINUTE_MAX 60
#define  SECONDS_MIN 0
#define  SECONDS_MAX 60

#define ARG_OK true
#define ARG_ERROR false



#define CHECK_ARGS(type, cmd, parameter, lower, upper, status, msg)    \
    status = ARG_OK;                                                    \
    try                                                                 \
    {                                                                   \
        msg = g_utilities()->CheckLimits<type>((type)parameter.size(), lower, upper, #parameter, __FILE__, __LINE__, __FUNCTION__, &status); \
    }                                                                   \
    catch (...)                                                         \
    {                                                                   \
        if (status == ARG_ERROR)                                        \
        {    \
                if (lower == upper)                                         \
            {                                                           \
                RANGE_EXCEPTION("%s:\t%s invalid number of parameters(%d): %s takes exactly %d parameter", cmd.c_str(),msg.c_str(),  parameter.size(),   cmd.c_str(), upper); \
            }                                                           \
            else                                                        \
            {   \
                RANGE_EXCEPTION("%s:\t%s invalid number of parameters(%d): %s takes between %d and %d parameters", cmd.c_str(), msg.c_str(),  parameter.size(),  cmd.c_str(), lower, upper); \
            }                                                           \
                                                                        \
        } \
    }

