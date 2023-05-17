#pragma once
#include "LGenerator.h"



namespace CONFIGURATOR
{
    class LGeneratorLoggingSystemTests : public LGenerator
    {
    public:
        LGeneratorLoggingSystemTests (const string fname, const LXMLInfo xmlinfo);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
    };

}
