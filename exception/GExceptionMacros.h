// -*- mode: c++ -*-



#pragma once 


EXCEPTION_CLASS_H	(GFsmException)
EXCEPTION_CLASS_CPP	(GFsmException)
EXCEPTION_CLASS_H	(GAlarmException)
EXCEPTION_CLASS_CPP	(GAlarmException)
EXCEPTION_CLASS_H	(GMessageException)
EXCEPTION_CLASS_CPP	(GMessageException)
EXCEPTION_CLASS_H	(GComException)
EXCEPTION_CLASS_CPP	(GComException)
EXCEPTION_CLASS_H	(GXmlException)
EXCEPTION_CLASS_CPP	(GXmlException)



#define FSM_EXCEPTION(...)			throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,	__VA_ARGS__ ) )
#define ALARM_EXCEPTION(...)			throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_ALARM,	__VA_ARGS__ ) )
#define A_EXCEPTION(...)			throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_ALARM,	__VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define MSG_EXCEPTION(...)			throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,	__VA_ARGS__ ) )
#define COM_EXCEPTION(...)			throw_exception( GComException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_COM,	__VA_ARGS__ ) )
#define XML_EXCEPTION(...)			throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,	__VA_ARGS__ ) )


#define FSM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GFsmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_FSM),	__VA_ARGS__ ) )
#define ALARM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_ALARM),	__VA_ARGS__ ) )
#define A_ASSERT_EXCEPTION(expr,  ...)		 if(!(expr)) throw_exception( GAlarmException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_ALARM),	__VA_ARGS__ ) )
#define MESSAGE_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_MESSAGE),	__VA_ARGS__ ) )
#define MSG_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GMessageException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_MESSAGE),	__VA_ARGS__ ) )
#define COM_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GComException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_COM),	__VA_ARGS__ ) )
#define XML_ASSERT_EXCEPTION(expr,  ...)	 if(!(expr)) throw_exception( GXmlException(	__FILE__,  __func__, __LINE__ , (eMSGSYSTEM)(eMSGSYSTEM::SYS_EX | eMSGSYSTEM ::SYS_XML),	__VA_ARGS__ ) )



