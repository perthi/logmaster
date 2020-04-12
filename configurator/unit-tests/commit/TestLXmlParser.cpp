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

TestLXmlParser::TestLXmlParser()
{

}




TestLXmlParser::~TestLXmlParser()
{

}



TEST_F( TestLXmlParser, check_file )
{
    GXmlValidator v;
    EXPECT_TRUE( v.IsValid(xml, xsd ) );
}


TEST_F( TestLXmlParser, parse_loglevels )
{
    std::shared_ptr<GXmlStreamReader> r = GXmlClassFactory::CreateStreamReaderSmartPtr(xml );
    LXmlParser p;
    vector < std::shared_ptr<LXmlEntityLogLevel> > entities = p.ParseLogLevels(r, "LOGLEVELS");
    
    EXPECT_TRUE ( p.HasElement("DEBUG", entities ) );
    EXPECT_TRUE ( p.HasElement("INFO", entities ) );
    EXPECT_TRUE ( p.HasElement("WARNING", entities ) );
    EXPECT_TRUE ( p.HasElement("ERROR", entities ) );
    EXPECT_TRUE ( p.HasElement("FATAL", entities ) );
    EXPECT_TRUE ( p.HasElement("BLAHHH", entities ) );



    
}


TEST_F( TestLXmlParser, parse_subsystems )
{
    std::shared_ptr<GXmlStreamReader> r = GXmlClassFactory::CreateStreamReaderSmartPtr(xml );
    LXmlParser p;
    vector < std::shared_ptr< LXmlEntitySubSystem > > entities = p.ParseSubSystems(r, "SUBSYSTEMS" );

    EXPECT_TRUE  ( p.HasElement("ANALYSIS", entities ) );
    EXPECT_TRUE  ( p.HasElement("XML", entities ) );
    EXPECT_TRUE  ( p.HasElement("EXCEPTION", entities ) );
    EXPECT_FALSE ( p.HasElement("BLAHHH", entities ) );

}


