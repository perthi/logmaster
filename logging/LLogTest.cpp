// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
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


#include "LLogTest.h"
#include "LLogApi.h"
#include <utilities/GLocation.h>

#include <iostream>

using std::endl;
using std::cout;

using namespace LOGMASTER;



void LLogTest::WriteMessages()
{
   // cout << endl << endl;
    Header();
    int a = 40;
    int b = 2;

    G_DEBUG("This is a system wide general DEBUG message written if any of the sub systems are enabled");
    G_INFO("This is a system wide general INFO message written if any of the sub systems are enabled");
    G_WARNING("This is a system wide general(non system specific) WARNING message ");
    G_ERROR("This a system wide general ERROR message with parameters: a = %d, b = %d", a, b);
    G_FATAL("Oppps.... a system wide general (non system specific) fatal nessage");

	// ALL_DEBUG("This is a ALL_DEBUG message (applied if any of the subsystems are on)");
    // ALL_INFO("This is a system wide  ALL_INFO message (applied if any of the subsystems are on)");
    // ALL_WARNING("This is a system wide ALL_WARNING message (applied if any of the subsystems are on)");
    // ALL_ERROR("This a This is a system wide ALL_ERROR message (applied if any of the subsystems are on) with parameters: a = %d, b = %d", a, b);
    // ALL_FATAL("Oppps.... a system wide ALL_FATAL message");

    //   EX_DEBUG("This is a EX_DEBUG message");
    //  EX_INFO("This  is a EX_INFO  message");
    //    EX_WARNING("This is a EX_WARNING message");
    // EX_ERROR("This is a EX_ERROR message with parameters: a = %d, b = %d", a, b);
    // EX_FATAL("Oppps.... a  EX_FATAL message");

    USER_DEBUG("This is a USER_DEBUG message");
    USER_INFO("This  is a USER_INFO  message");
    USER_WARNING("This is a USER_WARNING message");
    USER_ERROR("This is a USER_ERROR message with parameters: a = %d, b = %d", a, b);
    USER_FATAL("Oppps.... a  USER_FATAL message");

    FSM_DEBUG("This is a FSM_DEBUG message");
    FSM_INFO("This  is a FSM_INFO  message");
    FSM_WARNING("This is a FSM_WARNING message");
    FSM_ERROR("This is a FSM_ERROR message with parameters: a = %d, b = %d", a, b);
    FSM_FATAL("Oppps.... a  FSM_FATAL message");
    
    FSM_DEBUG_U("This is a FSM_DEBUG and USER message");
    FSM_INFO_U("This  is a FSM_INFO and USER message");
    FSM_WARNING_U("This is a FSM_WARNING and USER message");
    FSM_ERROR_U("This is a FSM_ERROR USERmessage with parameters: a = %d, b = %d", a, b);
    FSM_FATAL("Oppps.... a  FSM_FATAL USER message");
    //   ALARM_DEBUG("Lorem ipsum dolor sit amet,");
    //  ALARM_INFO("consectetur adipiscing elit,");
    // ALARM_WARNING("sed do eiusmod tempor incididunt ut labore et dolore");
    // ALARM_ERROR("magna aliqua. Ut enim ad minim veniam, quis nostrud");
    // ALARM_FATAL("exercitation ullamco laboris nisi ut aliquip ex ea");

    COM_DEBUG(       "(COM)sed do eiusmod tempor incididunt ut labore et dolore");
    COM_WARNING(     "(COM)magna aliqua. Ut enim ad minim veniam, quis nostrud");
    COM_INFO(        "(COM)sed do eiusmod tempor incididunt ut labore et dolore");
    COM_ERROR(       "(COM)magna aliqua. Ut enim ad minim veniam, quis nostrud");
    COM_FATAL(       "(COM)exercitation ullamco laboris nisi ut aliquip ex ea");
    COM_DEBUG_U(     "(COM)sed do eiusmod tempor incididunt ut labore et dolore");
    COM_WARNING_U(   "(COM)magna aliqua. Ut enim ad minim veniam, quis nostrud");
    COM_INFO_U(      "(COM)sed do eiusmod tempor incididunt ut labore et dolore");
    COM_ERROR_U(     "(COM)magna aliqua. Ut enim ad minim veniam, quis nostrud");
    COM_FATAL_U(     "(COM)exercitation ullamco laboris nisi ut aliquip ex ea");

    Footer();
    cout << endl;

}



 void
LLogTest::test()
{

    USER_ERROR("This is at test");

}



void
LLogTest::Header()
{
	cout << "*********************************************" << endl;
	cout << "********** WRITING MESSAGES *****************" << endl;
	cout << "*********************************************" << endl;
}


void
LLogTest::Footer()
{
	cout << "*********************************************" << endl;
	cout << "************** DONE *************************" << endl;
	cout << "*********************************************" << endl;
}

