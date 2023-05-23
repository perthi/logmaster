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


#include "TestLHashMaps.h"


#include <utilities/GUtilities.h>
#include <logging/LHashMaps.h>
using namespace LOGMASTER;
#include <vector>
using std::vector;

TestLHashMaps::TestLHashMaps()
{
}


TestLHashMaps::~TestLHashMaps()
{
}


void 
TestLHashMaps::SetUp()
{
    //FORCE_DEBUG("HELLO");
}

void 
TestLHashMaps::TearDown()
{

}


TEST_F( TestLHashMaps, IsTargetHash )
{
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-off") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-subscriber") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-file") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-stdout") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-gui") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsTargetHash("--target-all") );
    EXPECT_FALSE( LHashMaps::Instance()->IsTargetHash( "--gibberish" ) );
    EXPECT_FALSE( LHashMaps::Instance()->IsTargetHash( "gibberish" ) );
}


TEST_F( TestLHashMaps, IsFormatHash )
{
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--all-off") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--msg-type") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--time-stamp") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--file-path") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--func-name") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--line-no") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--prefix-none") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--msg-body") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--short") );
    EXPECT_TRUE(  LHashMaps::Instance()->IsFormatHash("--prefix-all") );
    EXPECT_FALSE( LHashMaps::Instance()->IsFormatHash( "--gibberish" ) );
    EXPECT_FALSE( LHashMaps::Instance()->IsFormatHash( "gibberish" ) );
}





TEST_F(TestLHashMaps, contains_targes_enums )
{
    EXPECT_TRUE(true);

    vector<eMSGTARGET>  targets = LHashMaps::Instance()->GetTargetEnums();

    EXPECT_TRUE( g_utilities()->Contains( targets, eMSGTARGET::TARGET_FILE) );
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_STDOUT));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_SUBSCRIBERS));

    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_OFF));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_ALL));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_GUI));

    g_utilities()->FilterOut(targets, { eMSGTARGET::TARGET_OFF, eMSGTARGET::TARGET_ALL });


    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_FILE));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_STDOUT));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_SUBSCRIBERS));

    EXPECT_FALSE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_OFF));
    EXPECT_FALSE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_ALL));
    EXPECT_TRUE(g_utilities()->Contains(targets, eMSGTARGET::TARGET_GUI));

}


TEST_F(TestLHashMaps, contains_format_enums)
{
    EXPECT_TRUE(true);
    vector<eMSGFORMAT>  formats = LHashMaps::Instance()->GetFormatEnums();
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::PREFIX_OFF));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::MESSAGE_TYPE));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::TIME_STAMP));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::FILE_PATH));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::FILE_NAME));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::FUNCTION_NAME));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::LINE_NO));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::MESSAGE_BODY));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::SHORT_MSG));
    EXPECT_TRUE(g_utilities()->Contains(formats, eMSGFORMAT::PREFIX_ALL));

}




TEST_F(TestLHashMaps, contains_levle_enums)
{
    EXPECT_TRUE(true);
    vector<eLOGLEVEL>  levels = LHashMaps::Instance()->GetLevelEnums();
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_OFF));
 //   EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_FORCE_DEBUG));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_DEBUG));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_INFO));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_WARNING));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_ERROR));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_FATAL));
    EXPECT_TRUE(g_utilities()->Contains(levels, eLOGLEVEL::LOG_ALL));
    
}