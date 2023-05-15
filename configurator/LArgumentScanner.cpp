

#include "LArgumentScanner.h"
#include <cmdline/GCommandLineArgument.h>
#include <cmdline/GArgument.h>
#include <cmdline/GLogApplication.h>

#include <memory>

void 
LArgumentScanner::ScanArguments(int argc, const char** argv, string& xmlfile, string& xsdfile)
{
    auto args = GenerateArgs(xmlfile, xsdfile);
    GLogApplication().AddArguments(args).ScanArguments(argc, argv);

}

deque<std::shared_ptr<GArgument>> 
LArgumentScanner::GenerateArgs(string& xmlfile, string& xsdfile)
{

    deque< std::shared_ptr<GArgument>  > arguments;
    std::shared_ptr<GArgument> xml_arg = std::make_shared <GCommandLineArgument< string > >("-xml", "-xml [file path]", "Sets the XML file to use", &xmlfile, fgkMANDATORY);
    std::shared_ptr<GArgument> xsd_arg = std::make_shared <GCommandLineArgument< string > >("-xsd", "-xsd [file path]", "Sets the XSD file to use for validation of the XML file", &xsdfile, fgkMANDATORY);

    arguments.push_back(xml_arg);
    arguments.push_back(xsd_arg);
    


    
    return arguments;
}
