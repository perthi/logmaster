// -*- mode: c++ -*-

#pragma once

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#include "LEnums.h"
#include "LMessage.h"
#include "LColorMap.h"
#include "LEnum2String.h"

#include "utilities/GDefinitions.h"
#include "utilities/GTokenizer.h"
#include "utilities/GTime.h"
#include <string>
#include <iostream>
#include <mutex>

using std::string;
using std::ostringstream;

#include <memory>


using namespace LOGMASTER;

class TestLogging_level_to_string_Test;
class TestLogging_system_to_string_Test;
class TestLogging_to_string_Test;

namespace LOGMASTER
{
    class LMessage;
    class LLogging;
    class LMessage2Json;
    class LDatabase;


/** @class  LMessageGenerator
 *  Helper class for the logging system that is responsible for the generation of log messages*/
class LMessageGenerator
{
    friend  LLogging;
    friend  LMessage2Json;
    friend  LDatabase;

    friend  TestLogging_level_to_string_Test;
    friend  TestLogging_system_to_string_Test;
    friend  TestLogging_to_string_Test;

public:
    static  LMessageGenerator API * Instance();
    LMessageGenerator();

    template<typename... Args>
    std::shared_ptr<LMessage> API GenerateMsg(const eMSGFORMAT format, const eMSGLEVEL l, const eMSGSYSTEM s,
                                              const char *fname, int line, const char *func, const char *fmt,
                                              const Args ... args);

    template<typename... Args>
    std::shared_ptr<LMessage> API GenerateMsg(const eMSGFORMAT format, const eMSGLEVEL l, const eMSGSYSTEM s,
                                              const char *fname, int line, const char *func, string addendum,
                                              const char *fmt, const Args ... args);
    

private:
    GTime fTime;
    GTokenizer fTokenizer;
   

};
namespace
{
    std::mutex G_gen_mutex;
}

/**@{*/
/* Generates a message and stores it in the LMessage struct m. This function is typically called via a macro, an using the
* build in preprocessor directives __FILE__, __FUNCTION__, __LINE__
*  @param m[in|out] A pointer to the LMessage struct that will be filled in
*  @param format[in] Controls which fields in the message  will be filled in
*  @param l[in] The severity level of this message
*  @param s[in] The subsystem this messsage applies to
*  @param fname[in]  The name of the files where the message was generated   (stripped form __FILE__ )
*  @param line  The line number where the message was generated
*  @param func  The name of the function where the message was generated ( __FUNCTION__)
*  @param fmt[in] */
template<typename... Args>
std::shared_ptr<LMessage> 
LMessageGenerator::GenerateMsg(const eMSGFORMAT format, const eMSGLEVEL l, const eMSGSYSTEM s,
                                                         const char *fname, int line, const char *func, string addendum,
                                                         const char *fmt, const Args ... args)
{
   // std::lock_guard<std::mutex> guard(G_gen_mutex);
    std::shared_ptr<LMessage> msg = std::make_shared<LMessage>();

    msg->ClearContent();
    msg->fEpochTime = fTime.GetEpochTime();

    if(format == eMSGFORMAT::ALL_FIELDS_OFF)
    {
        SPRINTF(msg->fMsg, MAX_MSG_SIZE, "NO MESSAGE WAS GENERATED BECAUSE ALL FILEDS ARE TURNED OFF !!\n");
        return msg;
    }

    string lfilepath = string(fname); // The full path to the file, including the filename
    string ldir; // Only the directory part of the path
    string lfilename; // Only the filename part of the full path

    bool has_filepath = (int)eMSGFORMAT::FILE_PATH & (int)format ? true : false;
    bool has_filename = (int)eMSGFORMAT::FILE_NAME & (int)format ? true : false;

    if((has_filepath || has_filename) == true)
    {
        fTokenizer.StripPath(lfilepath, ldir, lfilename);
    }

    msg->fLevel = l;
    msg->fSystem = s;
    msg->fFormat = format;
    msg->fRgBColor = LColorMap::Instance()->GetRGB(l);
    msg->fAColor = LColorMap::Instance()->GetAnsiColor(l);
    msg->fWColor = LColorMap::Instance()->GetCColor(l);


    //int snprintf ( char * s, size_t n, const char * format, ... );

    if((int)eMSGFORMAT::MESSAGE_TYPE & (int)format)
    {
        string ret = LEnum2String::ToString(s, l);
        SPRINTF(msg->fMsgType, (size_t)MAX_MSG_TYPE_SIZE, "%s", ret.c_str());
    }

    if((int)eMSGFORMAT::TIME_STAMP & (int)format)
    {
        SPRINTF(msg->fTimeStamp, MAX_MSG_TIME_STAMP_SIZE, "%s; ", fTime.TimeStamp().c_str());
    }

    if((int)eMSGFORMAT::TIME_STAMP_SHORT & (int)format)
    {
        SPRINTF(msg->fTimeStamp, MAX_MSG_TIME_STAMP_SIZE, "%s; ", fTime.TimeStampShort().c_str());
    }

    if(has_filepath)
    {
        SPRINTF(msg->fPath, MAX_MSG_PATH_SIZE, "%s;", ldir.c_str());
    }

    if(has_filename)
    {
        SPRINTF(msg->fFileName, MAX_MSG_FNAME_SIZE, "%s;", lfilename.c_str());
    }

    if((int)eMSGFORMAT::FUNCTION_NAME & (int)format)
    {
        SPRINTF(msg->fFunction, MAX_MSG_FUNC_NAME_SIZE, "%s;", func);
    }

    if((int)eMSGFORMAT::LINE_NO & (int)format)
    {
        msg->fLineNo = line;
    }

    char formatted_message[MAX_MSG_SIZE] = {0};

    if(((int)eMSGFORMAT::MESSAGE_BODY & (int)format) || l == eMSGLEVEL::LOG_FORCE_DEBUG)
    {
        if(fmt != 0)
        {
            if(sizeof...(args) > 0)
            {
                 SPRINTF(formatted_message, sizeof(formatted_message) - 1, fmt, args... );
                SPRINTF(msg->fMsgBody, MAX_MSG_SIZE, "%s%s", formatted_message, addendum.c_str());
            }
            else
            {
                SPRINTF(msg->fMsgBody, MAX_MSG_SIZE, "%s%s", fmt, addendum.c_str());
            }
        }
    }
    if((int)eMSGFORMAT::MESSAGE_TYPE & (int)format)
    {
        if((int)eMSGFORMAT::LINE_NO & (int)format)
        {
            SPRINTF(msg->fMsg, MAX_MSG_TOTAL_SIZE, "%-25s%s%s%s%s[line %d]\t%s\n", msg->fMsgType, msg->fTimeStamp,
                    msg->fPath, msg->fFileName, msg->fFunction, msg->fLineNo, msg->fMsgBody);
        }
        else
        {
            SPRINTF(msg->fMsg, MAX_MSG_TOTAL_SIZE, "%-25s%s%s%s%s\t%s\n", msg->fMsgType, msg->fTimeStamp,
                    msg->fPath, msg->fFileName, msg->fFunction, msg->fMsgBody);
        }
    }
    else
    {
        if((int)eMSGFORMAT::LINE_NO & (int)format)
        {
            SPRINTF(msg->fMsg, MAX_MSG_TOTAL_SIZE, "%s%s%s%s[line %d]\t%s\n", msg->fTimeStamp, msg->fPath,
                    msg->fFileName, msg->fFunction, msg->fLineNo, msg->fMsgBody);
        }
        else
        {
            SPRINTF(msg->fMsg, MAX_MSG_TOTAL_SIZE, "%s%s%s%s\t%s\n", msg->fTimeStamp, msg->fPath, msg->fFileName,
                    msg->fFunction, msg->fMsgBody);
        }
    }

    //  fgMsgLast = msg;
    return msg;
}



template<typename... Args>
std::shared_ptr<LMessage> 
LMessageGenerator::GenerateMsg(const eMSGFORMAT format, const eMSGLEVEL l, const eMSGSYSTEM s,
                                                         const char *fname, int line, const char *func, const char *fmt,
                                                         const Args ... args)
{
    return GenerateMsg(format, l, s, fname, line, func, string(""), fmt, args...);
}
/**@}*/
}
