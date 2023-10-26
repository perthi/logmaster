#pragma once

#include <utilities/GDefinitions.h>
#include <cmdline/GLogApplication.h>

#include <string>
using std::string;

#include <memory>
#include <deque>
using std::deque;

class  GArgument;


namespace CONFIGURATOR
{


    class LArgumentScanner : public GLogApplication
    {
    public:
        void API ScanArguments(int argc, const char** argv, string& xmlfile, string& xsdfile);
        deque< std::shared_ptr<GArgument>  >  API GenerateArgs(string& xmlfile, string& xsdfile);

    };

}



