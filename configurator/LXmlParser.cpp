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
#include <xml/GXmlStreamWriter.h>
#include <xml/GXmlStreamReader.h>
#include <xml/GXmlValidator.h>

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
    int i = 0;

    while (  node != nullptr  && i < 1000 )
    {
     //   AssertTagOpenGroup();
        i ++;
        //PrinttAttributes( node, GLOCATION);
        //FORCE_DEBUG("read node %d",  i );
        string name =  node->GetName();
      //  if( name == "LOGGING" )
        {
            FORCE_DEBUG("Tag = %s !!", name.c_str() );
        }
        
        node = xmlReader->ReadNode();

    }
    
    return tmp;
}
