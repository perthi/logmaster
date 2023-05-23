#pragma once
#include "LGenerator.h"
#include "LGeneratorTestBase.h"

namespace CONFIGURATOR
{

    class LGeneratorTestLHashMaps : public LGeneratorTestBase, public LGenerator
    {
    public:
        LGeneratorTestLHashMaps(const string path, const string classname, const LXMLInfo xmlinfo);

        virtual void GenerateLocalCommon( );
        virtual void GenerateContent(const logentity_vec levels, const sysentity_vec systems) override;
    };

}
