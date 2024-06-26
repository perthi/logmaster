// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/



#include "LXmlParser.h"
#include "LXmlEntity.h"

#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <configurator/LXmlEntityLogLevel.h>
#include <configurator/LXmlEntitySubSystem.h>
#include <logging/GException.h>
#include <utilities/GLocation.h>
#include <xml/GXmlClassFactory.h>
#include <xml/GXmlStreamReader.h>
#include <xml/GXmlValidator.h>


#include <vector>
using std::vector;

using namespace CONFIGURATOR;


#include <string>
using std::string;

void
LXmlParser::ParseXML(const LXMLInfo xmlinfo,
                     std::vector<std::shared_ptr<LXmlEntityLogLevel>>& loglevels,
                     std::vector<std::shared_ptr<LXmlEntitySubSystem>>& subsystems)
{

    XML_ASSERT_EXCEPTION(GXmlValidator::IsValid(xmlinfo.fXMLFileName, xmlinfo.fXSDFileName), "Failed to validate XML file %s against %s",
                         xmlinfo.fXMLFileName.c_str( ), xmlinfo.fXSDFileName.c_str( ));

    std::shared_ptr<GXmlStreamReader> xmlReader = GXmlClassFactory::CreateStreamReaderSmartPtr(xmlinfo.fXMLFileName.c_str( ));
    GXmlNode* node = xmlReader->ReadNode( );

    while ( node != nullptr )
    {
        string tag = node->GetName( );
        if ( tag == "LOGGING" )
        {
        }
        else
        {
            if ( tag == "LEVELS" )
            {
                bool the_end = false;
                while ( the_end == false )
                {
                    node = xmlReader->ReadNode( );
                    tag = node->GetName( );

                    if ( tag == "LOGLEVEL" && (node->GetType( ) == eXML_NODETYPE::EOpenTagNode) )
                    {
                        loglevels.push_back(ParseLogLevel(xmlReader, "LOGLEVEL"));
                    }
                    if ( node->GetName( ) == "LEVELS" && (node->GetType( ) == eXML_NODETYPE::ECloseTagNode) )
                    {
                        the_end = true;
                    }
                }
            }
            if ( tag == "SUBSYSTEMS" )
            {
                bool the_end = false;


                while ( the_end == false )
                {
                    node = xmlReader->ReadNode( );
                    tag = node->GetName( );

                    if ( tag == "SYSTEM" && (node->GetType( ) == eXML_NODETYPE::EOpenTagNode) )
                    {
                        subsystems.push_back(ParseSubSystem(xmlReader, "SYSTEM"));
                    }
                    if ( node->GetName( ) == "SUBSYSTEMS" && (node->GetType( ) == eXML_NODETYPE::ECloseTagNode) )
                    {
                        the_end = true;
                    }
                }
            }
        }

        node = xmlReader->ReadNode( );
    }
}


std::shared_ptr < LXmlEntityLogLevel >
LXmlParser::ParseLogLevel(std::shared_ptr<GXmlStreamReader>  r, const string   closing_tag)
{
    static int index = 0;

    std::shared_ptr<LXmlEntityLogLevel> l = std::make_shared<LXmlEntityLogLevel>( );
    l->fName = GetTagValue<string>(r, "LEVEL", GLOCATION);
    l->fIndex = index;

    index++;

    AssertTagCloseGroup(r, closing_tag, GLOCATION);
    return l;

}


std::shared_ptr < LXmlEntitySubSystem >
LXmlParser::ParseSubSystem(std::shared_ptr<GXmlStreamReader>  r, const string  closing_tag)
{
    /** @bug index is not reset if the parser is called twice (which should not happen) */
    //static int index = 1;
    static int index = 0;

    std::shared_ptr< LXmlEntitySubSystem> s = std::make_shared< LXmlEntitySubSystem>( );
    s->fName = GetTagValue<string>(r, "NAME", GLOCATION);
    s->fNameShort = GetTagValue<string>(r, "SHORT_NAME", GLOCATION);
    s->fTag = GetTagValue<string>(r, "TAG", GLOCATION);
    s->fTagShort = GetTagValue<string>(r, "TAG_SHORT", GLOCATION);
    s->fDefault = GetTagValue<string>(r, "DEFAULT", GLOCATION);
    s->fCanModify = GetTagValue<bool>(r, "CAN_MODIFY", GLOCATION);
    s->fForceOutput = GetTagValue<bool>(r, "FORCE_OUTPUT", GLOCATION);
    s->fIndex = index;

    index++;

    AssertTagCloseGroup(r, closing_tag, GLOCATION);
    return s;
}


//}