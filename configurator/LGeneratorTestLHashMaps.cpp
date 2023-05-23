
#include "LGeneratorTestLHashMaps.h"
#include "LXmlEntitySubSystem.h"
#include "LXmlEntityLogLevel.h"
#include "LFileInfo.h"
#include "LGeneratorCommon.h"

#include <format>

using std::format;

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
        fFileContentSource.push_back( format("#include \"{}\"", fFileInfo->GetHeaderName( )));
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
       
        
        vector<string> test_body;

        test_body.push_back("vector<eMSGSYSTEM>  systems = LHashMaps::GetSystemEnums();");

        for ( auto s : systems )
        {

            string line = "";
            //fSystemEnumName
            
            line = format( "EXPECT_TRUE(g_utilities()->Contains(systems,{}::SYS_{}));", fSystemEnumName, s->fName );
            //fFileContentSource.push_back(line);
            test_body.push_back(line);

        }


       fFileContentSource.push_back(GenerateTesCase(fFileInfo->GetClassName( ), "IsSubCmdhash", test_body));
    }

}


// vector<eMSGSYSTEM>  systems = LHashMaps::GetSystemEnums( );
//     EXPECT_TRUE(g_utilities()->Contains(systems, eMSGSYSTEM::SYS_NONE));
//     EXPECT_TRUE(g_utilities()->Contains(systems, eMSGSYSTEM::SYS_ANALYSIS));
//     EXPECT_TRUE(g_utilities()->Contains(systems, eMSGSYSTEM::SYS_DATA));
//     EXPECT_TRUE(g_utilities()->Contains(systems, eMSGSYSTEM::SYS_EX));