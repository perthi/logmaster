// -*- mode: c++ -*-
#ifndef LPUBLISHER_H
#define LPUBLISHER_H

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#include "LLogApi.h"
#include "LMessage.h"
#include "LEnums.h"

#include  "LMessage2Json.h"
#include  <utilities/GDefinitions.h>
#include  <memory>
#include  <queue>  
#include  <mutex>
#include  <thread>
#include  <atomic>

class GDataBaseIF;

namespace LOGMASTER
{
  //  struct LMessage;
    class LLogging;
    class LConfig;
    class LDatabase;
  
   

    /** @class LPublisher
    * class that is responsible for writing ( publishing) messages to various targets. Available targets
    * for the moment is  File, subscriber functions, or standard output (i.e the console). Targets soon to
    * be added is GUI, and TCP/IP port */
    class LPublisher
    {
        friend LLogging;
        friend LDatabase;
        friend GDataBaseIF;

    public:        
        static  LPublisher API * Instance();

        void            SetExternalTimeSource(  std::function<double()> funct ) {   GTime().SetExternalTimeSource(funct); };

        void  API   EnableColor();
        void  API   DisableColor();
        bool  API  * GetEnableColor();
        void  API   EnableJson();
        void  API   DisableJson() ;
        bool  API  * GetEnableJson() ; 
        void  API   QueMessage( std::shared_ptr<LMessage>  msg, std::shared_ptr<LConfig>,    const eMSGTARGET target  );    
        
        void  API   StartDispatcher(); 
        void  API   StopDispatcher(); 
        void  API   PauseDispatcher();
        void  API   ResumeDispatcher();
        void  API   RunDispatcher();
        void  API   SetMode( const ePUBLISH_MODE mode );
        void  API   Flush();
        
        static void AtExit();     

    private:
         LPublisher();
        ~LPublisher();
         LPublisher( const LPublisher   & );
         LPublisher operator =  ( const LPublisher   & );   


        struct Message
         {
         //   LMessage fMessage = LMessage();
            std::shared_ptr<LMessage> fMessage = nullptr;
            std::shared_ptr<LConfig>  fConfig = nullptr;
            eMSGTARGET     fTarget  = eMSGTARGET::TARGET_OFF;

         };    

         void     DispatchMessages();       
         void     API PublishMessage(     std::shared_ptr<LMessage> m, const std::shared_ptr<LConfig>,  const eMSGTARGET target  );
         void     API PublishToSubscribers(   std::shared_ptr<LMessage> msg);
         void     API PublishToGuiSubscribers( std::shared_ptr<LMessage>  msg);
         void     API PublishToConsole(     std::shared_ptr<LMessage> msg);
         void     API PublishToFile(     const char * filename,     std::shared_ptr<LMessage> msg );
         void     API PublishToFileJson( const char * filename,  std::shared_ptr<LMessage> msg    );
         void     API PublishToDatabase( std::shared_ptr<LMessage>  msg); 

         std::queue<  std::shared_ptr<Message> >  fMessageQeue      =  std::queue<  std::shared_ptr<Message> >();        
         std::queue<  std::shared_ptr<Message> >   fMessageQeueTmp   =  std::queue<  std::shared_ptr<Message> >();        

#ifdef _WIN32
         std::mutex                             fMessageQeueMutext;
         std::mutex                              fDispatcherMutext;
#else
         std::mutex                             fMessageQeueMutext = std::mutex();
         std::mutex                              fDispatcherMutext = std::mutex();

#endif

         bool     fgEnableColor       =   true;     /* !< Wether or not colors will be used for distinguishing messages when they are written to the console */  
         bool     fgEnableJson        =   true;
         std::thread *fDispatcher     =   nullptr;
         std::atomic_bool  fDoRun     =   true; 
         std::atomic_bool  fDoPause   =   false;
         std::atomic_bool  fIsRunning =   false; 

         //ePUBLISH_MODE fPublisherMode =  ePUBLISH_MODE::ASYNCHRONOUS;
         ePUBLISH_MODE fPublisherMode =  ePUBLISH_MODE::SYNCHRONOUS;

         GTime fTime;
         LMessage2Json fMessage2Json;
         ///std::shared_ptr<LDatabase>

    };


}
#endif
