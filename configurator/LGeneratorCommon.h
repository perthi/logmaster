#pragma once

#include "LDefinitions.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

namespace CONFIGURATOR
{
    string  commonTestHeader(const string classname, bool with_closing_bracket = true );
    string  toPascalCase(const string  in);
    bool    checkMandatorySubsystems(const sysentity_vec systems, const vector<string> mandatory);
}


