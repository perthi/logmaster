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

#include "TestLConfig.h"
#include <logging/LHashMaps.h>
#include <utilities/GUtilities.h>
#include <utilities/GNumbers.h>
#include <logging/LLogApi.h>
#include <logging/LPublisher.h>

using namespace LOGMASTER;

#include <bitset>

#include <thread>
#include <chrono>

void
TestLConfig::SetUp()
{
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
    fConfig = new LConfig();
    s_v    =    LHashMaps::Instance()->GetSystemEnums();
    l_v    =    LHashMaps::Instance()->GetLevelEnums();
    t_v =   LHashMaps::Instance()->GetTargetEnums();
   g_utilities()->FilterOut( s_v, { eMSGSYSTEM::SYS_NONE, eMSGSYSTEM::SYS_ALL, eMSGSYSTEM::SYS_EXCEPTION, eMSGSYSTEM::SYS_ALARM } );
    g_utilities()->FilterOut( l_v, { eLOGLEVEL::LOG_FORCE_DEBUG  } );
    g_utilities()->FilterOut( t_v, { eMSGTARGET::TARGET_OFF, eMSGTARGET::TARGET_ALL } );
}


void 
TestLConfig::TearDown()
{


}





TEST_F( TestLConfig, target_all )
{
    LLogging *log = LLogging::Instance();
    log->SetLogLevel( "--all-off");
    std::this_thread::sleep_for( std::chrono::milliseconds(50) );


    for ( size_t t = 0; t < t_v.size(); t++ )
    {
        for ( size_t s = 0; s < s_v.size(); s++ )
        {
            for ( size_t u = 0; u < l_v.size(); u++ )
            {
                EXPECT_FALSE( log->CheckLevel( s_v[s], l_v[u], t_v[t] ) );
            }
        }
    }

}




TEST_F(TestLConfig, format)
{
    vector<string> format = LHashMaps::Instance()->GetLogFormatTags();
    EXPECT_TRUE(g_utilities()->HasElement(string("--prefix-none"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--msg-type"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--time-stamp"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--file-path"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--file-name"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--func-name"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--line-no"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--msg-body"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--short"), format));
    EXPECT_TRUE(g_utilities()->HasElement(string("--prefix-all"), format));
}



TEST_F(TestLConfig, targets)
{
    vector<string> targets = LHashMaps::Instance()->GetLogTargetTags();

    EXPECT_TRUE( g_utilities()->HasElement(string("--target-off"), targets));
    EXPECT_TRUE( g_utilities()->HasElement(string("--target-subscriber"), targets));
    EXPECT_TRUE( g_utilities()->HasElement(string("--target-file"), targets));
    EXPECT_TRUE( g_utilities()->HasElement(string("--target-stdout"), targets));
    EXPECT_TRUE( g_utilities()->HasElement(string("--target-all"), targets));
}




TEST_F(TestLConfig, apply_get_level)
{
    LConfig *c = new LConfig();
    EXPECT_EQ( (int64_t)c->GetLogLevel(eMSGSYSTEM::SYS_EXCEPTION),  PAD(eLOGLEVEL::LOG_ERROR ) );
    EXPECT_EQ( (int64_t)c->GetLogLevel( eMSGSYSTEM::SYS_USER), PAD(eLOGLEVEL::LOG_WARNING) );
    EXPECT_EQ( (int64_t)c->GetLogLevel( eMSGSYSTEM::SYS_FSM), PAD(eLOGLEVEL::LOG_WARNING) );
    EXPECT_EQ( (int64_t)c->GetLogLevel( eMSGSYSTEM::SYS_GENERAL), PAD(eLOGLEVEL::LOG_WARNING) );
    delete c;
}




TEST_F(TestLConfig, apply_get_level_logging)
{
    PUSH();
    LLogging *log = LLogging::Instance();
    
    SET_LOGLEVEL( "--all-off --all-warning --user-info --fsm-warning --gen-info" );
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
  //  EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EX,       eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));
   // EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EX,       eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EXCEPTION,       eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EXCEPTION,       eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_INFO));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_INFO));

    POP();
}


TEST_F(TestLConfig, apply_get_level_logging_target)
{
    PUSH();
    LLogging *log = LLogging::Instance();
    SET_LOGLEVEL( "--all-off  --all-warning ");
    SET_LOGLEVEL( "--target-gui  --all-debug");

    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EXCEPTION,       eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_ERROR));
    
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
    
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_FILE),         PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EXCEPTION,       eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_STDOUT),       PAD(eLOGLEVEL::LOG_WARNING));

  // This test should pass
   // EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_DEBUG));
   
  // EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EX,       eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_ERROR));
    
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_DEBUG));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_DEBUG));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_GUI),          PAD(eLOGLEVEL::LOG_DEBUG));
    
    
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_NONE,     eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    //EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_EX,       eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_ERROR));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_USER,     eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_FSM,      eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    EXPECT_EQ((int64_t)log->GetLogLevel(  eMSGSYSTEM::SYS_GENERAL,  eMSGTARGET::TARGET_SUBSCRIBERS),  PAD(eLOGLEVEL::LOG_WARNING));
    

    POP();
}
