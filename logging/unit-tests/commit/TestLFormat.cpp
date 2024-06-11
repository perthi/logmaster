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



#include "TestLFormat.h"
#include <logging/LEnums.h>
#include <logging/LLogApi.h>
#include <logging/LPublisher.h>
#include <logging/GException.h>


using namespace LOGMASTER;


TestLFormat::TestLFormat()
{
    
}




TestLFormat::~TestLFormat()
{

}


/*
TEST_F( TestLFormat, msg_format )
{
    PUSH();
    LPublisher::Instance()->SetMode( ePUBLISH_MODE::SYNCHRONOUS );
    int s1 = 0;
    int s2 = 1;
    SET_LOGLEVEL("--all-off --com-warning");
    EXPECT_ANY_THROW( COM_DEBUG("s1 = %d", s1, s2) );
    EXPECT_ANY_THROW(  COM_ERROR("s1 = %d, s2 = %d, s3 = %d", s1, s2));
    EXPECT_ANY_THROW(  COM_ERROR("s1 = %d", s1, s2));
    EXPECT_ANY_THROW(  COM_INFO("s1 = %d, s2 = %d, s3 = %d", s1, s2));
    EXPECT_ANY_THROW(  COM_INFO("s1 = %d", s1, s2));
    
    LLogging::Instance()->SetFormatCheckAll(false);
    EXPECT_ANY_THROW(  COM_ERROR("s1 = %d, s2 = %d, s3 = %d", s1, s2));
    EXPECT_ANY_THROW(  COM_ERROR("s1 = %d", s1, s2) );

    EXPECT_NO_THROW(  COM_INFO("s1 = %d, s2 = %d, s3 = %d", s1, s2) );
    EXPECT_NO_THROW(  COM_INFO("s1 = %d", s1, s2)  );
    

    POP();

}
*/


/** @todo These tests should be auto generated  */
/*
TEST_F( TestLFormat, targets )
{
/// auto l = LLogging::Instance();
    SET_LOGFORMAT("--target-file 0000001");
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );
    SET_LOGFORMAT("--target-file 0000000");
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

    SET_LOGFORMAT("--target-file --short-user");
    EXPECT_EQ( eMSGFORMAT::USER_SHORT_MSG, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

//  SET_LOGFORMAT("--target-file  --all-off --msg-body --time-short");
//  EXPECT_EQ(  (eMSGFORMAT::MESSAGE_BODY | eMSGFORMAT::TIME_STAMP_SHORT), l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

//    SET_LOGFORMAT("--target-file  --all-off --msg-body --time-short");
//    EXPECT_EQ(  eMSGFORMAT::USER_SHORT_MSG, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

 //   SET_LOGFORMAT("--target-file  --all-off --msg-body --line-no --func-name --file-name --file-path --time-stamp --msg-type --time-short");
      SET_LOGFORMAT("--target-file  --all-off --msg-body --line-no --func-name --file-name --file-path --time-stamp --msg-type");
 //   EXPECT_EQ(  eMSGFORMAT::PREFIX_ALL, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

    SET_LOGFORMAT("--target-file  --all-off --file-name");
    EXPECT_EQ(  eMSGFORMAT::FILE_NAME, l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

    SET_LOGFORMAT("--target-file  --msg-body");
    EXPECT_EQ(  (eMSGFORMAT::FILE_NAME  | eMSGFORMAT::MESSAGE_BODY) , l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );

//    SET_LOGFORMAT("--target-file  --all-off --time-short");
//    EXPECT_EQ(  eMSGFORMAT::TIME_STAMP_SHORT , l->GetLogFormat( eMSGTARGET::TARGET_FILE ) );


    SET_LOGFORMAT("--target-gui 0000001");
    EXPECT_EQ( eMSGFORMAT::MESSAGE_BODY, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );
    
    SET_LOGFORMAT("--target-gui 0000000");
    EXPECT_EQ( eMSGFORMAT::ALL_FIELDS_OFF, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

    SET_LOGFORMAT("--target-gui --short-user");
    EXPECT_EQ( eMSGFORMAT::USER_SHORT_MSG, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

//    SET_LOGFORMAT("--target-gui  --all-off --msg-body --time-short");
//    EXPECT_EQ(  (eMSGFORMAT::MESSAGE_BODY | eMSGFORMAT::TIME_STAMP_SHORT), l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

    //SET_LOGFORMAT("--target-gui  --all-off --msg-body --time-short");
    SET_LOGFORMAT("--target-gui  --all-off --msg-body --time-stamp");
    
   // CERR << "USER SHORT = " <<  (int)eMSGFORMAT::USER_SHORT_MSG << endl;
   // CERR << "GUI  = " <<  (int)l->GetLogFormat( eMSGTARGET::TARGET_GUI  ) << endl;;


    EXPECT_EQ(  eMSGFORMAT::USER_SHORT_MSG, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

//    SET_LOGFORMAT("--target-gui  --all-off --msg-body --line-no --func-name --file-name --file-path --time-stamp --msg-type --time-short");
    SET_LOGFORMAT("--target-gui  --all-off --msg-body --line-no --func-name --file-name --file-path --time-stamp --msg-type");
    EXPECT_EQ(  eMSGFORMAT::PREFIX_ALL, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

    SET_LOGFORMAT("--target-gui  --all-off --file-name");
    EXPECT_EQ(  eMSGFORMAT::FILE_NAME, l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

    SET_LOGFORMAT("--target-gui  --msg-body");
    EXPECT_EQ(  (eMSGFORMAT::FILE_NAME  | eMSGFORMAT::MESSAGE_BODY) , l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

    // SET_LOGFORMAT("--target-gui  --all-off --time-short");
    // EXPECT_EQ(  eMSGFORMAT::TIME_STAMP_SHORT , l->GetLogFormat( eMSGTARGET::TARGET_GUI ) );

}
*/