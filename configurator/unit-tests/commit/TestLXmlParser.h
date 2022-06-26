// -*- mode: c++ -*-
#ifndef TESTLXMLPARSER_H
#define TESTLXMLPARSER_H

#include <testlib/TestBase.h>
#include <xml/GXmlValidator.h>

class  TestLXmlParser : public TestBase
{
    public:
      TestLXmlParser();

    protected:
        string xml = "";
        string xsd = ""; 
};


#endif
