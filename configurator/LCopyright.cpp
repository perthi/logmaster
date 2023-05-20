// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LCopyright.h"
#include "LXMLInfo.h"
#include <utilities/GUtilities.h>
#include <utilities/GLicence.h>

#include <sstream>
#include <iostream>

using std::endl;



namespace CONFIGURATOR
{

    string
    LCopyright::str(const LXMLInfo info)
    {
        std::stringstream buffer;
        buffer << "// -*- mode: c++ -*-" << endl; /// So that emacs understand that it is a c++ file
        string addendum = "";

        auto xml = info.fXMLFileName;
        auto xsd = info.fXSDFileName;

        if (xml != "" && xsd != "")
        {
            addendum = "/*** Generated from " + xml + " **/\n";
            addendum += "/*** Validated by " + xsd + " **/\n";
        }
    

        buffer << g_utilities()->AutoClause(addendum);
        buffer << GLicence::long_version ( );

        return buffer.str();
    }

}