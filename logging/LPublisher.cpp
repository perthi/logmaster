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




#include "LPublisher.h"

#include "LConfig.h"
#include "LLogging.h"
#include "LColorMap.h"
#include "LMessage.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <utilities/GTime.h>
#include <utilities/GColor.h>

#include "LLogApi.h"
#include "LMessage2Json.h"
#include "LDatabase.h"

#include <memory>
#include <json/json.hpp>



using namespace LOGMASTER;


#include <chrono>


namespace LOGMASTER
{

    LPublisher  * 
    LPublisher::Instance()
    {
        static  LPublisher *instance = new LPublisher();
        return instance;
    }

    LPublisher::LPublisher()
    {
         std::atexit(  AtExit );
        StartDispatcher(); 
    }

    LPublisher::~LPublisher()
    {
        CERR << "calling desrtructor " << endl;
    }



    void 
    LPublisher::AtExit()
    {
        Instance()->StopDispatcher();
    }     


    void  
    LPublisher::StartDispatcher()
    {
	    static  std::mutex m;
		std::lock_guard<std::mutex> guard( m );
        fDispatcher = new std::thread( &::LPublisher::RunDispatcher, this );
    }

    void
    LPublisher::StopDispatcher()
    {
        fDoRun = false;

        if (fDispatcher != nullptr)
        {
            if (fDispatcher->joinable() == true)
            {
                {
                    static std::mutex m;
                    std::lock_guard<std::mutex> guard(m);
                    fDispatcher->join();
                    delete fDispatcher;
                    fDispatcher = nullptr;
                    fIsRunning = false;
                }
            }
            else
            {
                CERR << "Thread is not joinable" << endl;
            }
        }
    }


    void  
    LPublisher::PauseDispatcher()
    {
       fDoRun = false;  
    }
    
    void  
    LPublisher::ResumeDispatcher()
    {
        fDoRun = true;  
    }


    void
    LPublisher::RunDispatcher()
    {

        while (fDoRun == true)
        {
            if (fDoPause == true)
            {
                fIsRunning = false;
            }
            else
            {
                fIsRunning = true;
                DispatchMessages();
            }
        }
    }


    void
    LPublisher::DispatchMessages()
    {
      std::queue<  std::shared_ptr<Message> > tmp_messages  = std::queue<  std::shared_ptr<Message> >();   
       {
           std::lock_guard<std::mutex> guard2( fMessageQeueMutext ); 
            std::swap( tmp_messages, fMessageQeue  );
       }

        static std::mutex mtx;
        std::lock_guard<std::mutex> guard3( mtx ); 

        while ( tmp_messages.size() > 0  )
        {
            auto m =  tmp_messages.front();
            tmp_messages.pop();
            PublishMessage( m->fMessage ,  m->fConfig, m->fTarget );
        }

    }



void
LPublisher::QueMessage(  const std::shared_ptr<LMessage>  msg, const std::shared_ptr<LConfig> cfg,    const eMSGTARGET target    )
{
   // Message m;
    std::lock_guard<std::mutex> guard( fMessageQeueMutext );
    std::shared_ptr< Message > m = std::make_shared< Message >();

    m->fMessage =  *msg;
    m->fConfig = cfg;
    m->fTarget = target;  
    fMessageQeue.push( m );
}



 /** Publish the message to all targets that is enabled.  Enabled targets are stored in the cfg parameter. The loglevel FORCE_DEBUG is handled differently
     *   than any other log levels and is always written to all targets regardless of the configuration of the logging system.
     *   @param[in] msg  The message to publish
     *   @param[in] cfg The current configuration of the logging system. 
     *   This configuration determins what is written and where it is written to (file, console or subscribers )
     *   @param[in] target The target for where to publish this message (file, stdout, subscribers etc..) */
 void LPublisher::PublishMessage(const LMessage &msg, const std::shared_ptr<LConfig> cfg, const eMSGTARGET target)
 {
     if (cfg == nullptr)
     {
         CERR << " CONFIG IS A ZERO POINTER" << endl;
         return;
     }

     if (msg.fFormat == eMSGFORMAT::ALL_FIELDS_OFF)
     {
         PublishToConsole(msg);
         return;
     }

     bool force_debug = ((int)msg.fLevel & (int)eMSGLEVEL::LOG_FORCE_DEBUG) != 0 ? true : false;

     if (force_debug == true)
     {
         if ((int)target & (int)eMSGTARGET::TARGET_TESTING)
         {
             PublishToConsole(msg);
             PublishToFile(cfg->fLogFilename.c_str(), msg);
             PublishToSubscribers(msg);
             PublishToDatabase(msg);
             PublishToGuiSubscribers(msg);
         }
     }
     else
     {
         //   Publish(msg,  cfg, target );
         if (((int)target & (int)eMSGTARGET::TARGET_FILE))
         {
             PublishToFile(cfg->fLogFilename.c_str(), msg);
         }

         if ((int)target & (int)eMSGTARGET::TARGET_DATABASE)
         {
             PublishToDatabase(msg);
         }

         if (((int)target & (int)eMSGTARGET::TARGET_SUBSCRIBERS))
         {
             PublishToSubscribers(msg);
         }

         if (((int)target & (int)eMSGTARGET::TARGET_GUI))
         {
             PublishToGuiSubscribers(msg);
         }

         if ((int)target & (int)eMSGTARGET::TARGET_STDOUT)
         {
             PublishToConsole(msg);
         }
     }
    }


    void
    LPublisher::PublishToDatabase(const LMessage  &msg  )
    {
        LDatabase::Instance()->AddLogEntry(msg);
    }

    /**  Publish messages via the publiser/subscriber interface. The function iterates thrugh an
     *   array of registered subscribers (if any), and  calls each callback function with the message, subsystem and level as arguments
     *   @param message  The message to publish */
    void
    LPublisher::PublishToSubscribers(const LMessage  &msg )
    {
        auto subscribers = LLogging::Instance()->GetSubscribers();

        for (uint16_t i = 0; i < subscribers.size(); i++)
        {
            void(*Subscriberfunct)(const  LMessage &  ) = subscribers.at(i);
            Subscriberfunct( msg );
        }
    }


    void
    LPublisher::PublishToGuiSubscribers(const LMessage &msg )
    {
        auto subscribers = LLogging::Instance()->GetGuiSubscribers();
        for (uint16_t i = 0; i < subscribers.size(); i++)
        {
            void(*Subscriberfunct)(const LMessage  &) = subscribers.at(i);
            Subscriberfunct(msg);
        }
    }


	void
    LPublisher::PublishToConsole(const  LMessage  &msg)
	{

#ifdef _WIN32
            static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            if (fgEnableColor == true)
            {
                SetConsoleTextAttribute(hConsole, msg.fWColor);
            }
            cout << string(msg.fMsg);
#else                   
            if( fgEnableColor == true  )
            {
                cerr << "\033" << "[1;" << msg.fAColor << "m" << msg.fMsg << "\033" << "[0m"  ;

            }
            else
            {
                cout << msg.fMsg;
            }

#endif  

#ifdef _WIN32            
            SetConsoleTextAttribute(hConsole, CONSOLE_DEFAULT);
#endif     
        }

      void
    LPublisher::PublishToFile(const char * filename, const  LMessage &msg)
    {
        FILE  *logFile = 0;

#ifdef _WIN32
        fopen_s(&logFile, filename, "a");
#else
        logFile = fopen(filename, "a");
#endif
        
        if (logFile)
        {
            fputs( msg.fMsg, logFile);
            fclose(logFile);
            logFile = 0;
        }
        else
        {
            cerr << __FILE__ << ":" << __LINE__ << g_time()->TimeStamp() << ": Error opening Logfile: " << filename << endl;
            CERR << "This message could not be logged:\t" << msg.fMsg << endl;
        }

        if( fgEnableJson == true )
        {
             PublishToFileJson( filename , msg );
        }
    }



    void     
    LPublisher::PublishToFileJson( const char *   filename_base, const  LMessage  & msg )
    {
        string fname_tmp = string( filename_base ) + ".json";
        const char * fname_tmp_c  = fname_tmp.c_str();
        FILE  *logFile = 0;

#ifdef _WIN32
        fopen_s(&logFile,fname_tmp_c, "a");
#else
        logFile = fopen(  fname_tmp_c, "a");
#endif
        nlohmann::json j;
        LMessage2Json::Message2Json( msg, j );
        std::stringstream buffer;
        buffer << j  << endl;

        if (logFile)
        {
            fputs(  buffer.str().c_str(), logFile);
            fclose(logFile);
            logFile = 0;
        }
        else
        {
            cerr << __FILE__ << ":" << __LINE__ << g_time()->TimeStamp() << ": Error opening Logfile: " << fname_tmp_c  << endl;
            CERR << "This message could not be logged:\t" << j << endl;
        }
    }


    void 
    LPublisher::EnableColor()
    {
        fgEnableColor = true;
    }


    void 
    LPublisher::DisableColor()
    {
        fgEnableColor = false;
    }


    bool  *
    LPublisher::GetEnableColor()
    {
        return  &fgEnableColor;
    }


    void   
    LPublisher::EnableJson()
    {
        fgEnableJson = true;
    }

    void   
    LPublisher::DisableJson()
    {
        fgEnableJson = false;
    }
    
    bool   *
    LPublisher::GetEnableJson()
    {
        return &fgEnableJson;
    }  


}
