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


#include "TestGSystem.h"
#include <utilities/GSystem.h>
#include <utilities/GRandom.h>
#include <utilities/GFileIOHandler.h>
#include <utilities/GCommon.h>
#include <utilities/GLocation.h>


TestGSystem::TestGSystem()
{
}


TestGSystem::~TestGSystem()
{
}


void
TestGSystem::SetUpTestCase()
{
    GCommon().DisableOutput();
}


void
TestGSystem::TearDownTestCase()
{
    GCommon().EnableOutput();
}



TEST_F(TestGSystem, mkfile)
{
    try
    {
        EXPECT_FALSE(g_system()->rm("testdir2"));
        g_system()->mkfile("testdir2/testfile2.txt");

        EXPECT_TRUE(g_system()->rm("testdir2/testfile2.txt"));
        EXPECT_TRUE(g_system()->rm("testdir2", true));

        // g_system()->mkfile("bla1/bla2/testfile2.txt");
    }

#ifdef HAS_LOGGING
    catch (GException& e)
    {
        cerr << e.what() << endl;
        FAIL();
    }
#endif
    catch (std::exception& e)
    {
        GCommon().HandleError(e.what(), GLOCATION, DISABLE_EXCEPTION);
        FAIL();
    }
    catch (...)
    {
        GCommon().HandleError("Unknown exception caught", GLOCATION, DISABLE_EXCEPTION);
        FAIL();
    }
}


TEST_F(TestGSystem,  cp)
{
    string source = "source.txt";
    string dest = "dest.txt";
    g_system()->rm(source);
    g_system()->rm(dest);

    g_system()->mkfile(source);
    g_file()->Append(source,  "Lorem ipsum dolor sit amet");
    g_file()->Append(source,  "\nconsectetur adipiscing elit");
    g_system()->cp(source, dest);
    
    vector<string> content = g_file()->ReadAll(dest);
    EXPECT_EQ(2, content.size());



    if (content.size() == 2)
    {
        EXPECT_EQ("Lorem ipsum dolor sit amet",  content[0]);
        EXPECT_EQ("consectetur adipiscing elit", content[1]);
    }
    
    EXPECT_TRUE(g_file()->CheckFile(source));
    EXPECT_TRUE(g_file()->CheckFile(dest));

    g_system()->rm(source);
    g_system()->rm(dest);
}



TEST_F(TestGSystem, mv)
{
    string s = "source.txt";
    string d = "dest.txt";
    
    g_system()->rm(s);
    g_system()->rm(d);

    
    g_system()->mkfile(s);
    g_file()->Append(s, "Sed ut perspiciatis unde omnis iste natus error sit voluptatem");
    g_file()->Append(s, "\naccusantium doloremque laudantium, totam rem aperiam, eaque ipsa");

    
    
    vector<string> s_data = g_file()->ReadAll(s);

    g_system()->mv(s, d);

    
    vector<string> d_data = g_file()->ReadAll(d);
    
    
    EXPECT_EQ(s_data, d_data);
    EXPECT_FALSE( g_system()->exists(s) );
    EXPECT_TRUE( g_system()->exists(d));

    vector<string> content = g_file()->ReadAll(d);
    EXPECT_EQ(2, content.size());

    if (content.size() == 2)
    {
        EXPECT_EQ("Sed ut perspiciatis unde omnis iste natus error sit voluptatem", content[0]);
        EXPECT_EQ("accusantium doloremque laudantium, totam rem aperiam, eaque ipsa", content[1]);
    }

    EXPECT_FALSE(g_file()->CheckFile(s));
    EXPECT_TRUE(g_file()->CheckFile(d));
    g_system()->rm(d);
    
}

