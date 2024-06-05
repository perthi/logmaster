
#include "TestLFileInfo.h"
#include <configurator/LFileInfo.h>
#include <exception>

#include <filesystem>

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

TEST_F(TestLFileInfo, set_get_classname)
{ 
    fValid->SetClassName("AnotherClass");
    EXPECT_EQ(fValid->GetClassName(), "AnotherClass" );
    EXPECT_EQ(fValid->GetHeaderName( ), "AnotherClass.h");
    EXPECT_EQ(fValid->GetSourceName( ), "AnotherClass.cpp");
}



TEST_F(TestLFileInfo, source_files)
{
    EXPECT_EQ(fValid->GetHeaderName(), "MyClassName.h");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClassName.cpp");
}


TEST_F(TestLFileInfo, disable_suffix)
{
    fValid->DisableSuffixes( );
    EXPECT_EQ(fValid->GetHeaderName( ), "MyClassName");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClassName");
}



TEST_F(TestLFileInfo, enable_suffix)
{
    fValid->DisableSuffixes( );
    fValid->EnableSuffixes( );
    EXPECT_EQ(fValid->GetHeaderName( ), "MyClassName");
    EXPECT_EQ(fValid->GetSourceName( ), "MyClassName");
}


TEST_F(TestLFileInfo, wrong_classname_suffix)
{
    /// Class name should be given without any suffix, actually any suffixes are bad, but these
    /// are some of the most likely ones to occur.
    vector<string> bad_suffix = { ".cpp", ".cxx", ".h", ".hpp", ".txt", ".foo", ".bar" };

    for ( auto &b : bad_suffix )
    {
        string class_name = "MyClassName" + b;
        EXPECT_THROW(LFileInfo(fs::current_path( ).string( ), class_name), std::invalid_argument);
        EXPECT_THROW(fValid->SetClassName(class_name), std::invalid_argument);
    }

}


TEST_F(TestLFileInfo, wrong_classname_starts_with_number)
{
    vector<string> starts_with_number = { "0MyClass", "44MyClass", "9MyClass" };

    for ( auto& s : starts_with_number )
    {
        EXPECT_THROW(LFileInfo(fs::current_path( ).string( ), s), std::invalid_argument);
        EXPECT_THROW(fValid->SetClassName(s), std::invalid_argument);
    }
}


TEST_F(TestLFileInfo, wrong_classname_not_alphanumeric)
{
    vector<string> non_alpha = { "MyCl#ass", "MyC{lass", "My?Class" };

    for ( auto& s : non_alpha )
    {
        EXPECT_THROW(LFileInfo(fs::current_path( ).string( ), s), std::invalid_argument);
        EXPECT_THROW(fValid->SetClassName(s), std::invalid_argument);
    }
}


TEST_F(TestLFileInfo, wrong_classname_is_directory)
{
    EXPECT_THROW(fValid->SetClassName(fs::current_path( ).string( )), std::invalid_argument);

}

TEST_F(TestLFileInfo, ok_alpanumeric)
{

    EXPECT_NO_THROW(fValid->SetClassName("MyClass1234"));
    EXPECT_NO_THROW(fValid->SetClassName("My12345677Class1234"));

}