

#include "LGeneratorCommon.h"
#include <utilities/GLicence.h>
#include "LCopyright.h"

#include <sstream>


namespace CONFIGURATOR
{
    string commonTestHeader(const string classname, bool with_closing_bracket)
    {
        std::stringstream buffer;
        buffer << endl << "#pragma once" << endl << endl;
        buffer << "#include <testlib/TestBase.h>" << endl << endl;
        buffer << "class " << classname << " : " << "public TestBase" << endl;
        buffer << "{" << endl;
        buffer << "public:" << endl;
        buffer << "    " << classname << "( ) = default;" << endl;
        buffer << "    " <<"virtual  ~" << classname << "( ) = default;" << endl;
        
        if ( with_closing_bracket == true )
        {
            buffer << "};" << endl;
        }
        return buffer.str( );
    } 
}

