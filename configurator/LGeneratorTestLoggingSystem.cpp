

#include "LGeneratorTestLoggingSystem.h"
#include "LFileInfo.h"

#include "LXmlEntityLogLevel.h"
#include "LXmlEntitySubSystem.h"
#include "LGeneratorCommon.h"

#include <logging/LLogApi.h>
#include <utilities/GNumbers.h>
#include <utilities/GRandom.h>
#include <utilities/GString.h>


#include <format>


using namespace LOGMASTER;




namespace CONFIGURATOR
{
	LGeneratorTestLoggingSystem::LGeneratorTestLoggingSystem(const string path, const string classname, const LXMLInfo xmlinfo) : LGenerator(path, classname, xmlinfo)
	{
		fDoGenerateHeader = true;
		fDoGenerateSource = true;
	}


	void
		LGeneratorTestLoggingSystem::GenerateLocalCommon()
	{
		fFileContentHeader.push_back(commonTestHeader(fFileInfo->GetClassName()));
		fFileContentSource.push_back(std::format("#include \"{}\"", fFileInfo->GetHeaderName()));
		fFileContentSource.push_back("#include <logging/LConversion.h>");
		fFileContentSource.push_back("\n\n\n");
	}


	void LGeneratorTestLoggingSystem::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
	{
		GenerateLocalCommon();
		GenerateString2SystemBin(levels, systems);
		GenerateString2SystemHex(levels, systems);
		GenerateString2SystemHash(levels, systems);
		GenerateString2LevelBin(levels, systems);
		GenerateString2LevelHex(levels, systems);
        GenerateString2LevelHash(levels, systems);
	}


	auto bitstring24 = [](const int lvl_index, const int sys_index)
	{
		string system_s = std::format("{:016b}", 1 << sys_index);
		string level_s = std::format("{:08b}", 1 << lvl_index);
		string bit24_s = level_s + system_s;
		return bit24_s;
	};

	auto hexstring6 = [](const int lvl_index, const int sys_index)
	{
		string system_s = std::format("{:04x}", 1 << sys_index);
		string level_s = std::format("{:02x}", 1 << lvl_index);
		string hex6_s = "0x" +level_s + system_s;
		return hex6_s;
	};



    void
    LGeneratorTestLoggingSystem::GenerateString2SystemBin(const logentity_vec levels, const sysentity_vec systems)
    {
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;
            for ( auto& s : systems ) {
                for ( auto l : levels )
                {
                    string bitstring = bitstring24(l->fIndex, s->fIndex);

                    auto single_test
                        = std::format("EXPECT_EQ({}::SYS_{}, LConversion::{}(\"{}\") );",
                                      fSystemEnumName, g_utilities( )->TabAlign(s->fName, 2), funct_name, bitstring);

                    test_body.push_back(single_test);
                }
            }
            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };

        generate("String2System", "string2system");
        generate("BinaryString2System", "bin2system");
    }



	void
	LGeneratorTestLoggingSystem::GenerateString2SystemHex(const logentity_vec levels, const sysentity_vec systems)
	{
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;
            for ( auto& s : systems ) {
                for ( auto l : levels ) {
                    string hextring = hexstring6(l->fIndex, s->fIndex);

                    auto single_test = std::format("EXPECT_EQ({}::SYS_{}, LConversion::{}(\"{}\") );",
                                                   fSystemEnumName, 
                                                   g_utilities( )->TabAlign(s->fName, 2), funct_name,
                                                   hextring);
                    test_body.push_back(single_test);
                }
            }
            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };

        generate("String2System", "string2system_hex");
        generate("HexString2System", "hex2system");
    }



    void
    LGeneratorTestLoggingSystem::GenerateString2SystemHash(const logentity_vec levels, const sysentity_vec systems)
    {
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;

            auto generate_line = [=](const string& tag, const string& sys, const string& lvl)
            {
                auto single_test
                    = std::format("EXPECT_EQ({}::SYS_{}, LConversion::{}(\"{}-{}\") );",
                                  fSystemEnumName,
                                  g_utilities( )->TabAlign(sys, 2),
                                  funct_name,
                                  tag,
                                  g_string( )->ToLower(lvl));

                return single_test; };

            for ( auto& s : systems ) {
                for ( auto l : levels ) {
                    test_body.push_back(generate_line(s->fTag, s->fName, l->fName));

                    if ( s->fTag != s->fTagShort ) {
                        test_body.push_back(generate_line(s->fTagShort, s->fName, l->fName));
                    }
                }
            }
            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };

        generate("String2System","string2system_hash");
        generate("Hash2System", "hash2system");
    }


	void
	LGeneratorTestLoggingSystem::GenerateString2LevelBin(const logentity_vec levels, const sysentity_vec systems)
	{
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;
            for ( auto& s : systems ) {
                for ( auto l : levels ) {
                    string bitstring = bitstring24(l->fIndex, s->fIndex);

                    auto single_test
                        = std::format("EXPECT_EQ({}::LOG_{}, LConversion::{}(\"{}\") );",
                                      fLevelEnumName, g_utilities( )->TabAlign(l->fName, 2), funct_name, bitstring);
                    test_body.push_back(single_test);
                }
            }

            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };

        generate("String2Level", "string2level" );
        generate("BinaryString2Level", "bin2level");
    }


	void 
    LGeneratorTestLoggingSystem::GenerateString2LevelHex(const logentity_vec levels, const sysentity_vec systems)
    {
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;
            for ( auto& s : systems ) {
                for ( auto l : levels ) {
                    string hexstring = hexstring6(l->fIndex, s->fIndex);

                    auto single_test = std::format("EXPECT_EQ({}::LOG_{}, LConversion::{}(\"{}\") );",
                                                   fLevelEnumName, g_utilities( )->TabAlign(l->fName, 2), funct_name, hexstring);
                    test_body.push_back(single_test);
                }
            }
            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };

        generate("String2Level", "string2level_hex");
        generate("HexString2Level", "hex2level");
    }
        

	void
	LGeneratorTestLoggingSystem::GenerateString2LevelHash(const logentity_vec levels, const sysentity_vec systems)
	{
        auto generate = [=](const string funct_name, const string testname)
        {
            vector<string> test_body;

            auto generate_line = [=](const string& tag, const string& sys, const string& lvl)
            {
                auto single_test
                    = std::format("EXPECT_EQ(PAD({}::LOG_{}{} (int)LConversion::{}(\"{}-{}\") );",
                                  fLevelEnumName, lvl, g_utilities( )->TabAlign("),", 2), funct_name,  tag, g_string( )->ToLower(lvl));

                return single_test;
            };


            for ( auto& s : systems ) {
                for ( auto l : levels ) {
                    test_body.push_back(generate_line(s->fTag, s->fName, l->fName));

                    if ( s->fTag != s->fTagShort ) {
                        test_body.push_back(generate_line(s->fTagShort, s->fName, l->fName));
                    }
                }
            }
            fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), testname, test_body));
        };
		
        generate("String2Level", "string2levelhash");
        generate("Hash2Level", "has2level");
    }
}
