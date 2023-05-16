
#pragma once

#include <string>
using std::string;



namespace CONFIGURATOR
{

	class LXMLInfo
	{
	public:
		LXMLInfo(const string& xml, const string& xsd);

		string fXMLFileName = "";
		string fXSDFileName = "";

	};

}

