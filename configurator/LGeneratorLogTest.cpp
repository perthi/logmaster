
#include "LGeneratorLogTest.h"

#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <utilities/GRandom.h>

#include <sstream>

using std::vector;


LGeneratorLogTest::LGeneratorLogTest(const string filename, const string xml, const string xsd) : LGenerator(filename, xml, xsd)
{

}


void
LGeneratorLogTest::Generate(vector<std::shared_ptr<LXmlEntityLogLevel>> levels, vector<std::shared_ptr<LXmlEntitySubSystem>>  systems)
{
	fFileLineEntries.push_back(string("\n\n"));
	fFileLineEntries.push_back("#include \"" + fHeaderFileName + "\"");
	fFileLineEntries.push_back("#include \"LLogApi.h\"");
	fFileLineEntries.push_back("#include <utilities/GRandom.h>");
	fFileLineEntries.push_back("#include <utilities/GLocation.h>\n");
	fFileLineEntries.push_back("#include <iostream>");
	fFileLineEntries.push_back("using std::endl;");
	fFileLineEntries.push_back("using std::cout;");
	fFileLineEntries.push_back("\n\n\n");
	fFileLineEntries.push_back(" namespace LOGMASTER ");
	fFileLineEntries.push_back("{");
	fFileLineEntries.push_back("void");
	fFileLineEntries.push_back(fClassName + "::WriteMessages()");
	fFileLineEntries.push_back("{");
	fFileLineEntries.push_back("    float fval = 0;");
	fFileLineEntries.push_back("    int ival = 0;");

	for (auto &s : systems)
	{
		fFileLineEntries.push_back("\n");  
		fFileLineEntries.push_back("        fval = g_random()->Uniform<float>(-10, 100);");
		fFileLineEntries.push_back("        ival = g_random()->Uniform<int>(-10, 1000);");

		for (auto l : levels)
		{
			string macroname = s->fName + "_" + l->fName;
			std::stringstream buffer;
			buffer << "        " << macroname << "(\"This is a " << macroname << "  test message with parameter: ival = %d, fval = %f\", ival, fval );";
			fFileLineEntries.push_back(buffer.str());
		}

	}


	fFileLineEntries.push_back("    cout << endl;");
	fFileLineEntries.push_back("}");
	fFileLineEntries.push_back("}");
}

