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


/** @class GLogApplication
*   @brief Main application that all applications should inherit from. The
*   constructors of this class initializes arguments for the logging system so that the logging system can be configured
*   from the command line by all applications that inherits from this class.
*
*   It also adds a command line tag "--version"
*   that when issued on the command line prints out SVN revision and tag information for this application. That is, which source code
*   revision, branch (trunk, tag, or release) an release tag (v-x-y-z) the application was compiled from.
*   The SVN information is contained in the object pointed to by SvnData fSvnData. The SvnData class is auto generated based on the current SVN
*   Information. */

#include <utilities/GDefinitions.h>
#include <utilities/GFileName_t.h>
#include <string>
#include <deque>
#include <vector>
using std::string;
using std::deque;
using std::vector;

template <typename T> class GCommandLineArgument;

#define DO_INIT true
#define DONT_INIT false

#include <functional>
#include <memory>

template <typename T> class GCommandLineArgument;
class GArgument;


#include "GArgumentDefinitions.h"

class GLogApplication
{
public:
    API  GLogApplication(const bool init = false);
    API  GLogApplication(const int argc, const char** argv, arg_deque_ptr additional_arguments = nullptr, bool do_init = DO_INIT);
    API  GLogApplication(const GFileName_t& t, arg_deque* additional_arguments = nullptr);
    virtual API ~GLogApplication() {};

    void  API  Purge( );
    void  API  SetCallBackFunction(const string cmd, callback_t funct);
    void  API  RemoveArgument(const string cmd);

    arg_ptr          API   GetArgument(const string cmd);
    void             API   SetDuplicateStrategy(const eDUP_STRATEGY);
    eDUP_STRATEGY    API   GetDuplicateStrategy( ) const;
    GLogApplication  API & AddArgument(arg_ptr  arg, eDUP_STRATEGY s = eDUP_STRATEGY::THROW_EXEPTION);
    GLogApplication  API & AddArguments(arg_deque  args);
    void             API   ScanArguments(const string cmdline);
    void             API   ScanArguments(const int argc, const char** argv);
    void             API   ScanArguments(const string cmdline, arg_ptr arg);
    void             API   ScanArguments(const string cmdline, arg_deque args);
    GLogApplication  API & ScanArguments(const int argc, const char** argv, arg_deque  arg);

#ifdef _WIN32
    void             API   ScanArguments( );
#endif
    string              API        Help(const string cmd = "" ) const;
    static string       API        Help(const deque  <  std::shared_ptr<GArgument>  > args, const string cmd = "" );
    string              API        Help(const char *exename, const string heading,  const string cmd = "" ) const;
    
    static bool      API   HasCommand(arg_deque  args, const string cmd);
    bool             API   HasCommand(const string cmd);
    arg_deque        API   GetArguments( );
    
    GLogApplication  API & InitLogArgs( );
    int              API   SetMandatory(const string cmd);
    int              API   SetOptional(const string cmd);
    bool             API   IsMandatory(const string cmd) const;
    bool             API   IsOptional(const string cmd) const;

//private:
    API      GLogApplication(GLogApplication&);
    void     operator=(GLogApplication&);
   

    arg_deque        fArgs = arg_deque( );
    void_arg_ptr     fHelp = nullptr;    //!< Command line argument for printing out version information
    vector_arg_ptr   fLog = nullptr;     //!< Command line argument for the configuration of the log  level
    vector_arg_ptr   fTarget = nullptr;  //!< Command line argument for the configuration of the log  target
    vector_arg_ptr   fFormat = nullptr;  //!< Command line argument for the configuration of the log  format
    bool_arg_ptr     fColor = nullptr;   //!< Command line argument for controlling whether or not to use color coding of log messages
    eDUP_STRATEGY    fStrategy = eDUP_STRATEGY::THROW_EXEPTION;

};


