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


#include "TestLConversion.h"

#include <logging/LEnums.h>
#include <logging/LConversion.h>
#include <logging/LHashMaps.h>

using namespace  LOGMASTER;

TestLConversion::TestLConversion()
{

}


TestLConversion::~TestLConversion()
{

}



TEST_F( TestLConversion, HexString2Target )
{
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,          LConversion::Instance()->HexString2Target("0x0")  );
    EXPECT_EQ( eMSGTARGET::TARGET_FILE,         LConversion::Instance()->HexString2Target( "0x1" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_STDOUT,       LConversion::Instance()->HexString2Target( "0x2" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_SUBSCRIBERS,  LConversion::Instance()->HexString2Target( "0x4" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_GUI,          LConversion::Instance()->HexString2Target( "0x8" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_ALL,          LConversion::Instance()->HexString2Target( "0xff" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,          LConversion::Instance()->HexString2Target("0x00")  );
    EXPECT_EQ( eMSGTARGET::TARGET_FILE,         LConversion::Instance()->HexString2Target( "0x01" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_STDOUT,       LConversion::Instance()->HexString2Target( "0x002" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_SUBSCRIBERS,  LConversion::Instance()->HexString2Target( "0x0004" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_GUI,          LConversion::Instance()->HexString2Target( "0x08" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_ALL,          LConversion::Instance()->HexString2Target( "0x0000ff" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,          LConversion::Instance()->HexString2Target( "gibberish")  );
    EXPECT_NE( eMSGTARGET::TARGET_FILE,         LConversion::Instance()->HexString2Target( "gibberish" ) );
    EXPECT_NE( eMSGTARGET::TARGET_STDOUT,       LConversion::Instance()->HexString2Target( "gibberish" ) );
    EXPECT_NE( eMSGTARGET::TARGET_SUBSCRIBERS,  LConversion::Instance()->HexString2Target( "gibberish" ) );
    EXPECT_NE( eMSGTARGET::TARGET_GUI,          LConversion::Instance()->HexString2Target( "gibberish" ) );
    EXPECT_NE( eMSGTARGET::TARGET_ALL,          LConversion::Instance()->HexString2Target( "gibberish" ) );
}



TEST_F( TestLConversion, HexString2Format )
{
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,        LConversion::Instance()->HexString2Format("0x00") );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_TYPE,        LConversion::Instance()->HexString2Format("0x40") );
    EXPECT_EQ( eMSGFORMAT::TIME_STAMP,            LConversion::Instance()->HexString2Format("0x20") );
    EXPECT_EQ( eMSGFORMAT::FILE_PATH,            LConversion::Instance()->HexString2Format("0x10") );
    EXPECT_EQ( eMSGFORMAT::FILE_NAME,            LConversion::Instance()->HexString2Format("0x08") );
    EXPECT_EQ( eMSGFORMAT::FUNCTION_NAME,        LConversion::Instance()->HexString2Format("0x04") );
    EXPECT_EQ( eMSGFORMAT::LINE_NO,                LConversion::Instance()->HexString2Format("0x02") );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY,        LConversion::Instance()->HexString2Format("0x01") );
    EXPECT_EQ( eMSGFORMAT::PREFIX_OFF,            LConversion::Instance()->HexString2Format("0x01") );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,            LConversion::Instance()->HexString2Format("0x4b") );
    EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,            LConversion::Instance()->HexString2Format("0x7f") );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,            LConversion::Instance()->HexString2Format("0x4B") );
    //EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,            LConversion::HexString2Format("0x7F") );

}



TEST_F(TestLConversion,  String2Format )
{
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,   LConversion::Instance()->String2Format( "0000000" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_TYPE,     LConversion::Instance()->String2Format( "1000000" ) );
    EXPECT_EQ( eMSGFORMAT::TIME_STAMP,       LConversion::Instance()->String2Format( "0100000" ) );
    EXPECT_EQ( eMSGFORMAT::FILE_PATH,        LConversion::Instance()->String2Format( "0010000" ) );
    EXPECT_EQ( eMSGFORMAT::FILE_NAME,        LConversion::Instance()->String2Format( "0001000" ) );
    EXPECT_EQ( eMSGFORMAT::FUNCTION_NAME,    LConversion::Instance()->String2Format( "0000100" ) );
    EXPECT_EQ( eMSGFORMAT::LINE_NO,          LConversion::Instance()->String2Format( "0000010" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY,     LConversion::Instance()->String2Format( "0000001" ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_OFF,       LConversion::Instance()->String2Format( "0000001" ) );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,        LConversion::Instance()->String2Format( "1001011" ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,       LConversion::Instance()->String2Format( "1111111" ) );

    EXPECT_EQ( (eMSGFORMAT::MESSAGE_TYPE | eMSGFORMAT::FILE_NAME), LConversion::Instance()->String2Format( "1001000" ) );

    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,   LConversion::Instance()->String2Format( "--all-off" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_TYPE,     LConversion::Instance()->String2Format( "--msg-type" ) );
    EXPECT_EQ( eMSGFORMAT::TIME_STAMP,       LConversion::Instance()->String2Format( "--time-stamp" ) );
    EXPECT_EQ( eMSGFORMAT::FILE_PATH,        LConversion::Instance()->String2Format( "--file-path" ) );
    EXPECT_EQ( eMSGFORMAT::FILE_NAME,        LConversion::Instance()->String2Format( "--file-name" ) );
    EXPECT_EQ( eMSGFORMAT::FUNCTION_NAME,    LConversion::Instance()->String2Format( "--func-name" ) );
    EXPECT_EQ( eMSGFORMAT::LINE_NO,          LConversion::Instance()->String2Format( "--line-no" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY,     LConversion::Instance()->String2Format( "--prefix-none" ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_OFF,       LConversion::Instance()->String2Format( "--msg-body" ) );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,        LConversion::Instance()->String2Format( "--short" ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,       LConversion::Instance()->String2Format( "--prefix-all" ) );
}




TEST_F(TestLConversion,  String2Target )
{
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,         LConversion::Instance()->String2Target( "--target-off" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_SUBSCRIBERS, LConversion::Instance()->String2Target( "--target-subscriber" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_FILE,        LConversion::Instance()->String2Target( "--target-file" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_STDOUT,      LConversion::Instance()->String2Target( "--target-stdout" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_GUI,         LConversion::Instance()->String2Target( "--target-gui" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_ALL,         LConversion::Instance()->String2Target( "--target-all" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,         LConversion::Instance()->String2Target( "0000" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_SUBSCRIBERS, LConversion::Instance()->String2Target( "0100" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_FILE,        LConversion::Instance()->String2Target( "0001" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_STDOUT,      LConversion::Instance()->String2Target( "0010" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_GUI,         LConversion::Instance()->String2Target( "1000" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_OFF,         LConversion::Instance()->String2Target( "0x0" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_SUBSCRIBERS, LConversion::Instance()->String2Target( "0x4" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_FILE,        LConversion::Instance()->String2Target( "0x1" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_STDOUT,      LConversion::Instance()->String2Target( "0x2" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_GUI,         LConversion::Instance()->String2Target( "0x8" ) );
    EXPECT_EQ( eMSGTARGET::TARGET_ALL,         LConversion::Instance()->String2Target( "0xff" ) );
}



TEST_F( TestLConversion, BinaryString2Format )
{
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,   LConversion::Instance()->BinaryString2Format( "0000000" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_TYPE,     LConversion::Instance()->BinaryString2Format( "1000000" ) );
    
    
    EXPECT_EQ( eMSGFORMAT::FILE_PATH,        LConversion::Instance()->BinaryString2Format( "0010000" ) );
    EXPECT_EQ( eMSGFORMAT::TIME_STAMP,       LConversion::Instance()->BinaryString2Format( "0100000" ) );
    
    
    EXPECT_EQ( eMSGFORMAT::FILE_NAME,        LConversion::Instance()->BinaryString2Format( "0001000" ) );
    EXPECT_EQ( eMSGFORMAT::FUNCTION_NAME,    LConversion::Instance()->BinaryString2Format( "0000100" ) );
    EXPECT_EQ( eMSGFORMAT::LINE_NO,          LConversion::Instance()->BinaryString2Format( "0000010" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY,     LConversion::Instance()->BinaryString2Format( "0000001" ) );
    
    EXPECT_EQ( eMSGFORMAT::PREFIX_OFF,       LConversion::Instance()->BinaryString2Format( "0000001" ) );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,        LConversion::Instance()->BinaryString2Format( "1001011" ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,       LConversion::Instance()->BinaryString2Format( "1111111" ) );
    
}



TEST_F( TestLConversion, Hash2Format )
{
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,    LConversion::Instance()->Hash2Format( "--all-off" ) );
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,    LConversion::Instance()->Hash2Format( "--off" ) );
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF,    LConversion::Instance()->Hash2Format( "--none" ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_TYPE,      LConversion::Instance()->Hash2Format( "--msg-type" ) );
    EXPECT_EQ( eMSGFORMAT::TIME_STAMP,        LConversion::Instance()->Hash2Format( "--time-stamp"  ) );
    EXPECT_EQ( eMSGFORMAT::FILE_PATH,         LConversion::Instance()->Hash2Format( "--file-path"  ) );
    EXPECT_EQ( eMSGFORMAT::FILE_NAME,         LConversion::Instance()->Hash2Format( "--file-name"  ) );
    EXPECT_EQ( eMSGFORMAT::FUNCTION_NAME,     LConversion::Instance()->Hash2Format( "--func-name"  ) );
    EXPECT_EQ( eMSGFORMAT::LINE_NO,           LConversion::Instance()->Hash2Format( "--line-no"  ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_OFF,        LConversion::Instance()->Hash2Format( "--prefix-none"  ) );
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY,      LConversion::Instance()->Hash2Format( "--prefix-none"  ) );
    EXPECT_EQ( eMSGFORMAT::SHORT_MSG,         LConversion::Instance()->Hash2Format( "--short"  ) );
    EXPECT_EQ( eMSGFORMAT::PREFIX_ALL,        LConversion::Instance()->Hash2Format( "--prefix-all"  ) );
}
