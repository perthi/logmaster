#pragma once

#include <string>

using std::string;

namespace CONFIGURATOR
{

    class LUtilities
    {
        static string ToHexString(const int num, const int widt = 4);
        static string ToBinaryString(const int num, const int widt = 16);

    };

}

