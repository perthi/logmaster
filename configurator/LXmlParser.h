// -*- mode: c++ -*-
#ifndef LXMLPARSER_H
#define LXMLPARSER_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <configurator/LXMLInfo.h>
#include <xml-parser/xml/GXmlParser.h>
#include <memory>

#include <vector>
using std::vector;

class GXmlStreamReader;

namespace CONFIGURATOR
{

    class LXmlEntityLogLevel;
    class LXmlEntitySubSystem;
  


    class  LXmlParser : public GXmlParser
    {
    public:
        virtual  void API ParseXML(const LXMLInfo xnlinfo,
            std::vector< std::shared_ptr <LXmlEntityLogLevel> >& loglevlels,
            std::vector< std::shared_ptr <LXmlEntitySubSystem> >& subsystems);

        template< typename T>
        bool API HasElement(const string name, vector<std::shared_ptr < T > > in);

    private:
        std::shared_ptr <LXmlEntitySubSystem>    ParseSubSystem(std::shared_ptr<GXmlStreamReader> r, const string closing_tag);
        std::shared_ptr < LXmlEntityLogLevel  >  ParseLogLevel(std::shared_ptr<GXmlStreamReader> r, const string closing_tag);

    };



    template< typename T>
    bool
        LXmlParser::HasElement(const string name, vector<std::shared_ptr < T> > in)
    {
        for (auto element : in)
        {
            if (element->fName == name)
            {
                return true;
            }
        }
        return false;
    }


}

#endif
