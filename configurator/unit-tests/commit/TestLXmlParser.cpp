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

#include <utilities/GUtilities.h>


#include <vector>
using std::vector;


#include <utilities/GString.h>
#include <logging/LLogApi.h>


using namespace LOGMASTER;

TestLXmlParser::TestLXmlParser()
{

	///  string    Replace(const string original, const string toreplace, const string replacement);
	 //string  xml2 = g_string()->Replace(CONFIG_DIR, "",  "" );

	string xml2 = "balhhhhh";
	// string xml2 = string(CONFIG_DIR);
	FORCE_DEBUG("size = %d", xml2.size());
	// XML_ERROR("%s", "balhhhh");

   //  G_ERROR("balhhhhh");
	// FORCE_DEBUG("blahhhhh"));
	 //for(int i=0; i < CONFIG_DIR)

}




TEST_F( TestLXmlParser, dummy )
{
  //   GXmlValidator v;
//     EXPECT_TRUE( v.IsValid(xml, xsd ) );
}


// TEST_F( TestLXmlParser, check_file )
// {
//     GXmlValidator v;
//     EXPECT_TRUE( v.IsValid(xml, xsd ) );
// }


// TEST_F( TestLXmlParser, parse_loglevels )
// {
//      LXmlParser p;
//      vector < std::shared_ptr<LXmlEntityLogLevel> > loglevels;
//      vector < std::shared_ptr< LXmlEntitySubSystem > > subsystems; 
//      p.ParseXML(xml, xsd, loglevels, subsystems  );

//     EXPECT_TRUE ( p.HasElement("DEBUG", loglevels ) );
//     EXPECT_TRUE ( p.HasElement("INFO", loglevels ) );
//     EXPECT_TRUE ( p.HasElement("WARNING", loglevels ) );
//     EXPECT_TRUE ( p.HasElement("ERROR", loglevels ) );
//     EXPECT_TRUE ( p.HasElement("FATAL", loglevels ) );
//     EXPECT_FALSE ( p.HasElement("BLAHHH", loglevels ) );
// }


// TEST_F( TestLXmlParser, parse_subsystems )
// {
//    LXmlParser p;
//    vector < std::shared_ptr<LXmlEntityLogLevel> > loglevels;
//    vector < std::shared_ptr< LXmlEntitySubSystem > > subsystems; 
//    p.ParseXML(xml, xsd, loglevels, subsystems  );

//    EXPECT_TRUE  ( p.HasElement("ANALYSIS",  subsystems  ) );
//    EXPECT_TRUE  ( p.HasElement("XML",       subsystems  ) );
//    EXPECT_TRUE  ( p.HasElement("EXCEPTION", subsystems  ) );
//    EXPECT_FALSE ( p.HasElement("BLAHHH",    subsystems  ) );
// }

