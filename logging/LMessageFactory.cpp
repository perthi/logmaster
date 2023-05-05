// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) Per Thomas Hille <pth@embc.no>  http:///www.embc.no      ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/

#include "LMessageFactory.h"
#include "LConfig.h"
#include "LMessage.h"
#include "LMessageGenerator.h"


namespace LOGMASTER
{


    LMessageFactory::LMessageFactory()
    {
        fConfig     =   std::make_shared<LConfig>();
        fGenerator  =   std::make_shared<LMessageGenerator>();
        fMessage    =   std::make_shared<LMessage>();
    }

    
    LMessageFactory::LMessageFactory( const LMessageFactory &gen )
    {
        fIsEnabled = gen.fIsEnabled;
        
        if( gen.fConfig  != nullptr )
         {
             fConfig     =   std::make_shared<LConfig>( *gen.fConfig );
         }
         else
         {
             fConfig     =   std::make_shared<LConfig>();
         }
        
         if( gen.fConfig  != nullptr )
         {
            fMessage     =   std::make_shared<LMessage>(*gen.fMessage  ); 
         }
         else
         {
             fMessage     =   std::make_shared<LMessage>();
         }

        
        if( gen.fGenerator  != nullptr )
         {
            fGenerator     =   std::make_shared<LMessageGenerator >( *gen.fGenerator  ); 
         }
         else
         {
             fGenerator     =   std::make_shared<LMessageGenerator >();
         }


    }
    

    LMessageFactory::~LMessageFactory()
    {

    }


    void 
    LMessageFactory::SetConfig( LConfig  c )
    {
        *fConfig = c;
    }


    std::shared_ptr<LConfig>  LMessageFactory::GetConfig()
    {
        return fConfig;
    }


    std::shared_ptr<LMessage> 
    LMessageFactory::GetMessage()
    {
        return fMessage;
    }

    bool
    LMessageFactory::IsEnabled() const
    {
        return fIsEnabled;
    }

    void LMessageFactory::Enable() { fIsEnabled = true; }

    void LMessageFactory::Disable() { fIsEnabled = false; }

    std::shared_ptr<LMessage> LMessageFactory::GenerateMessageUnsafe(const eMSGSYSTEM s, const eLOGLEVEL l,
                                                                     const char *file, const int line,
                                                                     const char *func, const std::string addendum,
                                                                     const char *fmt, va_list ap)
    {
        if (fConfig == nullptr)
        {
            CERR << "fConfig is a zero pointer !!!" << ENDL;
            std::shared_ptr<LMessage> m = std::make_shared<LMessage>();
            return m;
        }
        eMSGFORMAT f = fConfig->GetLogFormat();

        // fMessage =  fGenerator->GenerateMsg(fMessage,  f, l, s, file, line, func, fmt, ap, ad );
        fMessage = fGenerator->GenerateMsg(f, l, s, file, line, func, addendum, fmt, ap);

        return fMessage;
    }

} // namespace LOGMASTER
