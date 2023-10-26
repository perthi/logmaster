#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace CONFIGURATOR
{
    class LGeneratorTestBase
    { 
    protected:
        string GenerateTesCase(const string classname, const string testname, const vector<string> &content );
        virtual ~LGeneratorTestBase() {};
        virtual void GenerateLocalCommon( ) = 0;
    };

}

