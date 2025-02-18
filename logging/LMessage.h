// -*- mode: c++ -*-
#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


/* @struct LMessage Container class for storing a message.
 * The class has one member variable for each of the 7 message fields   
 * (message type,  timestamp, filepath, filename, function name, line number and message body ).
 * In addition there is a file for the complete message. 
 * The user application can thus choose to display the whole message or just parts of it. Please be aware though that the actual content of 
 * each field will depend on the configuration of the logging system. If a field is not enable by the global configuration (Configured by the SET_LOGFORMAT() macro)
 * then then corresponding filed in this struct will be empty. */

#include "LEnums.h"

#ifndef __cplusplus
typedef struct LMessage
#else


#include <utilities/GDefinitions.h>


namespace LOGMASTER
{

#define MAX_MSG_TYPE_SIZE 256
//#define MAX_TIME_STAMP_SIZE   256
#define MAX_MSG_TIME_STAMP_SIZE 64
#define MAX_MSG_PATH_SIZE 1024
#define MAX_MSG_FNAME_SIZE 1024
#define MAX_MSG_FUNC_NAME_SIZE 1024
////#define MAX_MSG_SIZE 65536
#define MAX_MSG_SIZE 8192

#define MAX_MSG_TOTAL_SIZE MAX_MSG_SIZE + MAX_MSG_TYPE_SIZE + MAX_MSG_TIME_STAMP_SIZE + MAX_MSG_PATH_SIZE + MAX_MSG_FNAME_SIZE + MAX_MSG_FUNC_NAME_SIZE + 16

    /**@brief Logging message. All messages is an instance of this struct */
    class LMessage
#endif
{

#ifdef __cplusplus
public:
    API LMessage() : fRgBColor(0), fWColor(0), fAColor(), fLevel(eLOGLEVEL::LOG_WARNING), fSystem(eMSGSYSTEM::SYS_ALL), fTarget(eMSGTARGET::TARGET_ALL), fFormat(eMSGFORMAT::PREFIX_ALL)
    {
        ClearContent();
    };
#endif


    char fOrigin[1024] = {0};
    char fMsgType[MAX_MSG_TYPE_SIZE] = {0};         //!< Message type and subsystem, e.eg <Error|Database>, <Driver|Debug> etc..
    char fTimeStamp[MAX_MSG_TIME_STAMP_SIZE] = {0}; //!< The date and time the message was created
    char fPath[MAX_MSG_PATH_SIZE] = {0};            //!< File path to the source code file where the message was created
    char fFileName[MAX_MSG_FNAME_SIZE] = {0};       //!< The name of the file where the message was created
    char fFunction[MAX_MSG_FUNC_NAME_SIZE] = {0};   //!< The name of the function where the message was created
    int fRgBColor = -1;                            //!< Message color in RGB color format ( 0x000000 - 0xFFFFFF)
    int fWColor = -1;                              //!< Message color in windows console format ( 1 -15 )
    int fAColor = -1;                              //!< Message color in ANSI format ( 30 -97 )

#ifdef __cplusplus
    int fLineNo = -1; //!< The line number where the messaeg was created
#else
        int fLineNo; //!< The line number where the messaeg was created
#endif
    char fMsgBody[MAX_MSG_SIZE] = "No MESSAGE YET"; //!< The actual message
    //        char  fMsg[MAX_G_SIZE];            //!< The complete message including time stamp etc..
    char fMsg[MAX_MSG_TOTAL_SIZE] = {}; //!< The complete message including time stamp etc..
    eLOGLEVEL fLevel = eLOGLEVEL(-1);              //!< The severity level of this message
    eMSGSYSTEM fSystem = eMSGSYSTEM(-1) ;            //!< The subsystem this message applies to
    eMSGTARGET fTarget = eMSGTARGET(-1);            //!< The intended log target(s), (This variable can be safely ignored by observer functions)
    eMSGFORMAT fFormat = eMSGFORMAT(-1) ;            //!< The format of the log message, i.e which files should be disabled (This variable can be safely ignored by observer functions)

    double fEpochTime = -1;

#ifdef __cplusplus
    inline void ClearContent()
    {
        fOrigin[0] = 0;
        fMsgType[0] = 0;
        fTimeStamp[0] = 0;
        fPath[0] = 0;
        fFileName[0] = 0;
        fFunction[0] = 0;
        fMsgBody[0] = 0;
        fMsg[0] = 0;
        fLineNo = -1;
        fEpochTime = -1;
    }
#endif
    API LMessage( const LMessage & );
    API LMessage & operator = ( const LMessage & );

    private:
        LMessage(LMessage&& other);
        LMessage& operator=(LMessage&& rhs);
     // LMessage( const LMessage & );
     // LMessage operator = ( const LMessage & );
};

#ifdef __cplusplus
}

#endif

