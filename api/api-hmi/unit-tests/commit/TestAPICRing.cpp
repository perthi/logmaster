
#include "TestAPICRing.h"

#include  <api/api-hmi/APIHmiCRing180.h>
#include  <api/api-hmi/APIHmiCRing360.h>
#include  <xml/GXmlDataTypes.h>

#include <configuration/KFConfigurationHandler.h>

KFConfigurationHandler  * TestAPICRing::cfg = nullptr;


void
TestAPICRing::SetUpTestCase()
{
	PUSH();
	SET_LOGTARGET("--target-off --target-file");
	cfg = KFConfigurationHandler::Instance();
	cfg->ParseConfigDevices( XMLFile_t("kf_config_unittest.xml") );
	cfg->ParseConfigHmi(XMLFile_t("kf_hmi_unittest.xml") );
	POP();
//	cfg->ParseDefaultConfig();
}


void
TestAPICRing::SetUp()
{
//	PUSH();
//	SET_LOGTARGET("--target-off --target-file");
//	SET_LOGLEVEL("--all-off --all-error");

}


void
TestAPICRing::TearDown()
{
//	POP();
}


TEST_F(TestAPICRing, title )
{
	try
	{
		auto c180 = std::make_shared<APIHmiCRing180>();
		EXPECT_EQ( c180->GetTitle(), "C-Ring 180");
		auto c360 = std::make_shared<APIHmiCRing360>();
		EXPECT_EQ( c360->GetTitle(), "C-Ring 360");

	}
	catch (GException& e)
	{
		cout << e.what() << endl;
		throw(e);
	}
}



TEST_F(TestAPICRing, steps )
{
	try
	{
		auto c180 = std::make_shared<APIHmiCRing180>();
		vector<int> steps = c180->GetStepsTranslation();
		ASSERT_EQ(steps.size(), 3);
		EXPECT_EQ(steps.at(0), 1 );
		EXPECT_EQ(steps.at(1), 2 );
		EXPECT_EQ(steps.at(2), 3);
		steps = c180->GetStepsRotation();
		ASSERT_EQ(steps.size(), 4);

		EXPECT_EQ(steps.at(0), 1  );
		EXPECT_EQ(steps.at(1), 30 );
		EXPECT_EQ(steps.at(2), 50 );
		EXPECT_EQ(steps.at(3), 70 );

		auto c360 = std::make_shared<APIHmiCRing360>();
		steps = c360->GetStepsTranslation();

		ASSERT_EQ(steps.size(), 3);
		EXPECT_EQ(steps.at(0), 1);
		EXPECT_EQ(steps.at(1), 100);
		EXPECT_EQ(steps.at(2), 200);

		steps = c360->GetStepsRotation();

		ASSERT_EQ(steps.size(), 7);
		EXPECT_EQ(steps.at(0), 1 );
		EXPECT_EQ(steps.at(1), 20 );
		EXPECT_EQ(steps.at(2), 3 );
		EXPECT_EQ(steps.at(3), 4);
		EXPECT_EQ(steps.at(4), 5);
		EXPECT_EQ(steps.at(5), 6);
		EXPECT_EQ(steps.at(6), 7);

	}
	catch (GException& e)
	{
		cout << e.what() << endl;
		throw(e);
	}
}


TEST_F(TestAPICRing, get_steppers)
{

//	PUSH();
//	SET_LOGTARGET("--target-stdout");
	auto c180 = std::make_shared<APIHmiCRing180>();
	auto c360 = std::make_shared<APIHmiCRing360>();
	EXPECT_NO_THROW( c180->GetStepperRotation() );
	EXPECT_NO_THROW( c360->GetStepperRotation() );

	EXPECT_NO_THROW( c180->GetStepperTranslation() );
	EXPECT_NO_THROW( c360->GetStepperTranslation() );

//	POP();
}
