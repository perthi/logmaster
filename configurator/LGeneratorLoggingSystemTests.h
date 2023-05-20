#pragma once
#include "LGenerator.h"



namespace CONFIGURATOR
{
    class LGeneratorLoggingSystemTests : public LGenerator
    {
    public:
        LGeneratorLoggingSystemTests (const string path, const string classname, const LXMLInfo xmlinfo);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
    };

}
