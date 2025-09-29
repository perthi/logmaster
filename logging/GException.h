// -*- mode: c++ -*-


#pragma once

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

///#include <utilities/GDefinitions.h>
#include <logging/LMessage.h>
#include <logging/LLogApi.h>
#include <logging/LLogging.h>
#include <utilities/GStackTrace.h>
#include <utilities/GCommon.h>

using namespace LOGMASTER;

#include <string>
using std::string;

#include <memory>
#include <cstdarg>

/** @brief custom exceptions that uses the logging system
 *
 *  @details Throws exceptions using printf formatting. The exception handling system uses the logging system so that
 * any exceptions thrown are also written to log files or standard output if the log level is ERROR or higher.
 * From the point of view of the logging system an exception message is just like any other logging message with the
 * following specifications
 *  - loglevel is ERROR
 *  - sub system is either
 *    -# SYS_EXCEPTION
 *    -# SYS_EXCEPTION  | "<any other sub-system>""
 *
 * The exceptions can be disabled for debugging purposes. If disabled then a EX_FATAL exception message is written
 * insted of throwing an exception when calling an exception macro. */
class  GException : public std::exception
{
public:
  API  GException(){};
  template<typename... Args>
  API  GException(const string file, const string function, const int line, const eMSGSYSTEM system,
                        const char *fmt, const Args ... args);

    virtual API inline  ~GException()
    {

    }

   // static std::shared_ptr<LOGMASTER::LMessage> API  GetMessageL();
    std::shared_ptr<LOGMASTER::LMessage> API  GetMessageL();

    static bool API IsEnabledException();
    static void API EnableException();
    static void API DisableException();
    static bool API IsEnabledStackTrace();
    static void API EnableStackTrace();
    static void API DisableStackTrace();
    string API LogTrace();
    void API SetLogMap();

    virtual const char   API * what()  const noexcept override;
    static string API ExtractClassname(const char *in);
    static  std::shared_ptr< std::map<eMSGTARGET, std::shared_ptr<LMessage > > > fgMessageMap;
    
    mutable std::shared_ptr<LOGMASTER::LMessage>  fgMessage = nullptr;
    
public:
    static bool fIsEnabledStackTrace; /* !< If set to true then a stack trace is included in the log message for the exception. This can be useful for debugging. Default is FALSE*/
    static bool fIsEnabledException;  /* !< If set to FALSE then a fatal error message is written instead of throwing an exception */

};


#define EXCEPTION_CLASS_H(classname)  class classname : public GException \
 {                                                                     \
 public:                                                               \
     inline classname() { };                                                \
     template<typename... Args>    \
     API inline classname(const string file, const string function, const int line, const eMSGSYSTEM system, const char * fmt, const Args ... args ); \
   virtual inline ~classname() override { };                                      \
};



#define EXCEPTION_CLASS_CPP(classname) template<typename... Args>  classname::classname (const string file, \
                          const string function,    \
                          const int line, \
                          const eMSGSYSTEM system,  \
                                              const char * fmt, const Args ... args)\
    { \
    string msg = GException::LogTrace(); \
    LLogging::Instance()->LogVarArgs(eLOGLEVEL::LOG_FATAL, system, file.c_str(), line, function.c_str(), true, msg, fmt, args...); \
    SetLogMap();\
    what(); \
}




template<typename T>
bool throw_exception(const T &e)
{
    if (GException::IsEnabledException() == true)
    {
        throw(e);
    }
    else
    {
      //  EXCEPTION_FATAL("Fatal condition that would have resulted in an exception, but exceptions was switched off !!");
      //  EXCEPTION_FATAL("%s", e.what());
        return false;
    }

    return true;
}

/** Common macro definitions of Exception classes */

EXCEPTION_CLASS_CPP(GException)
EXCEPTION_CLASS_H(   GFileNotFoundException )
EXCEPTION_CLASS_CPP( GFileNotFoundException )
EXCEPTION_CLASS_H(   GInvalidArgumentException)
EXCEPTION_CLASS_CPP( GInvalidArgumentException)
EXCEPTION_CLASS_H(GMissingArgumentException)
EXCEPTION_CLASS_CPP(GMissingArgumentException)
EXCEPTION_CLASS_H(GRangeException)
EXCEPTION_CLASS_CPP(GRangeException)
// EXCEPTION_CLASS_H    (GAlarmException)
// EXCEPTION_CLASS_CPP    (GAlarmException)


#define EXCEPTION(...)                     throw_exception( GException(                 __FILE__,  __func__, __LINE__ ,   eMSGSYSTEM::SYS_EXCEPTION,       __VA_ARGS__ ) )
#define RANGE_EXCEPTION(...)               throw_exception( GRangeException(            __FILE__,  __func__, __LINE__ ,   eMSGSYSTEM::SYS_EXCEPTION,       __VA_ARGS__ ) )
#define FILE_NOT_FOUND_EXCEPTION(...)      throw_exception( GFileNotFoundException(     __FILE__,  __func__, __LINE__ ,   eMSGSYSTEM::SYS_EXCEPTION,       __VA_ARGS__ ) )
#define INVALID_ARGUMENT_EXCEPTION(...)    throw_exception( GInvalidArgumentException(  __FILE__,  __func__, __LINE__ ,   eMSGSYSTEM::SYS_EXCEPTION,       __VA_ARGS__ ) )
#define MISSING_ARGUMENT_EXCEPTION(...)    throw_exception( GMissingArgumentException(  __FILE__,  __func__, __LINE__ ,   eMSGSYSTEM::SYS_EXCEPTION,       __VA_ARGS__ ) )
//#define G_ASSERT_EXCEPTION(expr, ...)          if(!(expr)) throw_exception( GException(          __FILE__,  __func__, __LINE__ ,    eMSGSYSTEM::SYS_EX , __VA_ARGS__ ) )
#define G_ASSERT_ARGUMENT_EXCEPTION(expr, ...)          if(!(expr)) throw_exception( GInvalidArgumentException(          __FILE__,  __func__, __LINE__ ,    eMSGSYSTEM::SYS_EXCEPTION , __VA_ARGS__ ) )

//#define ALARM_ASSERT_EXCEPTION(expr,  ...)     if(!(expr)) throw_exception( GAlarmException(    __FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_ALARM ),    __VA_ARGS__ ) )


/** Including auto generated macros */
 #include "GExceptionAutoGen.h"


#define  CATCH_EXCEPTION_DB \
   catch (GException &e) \
    { \
        DB_FATAL ("Exception caught: %s", e.what()); \
    } \
    catch (std::exception &e) \
    { \
        DB_FATAL("Exception caught: %s", e.what()); \
    } \
    catch (...) \
    { \
        DB_FATAL("Unknown exception caught"); \
    }


#define  CATCH_EXCEPTION \
   catch (GException &e) \
    { \
        G_FATAL ("Exception caught: %s", e.what()); \
    } \
    catch (std::exception &e) \
    { \
        G_FATAL("Exception caught: %s", e.what()); \
    } \
    catch (...) \
    { \
        G_FATAL("Unknown exception caught"); \
    }


///#endif
