// -*- mode: c++ -*-



#pragma once 



/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 24 June-2022 22:42:36  ***/
/*** Generated from config/logging.xml **/
/*** Validated by config/logging.xsd **/
/*** Copyright Per Thomas Hille pth@embc.no ***/



EXCEPTION_CLASS_H	(GFsmException)
EXCEPTION_CLASS_CPP	(GFsmException)
EXCEPTION_CLASS_H	(GMessageException)
EXCEPTION_CLASS_CPP	(GMessageException)
EXCEPTION_CLASS_H	(GComException)
EXCEPTION_CLASS_CPP	(GComException)
EXCEPTION_CLASS_H	(GXmlException)
EXCEPTION_CLASS_CPP	(GXmlException)
EXCEPTION_CLASS_H	(GDatabaseException)
EXCEPTION_CLASS_CPP	(GDatabaseException)



#define FSM_EXCEPTION(...)			throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,	__VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define MSG_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define COM_EXCEPTION(...)			throw_exception( GComException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_COM,	__VA_ARGS__ ) )
#define XML_EXCEPTION(...)			throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,	__VA_ARGS__ ) )
#define DATABASE_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define DB_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )


#define FSM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_FSM),	__VA_ARGS__ ) )
#define MESSAGE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define MSG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define COM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GComException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_COM),	__VA_ARGS__ ) )
#define XML_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_XML),	__VA_ARGS__ ) )
#define DATABASE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define DB_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )



