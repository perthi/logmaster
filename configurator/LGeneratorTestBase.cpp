
#include "LGeneratorTestBase.h"

#include <sstream>
using std::endl;

namespace CONFIGURATOR
{
    string
        LGeneratorTestBase::GenerateTesCase(const string classname, const string testname, const vector<string>& content)
    {
        std::stringstream buffer;
        
        buffer << "TEST_F(" << classname << ", " << testname << ")" << endl;
        buffer << "{" << endl;
        
        for ( auto& c : content )
        {
            buffer << "    " << c << endl;
        }
        buffer << "}" << endl << endl;
         
        return buffer.str( );
    }

}
