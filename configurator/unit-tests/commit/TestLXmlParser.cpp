// -*- mode: c++ -*-
#include "TestLXmlParser.h"


#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <xml/GXmlStreamReader.h>
#include <xml/GXmlValidator.h>
#include <xml/GXmlClassFactory.h>

#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LXmlParser.h>

using namespace CONFIGURATOR;


#include <utilities/GUtilities.h>
#include <utilities/GString.h>
#include <utilities/GSystem.h>


#include <vector>
using std::vector;

TestLXmlParser::TestLXmlParser()
{
#ifdef _WIN32
    xml = string(g_system()->GetHomeDir()) + "\\..\\config\\logging.xml";
    xsd = string(g_system()->GetHomeDir()) + "\\..\\config\\logging.xsd";
#else
    xml = string(CONFIG_DIR) + "/logging.xml";
    xsd = string(CONFIG_DIR) + "/logging.xsd";
#endif // _WIN32
}



/** @todo moc to xml library */
 TEST_F( TestLXmlParser, check_file )
 {
   GXmlValidator v;
    v.IsValid(xml, xsd );
    EXPECT_TRUE( v.IsValid(xml, xsd ) );
    EXPECT_TRUE(true);
 }



 TEST_F( TestLXmlParser, parse_loglevels )
 {
     LXmlParser p;
     vector < std::shared_ptr<LXmlEntityLogLevel> > loglevels;
     vector < std::shared_ptr< LXmlEntitySubSystem > > subsystems; 
     p.ParseXML(xml, xsd, loglevels, subsystems  );

     EXPECT_TRUE ( p.HasElement("DEBUG", loglevels ) );
     EXPECT_TRUE ( p.HasElement("INFO", loglevels ) );
     EXPECT_TRUE ( p.HasElement("WARNING", loglevels ) );
     EXPECT_TRUE ( p.HasElement("ERROR", loglevels ) );
     EXPECT_TRUE ( p.HasElement("FATAL", loglevels ) );
     EXPECT_FALSE ( p.HasElement("BLAHHH", loglevels ) );
 }



 TEST_F( TestLXmlParser, parse_subsystems )
 {
    LXmlParser p;
    vector < std::shared_ptr<LXmlEntityLogLevel> > loglevels;
    vector < std::shared_ptr< LXmlEntitySubSystem > > subsystems; 
    p.ParseXML(xml, xsd, loglevels, subsystems  );
    EXPECT_TRUE  ( p.HasElement("COM",  subsystems  ) );
    EXPECT_TRUE  ( p.HasElement("XML",       subsystems  ) );
    EXPECT_TRUE  ( p.HasElement("MESSAGE", subsystems  ) );
    EXPECT_FALSE ( p.HasElement("BLAHHH",    subsystems  ) );
 }


