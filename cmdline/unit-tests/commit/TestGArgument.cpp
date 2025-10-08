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


#include "TestGArgument.h"


TestGArgument::TestGArgument() : TestBase()
{

}

bool 
callback_test1(const string /*cmd*/, const string, const vector<string> /*subs*/, const vector<string> /*pars*/ )
{
    return true;
}



bool 
callback_test2(const string /*cmd*/, const string, const vector<string> /*subs*/, const vector<string> /*pars*/)
{
    return false;
}


TEST_F(TestGArgument, set_get )
{
    GArgument arg;
    arg.SetNTabs(3);

    EXPECT_FALSE(arg.IsMandatory());
    EXPECT_TRUE(arg.IsOptional());
    arg.SetMandatory();
    EXPECT_TRUE(arg.IsMandatory());
    EXPECT_FALSE(arg.IsOptional());
    EXPECT_EQ(arg.GetHelpText(), "NOT SET");
    arg.SetHelpText("a help text");
    EXPECT_EQ(arg.GetHelpText(), "a help text");
    EXPECT_EQ(arg.GetUsage(), "NOT SET");
    arg.SetUsage("lorem ipsum");
    EXPECT_EQ(arg.GetUsage(), "lorem ipsum");
    
    EXPECT_EQ(arg.GetCommand(), "Unknown");
    
    arg.SetCommand("-command");

    EXPECT_EQ(arg.GetCommand(), "-command" );
    vector<string> cmds = arg.GetSubCommands();
    EXPECT_EQ(cmds.size(), 0);
    EXPECT_EQ(arg.GetSubCommandsS(), "");

    arg.AddSubCommand("--sub1");
    arg.AddSubCommand("--sub2");
    
    cmds = arg.GetSubCommands();
    ASSERT_EQ(cmds.size(), 2);

    EXPECT_EQ(cmds[0], "--sub1");
    EXPECT_EQ(cmds[1], "--sub2");
    EXPECT_EQ(arg.GetSubCommandsS(), "--sub1 --sub2");
   
    // EXPECT_EQ(arg.str(), "-command");
    // EXPECT_EQ(arg.str(true), "-command --sub1 --sub2");

    arg.str();
    (arg.str(true));

    //g.SetCommand("");
}


TEST_F(TestGArgument, set_exe_name )
{
    GArgument arg;
    EXPECT_ANY_THROW(arg.SetExcecName(nullptr) );
    EXPECT_NO_THROW(arg.SetExcecName("name") );
}


TEST_F(TestGArgument, verify_validation_function_static )
{
    int test1;
    double test2;

    std::shared_ptr<GArgument> a1 = std::make_shared <GCommandLineArgument< int> >("-myint1", "-myint1 [value]","sets the value of  myint1", &test1, fgkOPTIONAL, callback_test1);
    std::shared_ptr<GArgument> a2 = std::make_shared <GCommandLineArgument< double> >("-myint1", "-myint1 [value]","sets the value of  myint1", &test2, fgkOPTIONAL, callback_test2);
    std::shared_ptr<GArgument> a3 = std::make_shared <GCommandLineArgument< double> >("-mydouble","-mydouble [value]","sets the second value",&test2, fgkOPTIONAL, nullptr);

    EXPECT_TRUE(a1->Verify());
    EXPECT_FALSE(a2->Verify());
    EXPECT_FALSE(a3->Verify());
}


/*
TEST_F(TestGArgument, verify_validation_function_member )
{

}
*/