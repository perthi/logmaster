// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/



#include <configurator/LXmlParser.h>
#include <xml/GXmlValidator.h>
#include <logging/LLogApi.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LCreateDefaultGenerators.h>
#include <configurator/LFileCreator.h>
#include <configurator/LArgumentScanner.h>
#include <configurator/LDefinitions.h>
#include <configurator/LXMLInfo.h>
#include <configurator/LGeneratorCommon.h>
#include <configurator/LGlobals.h>

#include <utilities/version-info/GMenu.h>

using namespace LOGMASTER;
using namespace CONFIGURATOR;

#include <utilities/GSystem.h>


/** Application that auto generates LOG macros for the logging system. Unit tests,
 *  and a test class used for demonstration and debugging.
 *  The Log levels and subsystems are defined in an XML file and validated by
 *  and XSD file. A default setup is present under <logmaster dir>/config/logging.xml
 *  @usage (typical) logging-configurator -xml logging.xml -xsd logging.xsd */
int main(int  argc, const char** argv)
{
    GMenu::Instance()->ScanArguments(argc, argv);
   
    string xml = "";
    string xsd = "";

    LArgumentScanner().ScanArguments(argc, argv, xml, xsd);


    try
    {
        XML_ASSERT_EXCEPTION(GXmlValidator().IsValid(xml, xsd), "failed to validate %s against %s", xml.c_str(), xsd.c_str());
        
        logentity_vec  loglevels;
        sysentity_vec  subsystems;
        LXmlParser().ParseXML(LXMLInfo(xml, xsd), loglevels, subsystems);

        XML_INFO("Successfully validated %s against %s and parsed the XML file", xml.c_str(), xsd.c_str());
        XML_ASSERT_EXCEPTION(checkMandatorySubsystems(subsystems, gMandatorySystems), "MANDATORY SUBSYSTEMS NOT PRESENT");


        generator_vec  generators  = LCreateDefaultGenerators::CreateAll(LXMLInfo(xml, xsd));
        LFileCreator::GenerateFiles(generators, loglevels, subsystems);
    }
    catch (const GException& e)
    {
        std::cerr << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    catch (const std::string& e)
    {
        std::cerr << e << endl;
    }
    catch (...)
    {
        FORCE_DEBUG("Unknown exception caught ....");
    }
}


