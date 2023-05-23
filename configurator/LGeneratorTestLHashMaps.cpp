#include "LGeneratorTestLHashMaps.h"

namespace CONFIGURATOR
{
    LGeneratorTestLHashMaps::LGeneratorTestLHashMaps(const string path, const string classname, const LXMLInfo xmlinfo) :LGenerator(path, classname, xmlinfo)
    {
        fDoGenerateHeader = true;
        fDoGenerateSource = true;
    }

    void 
    LGeneratorTestLHashMaps::GenerateContent(const logentity_vec levels, const sysentity_vec systems)
    {
       

    }

}