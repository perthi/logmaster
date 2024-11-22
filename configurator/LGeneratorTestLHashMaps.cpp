
#include "LGeneratorTestLHashMaps.h"
#include "LXmlEntitySubSystem.h"
#include "LXmlEntityLogLevel.h"
#include "LFileInfo.h"
#include "LGeneratorCommon.h"

#include <utilities/GString.h>

#include <fmt/format.h>


namespace CONFIGURATOR
{
    LGeneratorTestLHashMaps::LGeneratorTestLHashMaps(const string path, const string classname, const LXMLInfo xmlinfo) :LGenerator(path, classname, xmlinfo)
    {
        fDoGenerateHeader = true;
        fDoGenerateSource = true;
    }

    void LGeneratorTestLHashMaps::GenerateLocalCommon( )
    {
        fFileContentHeader.push_back(commonTestHeader(fFileInfo->GetClassName( )));

        fFileContentSource.push_back("#include \"TestLHashMaps.h\"");
        fFileContentSource.push_back( fmt::format("#include \"{}\"", fFileInfo->GetHeaderName( )));
        fFileContentSource.push_back("#include <utilities/GUtilities.h>");

        fFileContentSource.push_back("#include <logging/LHashMaps.h>");
        fFileContentSource.push_back("using namespace LOGMASTER;");
        fFileContentSource.push_back("#include <vector>");
        fFileContentSource.push_back("using std::vector;");
        fFileContentSource.push_back("\n\n\n");
    }




    void 
    LGeneratorTestLHashMaps::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
        GenerateLocalCommon( );
        GenerateTestContainEnum(systems);
        GenerateIsSubcmdHash(levels, systems);
    }


    void
        LGeneratorTestLHashMaps::GenerateTestContainEnum(const sysentity_vec systems)
    {
        vector<string> test_body;
        test_body.push_back("vector<eMSGSYSTEM>  systems = LHashMaps::GetSystemEnums();");

        for ( auto s : systems )
        {
            string line = "";
            line = fmt::format("EXPECT_TRUE(g_utilities()->Contains(systems,{}::SYS_{}));", fSystemEnumName, s->fName);
            test_body.push_back(line);
        }

        fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), "contains_enums", test_body));
    }


    void
    LGeneratorTestLHashMaps::GenerateIsSubcmdHash(const logentity_vec levels, const sysentity_vec systems)
    {
        vector<string> test_body;
        
        for ( auto s : systems )
        {

            vector<string> tags;
            tags.push_back(s->fTag);
            if ( s->fTag != s->fTagShort ) {
                tags.push_back( s->fTagShort);
            }
            
            for ( auto tag : tags )
            {
                /** @todo make a function or lamda that creates  tag */
                for ( auto l : levels )
                {
                    string tmptag = tag + "-" + g_string( )->ToLower(l->fName);
                    string line = "";
                    line = fmt::format("EXPECT_TRUE(LHashMaps::IsSubCmdHash(\"{}\"));", tmptag);
                    test_body.push_back(line);
                }
            }

        }
        fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), "is_subcmd", test_body));
    }

}

