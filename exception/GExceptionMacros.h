

#pragma once

EXCEPTION_CLASS_H(GFSMException)
EXCEPTION_CLASS_CPP(GFSMException)
EXCEPTION_CLASS_H(GAlarmException)
EXCEPTION_CLASS_CPP(GAlarmException)

EXCEPTION_CLASS_H(GComException)
EXCEPTION_CLASS_CPP(GComException)

EXCEPTION_CLASS_H(GMessageException)
EXCEPTION_CLASS_CPP(GMessageException)

EXCEPTION_CLASS_H(GXMLException)
EXCEPTION_CLASS_CPP(GXMLException)


/** Auto generated macro defintions of Exception classes */
#define COM_EXCEPTION(...)                 throw_exception( GComException(              __FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_COM,      __VA_ARGS__ ) )
#define FSM_EXCEPTION(...)                 throw_exception( GFSMException(              __FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_FSM,      __VA_ARGS__ ) )
#define ALARM_EXCEPTION(...)               throw_exception( GAlarmException(            __FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_ALARM,    __VA_ARGS__ ) )
#define MESSAGE_EXCEPTION(...)             throw_exception( GMessageException(          __FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_MESSAGE,  __VA_ARGS__ ) )
#define XML_EXCEPTION(...)                 throw_exception( GXMLException(              __FILE__,  __func__, __LINE__ , eMSGSYSTEM::SYS_XML,      __VA_ARGS__ ) )

#define FSM_ASSERT_EXCEPTION(expr, ...)        if(!(expr)) throw_exception( GFSMException(       __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_FSM ),      __VA_ARGS__  ) )
#define ALARM_ASSERT_EXCEPTION(expr, ...)      if(!(expr)) throw_exception( GAlarmException(     __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_ALARM ),    __VA_ARGS__  ) )
#define MESSAGE_ASSERT_EXCEPTION(expr, ...)    if(!(expr)) throw_exception( GMessageException(   __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_MESSAGE ),  __VA_ARGS__  ) )
#define MSG_ASSERT_EXCEPTION(expr, ...)        if(!(expr)) throw_exception( GMessageException(   __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_MESSAGE ),  __VA_ARGS__  ) )
#define COM_ASSERT_EXCEPTION(expr, ...)        if(!(expr)) throw_exception( GComException(       __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_COM),       __VA_ARGS__  ) )
#define XML_ASSERT_EXCEPTION(expr, ...)         if(!(expr)) throw_exception( GXMLException(       __FILE__,  __func__, __LINE__ ,	( eMSGSYSTEM)(  eMSGSYSTEM::SYS_EX |  eMSGSYSTEM::SYS_XML),       __VA_ARGS__  ) )
