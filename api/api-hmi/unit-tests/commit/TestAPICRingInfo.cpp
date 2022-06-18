// -*- mode: c++ -*-
/**************************************************************************
 * This file is property of and copyright by Flekkefjord Elektro  2017   *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no> for the UHCW project.*
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                *
 **************************************************************************/
#include "TestAPICRingInfo.h"


#include <api/api-hmi/APICRingInfo.h>

TestAPICRingInfo::TestAPICRingInfo()
{

}

TestAPICRingInfo::~TestAPICRingInfo()
{

}


void
TestAPICRingInfo::SetUp()
{
    fInfo = new  APICRingInfo();
}


void
TestAPICRingInfo::TearDown()
{
    delete fInfo;
}



TEST_F(TestAPICRingInfo, add_translation_cring180 )
{
    APICRingInfo *info = new APICRingInfo();
    EXPECT_NEAR(info->GetXValueC180(  ), 0, 0.1 );
    info->AddTranslationC180( 2500 );
    EXPECT_NEAR(info->GetXValueC180(  ), 2500, 0.1 );
    info->AddTranslationC180( -3000);
    EXPECT_NEAR(info->GetXValueC180(  ), -500, 0.1 );
    delete info;
}


TEST_F(TestAPICRingInfo, add_translation_cring360 )
{
  
    EXPECT_NEAR( fInfo->GetXValueC360(  ), 0, 0.1 );
    fInfo->AddTranslationC360( 2500);
    EXPECT_NEAR( fInfo->GetXValueC360(  ), 2500, 0.1 );
    fInfo->AddTranslationC360( -3000);
    EXPECT_NEAR( fInfo->GetXValueC360(  ), -500, 0.1 );
  
}


TEST_F(TestAPICRingInfo, add_angle_cring180 )
{
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 0, 0.1 );
    fInfo->AddAngleC180(60);
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 60, 0.1 );
    EXPECT_NO_THROW(fInfo->AddAngleC180(300));
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 180, 0.1 );
    fInfo->AddAngleC180(100);
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 180, 0.1 );
    EXPECT_NO_THROW(fInfo->AddAngleC180(-400) );
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 0, 0.1 );
    EXPECT_NO_THROW(fInfo->AddAngleC180(-90) );
    EXPECT_NEAR( fInfo->GetAngleC180(  ), 0, 0.1 );
}




TEST_F(TestAPICRingInfo, add_angle_cring360 )
{
    EXPECT_NEAR( fInfo->GetAngleC360(  ), 0, 0.01 ); 
    EXPECT_NEAR( fInfo->GetNRotationsC360(), 0, 0.01); 
    fInfo->AddAngleC360(100);
    // angle = 100, n = 0
    
    EXPECT_NEAR( fInfo->GetAngleC360(  ), 100, 0.01 ); 
    EXPECT_NEAR( fInfo->GetNRotationsC360(), 0, 0.01);
   
    fInfo->AddAngleC360(-160);
    //angle = 300, n = -1 
    
    EXPECT_NEAR( fInfo->GetAngleC360(  ), 300, 0.01 ); 
    
    EXPECT_EQ( fInfo->GetNRotationsC360(), -1);

    fInfo->AddAngleC360(520);
    
    
    
    EXPECT_NEAR( fInfo->GetAngleC360(  ), 100, 0.01 ); 
    EXPECT_NEAR( fInfo->GetNRotationsC360(), 1, 0.01);

    
    fInfo->AddAngleC360(1450);
    EXPECT_NEAR( fInfo->GetAngleC360(  ), 110, 0.01 ); 
    EXPECT_NEAR( fInfo->GetNRotationsC360(), 5, 0.01);
    
}






