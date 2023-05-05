// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
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

#include  <iostream>
#include  <logging/LLogging.h>
#include  <logging/LLogTest.h>
#include  <logging/LMessage.h>
#include  <logging/LConfig.h>
#include  <logging/LPublisher.h>
#include  <cmdline/GLogApplication.h>
#include  <logging/GException.h>
#include <utilities/version-info/GMenu.h>

using std::cout;
using std::endl;
using namespace LOGMASTER;
#include  <thread>
#include  <chrono>


#include <map>


int
main(int  argc, const char ** argv)
{
    GMenu::Instance()->ScanArguments(argc, argv);

   // LLogging::Instance()->SetLogLevel("--off --all-debug");
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
    LLogging::Instance()->SetLogLevel("--off --all-debug");
 //   std::this_thread::sleep_for(std::chrono::milliseconds(500));

  
    try
    {
        LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
        SET_LOGLEVEL("--off --all-debug");
        SET_LOGFILENAME("example.log");
        SET_LOGFORMAT("1111111");  // long timestamp
        SET_LOGTARGET("--target-stdout --target-file");
        FORCE_DEBUG("Writing some test messages");
                
        LLogTest::WriteMessages();

        FORCE_DEBUG("Turning everything off");
        FORCE_DEBUG("Setting loglevel to fatal");
        SET_LOGLEVEL("--fatal"); 
        LLogTest::WriteMessages(); // should see only fatal log messages
        FORCE_DEBUG("Setting loglevel to OFF");
        SET_LOGLEVEL("--off");
        LLogTest::WriteMessages(); // should see nothing
        double temperature = 99999.999;
        FORCE_DEBUG("Alarms are always writing, attempt to turn them off are vetoed by the system");
        ALARM_FATAL("Temperature reached %f degrees\n\n", temperature );

        FORCE_DEBUG("Forcing output to stdout, all settings ignored");
        FORCE_DEBUG("Setting  log level to debug for all subsystems");
        SET_LOGLEVEL("--debug");
        LLogTest::WriteMessages();
        
        
        // Pushing an popping coinfigurations on/off the stack 
        PUSH();
        SET_LOGLEVEL("--all-off --fsm-info");
        SET_LOGFORMAT("--short-user");
        FORCE_DEBUG("Selected info messages and above  the FSM subsystem");
        LLogTest::WriteMessages();      
        
        
        SET_LOGFORMAT("--all-off --msg-body");
        SET_LOGFORMAT("--all-off --msg-body");
        LLogTest::WriteMessages();      
    
        FORCE_DEBUG("Popping back the previous configuration");
        POP();
        LLogTest::WriteMessages();
    
        FSM_ASSERT_WARNING( true == false, "true and false are not equal"); 
        FSM_ASSERT_WARNING( true == true, "true and true are EQUAL"); //nothing writtns since the assertion is true 
    
        SET_LOGLEVEL("--fatal");
        FSM_ASSERT_WARNING( true == false, "true and false are not equal"); // nothing written because loglevel is fatal 
        FSM_ASSERT_ERROR( true == false, "true and false are not equal"); // nothing written because loglevel is fatal
        FSM_ASSERT_FATAL( true == false, "true and false are not equal"); // written beacause level is fatal, and assertion is false
        FSM_ASSERT_FATAL( true == true, "true and true are EQUAL"); // nothing written, assertion is true

        double temp_max = 125;
        // No exception, assertion is true.
        ALARM_ASSERT_EXCEPTION( temperature > temp_max, "Temperature too Low (%f) must be higher than %f",  temperature,  temp_max );
        
        // Exception thrown, assertion is false. loglevel is ignored for exceptions
        ALARM_ASSERT_EXCEPTION( temperature < temp_max, "Temperature too High (%f) must be less than %f",  temperature,  temp_max );
        
    }

    catch ( GAlarmException &e )
    {
        cout << "Alarm exception caught:" << e.what() << endl;
    }
    catch (GException &e)
    {
        cout << "exception caught:" << e.what() << endl;
    }
    catch (std::exception &e)
    {
        cout << "std::exception caught: " << e.what() << endl;
    }
    catch(string &e)
    {
        CERR << e << endl;
    }
    catch (...)
    {
        cout << "unknown exception caught" << endl;
    }
   
    return 0;

}
