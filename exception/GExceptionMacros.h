// -*- mode: c++ -*-



#pragma once 



/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 28 August-2020 19:58:18  ***/
/*** Generated from config/logging-kts.xml **/
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
EXCEPTION_CLASS_H	(GJsonException)
EXCEPTION_CLASS_CPP	(GJsonException)
EXCEPTION_CLASS_H	(GShotcalException)
EXCEPTION_CLASS_CPP	(GShotcalException)
EXCEPTION_CLASS_H	(GShotexcecException)
EXCEPTION_CLASS_CPP	(GShotexcecException)
EXCEPTION_CLASS_H	(GConfigurationException)
EXCEPTION_CLASS_CPP	(GConfigurationException)
EXCEPTION_CLASS_H	(GSensorException)
EXCEPTION_CLASS_CPP	(GSensorException)
EXCEPTION_CLASS_H	(GCliException)
EXCEPTION_CLASS_CPP	(GCliException)



#define FSM_EXCEPTION(...)			throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,	__VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define MSG_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define COM_EXCEPTION(...)			throw_exception( GComException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_COM,	__VA_ARGS__ ) )
#define XML_EXCEPTION(...)			throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,	__VA_ARGS__ ) )
#define DATABASE_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define DB_EXCEPTION(...)			throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_DATABASE,	__VA_ARGS__ ) )
#define JSON_EXCEPTION(...)			throw_exception( GJsonException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_JSON,	__VA_ARGS__ ) )
#define SHOTCAL_EXCEPTION(...)			throw_exception( GShotcalException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_SHOTCAL,	__VA_ARGS__ ) )
#define SC_EXCEPTION(...)			throw_exception( GShotcalException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_SHOTCAL,	__VA_ARGS__ ) )
#define SHOTEXCEC_EXCEPTION(...)		throw_exception( GShotexcecException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_SHOTEXCEC,	__VA_ARGS__ ) )
#define SE_EXCEPTION(...)			throw_exception( GShotexcecException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_SHOTEXCEC,	__VA_ARGS__ ) )
#define CONFIGURATION_EXCEPTION(...)		throw_exception( GConfigurationException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_CONFIGURATION,	__VA_ARGS__ ) )
#define CONFIG_EXCEPTION(...)			throw_exception( GConfigurationException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_CONFIGURATION,	__VA_ARGS__ ) )
#define SENSOR_EXCEPTION(...)			throw_exception( GSensorException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_SENSOR,	__VA_ARGS__ ) )
#define CLI_EXCEPTION(...)			throw_exception( GCliException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_CLI,	__VA_ARGS__ ) )


#define FSM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_FSM),	__VA_ARGS__ ) )
#define MESSAGE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define MSG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_MESSAGE),	__VA_ARGS__ ) )
#define COM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GComException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_COM),	__VA_ARGS__ ) )
#define XML_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_XML),	__VA_ARGS__ ) )
#define DATABASE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define DB_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GDatabaseException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_DATABASE),	__VA_ARGS__ ) )
#define JSON_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GJsonException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_JSON),	__VA_ARGS__ ) )
#define SHOTCAL_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GShotcalException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_SHOTCAL),	__VA_ARGS__ ) )
#define SC_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GShotcalException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_SHOTCAL),	__VA_ARGS__ ) )
#define SHOTEXCEC_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GShotexcecException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_SHOTEXCEC),	__VA_ARGS__ ) )
#define SE_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GShotexcecException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_SHOTEXCEC),	__VA_ARGS__ ) )
#define CONFIGURATION_ASSERT_EXCEPTION(expr,  ...) if(!(expr)) throw_exception( GConfigurationException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_CONFIGURATION),	__VA_ARGS__ ) )
#define CONFIG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GConfigurationException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_CONFIGURATION),	__VA_ARGS__ ) )
#define SENSOR_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GSensorException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_SENSOR),	__VA_ARGS__ ) )
#define CLI_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GCliException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM::SYS_CLI),	__VA_ARGS__ ) )



