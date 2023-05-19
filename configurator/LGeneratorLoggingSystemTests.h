#pragma once
#include "LGenerator.h"



namespace CONFIGURATOR
{
    class LGeneratorLoggingSystemTests : public LGenerator
    {
    public:
        LGeneratorLoggingSystemTests (const string path, const string classname, const LXMLInfo xmlinfo, const bool add_suffix= true);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
    };

}
