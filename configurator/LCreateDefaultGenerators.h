#pragma once

#include <configurator/LDefinitions.h>
#include <configurator/LXMLInfo.h>

#include <memory>

#include <string>

using std::string;

class LGenerator;



namespace CONFIGURATOR
{

    class LCreateDefaultGenerators
    {
    public:
        static generator_vec  CreateAll(const LXMLInfo xmlinfo);



    };


}

