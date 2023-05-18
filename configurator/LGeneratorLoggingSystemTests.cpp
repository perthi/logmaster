
#include "LGeneratorLoggingSystemTests.h"
#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>
#include <utilities/GNumbers.h>


using namespace LOGMASTER;

namespace CONFIGURATOR
{
    LGeneratorLoggingSystemTests::LGeneratorLoggingSystemTests(const string fname, const LXMLInfo xmlinfo) : LGenerator(fname, xmlinfo)
    {
    }
    void LGeneratorLoggingSystemTests::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
        PUSH();
        SET_LOGFORMAT("1000001");

        for (auto &l : levels)
        {
           // FORCE_DEBUG("fName = %s", l->fName.c_str() );
        }

        for (auto &s : systems)
        {
            //FORCE_DEBUG("fName:%s fNameShort: %s  fTag:%s  fTagShort:%s",s->fName.c_str(), s->fNameShort.c_str(), 
            //    s->fTag.c_str(), s->fTagShort.c_str() );

            //FORCE_DEBUG("fIndex = %d\n\n", s->fIndex);
            
            /** @todo use defines, not hard coded numbers*/
           // string bin = g_numbers()->Number2BinaryString(s->fIndex, 24, 16 );
            string bin = g_numbers()->Number2BinaryString(1, 24, s->fIndex -1 );

            
            fSystemEnumName;
            
            string test = "EXPECT_EQ( " + fSystemEnumName + "::SYS_" + s->fName;
            test += "," + g_utilities()->TabAlign("LConversion::String2System");
            test += "(" +  string("\"")  + bin + "\"" + "));";

            FORCE_DEBUG("idx =%d\ttest = %s",  s->fIndex, test.c_str() );

        }

        POP();
    }
}