// -*- mode: c++ -*-

#pragma once


/** @class LOGMASTER::LLogging
 *  @brief The main logging class providing interfaces for generation of logmessages. This class is tyically called via the interfaces defined in LLogApi.h/CPP */

#define G_STANDALONE


/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include "LMessageFactory.h"
#include <utilities/GLocation.h>
#include "utilities/GFormatting.h"

#include <string>
#include <stack>
#include <vector>
#include <map>
#include <memory>

using std::string;
using std::vector;
using std::map;


class TestLConfig_target_all_Test;
class TestLConfig_default_setting_Test;
class TestLogging_levels_Test;
class TestCheckLevel_check_level_Test;


namespace LOGMASTER
{
    class LMessage;
    using logmap =    std::shared_ptr< std::map<eMSGTARGET,  std::shared_ptr<LMessage>  >	>;	

    class LLogging
    {
        friend TestLConfig_target_all_Test;
        friend TestLConfig_default_setting_Test;
        friend TestLogging_levels_Test;
        friend TestCheckLevel_check_level_Test;

    public:
        ~LLogging();
        static LLogging			API *	Instance();

        template<typename... Args>
        logmap API Log(const eMSGLEVEL level, const eMSGSYSTEM sys, const GLocation l, const char *fmt,
                       const Args ... args);
        template<typename... Args>
        logmap API Log(const eMSGLEVEL level, const eMSGSYSTEM sys, const char *file, const int line, const char *funct,
                       const char *fmt, const Args ... args);
        template<typename... Args>
        logmap API LogVarArgs(const eMSGLEVEL level, const eMSGSYSTEM system, const char *filename,
                              const int linenumber, const char *functionname, const char *fmt, const Args ... args);
        template<typename... Args>
        logmap	API 	LogVarArgs(	const eMSGLEVEL level, const eMSGSYSTEM system, const char * filename, const int linenumber,
                                                                        const char * functionname,
                                                                        const bool force_generate, string addendum, const char *fmt, const Args ... args) ;
        logmap	API 	LogVarArgsUnsafe(const eMSGLEVEL level, const eMSGSYSTEM system, const char * filename, const int linenumber,
                                                                        const char * functionname,
                                                                        const bool force_generate, string addendum, const char *fmt, va_list ap) ;



        
        void					API		SetLogFormat(   const  string  &format, bool enable = true);
        void					API		SetLogLevel( const  string  &level);
        void					API		SetLogTarget(   const  string  &target, bool eneable = true);
        void					API		SetLogFileName( const string &filename );

        eMSGTARGET				API		GetLogTarget()  const;
        eMSGFORMAT				API		GetLogFormat(   const eMSGTARGET target) const;
        std::shared_ptr<LConfig> API 	GetConfig(  const eMSGTARGET target);
        eMSGLEVEL				API		GetLogLevel(const eMSGSYSTEM system, const eMSGTARGET  target) const;
        string					API		GetLogFileName(const eMSGTARGET  target = eMSGTARGET::TARGET_FILE ) const;
		std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  GetLastMessages()  { return  fMessages; };

        vector< void( *)(const LMessage &  ) >  API & GetSubscribers();
        void					API		RegisterSubscriber(  void(  *funct)(const LMessage &   ));
        void					API		ClearSubscribers();

        vector< void( *)(const LMessage & ) >  API & GetGuiSubscribers();
        void					API		RegisterGuiSubscriber(  void(  *funct)(const  LMessage  &  ));
        void					API		ClearGuiSubscribers();
        void					API		Reset();
        int					API		Push( );
        int					API		Pop( );
        bool 					API CheckLevel(const eMSGSYSTEM system, const eMSGLEVEL level, const eMSGTARGET target);
        void 					API Flush();

    private:
        LLogging();
        LLogging(LLogging &);

        void QueMessage(const std::shared_ptr<LMessage> msg, const std::shared_ptr<LConfig> cfg,
                        const eMSGTARGET target);

        void	Init();
        void    ClearMessages();
        void    TurnOffAllTargets();
        void    TurnOnfAllTargets();
        void	operator=(LLogging &);
        
        vector< void(*)(const LMessage &   ) > fSubscribers;
        vector< void(*)(const  LMessage &  ) > fGuiSubscribers;

        std::shared_ptr<std::map<eMSGTARGET,  LMessageFactory  > >  fConfig = nullptr;
        std::shared_ptr<std::map<eMSGTARGET, LMessageFactory > >   fDefaultConfig = nullptr;
        std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > > fMessages = nullptr;

        static std::stack<   std::shared_ptr<  std::map<eMSGTARGET,  LMessageFactory   >  >     >  fConfigurationStack;
    };

    /**@{*/
    /** Main logging function that takes a log message, and adds to it the message
     *  type and the location in the source file where the message was generated.
     *   @param  level  the loglevel/severity of the message
     *   @param  sys    the subsystem the message applies to
     *   @param  l    The location of the log  message in the code (filenam, function name line number etc.. )
     *   @param  fmt The formatting for the message (same as the  C style printf formatting)
     *   @param  args  Variable argument list
     *   @return  The generated log messages */
    template<typename... Args>
    logmap LLogging::Log(const eMSGLEVEL level, const eMSGSYSTEM sys, const GLocation l, const char *fmt,
                         const Args ... args)
    {
        return Log(level, sys, l.fFileName.c_str(), l.fLineNo, l.fFunctName.c_str(), fmt, args...);
    }
    template<typename... Args>
    logmap LLogging::Log(const eMSGLEVEL level, const eMSGSYSTEM sys, const char *file, const int line,
                         const char *funct, const char *fmt, const Args ... args)
    {
        return LogVarArgs(level, sys, file, line, funct, fmt, args...);
    }

    /**@}*/


    /**@{*/
    /** Helper function for the main logging (Log) function. The severity("level")
     *  and subsystem  ("system") of the message is checked against the configuration
     *  of the  logging system as given by the assoccicated hash maps. If logging
     *  is enabled for this level and system., then the message is generated and published.
     *   @param  level the loglevel/severity of the message
     *   @param  system the subsystem the message applies to
     *   @param  filename The name of the source code file where the message i created
     *   @param  lineno  The line number where the message is generated
     *   @param  function The name of the function that generated the message
     *   @param  force_generate Force the generation of message, regardless of the
     *			 loglevel and subystem. This feature is used by the exception handling system
     *			 where one wants the message to be genrated regardless (because you want to
     *			catch the exception with an exception handler). This falf is also usefull for debugging
     *   @param  addendum  optional string to attach to the messag
     *   @param  fmt The formatting for the message (same as the  C style printf formatting)
     *   @param  args  The list of arguments */
    template<typename... Args>
    logmap
    LLogging::LogVarArgs(const eMSGLEVEL level, const eMSGSYSTEM system, const char * filename, const int lineno,
                                                                        const char * function,
                                                                        const bool force_generate, string addendum, const char *fmt, const Args ... args)
    {
       if( fConfig == nullptr )
       {
           CERR << "CONFIG IS A ZERO POINTER" << ENDL;
           exit(-1);
       }
       GFormatting::checkFormat(filename, lineno, function, fmt, args...); // Throws exception if format is bad


        static std::shared_ptr<LMessage>           tmp_msg  =   std::make_shared<LMessage>();

        ClearMessages();

        for ( auto it = fConfig->begin(); it != fConfig->end(); ++it )
        {

            if ( it->second.IsEnabled() == true )
            {
                bool cl = CheckLevel( system, level, it->first );

                if ( (cl == true) || force_generate == true )
                {
                    tmp_msg = it->second.GenerateMessage( system, level, filename, lineno, function, addendum, fmt, args...);

                    if ( cl == true )
                    {


                        QueMessage( tmp_msg,   it->second.GetConfig(),  it->first   );

                     //   LPublisher::Instance()->PublishMessage( tmp_msg, it->second.GetConfig(), it->first );

                        //LPublisher::PublishMessage( tmp_msg, it->second.GetConfig(), target );
                        auto it_msg = fMessages->find(it->first);
                        if ( it_msg != fMessages->end() )
                        {
                            it_msg->second = tmp_msg;
                        }

                    }
                }
            }
        }

        return fMessages;

    }
    template<typename... Args>
    logmap LLogging::LogVarArgs(const eMSGLEVEL level, const eMSGSYSTEM system, const char *filename,
                                const int linenumber, const char *functionname, const char *fmt, const Args ... args)
    {
        return LogVarArgs(level, system, filename, linenumber, functionname, bool(false), (const char*)"", fmt, args...);
    }
    /**@}*/
}

