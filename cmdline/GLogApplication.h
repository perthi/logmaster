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
*   Information. The auto generation tool is svninfo.exe.
*/

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
    API GLogApplication( const bool init = false )
    {
        if(init == true )
        {
            InitLogArgs();
        }
    };
 
    API  virtual ~GLogApplication();
 
    API  GLogApplication(	const int argc, const char** argv,  arg_deque  *additional_arguments = nullptr, bool do_init = DO_INIT);
    API  GLogApplication(	const GFileName_t &t, arg_deque *additional_arguments = nullptr);

    void		API     Purge();
    void		API		SetCallBackFunction(	const string cmd,
                                                std::function< bool( const string cmd,  const string args_s,
                                                                     const vector<string> sub, const	vector<string> par ) > funct ) ;
    void		API	    RemoveArgument(const string cmd);
  
    API     std::shared_ptr<GArgument>	 	GetArgument(const string cmd);
    virtual void        API     SetDuplicateStrategy(const eDUPLICATE_STRATEGY);
    virtual eDUPLICATE_STRATEGY  API     GetDuplicateStrategy() const;
    
    GLogApplication  API & AddArgument(std::shared_ptr<GArgument>  arg, eDUPLICATE_STRATEGY ignore_duplicates = eDUPLICATE_STRATEGY::THROW_EXEPTION);
    GLogApplication  API & AddArguments(deque< std::shared_ptr<GArgument> >  args);


    virtual void                 API       ScanArguments(const string cmdline);
    virtual void                 API	   ScanArguments(const int argc, const char** argv);
#ifdef _WIN32
    void		                 API       ScanArguments();
#endif
    
    static bool			API		HasCommand( deque < std::shared_ptr<GArgument>  >  args, const string cmd);
    bool				API		HasCommand( const string cmd);
    deque< std::shared_ptr<GArgument>  >	API	 	GetArguments();
    string				API		Help(const string cmd = "" ) const;
    static string		API		Help(const deque  <  std::shared_ptr<GArgument>  > args, const string cmd = "" );
    string				API		Help(const char *exename, const string heading,  const string cmd = "" ) const;
    GLogApplication     API	  &	InitLogArgs();
	int					API		SetMandatory(const string cmd);
	int					API		SetOptional(const string cmd);
	bool				API		IsMandatory(const string cmd) const;
	bool				API		IsOptional(const string cmd) const;


//protected:
private:
    deque  <  std::shared_ptr<GArgument>  >    fArgs  =  deque  <  std::shared_ptr<GArgument>  > ()  ; 
    std::shared_ptr<GCommandLineArgument < void > > fHelp = nullptr; //!< Command line argument for printing out version information
    std::shared_ptr<GCommandLineArgument < vector< string > > >  fLog = nullptr;     //!< Command line argument for the configuration of the log  level
    std::shared_ptr < GCommandLineArgument < vector< string > > > fTarget = nullptr;  //!< Command line argument for the configuration of the log  target
    std::shared_ptr < GCommandLineArgument < vector< string > > > fFormat = nullptr;  //!< Command line argument for the configuration of the log  format
    std::shared_ptr < GCommandLineArgument < bool > > fColor = nullptr;   //!< Command line argument for controlling whether or not to use color coding of log messages

    API GLogApplication (GLogApplication &);
    void operator=(GLogApplication &);
    virtual void                 API       ScanArguments(const string cmdline, std::shared_ptr<GArgument> arg);
    virtual void                 API	   ScanArguments(const string cmdline, deque  < std::shared_ptr<GArgument> > args);

    virtual      GLogApplication API& ScanArguments(const int argc, const char** argv, deque  < std::shared_ptr<GArgument>  > arg);



    eDUPLICATE_STRATEGY fStrategy = eDUPLICATE_STRATEGY::THROW_EXEPTION;

};


