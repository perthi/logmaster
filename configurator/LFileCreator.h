#pragma once



#include "LDefinitions.h"
#include <utilities/GDefinitions.h>

#include <memory>
#include <vector>

using std::vector;

namespace CONFIGURATOR
{


    class LFileCreator
    {
    public:
        static void API GenerateFiles(const generator_vec& g, const  logentity_vec, const  sysentity_vec  s);
        
        /** @todo <function name is misleading since 2 files can be written. Make it more logical */
        static void API GenerateSingleFile(const generator_ptr& g, const logentity_vec l, const  sysentity_vec s);
    
    private:
        static void WriteFile( const vector<string> &content, const string &filepath );
    
    };

}