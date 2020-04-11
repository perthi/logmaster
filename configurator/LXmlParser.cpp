// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <vector>
using std::vector;
#include "LXmlParser.h"
#include <logging/LLogApi.h>
using namespace LOGMASTER;


LXmlParser::LXmlParser()
{

}

LXmlParser::~LXmlParser()
{

}


vector< std::shared_ptr<GXmlEntity> > 
LXmlParser::ParseXML(const string  xml, const string  xsd ) 
{
    vector < std::shared_ptr<GXmlEntity > > tmp;
    FORCE_DEBUG("xml file = %s",  xml.c_str()  );
    FORCE_DEBUG("xsd file = %s",  xsd.c_str()  );
    return tmp;
}
