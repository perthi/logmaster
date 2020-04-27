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

//#include <version-info/GMenu.h>
///#include <boost/regex.hpp>

#define G_STANDALONE

#include  <iostream>
#include  <logging/LLogging.h>
#include  <logging/LLogTest.h>
#include  <logging/LMessage.h>
#include  <logging/LConfig.h>
#include  <cmdline/GLogApplication.h>
#include  <exception/GException.h>


using std::cout;
using std::endl;
using namespace LOGMASTER;


#include <map>


int
main(int  /*argc*/, const char ** /*argv*/ )
{



	try
	{
		SET_LOGLEVEL("--off --all-debug");
        SET_LOGTARGET("1111");
		SET_LOGFORMAT("11111111");
		FORCE_DEBUG("Tis is a test");
		LLogTest::WriteMessages();
		/// turn off all loglevles for all subsystems
		/// Turning of Alrams and Exceptions will be vetoed by the system
					//| level|  subsystem	|
		SET_LOGLEVEL("000000001111111111111111");		
		LLogTest::WriteMessages(); // should see nothing

		SET_LOGLEVEL("--off");
		FORCE_DEBUG("Forcing output to stdout, all settings ignored");
		
		FORCE_DEBUG("TP0");
		LLogTest::WriteMessages();
		SET_LOGLEVEL("--all-debug");
		FORCE_DEBUG("TP1");
		LLogTest::WriteMessages();

		auto ptr = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT ).get();
		auto ptr2 = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT );
		FORCE_DEBUG("1ptr_raw   = 0x%x", ptr);
		FORCE_DEBUG("1ptr2_shrd = 0x%x", ptr2);
		PUSH();
		ptr = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT ).get() ;
		ptr2 = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT ) ;
		FORCE_DEBUG("2ptr_raw   = 0x%x", ptr);
		FORCE_DEBUG("2ptr2_shrd = 0x%x", ptr2 );

		SET_LOGLEVEL("--all-off --fsm-info");
		SET_LOGFORMAT("00000001");
		FORCE_DEBUG("Selceted only info messages form the FSM subsystem");
		LLogTest::WriteMessages();		
		//SET_LOGLEVEL("--all-debug");

		POP();
		ptr = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT ).get() ;
		ptr2 = LLogging::Instance()->GetConfig(  eMSGTARGET::TARGET_STDOUT ) ;
		FORCE_DEBUG("3ptr_raw  =  0x%x", ptr);
		FORCE_DEBUG("3ptr2_shrd = 0x%x", ptr2 );


	//	POP();
		//	SET_LOGLEVEL("--all-debug");
		FORCE_DEBUG("TP2");
		LLogTest::WriteMessages();


	}
	catch (GException &e)
	{
		cout << "exception caucht:" << e.what() << endl;
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
