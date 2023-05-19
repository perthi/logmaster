#include "TestLFileInfo.h"

#include <configurator/LFileInfo.h>
//#include <utilities/GSystem.h>
//#include <utilities/GFileIOHandler.h>
#include <format>

#include <filesystem>

#include <exception>

namespace fs = std::filesystem;

using namespace CONFIGURATOR;



void TestLFileInfo::SetUp( )
{
    fValid = std::make_shared<LFileInfo>(fs::current_path( ).string( ), "MyClassName") ;
}


TEST_F(TestLFileInfo, constructor)
{
    EXPECT_THROW(LFileInfo("gibberish/gibberish", "MyClassName"), std::invalid_argument );
    EXPECT_NO_THROW(LFileInfo(fs::current_path( ).string( ), "MyClassName"));
}


TEST_F(TestLFileInfo, class_names)
{
    EXPECT_EQ(fValid->GetClassName( ), "MyClassName");
}



TEST_F(TestLFileInfo, path_names)
{
    EXPECT_EQ(fValid->GetPath( ), fs::current_path( ).string( ));
}

/*
TEST_F(TestLFileInfo, source_files)
{
    EXPECT_EQ(fValid->GetHeaderName(), "MyClass.h");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClass.cpp");
}


TEST_F(TestLFileInfo, disable_suffix)
{
    fValid->DisableSuffixes( );
    EXPECT_EQ(fValid->GetHeaderName( ), "MyClass");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClass");
}



TEST_F(TestLFileInfo, enable_suffix)
{
    fValid->DisableSuffixes( );
    fValid->EnableSuffixes( );
    EXPECT_EQ(fValid->GetHeaderName( ), "MyClass");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClass");
}



TEST_F(TestLFileInfo, wrong_classname_format)
{
    /// Class name should be given without any suffix, actually any suffixes are bad, but these
    /// are some of the most likely ones to occur.
    vector<string> bad_suffix = { ".cpp", ".cxx", ".h", ".hpp", ".txt", ".foo", ".bar" };

    for ( auto b : bad_suffix )
    {
        string class_name = "MyClassName" + b;
        EXPECT_THROW(LFileInfo(fs::current_path( ).string( ), class_name), std::invalid_argument);
    }

}


TEST_F(TestLFileInfo, set_path )
{
    FAIL( );
}


TEST_F(TestLFileInfo, classname)
{
    FAIL( );
}

*/
