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
class GXmlStreamReader;


class  LXmlParser : public GXmlParser
{
	public:
		virtual  vector< std::shared_ptr<GXmlEntity> > API ParseXML(const string  xml, const string  xsd ) ;
		LXmlParser();
		virtual ~LXmlParser();

//	private:
		vector<std::shared_ptr <LXmlEntitySubSystem> > ParseSubSystems(  std::shared_ptr<GXmlStreamReader> r, const string tag  );
	    vector<std::shared_ptr < LXmlEntityLogLevel  > >  ParseLogLevels( std::shared_ptr<GXmlStreamReader> r, const string tag   );

    	std::shared_ptr <LXmlEntitySubSystem>  ParseSubSystem(  std::shared_ptr<GXmlStreamReader> r, const string closing_tag  );
	    std::shared_ptr < LXmlEntityLogLevel  >  ParseLogLevel( std::shared_ptr<GXmlStreamReader> r, const string closing_tag   );

		template< typename T>
		bool HasElement( const string name,  vector<std::shared_ptr < T > > in );

};


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


#endif
