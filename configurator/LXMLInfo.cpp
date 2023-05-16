
#include "LXMLInfo.h"
#include <utilities/GString.h>
#include <logging/GException.h>


namespace CONFIGURATOR
{

	LXMLInfo::LXMLInfo(const string& xml, const string& xsd)
	{

		XML_ASSERT_EXCEPTION(g_string()->EndsWith(xml, vector<string>{ ".xml", "XML"}), "%s is an invalid filename. An XML file must end with .xml or .XML");
		XML_ASSERT_EXCEPTION(g_string()->EndsWith(xsd, vector <string>{ ".xsd", "XSD" }), "%s is an invalid filename. An XSD file must end with .xsd or .XSD");

		fXMLFileName = xml;
		fXSDFileName = xsd;

	}

}
