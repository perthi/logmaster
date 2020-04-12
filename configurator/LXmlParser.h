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
         virtual  void API ParseXML( const string  xml, 
                                     const string  xsd, 
                                     std::vector< std::shared_ptr <LXmlEntityLogLevel> >  &loglevlels,
                                     std::vector< std::shared_ptr <LXmlEntitySubSystem> > &subsystems ) ;
		LXmlParser();
		virtual ~LXmlParser();

	private:		
    	std::shared_ptr <LXmlEntitySubSystem>    ParseSubSystem(  std::shared_ptr<GXmlStreamReader> r, const string closing_tag  );
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
