// -*- mode: c++ -*-
#ifndef TESTAPIHMIOPERATION_H
#define TESTAPIHMIOPERATION_H
/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
***************************************************/


#include <protocol/KFProtocolEnums.h>
#include <testlib/TestBase.h>

#include <memory>

struct KFEntityHMIOperation;
class APIHmiOperation;

class  TestAPIHmiOperation : public ::testing::WithParamInterface< eHMI_TYPE >, public  TestBase
{
	public:
		TestAPIHmiOperation();
		virtual ~TestAPIHmiOperation();

	protected:	
	///	static  void    SetUpTestCase();
		virtual void SetUp() override;
		virtual void TearDown() override;
		void Compare( std::shared_ptr<KFEntityHMIOperation> e1, std::shared_ptr<KFEntityHMIOperation> e2 );
		std::shared_ptr<KFEntityHMIOperation> op  = nullptr; 
		std::shared_ptr<  KFEntityHMIOperation > op_api = nullptr;
		std::shared_ptr< APIHmiOperation > api;
};


#endif

