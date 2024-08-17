// -*- mode: c++ -*-

/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Sat 17 August-2024 02:36:27  ***/
/*** Generated from config/logging-ecostor.xml **/
/*** Validated by config/logging.xsd **/

/***************************************************
* @copyright Embedded Consulting AS    2024        *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

/********************************************************************************
*********************************************************************************
*** This file is part of logmaster.                                           ***
*** Copyright (C) 2024 Per Thomas Hille <pth@embc.no>  http:///www.embc.no    ***
*** all rights reserved                                                       ***
***                                                                           ***
*** logmaster is free software: you can redistribute it and/or modify         ***
*** it under the terms of the Lesser GNU General Public License (LGPL)        ***
*** as published by the Free Software Foundation, either version 3 of the     ***
*** License, or (at your option) any later version.                           ***
***                                                                           ***
*** logmaster is distributed in the hope that it will be useful,              ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of            ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             ***
*** GNU General Public License for more details.                              ***
***                                                                           ***
*** You should have received a copy of the Lesser GNU General Public          ***
*** License along with logmaster in the README file in the source code        ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                    ***
*********************************************************************************
*********************************************************************************/




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
        EXCEPTION_FORCE_DEBUG("This is a EXCEPTION_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        FSM_FATAL("This is a FSM_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_ERROR("This is a FSM_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_WARNING("This is a FSM_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_INFO("This is a FSM_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_DEBUG("This is a FSM_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        FSM_FORCE_DEBUG("This is a FSM_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        MESSAGE_FATAL("This is a MESSAGE_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_ERROR("This is a MESSAGE_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_WARNING("This is a MESSAGE_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_INFO("This is a MESSAGE_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_DEBUG("This is a MESSAGE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        MESSAGE_FORCE_DEBUG("This is a MESSAGE_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        EMS_FATAL("This is a EMS_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        EMS_ERROR("This is a EMS_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        EMS_WARNING("This is a EMS_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        EMS_INFO("This is a EMS_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        EMS_DEBUG("This is a EMS_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        EMS_FORCE_DEBUG("This is a EMS_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        MBMS_FATAL("This is a MBMS_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        MBMS_ERROR("This is a MBMS_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        MBMS_WARNING("This is a MBMS_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        MBMS_INFO("This is a MBMS_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        MBMS_DEBUG("This is a MBMS_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        MBMS_FORCE_DEBUG("This is a MBMS_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        BIU_FATAL("This is a BIU_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        BIU_ERROR("This is a BIU_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        BIU_WARNING("This is a BIU_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        BIU_INFO("This is a BIU_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        BIU_DEBUG("This is a BIU_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        BIU_FORCE_DEBUG("This is a BIU_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        RESTAPI_FATAL("This is a RESTAPI_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        RESTAPI_ERROR("This is a RESTAPI_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        RESTAPI_WARNING("This is a RESTAPI_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        RESTAPI_INFO("This is a RESTAPI_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        RESTAPI_DEBUG("This is a RESTAPI_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        RESTAPI_FORCE_DEBUG("This is a RESTAPI_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        XML_FATAL("This is a XML_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_ERROR("This is a XML_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_WARNING("This is a XML_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_INFO("This is a XML_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_DEBUG("This is a XML_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        XML_FORCE_DEBUG("This is a XML_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        DATABASE_FATAL("This is a DATABASE_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_ERROR("This is a DATABASE_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_WARNING("This is a DATABASE_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_INFO("This is a DATABASE_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_DEBUG("This is a DATABASE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        DATABASE_FORCE_DEBUG("This is a DATABASE_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        USER_FATAL("This is a USER_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_ERROR("This is a USER_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_WARNING("This is a USER_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_INFO("This is a USER_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_DEBUG("This is a USER_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        USER_FORCE_DEBUG("This is a USER_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        GENERAL_FATAL("This is a GENERAL_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_ERROR("This is a GENERAL_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_WARNING("This is a GENERAL_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_INFO("This is a GENERAL_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_DEBUG("This is a GENERAL_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        GENERAL_FORCE_DEBUG("This is a GENERAL_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );


        fval = g_random()->Uniform<float>(-10, 100);
        ival = g_random()->Uniform<int>(-10, 1000);
        ALARM_FATAL("This is a ALARM_FATAL  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_ERROR("This is a ALARM_ERROR  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_WARNING("This is a ALARM_WARNING  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_INFO("This is a ALARM_INFO  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_DEBUG("This is a ALARM_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
        ALARM_FORCE_DEBUG("This is a ALARM_FORCE_DEBUG  test message with parameter: ival = %d, fval = %f", ival, fval );
    cout << endl;
}
}
