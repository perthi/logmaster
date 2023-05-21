#pragma once
#include "LGenerator.h"
#include "LGeneratorTestBase.h"


namespace CONFIGURATOR
{
    class LGeneratorTestLoggingSystem : public LGeneratorTestBase,  public LGenerator
    {
    public:
        LGeneratorTestLoggingSystem (const string path, const string classname, const LXMLInfo xmlinfo);
        virtual void GenerateContent(logentity_vec levels, sysentity_vec  systems) override;
        virtual void GenerateLocalCommon();
    private:
        void GenerateString2System(const logentity_vec levels, const sysentity_vec systems);
    };

}
