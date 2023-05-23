#pragma once
#include "LGenerator.h"


namespace CONFIGURATOR
{

class LGeneratorTestLHashMaps : public LGenerator
{
public:
    LGeneratorTestLHashMaps(const string path, const string classname, const LXMLInfo xmlinfo);
    virtual void GenerateContent(const logentity_vec levels, const sysentity_vec systems) override;
};

}
