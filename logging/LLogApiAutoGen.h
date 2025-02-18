// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Sat 17 August-2024 02:36:27  ***/
/*** Generated from config/logging-ecostor.xml **/
/*** Validated by config/logging.xsd **/

/****************************************************************************
*** Copyright(C) 2024  Per Thomas Hille, pth@embc.no                  ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later. See.cpp file for details    ***
*****************************************************************************/

#define EXCEPTION_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EXCEPTION_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EXCEPTION_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_WARNING_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EXCEPTION_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_INFO_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EXCEPTION_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EXCEPTION_FORCE_DEBUG(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EXCEPTION_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EX_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define FSM_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define FSM_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_FSM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define FSM_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_FSM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define MESSAGE_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MESSAGE_FORCE_DEBUG(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MESSAGE_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MSG_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MESSAGE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define EMS_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EMS_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EMS_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EMS_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EMS_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define EMS_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define EMS_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_EMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define MBMS_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MBMS_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MBMS_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MBMS_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MBMS_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define MBMS_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MBMS, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define MBMS_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_MBMS | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define BIU_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define BIU_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define BIU_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define BIU_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define BIU_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define BIU_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_BIU, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define BIU_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_BIU | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define RESTAPI_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define RESTAPI_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define RESTAPI_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define RESTAPI_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define RESTAPI_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define RESTAPI_FORCE_DEBUG(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define RESTAPI_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define REST_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_RESTAPI | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define XML_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define XML_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_XML, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define XML_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_XML | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define DATABASE_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_WARNING_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_INFO(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_INFO_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define DATABASE_FORCE_DEBUG(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DATABASE_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define DB_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_DATABASE | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define USER_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define USER_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USER_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define USR_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_USER | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define GENERAL_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FATAL(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FATAL_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ERROR(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ERROR_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_WARNING(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_INFO(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_INFO_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_DEBUG(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_DEBUG_U(...) 						LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define GENERAL_FORCE_DEBUG(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define GENERAL_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define G_FORCE_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)






#define ALARM_FATAL(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_FATAL(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_FATAL_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FATAL,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_ERROR(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_ERROR(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ERROR_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_ERROR,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_WARNING(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_WARNING(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_WARNING_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_WARNING,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_INFO(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_INFO(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_INFO_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_INFO,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_DEBUG(expr, ...) 	if ( ! (expr) )		LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_DEBUG_U(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_DEBUG,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)


#define ALARM_FORCE_DEBUG(...) 					LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_ASSERT_FORCE_DEBUG(expr, ...) 	if ( ! (expr) )	LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_ALARM, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)
#define ALARM_FORCE_DEBUG_U(...) 				LLogging::Instance()->Log( eLOGLEVEL::LOG_FORCE_DEBUG,    eMSGSYSTEM::SYS_ALARM | eMSGSYSTEM::SYS_USER, GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)









