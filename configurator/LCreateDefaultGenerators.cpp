

#include "LCreateDefaultGenerators.h"


#include <configurator/LGeneratorMacrosLogging.h>
#include <configurator/LGeneratorHashMap.h>
#include <configurator/LGeneratorMacrosException.h>
#include <configurator/LGeneratorEnum.h>
#include <configurator/LGeneratorLogTest.h>

#include <memory>


namespace CONFIGURATOR
{

    generator_vec LCreateDefaultGenerators::CreateAll(LXMLInfo xmlinfo)
    {
        vector< std::shared_ptr< LGenerator >  > generators;

        generators.push_back(std::make_shared < LGeneratorEnum >("logging/LEnumAutoGen.h", xmlinfo));
        generators.push_back(std::make_shared < LGeneratorMacrosLogging >("logging/LLogApiAutoGen.h", xmlinfo));
       // generators.push_back(std::make_shared < LGeneratorMacrosException >("logging/GExceptionAutoGen.h", xmlinfo));
        generators.push_back(std::make_shared < LGeneratorHashMap >("logging/LHashMapsAutoGen.cpp", xmlinfo));
        generators.push_back(std::make_shared < LGeneratorLogTest >("logging/LLogTestAutoGen.cpp", xmlinfo));
        //  generator_vec generators;
        return generators;
    }

}
