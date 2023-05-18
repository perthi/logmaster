
// -*- mode: c++ -*-
#include "LGeneratorMacrosException.h"
#include <configurator/LXmlEntitySubSystem.h>

#include <logging/LLogApi.h>
#include <utilities/GUtilities.h>
#include <utilities/GString.h>

using namespace LOGMASTER;

namespace CONFIGURATOR
{
    /** @copydoc LGenerator */
    LGeneratorMacrosException::LGeneratorMacrosException(const string path, const string classname, 
        const LXMLInfo xmlinfo) : LGenerator(path, classname, xmlinfo)
    {
        fDoGenerateHeader = true;
    }


    void
        LGeneratorMacrosException::GenerateContent( const logentity_vec  /*levels*/, const sysentity_vec systems)
    {
        GenerateClasses(systems, fFileContentHeader);
        fFileContentHeader.push_back("\n\n");
        GenerateExceptionMacros(systems, fFileContentHeader);
        fFileContentHeader.push_back("\n\n");
    }


    string
        LGeneratorMacrosException::ClassName(  const sysentity_ptr   sys) const
    {
        return  string("G") + g_string()->ToPascalCase(sys->fName) + "Exception";

    }


    void
        LGeneratorMacrosException::GenerateClasses(  const sysentity_vec systems, content_vec & content) const
    {
        for (auto& sys : systems)
        {
            string tmp = "EXCEPTION_CLASS_H\t(" + ClassName(sys) + ")";
            content.push_back(tmp);
            tmp = "EXCEPTION_CLASS_CPP\t(" + ClassName(sys) + ")";
            content.push_back(tmp);
        }
    }


    void
        LGeneratorMacrosException::GenerateExceptionMacros( const sysentity_vec systems, content_vec & content) const
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
                
                /** @bug SYS_EXCEPTION should be read from XML file, not hard coded */
                buffer << "(" << e << ")(" << e << "::SYS_EXCEPTION | " << e << "::SYS_" << sys->fName << "),\t__VA_ARGS__ ) )";
                ass_macros.push_back(buffer.str());
            }
        }

        content.insert(content.end(), exc_macros.begin(), exc_macros.end());
        content.push_back("\n");
        content.insert(content.end(), ass_macros.begin(), ass_macros.end());
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
