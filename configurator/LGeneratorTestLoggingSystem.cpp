

#include "LGeneratorTestLoggingSystem.h"
#include "LFileInfo.h"

#include "LXmlEntityLogLevel.h"
#include "LXmlEntitySubSystem.h"
#include "LGeneratorCommon.h"

#include <logging/LLogApi.h>
#include <utilities/GNumbers.h>
#include <utilities/GRandom.h>


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
        LGeneratorTestLoggingSystem::GenerateLocalCommon( )
    {
        fFileContentHeader.push_back(commonTestHeader(fFileInfo->GetClassName( )));
        fFileContentSource.push_back(std::format("#include \"{}\"", fFileInfo->GetHeaderName( )));
        fFileContentSource.push_back("#include <logging/LConversion.h>");
        fFileContentSource.push_back("\n\n\n");
    }


    void LGeneratorTestLoggingSystem::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
        GenerateLocalCommon( );
        GenerateString2System(levels, systems);
    }


    void
        LGeneratorTestLoggingSystem::GenerateString2System(const logentity_vec levels, const sysentity_vec systems)
    {
       
        vector<string> test_body;

        for ( auto& s : systems )
        {
            /** @todo use defines, not hard coded numbers*/
            for (auto l: levels)
            {
                string system_s = std::format("{:016b}", 1 << s->fIndex);
                string level_s = std::format("{:08b}", 1 << l->fIndex);
                string bitstring24_s = level_s + system_s;

                auto single_test
                    = std::format("EXPECT_EQ({}::SYS_{}, LConversion::String2System(\"{}\") );",
                                  fSystemEnumName,
                                  g_utilities( )->TabAlign(s->fName, 2),
                                  bitstring24_s);

                test_body.push_back(single_test);
            }

        }


        fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), "string2system", test_body));

    }
}