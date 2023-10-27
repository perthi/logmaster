// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 27 October-2023 22:37:20  ***/
/*** Generated from config/logging.xml **/
/*** Validated by config/logging.xsd **/

/****************************************************************************
*** Copyright(C) 2023  Per Thomas Hille, pth@embc.no                  ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later. See.cpp file for details    ***
*****************************************************************************/

#pragma once


 #ifdef __cplusplus
enum class eMSGSYSTEM
#else
enum  eMSGSYSTEM
#endif
 {
	SYS_NONE		=  0x0000,    //  00000000 00000000    No sub system
    SYS_EXCEPTION    = 0x0001,    
    SYS_FSM          = 0x0002,    
    SYS_MESSAGE      = 0x0004,    
    SYS_COM          = 0x0008,    
    SYS_XML          = 0x0010,    
    SYS_DATABASE     = 0x0020,    
    SYS_USER         = 0x0040,    
    SYS_GENERAL      = 0x0080,    
    SYS_ALARM        = 0x0100,    
	SYS_ALL			=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)
};



/*Enum controlling the log level*/
#ifdef __cplusplus
enum class  eLOGLEVEL
#else
enum eLOGLEVEL
#endif
{
	LOG_OFF			=  0x00,    //  00000000   No sub system
    LOG_FATAL        = 0x01,    
    LOG_ERROR        = 0x02,    
    LOG_WARNING      = 0x04,    
    LOG_INFO         = 0x08,    
    LOG_DEBUG        = 0x10,    
    LOG_FORCE_DEBUG  = 0x20,    
	LOG_ALL			=  0xff,    //  11111111   All sub systems
};
