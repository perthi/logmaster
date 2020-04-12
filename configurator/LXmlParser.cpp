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
        if( tag == "LOGGING" )
        {
            FORCE_DEBUG("trag = LOGGING");
        }   
        else
        {
            
        }
        

        node = xmlReader->ReadNode();

    }




    // while (  node != nullptr  && i < 1000 )
    // {
    //  //   AssertTagOpenGroup();
    //     i ++;
    //     //PrinttAttributes( node, GLOCATION);
    //     //FORCE_DEBUG("read node %d",  i );
    //     string name =  node->GetName();
    //   //  if( name == "LOGGING" )
    //     {
    //         FORCE_DEBUG("Tag = %s !!", name.c_str() );
    //     }
        
    //     node = xmlReader->ReadNode();

    // }



    return tmp;
}


vector<std::shared_ptr <LXmlEntitySubSystem> > 
LXmlParser::ParseSubSystems( std::shared_ptr<GXmlStreamReader> /*r*/ )
{
   vector<std::shared_ptr <LXmlEntitySubSystem> >  tmp;
   return tmp;  
}


vector<std::shared_ptr < LXmlEntityLogLevel  > >  
LXmlParser::ParseLogLevels( std::shared_ptr<GXmlStreamReader>  /*r*/ )
{
   vector<std::shared_ptr < LXmlEntityLogLevel  > >  tmp;   
   return tmp;
}

// template< typename T>
// 		bool HasElement( const string name,  vector<std::shared_ptr < T > > in );

template< typename T>
bool 
LXmlParser::HasElement( const string name,  vector<std::shared_ptr < T> > in )
{
    for( auto element : in )
    {
        if ( element->fName == name  )
        {
            return true;
        }
    }
    return false;
}