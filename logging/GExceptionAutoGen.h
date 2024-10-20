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

EXCEPTION_CLASS_H	(GExceptionException)
EXCEPTION_CLASS_CPP	(GExceptionException)
EXCEPTION_CLASS_H	(GFsmException)
EXCEPTION_CLASS_CPP	(GFsmException)
EXCEPTION_CLASS_H	(GMessageException)
EXCEPTION_CLASS_CPP	(GMessageException)
EXCEPTION_CLASS_H	(GEmsException)
EXCEPTION_CLASS_CPP	(GEmsException)
EXCEPTION_CLASS_H	(GMbmsException)
EXCEPTION_CLASS_CPP	(GMbmsException)
EXCEPTION_CLASS_H	(GBiuException)
EXCEPTION_CLASS_CPP	(GBiuException)
EXCEPTION_CLASS_H	(GRestapiException)
EXCEPTION_CLASS_CPP	(GRestapiException)
EXCEPTION_CLASS_H	(GXmlException)
EXCEPTION_CLASS_CPP	(GXmlException)
EXCEPTION_CLASS_H	(GDatabaseException)
EXCEPTION_CLASS_CPP	(GDatabaseException)
EXCEPTION_CLASS_H	(GUserException)
EXCEPTION_CLASS_CPP	(GUserException)
EXCEPTION_CLASS_H	(GGeneralException)
EXCEPTION_CLASS_CPP	(GGeneralException)
EXCEPTION_CLASS_H	(GAlarmException)
EXCEPTION_CLASS_CPP	(GAlarmException)



#define EXCEPTION_EXCEPTION(...)		throw_exception( GExceptionException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_EXCEPTION,	__VA_ARGS__ ) )
#define EX_EXCEPTION(...)			throw_exception( GExceptionException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_EXCEPTION,	__VA_ARGS__ ) )
#define FSM_EXCEPTION(...)			throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,	__VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define MSG_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define EMS_EXCEPTION(...)			throw_exception( GEmsException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_EMS,	__VA_ARGS__ ) )
#define MBMS_EXCEPTION(...)			throw_exception( GMbmsException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MBMS,	__VA_ARGS__ ) )
#define BIU_EXCEPTION(...)			throw_exception( GBiuException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_BIU,	__VA_ARGS__ ) )
#define RESTAPI_EXCEPTION(...)			throw_exception( GRestapiException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_RESTAPI,	__VA_ARGS__ ) )
#define REST_EXCEPTION(...)			throw_exception( GRestapiException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_RESTAPI,	__VA_ARGS__ ) )
#define XML_EXCEPTION(...)			throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,	__VA_ARGS__ ) )
#define DATABASE_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define DB_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define USER_EXCEPTION(...)			throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_USER,	__VA_ARGS__ ) )
#define USR_EXCEPTION(...)			throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_USER,	__VA_ARGS__ ) )
#define GENERAL_EXCEPTION(...)			throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_GENERAL,	__VA_ARGS__ ) )
#define G_EXCEPTION(...)			throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_GENERAL,	__VA_ARGS__ ) )
#define ALARM_EXCEPTION(...)			throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_ALARM,	__VA_ARGS__ ) )


#define EXCEPTION_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GExceptionException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_EXCEPTION),	__VA_ARGS__ ) )
#define EX_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GExceptionException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_EXCEPTION),	__VA_ARGS__ ) )
#define FSM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_FSM),	__VA_ARGS__ ) )
#define MESSAGE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define MSG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define EMS_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GEmsException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_EMS),	__VA_ARGS__ ) )
#define MBMS_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMbmsException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_MBMS),	__VA_ARGS__ ) )
#define BIU_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GBiuException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_BIU),	__VA_ARGS__ ) )
#define RESTAPI_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GRestapiException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_RESTAPI),	__VA_ARGS__ ) )
#define REST_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GRestapiException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_RESTAPI),	__VA_ARGS__ ) )
#define XML_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_XML),	__VA_ARGS__ ) )
#define DATABASE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define DB_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define USER_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER),	__VA_ARGS__ ) )
#define USR_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GUserException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_USER),	__VA_ARGS__ ) )
#define GENERAL_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_GENERAL),	__VA_ARGS__ ) )
#define G_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GGeneralException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_GENERAL),	__VA_ARGS__ ) )
#define ALARM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EXCEPTION | eMSGSYSTEM::SYS_ALARM),	__VA_ARGS__ ) )



