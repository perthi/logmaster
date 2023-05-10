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

// cmndlineexample1.cpp : Defines the entry point for the console application.

#ifdef _WIN32
#include <windows.h>
#endif


#include <logging/LMessage.h>
#include <logging/LMessageGenerator.h>
#include <logging/LLogging.h>
#include <utilities/GSystem.h>
#include <cmdline/GArgument.h>
#include <cmdline/GCommandLineArgument.h>
#include <cmdline/GLogApplication.h>
#include <utilities/GNumbers.h>
#include <utilities/GConstants.h>
#include <logging/GException.h>

#include <utilities/version-info/GMenu.h>


using namespace GCONSTANTS;
using namespace LOGMASTER;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <deque>
using std::deque;


bool 
callback_test1(const string cmd, const string, const vector<string> subs, const vector<string> pars)
{
    /// You can do additional checks here
    FORCE_DEBUG("cmd = %s, subs size = %d, + pars size = %d", cmd.c_str(),  subs.size(), pars.size() );
    return true;
}



bool 
callback_test2(const string cmd, const string, const vector<string> subs, const vector<string> pars)
{
    /// You can do additional checks ob the
    if( pars.size() !=2 && subs.size() != 0 )
    {   
        
    }
    FORCE_DEBUG("cmd = %s, subs size = %d, + pars size = %d", cmd.c_str(),  subs.size(), pars.size() );
    return true;
}

bool
bug(const string, const string args_s, const vector<string> sub, const vector<string> par);


int main(const int argc, const char** argv )
{ 
    GMenu::Instance()->ScanArguments(argc, argv);
    cerr << "The hostname is: " << g_system()->GetHostName() << endl;
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);

    try
    {
        SET_LOGFORMAT("1111111");
        SET_LOGTARGET("1111");

        int test1 = 0;
        int test2 = 0;
        //double test3 = 0;
        string test4 = "";
        vector<string> test5 = vector<string>();

        deque< std::shared_ptr<GArgument>  > arguments;


        std::shared_ptr<GArgument> a1 = std::make_shared <GCommandLineArgument< int> >("-myint1",
            "-myint1 [value]",
            "sets the value of  myint1",
            &test1, fgkOPTIONAL, callback_test1);


        /// Simlified version, no callback function, the argument is assumed to be optional
        std::shared_ptr<GArgument> a2 = std::make_shared <GCommandLineArgument< int> >("-mydouble",
            "-mydouble [value]",
            "sets the second value",
            &test2);

        /*
        std::shared_ptr<GArgument> a3  =  std::make_shared <GCommandLineArgument< double> >("-mydouble",
                                                        "-mydouble [value]",
                                                        "sets the value of mydouble",
                                                         &test3, fgkOPTIONAL,  callback_test2 );



        std::shared_ptr<GArgument> a4  =  std::make_shared <GCommandLineArgument< string> >("-mystring",
                                                        "-myval1 [value]",
                                                        "sets the second value",
                                                         &test4, fgkMANDATORY,  callback_test2 );
        */



        std::shared_ptr<GArgument> a5 = std::make_shared <GCommandLineArgument< vector<string> > >("-mystring",
            "-myval [value]",
            "sets the second value",
            &test5, fgkOPTIONAL, callback_test2);



        std::shared_ptr<GArgument> a6 = std::make_shared <GCommandLineArgument<void> >("-test",
            "-test [value]",
            "TEST",
            &test5, fgkOPTIONAL, bug);


        arguments.push_back(a1);
        arguments.push_back(a2);
        //  arguments.push_back(a3);
       //   arguments.push_back(a4);
        arguments.push_back(a5);
        arguments.push_back(a6);

        GLogApplication* g = new GLogApplication();
        
        
        g->ScanArguments(argc, argv, arguments);
      //  g->ScanArguments("-test", arguments);

        cout << "test1 = " << test1 << endl;

    }
    catch (GException& e)
    {
        CERR << e.what() << ENDL;
    }
    catch (std::exception & e)
    {
        CERR << e.what() << ENDL;
    }
    catch (...)
    {
        CERR << "Unknown exception caught" << ENDL;
    }


    return 0;
}




bool
bug(const string, const string /*args_s*/, const vector<string> sub, const vector<string> par)
{

    FORCE_DEBUG("Inside callback !!!!!!!, sub.size() = %d, par.size() = %d");
    G_ASSERT_EXCEPTION(sub.size() == 1, "Unexpected subcommand size\t%d, expected size =1 ", sub.size());
    G_ASSERT_EXCEPTION(par.size() == 0, "Unexpected parameter size\t%d, expected size =1 ", par.size());

    if (sub.size() == 1)
    {
        G_ASSERT_EXCEPTION((sub[0] == "--motor" || sub[0] == "--rgb"), "Invalid parameter %s, must be either --motor or --rgb");

        if (sub[0] == "--motor")
        {
            //bootloader->SetDeviceType(eMCU_DEVICETYPE::BOOTLOADER_MOTOR);
        }

        if (sub[0] == "--rgb")
        {
            //bootloader->SetDeviceType(eMCU_DEVICETYPE::BOOTLOADER_RGB);
        }

    }

    return false;
}
