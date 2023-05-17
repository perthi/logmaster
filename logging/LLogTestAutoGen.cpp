// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Wed 17 May-2023 16:54:35  ***/
/*** Generated from config\logging.xml **/
/*** Validated by config\logging.xsd **/

/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/
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




#include "LLogTestAutoGen.h"
#include "LLogApi.h"
#include <utilities/GRandom.h>
#include <utilities/GLocation.h>

#include <iostream>
using std::endl;
using std::cout;




 namespace LOGMASTER 
{
void
LLogTestAutoGen::WriteMessages()
{
    float fval = 0;
    int ival = 0;


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        EXCEPTION_FATAL("This is a EXCEPTION_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        EXCEPTION_ERROR("This is a EXCEPTION_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        EXCEPTION_WARNING("This is a EXCEPTION_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        EXCEPTION_INFO("This is a EXCEPTION_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        EXCEPTION_DEBUG("This is a EXCEPTION_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        FSM_FATAL("This is a FSM_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_ERROR("This is a FSM_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_WARNING("This is a FSM_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_INFO("This is a FSM_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_DEBUG("This is a FSM_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        MESSAGE_FATAL("This is a MESSAGE_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_ERROR("This is a MESSAGE_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_WARNING("This is a MESSAGE_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_INFO("This is a MESSAGE_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_DEBUG("This is a MESSAGE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        COM_FATAL("This is a COM_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        COM_ERROR("This is a COM_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        COM_WARNING("This is a COM_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        COM_INFO("This is a COM_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        COM_DEBUG("This is a COM_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        XML_FATAL("This is a XML_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_ERROR("This is a XML_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_WARNING("This is a XML_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_INFO("This is a XML_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_DEBUG("This is a XML_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        DATABASE_FATAL("This is a DATABASE_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_ERROR("This is a DATABASE_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_WARNING("This is a DATABASE_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_INFO("This is a DATABASE_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_DEBUG("This is a DATABASE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        USER_FATAL("This is a USER_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_ERROR("This is a USER_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_WARNING("This is a USER_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_INFO("This is a USER_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_DEBUG("This is a USER_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        GENERAL_FATAL("This is a GENERAL_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_ERROR("This is a GENERAL_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_WARNING("This is a GENERAL_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_INFO("This is a GENERAL_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_DEBUG("This is a GENERAL_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        ALARM_FATAL("This is a ALARM_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_ERROR("This is a ALARM_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_WARNING("This is a ALARM_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_INFO("This is a ALARM_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_DEBUG("This is a ALARM_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
    cout << endl;
}
}
