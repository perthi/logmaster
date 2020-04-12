// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/



#include "LXmlParser.h"
#include "LXmlEntity.h"

#include <logging/LLogApi.h>
using namespace LOGMASTER;



#include <exception/GException.h>
#include <xml/GXmlClassFactory.h>
//#include <xml/GXmlStreamWriter.h>
#include <xml/GXmlStreamReader.h>
#include <xml/GXmlValidator.h>
#include <xml/GLocationXml.h>

#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>

#include <vector>
using std::vector;


LXmlParser::LXmlParser()
{

}

LXmlParser::~LXmlParser()
{

}


vector< std::shared_ptr<GXmlEntity> > 
LXmlParser::ParseXML(const string  xml, const string  xsd ) 
{
    vector< std::shared_ptr<GXmlEntity > > tmp;
    FORCE_DEBUG("xml file = %s",  xml.c_str()  );
    FORCE_DEBUG("xsd file = %s",  xsd.c_str()  );
    
    XML_ASSERT_EXCEPTION(GXmlValidator::IsValid(xml, xsd ), "Faild to validate XML file %s against %s",  
	xml.c_str(), xsd.c_str());
	
    std::shared_ptr<GXmlStreamReader> xmlReader = GXmlClassFactory::CreateStreamReaderSmartPtr(xml.c_str() );
	GXmlNode* node = xmlReader->ReadNode();
    ///int i = 0;

    while (  node != nullptr )
    {
        string tag = node->GetName();
        if (tag == "LOGGING")
        {
            FORCE_DEBUG("tag = LOGGING");
            FORCE_DEBUG("type = %s", node->GetTypeS().c_str());
        }
        else
        {
            if (tag == "LEVELS")
            {
                ParseLogLevels( xmlReader, "LEVELS" );
            }

            if (tag == "SUBSYSTEMS")
            {
                ParseSubSystems(xmlReader, "SUBSYSTEMS" );
            }
        }

        node = xmlReader->ReadNode();

    }



    return tmp;
}



vector<std::shared_ptr <LXmlEntitySubSystem> > 
LXmlParser::ParseSubSystems( std::shared_ptr<GXmlStreamReader> r, const string /*tag*/ )
{
    FORCE_DEBUG("Parsing subsystems");
    AssertTagOpenGroup( r,"SYSTEM", GLOCATION_XML  );
	
    AssertTagCloseGroup( r,"SYSTEM", GLOCATION_XML  );

   vector<std::shared_ptr <LXmlEntitySubSystem> >  tmp;
   return tmp;  
}


vector<std::shared_ptr < LXmlEntityLogLevel  > >  
LXmlParser::ParseLogLevels( std::shared_ptr<GXmlStreamReader>  /*r*/, const string /*tag*/ )
{
   FORCE_DEBUG("Parsing loglevels"); 
   

   
   vector<std::shared_ptr < LXmlEntityLogLevel  > >  tmp;   
   return tmp;
}

std::shared_ptr < LXmlEntitySubSystem >  
LXmlParser::ParseSubSystem(  std::shared_ptr<GXmlStreamReader> /*r*/, const string /*closing_tag*/  )
{

    return nullptr;
}

std::shared_ptr < LXmlEntityLogLevel >  
LXmlParser::ParseLogLevel( std::shared_ptr<GXmlStreamReader> /*r*/, const string  /*closing_tag*/   )
{
    return nullptr;

}