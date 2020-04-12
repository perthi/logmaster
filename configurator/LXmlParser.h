// -*- mode: c++ -*-
#ifndef LXMLPARSER_H
#define LXMLPARSER_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <xml/GXmlParser.h>
#include <memory>

#include <vector>
using std::vector;

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;

class  LXmlParser : public GXmlParser
{
	public:
		virtual  vector< std::shared_ptr<GXmlEntity> > API ParseXML(const string  xml, const string  xsd ) ;
		LXmlParser();
		virtual ~LXmlParser();

	private:
		vector<std::shared_ptr <LXmlEntitySubSystem> > ParseSubSystems();
	    vector<std::shared_ptr < LXmlEntityLogLevel  > >  ParseLogLevels();

};

#endif
