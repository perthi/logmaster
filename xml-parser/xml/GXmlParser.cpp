// -*- mode: c++ -*-


/***************************************************
* @copyright Embedded Consulting                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
****************************************************/


#include <exception>
#include <cmath>
#include "GXmlParser.h"
#include "GXmlEnum2String.h"

#include <fmt/format.h>

#include <utilities/GLocation.h>



GXmlParser::GXmlParser()
{

}


GXmlParser::~GXmlParser()
{

}


void
GXmlParser::AssertTagOpenGroup(std::shared_ptr<GXmlStreamReader> xmlReader, const string tag, GLocation l, const bool read_node )
{
    AssertTag(xmlReader, tag, l, eXML_NODETYPE::EOpenTagNode, read_node );
}


void
GXmlParser::AssertTagCloseGroup(std::shared_ptr<GXmlStreamReader> xmlReader, const string tag, GLocation l, const bool read_node  )
{
    AssertTag(xmlReader, tag, l, eXML_NODETYPE::ECloseTagNode, read_node );
}


void
GXmlParser::AssertTag(std::shared_ptr<GXmlStreamReader> xmlReader, const string tag, GLocation l, eXML_NODETYPE node_type,  const bool read_node  )
{

    
    GXmlNode *node  = xmlReader->GetCurrentNode();

    if(read_node == true)
    {
        node = xmlReader->ReadNode();
    }

    XML_ASSERT(node != nullptr, "node is a ZERO pointer", l);

    eXML_NODETYPE node_type_l = node->GetType();
    string tag_l =  node->GetName();

    #ifdef HAS_LOGGING
    
    GLocation ll =  GLocation( l.fFileName, l.fLineNo , l.fFunctName );
    
    if( tag_l != tag )
    {
        throw( GXmlException( ll.fFileName,ll.fFunctName, ll.fLineNo, eMSGSYSTEM::SYS_XML, 
        "Unexpected node type(%s), expected %s, got %s",  ToString(node_type).c_str()  ,  tag.c_str(),  tag_l.c_str() ) );
    }
    else if( node_type != node_type_l )
    {
        throw( GXmlException( ll.fFileName,ll.fFunctName, ll.fLineNo, eMSGSYSTEM::SYS_XML, 
        "Unexpected tag, expected %s, got %s",  ToString(node_type).c_str() , ToString(node_type_l).c_str()   ) );
    }

    #else
    if( tag_l != tag )
    {
        GCommon().HandleError(   fmt::format( "Unexpected node type({}), expected {}, got {}",  
                                                 ToString(node_type) ,  tag,  tag_l ), l, THROW_EXCEPTION    );
    }
    else if( node_type != node_type_l )
    {
        GCommon().HandleError(   fmt::format(  "Unexpected tag, expected {}, got {}",  ToString(node_type), 
                                                  ToString(node_type_l) ), l, THROW_EXCEPTION    );
    }

    #endif


}


void
GXmlParser::PrinttAttributes( const GXmlNode * const node,  GLocation  l )
{
    vector<GXmlAttribute> a =  node->GetAttributes();
    string name = node->GetName();
    auto type = node->GetType();
    
    #ifdef HAS_LOGGING
    GLocation ll =  GLocation( l.fFileName, l.fLineNo , l.fFunctName );
    LLogging::Instance()->Log(  eLOGLEVEL::LOG_INFO, eMSGSYSTEM::SYS_XML, ll,  
    "tag = %s, type = %s, attributes.size() = %d", name.c_str(),  ToString(type).c_str() , a.size() );

    for(size_t i =0; i < a.size(); i++ )
    {
        LLogging::Instance()->Log(  eLOGLEVEL::LOG_INFO, eMSGSYSTEM::SYS_XML, ll, 
        "Attribute[%d]: name = %s, value = %s", i, a.at(i).GetName().c_str(), a.at(i).GetValue().c_str()  );
    }


    #else
    for(size_t i =0; i < a.size(); i++ )
    {
        //COUT << l.str() << ":" << GTextXml(   "Attribute[%d]: name = %s, value = %s", i, a.at(i).GetName().c_str(), a.at(i).GetValue().c_str()    ).str()  << endl;    
    }

    #endif
}


bool
GXmlParser::HasAttributes(  const GXmlNode * const node ) const
{
    return node->GetAttributes().size() > 0 ? true : false;
}


string
GXmlParser::ToString( const eXML_NODETYPE type)
{
    string s =  GXmlEnum2String::Enum2String(type );
//    FORCE_DEBUG("s = %s", s.c_str() );
    return s;
}


// const char *
// GXmlParser::ToCharPtr( const eXML_NODETYPE type)
// {

//     return ( ToString(type ) ).c_str();

// }
