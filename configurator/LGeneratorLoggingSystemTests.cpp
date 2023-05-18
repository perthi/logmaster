
#include "LGeneratorLoggingSystemTests.h"
#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>
#include <utilities/GNumbers.h>

#include <format>


using namespace LOGMASTER;


namespace CONFIGURATOR
{
    LGeneratorLoggingSystemTests::LGeneratorLoggingSystemTests(const string path, const string classname,  const LXMLInfo xmlinfo) : LGenerator(path, classname,  xmlinfo)
    {
    }





    void LGeneratorLoggingSystemTests::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
        PUSH();
        SET_LOGFORMAT("1000001");

        for (auto &l : levels)
        {
            FORCE_DEBUG("CLassname = %s", fClassName.c_str());
            // FORCE_DEBUG("fName = %s", l->fName.c_str() );
        }

        for (auto &s : systems)
        {
            /** @todo use defines, not hard coded numbers*/
           // string bin = g_numbers()->Number2BinaryString(s->fIndex, 24, 16 );
            string bin = g_numbers()->Number2BinaryString(1, 24, s->fIndex );


            auto single_test 
                = std::format(      "EXPECT:EQ({}::SYS_{}, LConversion::String2System(\"{}\") );\n", 
                                  fSystemEnumName,
                                    g_utilities()->TabAlign(s->fName, 2), 
                                   bin);

            cout << "fs = " << single_test;


            fFileContentSource.push_back(single_test);


        }

        POP();
    }
}