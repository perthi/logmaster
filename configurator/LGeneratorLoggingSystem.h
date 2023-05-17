#pragma once
#include "LGenerator.h"



namespace CONFIGURATOR
{
    class LGeneratorLoggingSystem : public LGenerator
    {
    public:
        LGeneratorLoggingSystem (const string fname, const LXMLInfo xmlinfo);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
    };

}
