

#include "LGeneratorTestLoggingSystem.h"
#include "LFileInfo.h"

#include "LXmlEntityLogLevel.h"
#include "LXmlEntitySubSystem.h"
#include "LGeneratorCommon.h"

#include <logging/LLogApi.h>
#include <utilities/GNumbers.h>



#include <format>


using namespace LOGMASTER;


namespace CONFIGURATOR
{
    LGeneratorTestLoggingSystem::LGeneratorTestLoggingSystem(const string path, const string classname,  const LXMLInfo xmlinfo) : LGenerator(path, classname,  xmlinfo)
    {
        fDoGenerateHeader = true;
        fDoGenerateSource = true;
    }





    void LGeneratorTestLoggingSystem::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
       // PUSH();
       // SET_LOGFORMAT("1000001");

        string classname = fFileInfo->GetClassName( );

        for (auto &l : levels)
        {
            FORCE_DEBUG("CLassname = %s", classname.c_str() );
            // FORCE_DEBUG("fName = %s", l->fName.c_str() );
        }

        fFileContentHeader.push_back(commonTestHeader(classname));

       

       // fFileContentSource.push_back("#include  <testlib/TestBase>");
        fFileContentSource.push_back(std::format("#include \"{}\"", fFileInfo->GetHeaderName()));
        fFileContentSource.push_back("#include <logging/LConversion.h>");
        fFileContentSource.push_back("\n\n\n");

        vector<string> test_body;
     

        for (auto &s : systems)
        {
            /** @todo use defines, not hard coded numbers*/
           // string bin = g_numbers()->Number2BinaryString(s->fIndex, 24, 16 );
            string bin = g_numbers()->Number2BinaryString(1, 24, s->fIndex );


            auto single_test 
                = std::format(      "EXPECT_EQ({}::SYS_{}, LConversion::String2System(\"{}\") );", 
                                  fSystemEnumName,
                                    g_utilities()->TabAlign(s->fName, 2), 
                                   bin);

//            cout << "fs = " << single_test;

            test_body.push_back(single_test);


        }

       /// GenerateTesCase(fFileInfo->GetClassName( ), "string3level", test_body);

        
        fFileContentSource.push_back(GenerateTesCase(classname, "string3level", test_body));

       // POP();

    }
}