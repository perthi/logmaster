// -*- mode: c++ -*-/n/n
#pragma once


 #ifdef __cplusplus
enum class eMSGSYSTEM
#else
enum  eMSGSYSTEM
#endif
 {
	SYS_NONE		=  0x0000,    //  00000000 00000000    No sub system
	SYS_EX			=  0x0001,    //  00000000 00000001    The exeption handling sub system
	SYS_ALARM			=  0x0002,    //  00000000 00000001    The exeption handling sub system
	SYS_USER		=  0x0004,    //  00000000 00000010    User messages
	SYS_GENERAL		=  0x0008,    //  00000000 00000100    No specific sub system (i.e general message)
	SYS_FSM 		=  0x0010,    //  00000000 00010000
	SYS_MESSAGE 		=  0x0020,    //  00000000 00100000
	SYS_COM 		=  0x0040,    //  00000000 01000000
	SYS_XML 		=  0x0080,    //  00000000 10000000
	SYS_DATABASE 		=  0x0100,    //  00000001 00000000
	SYS_ALL			=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)
};



/*Enum controlling the log level*/
#ifdef __cplusplus
enum class  eMSGLEVEL
#else
enum eMSGLEVEL
#endif
{
	LOG_OFF			=  0x00,    //  00000000   No sub system
	LOG_FATAL 		=  0x01,    //  00000001
	LOG_ERROR 		=  0x02,    //  00000010
	LOG_WARNING 		=  0x04,    //  00000100
	LOG_INFO 		=  0x08,    //  00001000
	LOG_DEBUG 		=  0x10,    //  00010000
	LOG_FORCE_DEBUG		= 0x20,  // 00100000
	LOG_ALL			=  0xff,    //  11111111   All sub systems
};
