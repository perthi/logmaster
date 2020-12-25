// -*- mode: c++ -*-


/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/






/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Wed 23 December-2020 12:34:43  ***/
/*** Generated from config/logging-kts.xml **/
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






#define MESSAGE_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






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






#define JSON_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_JSON | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define JSON_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_JSON | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define JSON_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_JSON | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define JSON_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_JSON | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define JSON_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_JSON, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define JSON_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_JSON | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define SHOTCAL_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTCAL_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTCAL_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTCAL_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_INFO_U(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTCAL_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTCAL_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SC_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTCAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define SHOTEXCEC_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTEXCEC_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTEXCEC_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_WARNING_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTEXCEC_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_INFO_U(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define SHOTEXCEC_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SHOTEXCEC_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define SE_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_SHOTEXCEC | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define CONFIGURATION_FATAL(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_FATAL_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CONFIGURATION_ERROR(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ERROR_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CONFIGURATION_WARNING(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_WARNING_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CONFIGURATION_INFO(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_INFO_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define CONFIGURATION_DEBUG(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIGURATION_DEBUG_U(...) 				LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define CONFIG_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_CONFIGURATION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






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






#define MCU_FATAL(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MCU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCU_ERROR(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MCU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCU_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MCU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCU_INFO(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MCU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MCU_DEBUG(...) 						LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MCU_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MCU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define DRIVER_FATAL(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_FATAL_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DRIVER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DRIVER_ERROR(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ERROR_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DRIVER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DRIVER_WARNING(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_WARNING_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DRIVER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DRIVER_INFO(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_INFO_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DRIVER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DRIVER_DEBUG(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DRIVER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DRIVER_DEBUG_U(...) 					LLogging::Instance()->Log( eMSGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DRIVER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)









#endif



