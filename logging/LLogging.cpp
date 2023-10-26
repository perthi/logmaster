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
#include "LDoc.h"

#include <utilities/GTime.h>


#include <cstdarg>

#ifdef THREAD_SAFE
#include <mutex>
std::mutex log_mutex;
std::mutex new_mutex;
#endif


#include <exception>


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

    void
    LLogging::Init()
    {
        fConfig    =            std::make_shared<  std::map<eMSGTARGET,  LMessageFactory  > >();
        fDefaultConfig =        std::make_shared< std::map<eMSGTARGET, LMessageFactory > > ();

        fConfig->emplace(  eMSGTARGET::TARGET_FILE,        LMessageFactory()  ) ;
        fConfig->emplace(  eMSGTARGET::TARGET_STDOUT,      LMessageFactory());
        fConfig->emplace(  eMSGTARGET::TARGET_SUBSCRIBERS, LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_GUI,         LMessageFactory() );
        fConfig->emplace(  eMSGTARGET::TARGET_EXCEPTION,   LMessageFactory() );
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
            fConfigurationStack.pop();
        } while ( fConfigurationStack.size() > 0 );
    }

  

    /** Checks the log level of a message issued by the user against the current log level configured for the logging system*
     *  @param system  The subsystem this message applies to
     *  @param level   The log level (severity) of the message
     *  @param target  Which target (file, stdout, etc..) to check level for
     *   @return true if the message should be generated for this level, false otherwise */
    bool
    LLogging::CheckLevel( const eMSGSYSTEM system, const eLOGLEVEL level, const eMSGTARGET target )
    {

        static eLOGLEVEL zero_l = (eLOGLEVEL)0;
        static eMSGSYSTEM zero_s = (eMSGSYSTEM)0;

        if ( level == eLOGLEVEL::LOG_FORCE_DEBUG )
        {
            return true;
        }
  
        if(target == eMSGTARGET::TARGET_ALL )
        {
            for(auto it = fConfig->begin(); it != fConfig->end(); it ++ )
            {
                auto & hash = it->second.GetConfig()->GetHash()->fLogLevelHash;
                auto it_hash = hash.find( system );
                    
               for ( it_hash = hash.begin(); it_hash != hash.end(); it_hash++ )
               {
                    if (  ( it_hash->first   & system)   !=  zero_s )  
                    {
                        if ( (level & it_hash->second) != zero_l )
                        {
                            return true;
                        }
                    }
                }

                return false;
            }
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


    eLOGLEVEL
    LLogging::GetLogLevel( const eMSGSYSTEM system, const eMSGTARGET target ) const
    {
        auto it = fConfig->find( target );

        if ( it != fConfig->end() )
        {
            return it->second.GetConfig()->GetLogLevel( system );
        }

        return eLOGLEVEL::LOG_OFF;
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
        
        try
        {
//            CERR << "level_s = " << level_s << ENDL;
            auto m = LConversion::SplitByTarget(level_s);
  //          CERR << "m.size() = "<< m.size()  << ENDL;

            for ( auto it_m = m.begin( ); it_m != m.end( ); it_m++ )
            {
                eMSGTARGET target = it_m->first;
                

                for ( auto it = fConfig->begin( ); it != fConfig->end( ); it++ )
                {
                    if ( (it->first & target) != (eMSGTARGET)0 )
                    {
                       // CERR << "it->second = " << it_m->second << ENDL;
                        it->second.GetConfig( )->SetLogLevel(it_m->second);
                    }
                }
            }
        }
        catch( std::exception &e )
        { 
        
            cout << LDoc::Help( ) << endl;
            //CERR << "Exception caught setting log level: " << e.what() << ENDL;
            throw(e);
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


    /** Register a subscriber callback function that will be called by the logging system *
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
        fSubscribers.clear(); /// @todo , should be erased, not cleared. Fix + make unit tests
    }

    vector<void( *)( std::shared_ptr<LMessage>  )> 
    LLogging::GetGuiSubscribers()
    {
        return fGuiSubscribers;
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
        fGuiSubscribers.clear();  ///  @todo , should be erased, not cleared. Fix + make unit tests
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

         //   if ( it->first != eMSGTARGET::TARGET_EXCEPTION  && it->first != eMSGTARGET::TARGET_TESTING )
                if (it->first != eMSGTARGET::TARGET_EXCEPTION )
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


   /** @brief Whether or not to perform printf format check on all messages or just on messages that will be written.i.e
    *  that is above a given log level.
    *  @details In a production system the performance can be significantly improved by only performing a format check
    *  on messages that will actually be written to any of the log targets. However this has the drawback that
    *  formatting errors for DEBUG, INFO etch will not be detected if the log level is for instance WARNING, so one can get a suprise
    *  if the log level is changed.
    *  @param val[in] true/false. TRUE: all messages are checked, FALSE: Only messages matching the log level will be checked. */ 
   void  
   LLogging::SetFormatCheckAll( const bool val )
   {
        fFormatCheckAll = val;
   }    

} // namespace LOGMASTER

