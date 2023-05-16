
// -*- mode: c++ -*-
#include "LGeneratorMacrosException.h"
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>
#include <utilities/GUtilities.h>
#include <utilities/GString.h>

using namespace LOGMASTER;

namespace CONFIGURATOR
{

    LGeneratorMacrosException::LGeneratorMacrosException(const string fname, const LXMLInfo xmlinfo) : LGenerator(fname, xmlinfo)
    {

    }


    void
        LGeneratorMacrosException::GenerateContent(vector< std::shared_ptr<LXmlEntityLogLevel  > >  /*levels*/,
            vector< std::shared_ptr<LXmlEntitySubSystem > >  systems)
    {
        GenerateClasses(systems, fFileLineEntries);
        fFileLineEntries.push_back("\n\n");
        GenerateExceptionMacros(systems, fFileLineEntries);
        fFileLineEntries.push_back("\n\n");
    }


    string
        LGeneratorMacrosException::ClassName(std::shared_ptr<LXmlEntitySubSystem >  sys) const
    {
        return  string("G") + g_string()->ToPascalCase(sys->fName) + "Exception";

    }


    void
        LGeneratorMacrosException::GenerateClasses(vector<std::shared_ptr<LXmlEntitySubSystem>> systems, vector<string>& in) const
    {
        for (auto& sys : systems)
        {
            string tmp = "EXCEPTION_CLASS_H\t(" + ClassName(sys) + ")";
            in.push_back(tmp);
            tmp = "EXCEPTION_CLASS_CPP\t(" + ClassName(sys) + ")";
            in.push_back(tmp);
        }
    }


    void
        LGeneratorMacrosException::GenerateExceptionMacros(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& in) const
    {
        vector<string> exc_macros;
        vector<string> ass_macros;

        int tabsize = 6;

        for (auto& sys : systems)
        {
            vector<string> syslist = MacroNames(sys);

            for (auto& name : syslist)
            {
                std::stringstream buffer;
                buffer << g_utilities()->TabAlign("#define " + name + "_EXCEPTION(...)", tabsize);
                buffer << "throw_exception( " << ClassName(sys) << "(\t";
                buffer << "__FILE__,  __func__, __LINE__ , " << fSystemEnumName << "::SYS_" << sys->fName << ",\t__VA_ARGS__ ) )";

                exc_macros.push_back(buffer.str());
                buffer.clear();
                buffer.str("");

                buffer << g_utilities()->TabAlign("#define " + name + "_ASSERT_EXCEPTION(expr,  ...)", tabsize);
                buffer << " if(!(expr)) throw_exception( " << ClassName(sys) << "(\t";
                buffer << "__FILE__,  __func__, __LINE__ , ";
                auto& e = fSystemEnumName;
                buffer << "(" << e << ")(" << e << "::SYS_EX | " << e << "::SYS_" << sys->fName << "),\t__VA_ARGS__ ) )";
                ass_macros.push_back(buffer.str());
            }
        }

        in.insert(in.end(), exc_macros.begin(), exc_macros.end());
        in.push_back("\n");
        in.insert(in.end(), ass_macros.begin(), ass_macros.end());
    }



    vector<string>
        LGeneratorMacrosException::MacroNames(std::shared_ptr<LXmlEntitySubSystem >  sys) const
    {
        vector<string> tmp;
        tmp.push_back(sys->fName);
        if (sys->fName != sys->fNameShort)
        {
            tmp.push_back(sys->fNameShort);
        }
        return tmp;
    }

}
