// -*- mode: c++ -*-
#ifndef LXMLPARSER_H
#define LXMLPARSER_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <xml/GXmlParser.h>
#include <memory>

class  LXmlParser : public GXmlParser
{
	public:
		virtual  vector< std::shared_ptr<GXmlEntity> > API ParseXML(const string  xml, const string  xsd ) ;
		LXmlParser();
		virtual ~LXmlParser();
};

#endif
