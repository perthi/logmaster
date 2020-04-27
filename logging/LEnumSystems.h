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
	SYS_ALARM			=  0x0001,    //  00000000 00000001    The exeption handling sub system
	SYS_USER		=  0x0003,    //  00000000 00000010    User messages
	SYS_GENERAL		=  0x0004,    //  00000000 00000100    No specific sub system (i.e general message)
	SYS_FSM 		=  0x0010,    //  00000000 00010000
	SYS_MESSAGE 		=  0x0020,    //  00000000 00100000
	SYS_COM 		=  0x0040,    //  00000000 01000000
	SYS_XML 		=  0x0080,    //  00000000 10000000
	SYS_ALL			=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)
};
