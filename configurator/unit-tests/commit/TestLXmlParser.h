// -*- mode: c++ -*-
#ifndef TESTLXMLPARSER_H
#define TESTLXMLPARSER_H

#include <testlib/TestBase.h>
#include <xml/GXmlValidator.h>
#include <configurator/LXMLInfo.h>

#include <memory>

using namespace CONFIGURATOR;

class  TestLXmlParser : public TestBase
{
    protected:
        virtual void SetUp( ) override;
        std::shared_ptr<LXMLInfo> fXMLInfo = nullptr;
};


#endif
