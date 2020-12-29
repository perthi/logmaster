// -*- mode: c++ -*-

/* ****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
***************************************************************************** */

/* ****************************************************************************
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

#define G_STANDALONE
#define EXT_DEBUG
#define MAX_STACK_DEPTH 20

#define THREAD_SAFE

#include "LLogging.h"
#include "LMessage.h"
#include "LConfig.h"
#include "LPublisher.h"
#include "LConversion.h"
#include <utilities/GTime.h>


#include <cstdarg>

#ifdef THREAD_SAFE
#include <mutex>
std::mutex log_mutex;
std::mutex new_mutex;
#endif



string fSource;

namespace LOGMASTER
{
    LLogging *
    LLogging::Instance()
    {
        static LLogging* instance = new LLogging();
        return instance;
    }


    LLogging::LLogging() : fSubscribers(),
                           fGuiSubscribers(),
                           fConfig(nullptr),
                           fDefaultConfig(nullptr),
                           fMessages(nullptr), fConfigurationStack()
    {
        Init();
    }


    void            
    LLogging::SetExternalTimeSource(  std::function<double()>  funct )
    {
        GTime::SetExternalTimeSource( funct );    
    }


    void 
    LLogging::SetPublishingMode( const ePUBLISH_MODE mode )
    {  
        LPublisher::Instance()->SetMode( mode ); 
    }

    void 
    LLogging::QueMessage(const std::shared_ptr<LMessage> msg, const std::shared_ptr<LConfig> cfg, const eMSGTARGET target)
    {
                        LPublisher::Instance()->QueMessage( msg,   cfg,  target);
    }


    LLogging::~LLogging()
    {
        try
        {
            do
            {
                if ( fConfigurationStack.size() > 0 )
                {
                    delete &fConfigurationStack.top();
                    fConfigurationStack.pop();
                }
            } while ( fConfigurationStack.size() > 0 );
        }
        catch ( std::exception& e )
        {
            CERR << ":" << e.what() << ENDL;

        }
        catch ( ... )
        {
            CERR << ": Unknown exception !!" << ENDL;
        }
    }

	//  std::shared_ptr<std::map<eMSGTARGET,  LMessageFactory  > >  fConfig = nullptr;
    void
    LLogging::Init()
    {
      //  LPublisher::Instance()->StartDispatcher();
        fConfig    =            std::make_shared<  std::map<eMSGTARGET,  LMessageFactory  > >();
        fDefaultConfig =        std::make_shared< std::map<eMSGTARGET, LMessageFactory > > ();

        fConfig->emplace(  eMSGTARGET::TARGET_FILE,        LMessageFactory()  ) ;
        fConfig->emplace(  eMSGTARGET::TARGET_STDOUT,      LMessageFactory());
        fConfig->emplace(  eMSGTARGET::TARGET_SUBSCRIBERS, LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_GUI,         LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_EXCEPTION,   LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_TESTING,     LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_DATABASE,     LMessageFactory() );

        fDefaultConfig = fConfig;

        SetLogTarget( "--target-off --target-file --target-subscriber --target-stdout --target-gui --target-db" );
        SetLogLevel("--all-warning");
        SetLogFormat("--target-gui --all-off --short-user");

        fMessages =  std::make_shared< std::map<eMSGTARGET,  std::shared_ptr<LMessage>   > >();

        for ( auto it = fConfig->begin(); it != fConfig->end(); it ++ )
        {
            fMessages->emplace( it->first, new LMessage() );
        }

    }


    void
    LLogging::ClearMessages()
    {
        for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
        {
            it->second.GetMessage()->ClearContent();
        }

        for ( auto it = fMessages->begin(); it != fMessages->end(); it++ )
        {
            it->second->ClearContent();
        }
    }


    void
    LLogging::Reset()
    {
#ifdef THREAD_SAFE
        std::lock_guard<std::mutex> guard( log_mutex );
#endif
        fConfig = fDefaultConfig;
        do
        {
            auto c = fConfigurationStack.top();
            fConfigurationStack.pop();
        } while ( fConfigurationStack.size() > 0 );
    }

  
  logmap 
  LLogging::LogVarArgsUnsafe(const eMSGLEVEL level, const eMSGSYSTEM system, const char *filename,
                                      const int lineno, const char *funct, const bool force_generate, string addendum,
                                      const char *fmt, va_list ap)
    {
        if(fConfig == nullptr)
        {
            CERR << "CONFIG IS A ZERO POINTER" << ENDL;
            exit(-1);
        }

        static std::shared_ptr<LMessage> tmp_msg = std::make_shared<LMessage>();

        ClearMessages();
        va_list ap_l;
        va_copy(ap_l, ap);
        for(auto it = fConfig->begin(); it != fConfig->end(); ++it)
        {
            if(it->second.IsEnabled() == true)
            {
                bool cl = CheckLevel(system, level, it->first);

                if((cl == true) || force_generate == true)
                {
                    tmp_msg = it->second.GenerateMessageUnsafe(system, level, filename, lineno, funct, addendum, fmt, ap_l);

                    if(cl == true)
                    {
                        QueMessage(tmp_msg, it->second.GetConfig(), it->first);

                        //   LPublisher::Instance()->PublishMessage( tmp_msg, it->second.GetConfig(), it->first );

                        // LPublisher::PublishMessage( tmp_msg, it->second.GetConfig(), target );
                        auto it_msg = fMessages->find(it->first);
                        if(it_msg != fMessages->end())
                        {
                            it_msg->second = tmp_msg;
                        }
                    }
                }
            }
        }
        va_end(ap_l);
        return fMessages;

    }




    /** Checks the loglevel of a message issued by the user against the current loglevel configured for the logging system*
     *  @param system  The subsystem this message applies to
     *  @param level   The loglevel (severity) of the message
     *  @param target  Which target (file, stdout, etc..) to check level for
     *   @return true if the message should be generated for this level, false othervise */
    bool
    LLogging::CheckLevel( const eMSGSYSTEM system, const eMSGLEVEL level, const eMSGTARGET target )
    {

        static eMSGLEVEL zero_l = (eMSGLEVEL)0;
        static eMSGSYSTEM zero_s = (eMSGSYSTEM)0;

        if ( level == eMSGLEVEL::LOG_FORCE_DEBUG )
        {
            return true;
        }

        auto it_1 = fConfig->find( target );

        if ( it_1 == fConfig->end() )
        {
            return false;
        }
        else
        {
            auto hash = &it_1->second.GetConfig()->GetHash()->fLogLevelHash;
            auto it = hash->find( system );

            if ( it != hash->end() )
            {
                if ( (it->second & level) != zero_l )
                {
                    return true;
                }
            }
            for ( it = hash->begin(); it != hash->end(); it++ )
            {
                if ( (it->first & system) != zero_s )
                {
                    if ( (level & it->second) != zero_l )
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }

    void LLogging::Flush()
    {
        LPublisher::Instance()->Flush();
    }


    void
    LLogging::SetLogTarget( const string& target_s, bool eneable )
    {
#ifdef THREAD_SAFE
        std::lock_guard<std::mutex> guard( log_mutex );
#endif
        vector<eMSGTARGET> e_targets;
        vector<string> tokens  =  GTokenizer().Tokenize( target_s, vector<string>{" ", "\n","\t" } );

        for ( size_t i = 0; i < tokens.size(); i++ )
        {
            eMSGTARGET e_tmp = LConversion::String2Target(  tokens[i]);

            if ( e_tmp == eMSGTARGET::TARGET_OFF )
            {
                TurnOffAllTargets();
                continue;
            }

            for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
            {
                if ( (e_tmp & it->first) != eMSGTARGET::TARGET_OFF )
                {
                    if(eneable)
                    {
                        it->second.Enable();
                    }
                    else
                    {
                        it->second.Disable();
                    }
                }
            }
        }
    }


    std::shared_ptr<LConfig>
    LLogging::GetConfig( const eMSGTARGET target )
    {
        auto it = fConfig->find( target );

        if ( it != fConfig->end() )
        {
            return it->second.GetConfig();
        }
        else
        {
            return nullptr;
        }
    }


    eMSGTARGET
    LLogging::GetLogTarget() const
    {

        eMSGTARGET tmp = eMSGTARGET::TARGET_OFF;

        for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
        {
            bool b = it->second.IsEnabled();

            if ( b == true )
            {
                tmp = tmp | it->first;
            }
        }

        return tmp;
    }


    eMSGFORMAT
    LLogging::GetLogFormat( const eMSGTARGET target ) const
    {
        auto it = fConfig->find( target );

        if ( it != fConfig->end() )
        {
            return it->second.GetConfig()->GetLogFormat();
        }
        else
        {
            return (eMSGFORMAT)0;
        }
    }


    void
    LLogging::SetLogFileName( const string& filename )
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> guard( mtx );

        auto m = LConversion::SplitByTarget( filename );
        for ( auto it = m.begin(); it != m.end(); it++ )
        {
            eMSGTARGET target = it->first;
            for ( auto it2 = fConfig->begin(); it2 != fConfig->end(); it2++ )
            {
                if ( (it2->first & target) != eMSGTARGET::TARGET_OFF )
                {
                    it2->second.GetConfig()->fLogFilename = filename;
                }
            }
        }
    }


    eMSGLEVEL
    LLogging::GetLogLevel( const eMSGSYSTEM system, const eMSGTARGET target ) const
    {
        auto it = fConfig->find( target );

        if ( it != fConfig->end() )
        {
            return it->second.GetConfig()->GetLogLevel( system );
        }

        return eMSGLEVEL::LOG_OFF;
    }


    string
    LLogging::GetLogFileName( const eMSGTARGET target ) const
    {
     //   std::lock_guard<std::mutex> guard( log_mutex );
        auto it = fConfig->find( target );

        if ( it != fConfig->end() )
        {
            return it->second.GetConfig()->fLogFilename;
        }
        else
        {
            return "no such subsystem-found";
        }
    }


    vector< void( *) (  std::shared_ptr<LMessage>  ) >  
    LLogging::GetSubscribers()
    {
        return fSubscribers;
    }


    void
    LLogging::SetLogLevel( const string& level_s )
    {
        std::lock_guard<std::mutex> guard( log_mutex );
        auto m = LConversion::SplitByTarget(level_s);

        for ( auto it_m = m.begin(); it_m != m.end(); it_m++ )
        {
            eMSGTARGET target = it_m->first;

            for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
            {
                if ( (it->first & target) != (eMSGTARGET)0 )
                {
                    it->second.GetConfig()->SetLogLevel( it_m->second );
                }
            }
        }
    }


    void
    LLogging::SetLogFormat( const string& f, bool enable)
    {

#ifdef THREAD_SAFE
        std::lock_guard<std::mutex> guard( log_mutex );
#endif

        auto m = LConversion::SplitByTarget(f );

        for ( auto it_m = m.begin(); it_m != m.end(); it_m++ )
        {
            eMSGTARGET target = it_m->first;

            for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
            {
                if ( (it->first & target) != (eMSGTARGET)0 )
                {
                    std::shared_ptr<LConfig> cfg = it->second.GetConfig();
                    cfg->SetLogFormat( it_m->second, enable);
                }
            }
        }
    }


	/** Register a subscriber callbakc function that will be called by the logging system *
	* NB! You must not call the logging itself system within a subscriber function s*/
    void
    LLogging::RegisterSubscriber( void( *funct )(  std::shared_ptr<LMessage>   ) )
    {
      //  std::lock_guard<std::mutex> guard( log_mutex );
        fSubscribers.push_back( funct );
    }


    void
    LLogging::ClearSubscribers()
    {
      ///  std::lock_guard<std::mutex> guard( log_mutex );
        fSubscribers.clear();
    }

    vector<void( *)( std::shared_ptr<LMessage>  )> 
    LLogging::GetGuiSubscribers()
    {
        return fGuiSubscribers;
        // TODO: insert return statement here
    }

    void
    LLogging::RegisterGuiSubscriber( void( *funct )( std::shared_ptr <LMessage>  ) )
    {
      //  std::lock_guard<std::mutex> guard( log_mutex );
        fGuiSubscribers.push_back(funct);
    }


    void
    LLogging::ClearGuiSubscribers()
    {
      //  std::lock_guard<std::mutex> guard( log_mutex );
        fGuiSubscribers.clear();
    }



    int
    LLogging::Push( )
    {
      ///  static std::mutex m;
        std::lock_guard<std::mutex> guard( log_mutex );
       // return 0;
        if ( fConfigurationStack.size() >= MAX_STACK_DEPTH )
        {
            CERR << "stack is full (size = " << fConfigurationStack.size() << ")" << ENDL;
            return -1;
        }
        else
        {   
            fConfigurationStack.push( fConfig );
            fConfig =  std::make_shared< std::map<eMSGTARGET, LMessageFactory > >( *fConfig );
            return 0;
        }
        return 0;
    }


    int
    LLogging::Pop(  )
    {
       std::lock_guard<std::mutex> guard( log_mutex );
        if ( fConfigurationStack.size() > 0 )
        {
            fConfig = fConfigurationStack.top();
            fConfigurationStack.pop();

            return 0;

        }
        else
        {
            return -1;
        }
    }


    void
    LLogging::TurnOffAllTargets()
    {
    //    std::lock_guard<std::mutex> guard( log_mutex );
        for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
        {

            if ( it->first != eMSGTARGET::TARGET_EXCEPTION  && it->first != eMSGTARGET::TARGET_TESTING )
            {
                it->second.Disable();
            }
        }
    }


    void
    LLogging::TurnOnfAllTargets()
    {
  //     std::lock_guard<std::mutex> guard( log_mutex );
        for ( auto it = fConfig->begin(); it != fConfig->end(); it++ )
        {
            it->second.Enable();
        }
    }

} // namespace LOGMASTER

