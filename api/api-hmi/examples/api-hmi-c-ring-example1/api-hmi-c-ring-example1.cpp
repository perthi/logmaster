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


#include  <logging/LLogApi.h>
using namespace LOGMASTER;

#include <api/api-hmi/APIHmiOperation.h>
#include <api/api-hmi/APIHmiOperationWrapping.h>
#include <configuration/KFConfigurationHandler.h>

#include <memory>
#include <thread>
#include <chrono>


bool gDoRun = true;

void Run();

int 
main(int  /*argc*/, const char ** /*argv*/ )
{
    KFConfigurationHandler::Instance();
    std::thread th1 = std::thread( Run );
    th1.join();
    FORCE_DEBUG("Thread was joined");
    return 0;    
}



void Run()
{
    std::shared_ptr< APIHmiOperationWrapping > test = std::make_shared<  APIHmiOperationWrapping >();

    while ( gDoRun == true )
    { 
        try
        {
            string command = g_utilities()->QueryInput("type a command: ");

            if( command == "q" || command == "-q" )
            {
                gDoRun = false;
            }

            if( command == "s" || command == "-s" )
            {
                test->SetXMLConfiguration("kf_pth", "kf_hmi_pth"); 
                FORCE_DEBUG("Sent message ");
            }
        }
        catch( GException &e )
        {
            CERR << e.what()  << endl;
        }


    }
}