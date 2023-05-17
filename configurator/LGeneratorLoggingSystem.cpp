#include "LGeneratorLoggingSystem.h"
#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>

using namespace LOGMASTER;

namespace CONFIGURATOR
{
    LGeneratorLoggingSystem::LGeneratorLoggingSystem(const string fname, const LXMLInfo xmlinfo) : LGenerator(fname, xmlinfo)
    {
    }
    void LGeneratorLoggingSystem::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
        PUSH();
        SET_LOGFORMAT("1000001");

        for (auto l : levels)
        {
            FORCE_DEBUG("fName = %s", l->fName.c_str() );
        }

        for (auto s : systems)
        {
            FORCE_DEBUG("fName:%s fNameShort: %s  fTag:%s  fTagShort:%s",s->fName.c_str(), s->fNameShort.c_str(), 
                s->fTag.c_str(), s->fTagShort.c_str() );

            FORCE_DEBUG("fIndex = %d\n\n", s->fIndex);
        }

        POP();
    }
}