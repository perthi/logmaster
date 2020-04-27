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
        SET_LOGTARGET("--target-stdout --target-file");
		FORCE_DEBUG("Writing some test messages");
		LLogTest::WriteMessages();
		/// turn off all loglevles for all subsystems
		/// Turning of Alrams and Exceptions will be vetoed by the system
					//| level|  subsystem	|
		///SET_LOGLEVEL("000000001111111111111111");		
		FORCE_DEBUG("Turning everything off");
		SET_LOGLEVEL("--off");
		LLogTest::WriteMessages(); // should see nothing
		double temperature = 99999.999;
		FORCE_DEBUG("Alarms are always writing, attempt to turn them off are vetoed by the system");
		ALARM_FATAL("Temperature reached %f degrees\n\n", temperature );

		FORCE_DEBUG("Forcing output to stdout, all settings ignored");
		FORCE_DEBUG("Setting  log level to debug for all subsystems");
		SET_LOGLEVEL("--debug");
		LLogTest::WriteMessages();
		
		
		/** Pushing an popping coinfigurations on/off the stack */
		PUSH();
		//FORCE_DEBUG(Setting);	
		SET_LOGLEVEL("--all-off --user-info");
		SET_LOGFORMAT("--short-user");
		//SET_LOGFORMAT("00000001");
		FORCE_DEBUG("Selceted only info messages form the FSM subsystem");
		LLogTest::WriteMessages();		
		//SET_LOGLEVEL("--all-debug");
		POP();
		FORCE_DEBUG("Popping back the previous configuration");
		LLogTest::WriteMessages();

	
		FSM_ASSERT_WARNING( true == false, "true and false are not equal"); 
		FSM_ASSERT_WARNING( true == true, "true and true are EQUAL"); //nothing writtns since the assertion is true 
	
		SET_LOGLEVEL("--fatal");
		FSM_ASSERT_WARNING( true == false, "true and false are not equal"); // nothing written because loglevel is fatal 
		FSM_ASSERT_ERROR( true == false, "true and false are not equal"); // nothing written because loglevel is fatal
		FSM_ASSERT_FATAL( true == false, "true and false are not equal"); // written beacause level is fatal, and assertion is false
		FSM_ASSERT_FATAL( true == true, "true and true are EQUAL"); // nothing written, assertion is true

		double temp_max = 125;
		// No exceotion, assertion is true.
		ALARM_ASSERT_EXCEPTION( temperature > temp_max, "Temperature too Low (%f) must be higher than %f",  temperature,  temp_max );
		
		// Exection thrown, assertion is false. loglevel is ignored for exceptions
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
