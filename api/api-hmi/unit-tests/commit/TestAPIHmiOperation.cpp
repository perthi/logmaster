// -*- mode: c++ -*-
/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
***************************************************/



#include "TestAPIHmiOperation.h"
#include <configuration/KFConfigurationHandler.h>
#include <configuration/KFEntityHMIOperation.h>
#include <api/api-hmi/APIHmiOperation.h>

#include <configuration/KFHMICaption.h>
#include <configuration/KFEntityHMIOperation.h>

#include <kf-main/KFGlobals.h>

TestAPIHmiOperation::TestAPIHmiOperation()
{

}


TestAPIHmiOperation::~TestAPIHmiOperation()
{

}



void
TestAPIHmiOperation::SetUp()
{
    auto cfg =  KFConfigurationHandler::Instance();
    cfg->ParseConfigDevices(  XMLFile_t("kf_config_unittest.xml" ), KFGlobals::Instance()->GetXSDFilenameDevices()   );
    cfg->ParseConfigHmi(  XMLFile_t("kf_hmi_unittest.xml"), KFGlobals::Instance()->GetXSDFilenameHmi()  );

    auto entity = cfg->GetByHMIType( GetParam() );
    ASSERT_NE(entity,  nullptr );
    op = std::dynamic_pointer_cast< KFEntityHMIOperation >(entity);
    ASSERT_NE(op,  nullptr );
    api = std::make_shared<APIHmiOperation>( GetParam() );
    EXPECT_EQ( api->GetTitle(), op->fTitle);
    op_api =  api->GetOperation();
}



void
TestAPIHmiOperation::TearDown()
{

}


INSTANTIATE_TEST_CASE_P(test_api, TestAPIHmiOperation , ::testing::Values(
    eHMI_TYPE::COATING, eHMI_TYPE::SURFACE_PREP, eHMI_TYPE::WRAPPING
));




void
TestAPIHmiOperation::Compare( std::shared_ptr<KFEntityHMIOperation> e1, std::shared_ptr<KFEntityHMIOperation> api )
{
    try
    {
        EXPECT_EQ( e1->fHMIID, api->fHMIID );
    ///    FORCE_DEBUG("hmiid1= %s,  hmiid2 = %s",  e1->fHMIID.c_str() , api->fHMIID.c_str()   );
        EXPECT_EQ( e1->fControls.size(), api->fControls.size() );
        EXPECT_EQ( e1->fIndicatorMain.fCanDecrement,  api->fIndicatorMain.fCanDecrement );
        EXPECT_EQ( e1->str(), api->str() );
        EXPECT_EQ( e1->fIndicatorMain.fCaption.fCaption, api->fIndicatorMain.fCaption.fCaption);
        EXPECT_EQ( e1->fIndicatorMain.fCaption.fCaptionMin, api->fIndicatorMain.fCaption.fCaptionMin);
        EXPECT_EQ( e1->fIndicatorMain.fCaption.fCaptionMax, api->fIndicatorMain.fCaption.fCaptionMax);
        EXPECT_EQ( e1->fIndicatorMain.fDeviceID,    api->fIndicatorMain.fDeviceID);
        EXPECT_EQ( e1->fIndicatorMain.fMaxValue,    api->fIndicatorMain.fMaxValue);
        EXPECT_EQ( e1->fIndicatorMain.fMinValue,    api->fIndicatorMain.fMinValue);
        EXPECT_EQ( (int)e1->fIndicatorMain.fOrientation, (int)api->fIndicatorMain.fOrientation);
        EXPECT_EQ( e1->fNavigatorMain.fDeviceID,    api->fNavigatorMain.fDeviceID);

        vector<int>  s1  =  api->fNavigatorMain.fSteps;
        vector<int>  s2  =  e1->fNavigatorMain.fSteps;

        ASSERT_EQ(s1.size(), s2.size() );

        for(size_t i=0; i < s1.size();  i++ )
        {
            EXPECT_EQ(s1[i], s2[i] );
        }

        EXPECT_EQ( (int)e1->fType, (int)api->fType);

        auto ctrl1 = e1->fControls;
        auto ctrl2 = api->fControls;

        ASSERT_EQ(ctrl1.size(), ctrl2.size() );

        for( size_t i=0; i < ctrl1.size(); i++ )
        {
            auto control1 = ctrl1.at(i);
        }
    }
    catch( GException &e )
    {
        CERR << e.what();
    }
    catch(std::exception &e )
    {
        CERR << e.what() << endl;
    }
    catch(...)
    {
        FORCE_DEBUG("unknown exception caught");
    }

}


TEST_P( TestAPIHmiOperation, operation )
{
    Compare(op, op_api);
}


TEST_P( TestAPIHmiOperation, set_xml )
{
    try
    {
        api->SetXMLConfiguration( "kf_config_unittest2.xml", "kf_hmi_unittest2.xml");
        std::this_thread::sleep_for( std::chrono::milliseconds( 400 ) );
        auto entity = KFConfigurationHandler::Instance()->GetByHMIType( GetParam() );
        ASSERT_NE(entity,  nullptr );
        op = std::dynamic_pointer_cast< KFEntityHMIOperation >(entity);
///        ASSERT_NE(op,  nullptr );
        op_api =  api->GetOperation();
        Compare(op, op_api);
        //api->SetXMLConfiguration( "kf_hmi_test", "kf_config_test" );
    }
    catch( GException &e )
    {
        CERR << e.what();
        FORCE_DEBUG("%s", e.what() );
    }
    catch( std::exception &e )
    {
        CERR << e.what();
        FORCE_DEBUG("%s", e.what() );
    }
    catch(...)
    {
        FORCE_DEBUG("unknow exception caught");
    }
}



/*
TEST_P( TestAPIHmiOperation, operation )
{
    auto cfg =  KFConfigurationHandler::Instance();
    auto entity = cfg->GetByHMIType( GetParam() );
    ASSERT_NE(entity,  nullptr );
    auto op = std::dynamic_pointer_cast< KFEntityHMIOperation >(entity);
    ASSERT_NE(op,  nullptr );
    std::shared_ptr< APIHmiOperation > api = std::make_shared<APIHmiOperation>( GetParam() );
    EXPECT_EQ( api->GetTitle(), op->fTitle);
    std::shared_ptr<KFEntityHMIOperation> op_api =  api->GetOperation();
    EXPECT_EQ( op->fHMIID, op_api->fHMIID );
    EXPECT_EQ( op->fControls.size(), op_api->fControls.size() );
    EXPECT_EQ( op_api->fIndicatorMain.fCanDecrement,  op->fIndicatorMain.fCanDecrement );

    EXPECT_EQ( op->str(), op_api->str() );

    EXPECT_EQ( op->fIndicatorMain.fCaption.fCaption, op->fIndicatorMain.fCaption.fCaption);
    EXPECT_EQ( op->fIndicatorMain.fCaption.fCaptionMin, op->fIndicatorMain.fCaption.fCaptionMin);
    EXPECT_EQ( op->fIndicatorMain.fCaption.fCaptionMax, op->fIndicatorMain.fCaption.fCaptionMax);
    EXPECT_EQ( op->fIndicatorMain.fDeviceID,    op_api->fIndicatorMain.fDeviceID);
    EXPECT_EQ( op->fIndicatorMain.fMaxValue,    op_api->fIndicatorMain.fMaxValue);
    EXPECT_EQ( op->fIndicatorMain.fMinValue,    op_api->fIndicatorMain.fMinValue);
    EXPECT_EQ( (int)op->fIndicatorMain.fOrientation, (int)op_api->fIndicatorMain.fOrientation);
    EXPECT_EQ( op->fNavigatorMain.fDeviceID,    op_api->fNavigatorMain.fDeviceID);

    vector<int>  s1  =  op_api->fNavigatorMain.fSteps;
    vector<int>  s2  =  op->fNavigatorMain.fSteps;

    ASSERT_EQ(s1.size(), s2.size() );

    for(size_t i=0; i < s1.size();  i++ )
    {
        EXPECT_EQ(s1[i], s2[i] );
    }

    EXPECT_EQ( (int)op->fType, (int)op_api->fType);

    auto ctrl1 = op->fControls;
    auto ctrl2 = op_api->fControls;

    ASSERT_EQ(ctrl1.size(), ctrl2.size() );

    for( size_t i=0; i < ctrl1.size(); i++ )
    {
        auto control1 = ctrl1.at(i);
    }

}
*/



