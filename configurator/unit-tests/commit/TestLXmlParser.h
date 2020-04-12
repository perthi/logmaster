// -*- mode: c++ -*-
#ifndef TESTLXMLPARSER_H
#define TESTLXMLPARSER_H

#include <testlib/TestBase.h>


class  TestLXmlParser : public TestBase
{
	public:
	  TestLXmlParser();
	  virtual ~TestLXmlParser();

	protected:
		string xml = string(CONFIG_DIR) + "/logging-test.xml";
		string xsd = string(CONFIG_DIR) + "/logging-test.xsd";


};


#endif
