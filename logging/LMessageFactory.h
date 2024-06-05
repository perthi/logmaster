// -*- mode: c++ -*-
#pragma once


/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/

#include "LEnums.h"
#include "LMessageGenerator.h"
#include "LConfig.h"

#include <utilities/GDefinitions.h>

#include <string>

using std::string;

#include <memory>
#include <stdarg.h>

namespace LOGMASTER
{
    class  LMessage;
    class  LConfig;
    class  LLogging;

    /** @class LMessageFactory
    * Helper class used by LLogging  */
    class LMessageFactory
    {

            friend LLogging;
    public:
            LMessageFactory();
            LMessageFactory( const LMessageFactory &gen );
            ~LMessageFactory();
            void      API    SetConfig( const LConfig  c );
            std::shared_ptr< LConfig>   API   GetConfig();
            std::shared_ptr< LMessage>  API  GetMessage();
            bool      API    IsEnabled() const;
            void      API    Enable();
            void      API    Disable();
            template<typename... Args>
            std::shared_ptr<LMessage> API GenerateMessage(const eMSGSYSTEM s, const eLOGLEVEL l, const char *file,
                                                          const int line, const char *func, const string addendum,
                                                          const char *fmt, const Args ... args);
            std::shared_ptr<LMessage> API GenerateMessageUnsafe(const eMSGSYSTEM s, const eLOGLEVEL l, const char *file,
                                                          const int line, const char *func, const string addendum,
                                                          const char *fmt, va_list ap);

    private:
            LMessageFactory operator = ( const LMessageFactory &);
            bool fIsEnabled = true;
            std::shared_ptr<LMessage> fMessage = nullptr;
            std::shared_ptr<LMessageGenerator> fGenerator = nullptr;
            std::shared_ptr<LConfig> fConfig = nullptr;
        };

        template<typename... Args>
        std::shared_ptr<LMessage> LMessageFactory::GenerateMessage(const eMSGSYSTEM s, const eLOGLEVEL l,
                                                                   const char *file, const int line, const char *func,
                                                                   const std::string ad, const char *fmt,
                                                                   const Args ... args)
        {
            if(fConfig == nullptr)
            {
               // CERR << "fConfig is a zero pointer !!!" << ENDL;
                std::shared_ptr<LMessage> m = std::make_shared<LMessage>();
                return m;
            }
            eMSGFORMAT f = fConfig->GetLogFormat();

            // fMessage =  fGenerator->GenerateMsg(fMessage,  f, l, s, file, line, func, fmt, ap, ad );
            fMessage = fGenerator->GenerateMsg(f, l, s, file, line, func, ad, fmt, args...);

            return fMessage;
        }

}

