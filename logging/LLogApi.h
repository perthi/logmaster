// -*- mode: c++ -*-


/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/






/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 03 September-2021 20:56:58  ***/
/*** Generated from config/logging-ucw.xml **/
/*** Validated by config/logging.xsd **/
/*** Copyright Per Thomas Hille pth@embc.no ***/


#ifdef _WIN32
#define __func__ __FUNCTION__
#endif
#include  <logging/LEnums.h>
#include  <logging/LLogging.h>
#include  <logging/LOperators.h>
#include  <utilities/GDefinitions.h>



#ifdef ERROR
#undef ERROR
#endif



#ifdef __cplusplus



#include <utilities/GLocation.h>



#define SET_LOGLEVEL(level)          LLogging::Instance()->SetLogLevel(level )
#define SET_LOGFORMAT(format )       LLogging::Instance()->SetLogFormat(format )
#define SET_LOGTARGET(target )       LLogging::Instance()->SetLogTarget(target )
#define SET_LOGFILENAME(filename)    LLogging::Instance()->SetLogFileName(filename )
#define SET_APPLICATION(src)         LLogging::Instance()->SetApplication(src) 



#define PUSH()                       LLogging::Instance()->Push(  )
#define POP()                        LLogging::Instance()->Pop(  )
#define LOG_DATA(data, ...)          LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,  eMSGSYSTEM::SYS_DATA,  GLocation( __FILE__, __LINE__, __func__ ), data,  __VA_ARGS__)
#define G_LOG(level, system, ...)    LLogging::Instance()->Log( level, system,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)



#define FORCE_DEBUG(...)             LLogging::Instance()->Log(eMSGLEVEL::LOG_FORCE_DEBUG, eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define EX_ERROR(...)                LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define EX_FATAL(...)                LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)



#define ALARM_WARNING(...)             LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALARM_ERROR(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALARM_FATAL(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALARM_ASSERT_WARNING(expr, ...)    if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_ERROR(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_FATAL(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_DEBUG(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_INFO(...)                LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_WARNING(...)             LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_ERROR(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_FATAL(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define ALL_ASSERT_DEBUG(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_INFO(expr, ...)       if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_WARNING(expr, ...)    if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_ERROR(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALL_ASSERT_FATAL(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)



#define G_DEBUG(...)                 LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_INFO(...)                  LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_WARNING(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_ERROR(...)                 LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_FATAL(...)                 LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_DEBUG_U(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_INFO_U(...)                LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_WARNING_U(...)             LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_ERROR_U(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_FATAL_U(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,	   eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define G_ASSERT_DEBUG(expr, ...)    if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,     eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_INFO(expr,  ...)    if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_WARNING(expr, ...)  if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_ERROR(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_FATAL(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)



#define USER_DEBUG(...)              LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define USER_INFO(...)               LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define USER_WARNING(...)            LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define USER_ERROR(...)              LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define USER_FATAL(...)              LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)
#define USER_ASSERT_DEBUG(expr, ...)    if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::DEBUG,     eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_INFO(expr,  ...)    if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_INFO,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_WARNING(expr, ...)  if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_ERROR(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_FATAL(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eMSGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)



#define DATABASE_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_WARNING_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO_U(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define FSM_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define COM_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define COM_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define COM_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_COM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define XML_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define CLI_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CLI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CLI_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CLI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CLI_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CLI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CLI_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CLI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CLI_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CLI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CLI_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CLI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define MEASUREMENT_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_FATAL_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MEASUREMENT_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ERROR_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MEASUREMENT_WARNING(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_WARNING_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MEASUREMENT_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_INFO_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MEASUREMENT_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEASUREMENT_DEBUG_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MEAS_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MEASUREMENT | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define HMI_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_HMI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define HMI_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_HMI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define HMI_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_HMI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define HMI_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_HMI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define HMI_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_HMI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define HMI_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_HMI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define FOC_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FOC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FOC_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FOC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FOC_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FOC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FOC_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FOC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FOC_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FOC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FOC_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FOC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define MCUREPLY_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCUREPLY_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCUREPLY_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_WARNING_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCUREPLY_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCUREPLY_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCUREPLY_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCUREPLY | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)









#endif



