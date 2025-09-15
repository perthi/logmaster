// -*- mode: c++ -*-

#pragma once


/** @class LOGMASTER::LLogging
 *  @brief The main logging class providing interfaces for generation of log messages. This class is typically called via the interfaces defined in LLogApi.h/CPP */

#define G_STANDALONE
#define THREAD_SAFE


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
#include <mutex>


class TestLConfig_target_all_Test;
class TestLConfig_default_setting_Test;
class TestLogging_levels_Test;
class TestCheckLevel_check_level_Test;


namespace LOGMASTER
{
    /** @class LLogging 
     *  @brief Man logging class
     * 
     *  @details This class is the workhorse of the logging system. It is implemented as a singleton and is
     *  used by all the logging macros defined in LLogApi.h. Functionality for logging messages checking loglevels etc
     *  is handled by this class */


    class LMessage;
    using logmap = std::shared_ptr< std::map<eMSGTARGET, std::shared_ptr<LMessage>  >    >;

    class LLogging
    {
        friend TestLConfig_target_all_Test;
        friend TestLConfig_default_setting_Test;
        friend TestLogging_levels_Test;
        friend TestCheckLevel_check_level_Test;

    public:
        ~LLogging() noexcept;
        static LLogging            API* Instance()  noexcept;
        
        void            SetExternalTimeSource(  std::function<double()>  funct ); 
        void API        SetPublishingMode( const ePUBLISH_MODE mode );

        template<typename... Args>
        logmap API Log(const eLOGLEVEL level, const eMSGSYSTEM sys, const GLocation l, const char* fmt,
            const Args ... args);
        
        logmap API Log(const eLOGLEVEL level, const eMSGSYSTEM sys, const GLocation l, const std::string message) 
        {
            return Log(level, sys, l,  "%s", message.c_str());
        };

        template<typename... Args>
        logmap API LogVarArgs(const eLOGLEVEL level, const eMSGSYSTEM system, const char* filename,
            const int linenumber, const char* functionname, const char* fmt, const Args ... args);

        template<typename... Args>
        logmap    API     LogVarArgs(const eLOGLEVEL level, const eMSGSYSTEM system, const char* filename, const int linenumber,
            const char* functionname,
            const bool force_generate, std::string addendum, const char* fmt, const Args ... args);
        
        void                     API       SetLogFormat(const  std::string& format, bool enable = true);
        void                     API       SetLogLevel(const   std::string& level);
        void                     API       SetLogTarget(const  std::string& target, bool eneable = true);
        void                     API       SetLogFileName(const std::string& filename);

        eMSGTARGET               API       GetLogTarget()  const;
        eMSGFORMAT               API       GetLogFormat(const eMSGTARGET target) const;
        std::shared_ptr<LConfig> API       GetConfig(const eMSGTARGET target);
        eLOGLEVEL                API       GetLogLevel(const eMSGSYSTEM system, const eMSGTARGET  target) const;
        std::string                   API       GetLogFileName(const eMSGTARGET  target = eMSGTARGET::TARGET_FILE) const;
        std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  GetLastMessages() { return  fMessages; };

        std::vector< void(*)( std::shared_ptr<LMessage> ) >  API GetSubscribers();
        void                    API        RegisterSubscriber(void(*funct)(  std::shared_ptr<LMessage> ));
        void                    API        ClearSubscribers();

        std::vector< void(*)( std::shared_ptr<LMessage> ) >  API GetGuiSubscribers();
        void                    API     RegisterGuiSubscriber(void(*funct)( std::shared_ptr<LMessage> ));
        void                    API     ClearGuiSubscribers();
        void                    API     Reset();
        int                     API     Push();
        int                     API     Pop();
        bool                    API     CheckLevel(const eMSGSYSTEM system, const eLOGLEVEL level, const eMSGTARGET target);
        void                    API     Flush();
        void                    API     SetFormatCheckAll( const bool val );   
        void                    API     DisableFormatCheck() { fFormatCheck  = false;};  
        void                    API     EnableFormatCheck() {  fFormatCheck  = true;};  
        logmap                  API     GetLogMap() { return fMessages;};
    private:
        API LLogging();
        API LLogging(LLogging&);

        void API QueMessage(const std::shared_ptr<LMessage> msg, const std::shared_ptr<LConfig> cfg,
        const eMSGTARGET target);

        void    Init();
        void    ClearMessages();
        void    TurnOffAllTargets();
        void    TurnOnfAllTargets();
        void    operator=(LLogging&);

        std::vector< void(*)( std::shared_ptr<LMessage> ) > fSubscribers;
        std::vector< void(*)( std::shared_ptr<LMessage> ) > fGuiSubscribers;
        std::shared_ptr<std::map<eMSGTARGET, LMessageFactory  > >  fConfig = nullptr;
        std::shared_ptr<std::map<eMSGTARGET, LMessageFactory > >   fDefaultConfig = nullptr;
        logmap fMessages = nullptr;
        std::stack<   std::shared_ptr<std::map<eMSGTARGET, LMessageFactory   >  >     >  fConfigurationStack;
        std::mutex fLoggingMutex{};
        
        bool fFormatCheckAll = true; //!< Wether or not to perform format check on all messages 
        bool fFormatCheck = true;
    };


    /** Main logging function that takes a log message, and adds to it the message
     *  type and the location in the source file where the message was generated.
     *   @param  level  the loglevel/severity of the message
     *   @param  sys    the subsystem the message applies to
     *   @param  l    The location of the log  message in the code (filename, function name line number etc.. )
     *   @param  fmt The formatting for the message (same as the  C style printf formatting)
     *   @param  args  Variable argument list
     *   @return  The generated log messages */
    template<typename... Args>
    logmap LLogging::Log(const eLOGLEVEL level, const eMSGSYSTEM sys, const GLocation l, const char* fmt,
        const Args ... args)
    {
        return LogVarArgs(level, sys, l.fFileName.c_str(),  l.fLineNo, l.fFunctName.c_str(), false, std::string(""), fmt, args...);
    }


    /**@{*/
    /** Helper function for the main logging (Log) function. The severity("level")
     *  and subsystem  ("system") of the message is checked against the configuration
     *  of the  logging system as given by the associated hash std::maps. If logging
     *  is enabled for this level and system., then the message is generated and published.
     *   @param  level the loglevel/severity of the message
     *   @param  system the subsystem the message applies to
     *   @param  filename The name of the source code file where the message i created
     *   @param  linenumber  The line number where the message is generated
     *   @param  function_name The name of the function that generated the message
     *   @param  force_generate Force the generation of message, regardless of the
     *             loglevel and subsystem. This feature is used by the exception handling system
     *             where one wants the message to be generated regardless (because you want to
     *            catch the exception with an exception handler). This flag is also useful for debugging
     *   @param  addendum  optional std::string to attach to the message
     *   @param  fmt The formatting for the message (same as the  C style printf formatting)
     *   @param  args  The list of arguments */
    template<typename... Args>
    logmap
        LLogging::LogVarArgs(const eLOGLEVEL level, const eMSGSYSTEM system, const char* filename, const int linenumber,
            const char* function_name,
            const bool force_generate, std::string addendum, const char* fmt, const Args ... args)
    {
         /** @todo Refactor this function */
        static std::mutex mtx;
        std::lock_guard<std::mutex> lock(mtx);
    

        if (fConfig == nullptr)
        {
            CERR << "CONFIG IS A ZERO POINTER" << ENDL;
            throw( std::invalid_argument("CONFIG IS A ZERO POINTER") );
        }


        std::shared_ptr<LMessage>  tmp_msg =  nullptr;
        std::pair<bool, std::string>  formatCheck;

        auto format_check = [ &addendum, &filename, &linenumber, &function_name, fmt, args...](  )
        {
            std::pair<bool, std::string>  f = GFormatting::checkFormat(filename, linenumber, function_name, fmt, args...);
            if (f.first == false)
            {
                addendum += " (" + f.second + ")";
            }
            return f;
        };


        if( fFormatCheckAll  == true && fFormatCheck == true )
        {
           formatCheck = format_check();
        }
        else
        {
            formatCheck = std::make_pair<bool, std::string>(true, ""); 
        }
        
       std::lock_guard<std::mutex> guard( fLoggingMutex );
       
       for (auto it = fConfig->begin(); it != fConfig->end(); it++ )
      //  for (auto &it = start; it != end; ++it)
        {
            if (it->second.IsEnabled() == true)
            {
                bool cl = CheckLevel(system, level, it->first);
                if ((cl == true) || force_generate == true)
                {
                    if( fFormatCheckAll  == false &&  fFormatCheck == true )
                    {
                       formatCheck = format_check();  
                    }
                    else
                    {
                        formatCheck = std::make_pair<bool, std::string>(true, ""); 
                    }
                    

                    if (formatCheck.first == true)
                    {
                     //   std::lock_guard<std::mutex> guard2( fLoggingMutex  );
                        tmp_msg = it->second.GenerateMessage(system, level, filename, linenumber, function_name, addendum, fmt, args...);
                    }
                    else
                    {
                        CERR << "FORMAT ERROR" << ENDL;
                        tmp_msg = it->second.GenerateMessage(system, level, filename, linenumber, function_name, addendum, fmt);
                    }

                    if (cl == true)
                    {
                      //  std::lock_guard<std::recursive_mutex> lock(fLoggingMutex);
                        QueMessage(tmp_msg, it->second.GetConfig(), it->first);

                        auto it_msg = fMessages->find(it->first);
                        if (it_msg != fMessages->end())
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
    logmap LLogging::LogVarArgs(const eLOGLEVEL level, const eMSGSYSTEM system, const char* filename,
        const int linenumber, const char* functionname, const char* fmt, const Args ... args)
    {
        return LogVarArgs(level, system, filename, linenumber, functionname, bool(false), (const char*)"", fmt, args...);
    }
    /**@}*/

}

