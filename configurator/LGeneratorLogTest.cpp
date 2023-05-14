
#include "LGeneratorLogTest.h"

#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <utilities/GRandom.h>

#include <sstream>


LGeneratorLogTest::LGeneratorLogTest(const string filename) : LGenerator(filename)
{

}


vector<string> LGeneratorLogTest::Generate(vector<std::shared_ptr<LXmlEntityLogLevel>> levels, vector<std::shared_ptr<LXmlEntitySubSystem>>  systems, const string /*autoclause*/) const
{
	vector<string> lines;

	lines.push_back("\n\n");
	lines.push_back("#include \"" + fHeaderFileName + "\"");
	lines.push_back("#include \"LLogApi.h\"");
	lines.push_back("#include \<utilities/GRandom.h>");
	lines.push_back("#include <utilities/GLocation.h>\n");
	lines.push_back("#include <iostream>");

	lines.push_back("using std::endl");
	lines.push_back("using std::cout");


	lines.push_back("\n\n\n");

	lines.push_back(" namespace LOGMASTER ");
	lines.push_back("{");

	lines.push_back("void");
	lines.push_back(fClassName + "::WriteMessages()");
	lines.push_back("{");

	lines.push_back("    float fval = 0");
	lines.push_back("    int ival = 0");


	for (auto s : systems)
	{
		 lines.push_back("    fval = g_random()->Uniform<float>(-10, 100)");
	     lines.push_back("    ival = g_random()->Uniform<int>(-10, 1000");

		for (auto l : levels)
		{
			string macroname = s->fName + "_" + l->fName;

			//	float fval = g_random()->Uniform<float>(-10, 100);
			//	int   ival = g_random()->Uniform<int>(-10, 1000);

			std::stringstream buffer;
			buffer << "     " << macroname << "(\"This is a " << macroname << "  test message with parameter: ival = %d, fval = %f\", ival, fval )";
			cerr << buffer.str() << endl;

			lines.push_back(buffer.str());

		}

	}


	lines.push_back("    cout << endl");
	lines.push_back("}");

	//float r = g_random()->Uniform(-10, 100);

	return lines;
}


/*
FSM_DEBUG("This is a FSM_DEBUG message");
FSM_INFO("This  is a FSM_INFO  message");
FSM_WARNING("This is a FSM_WARNING message");
FSM_ERROR("This is a FSM_ERROR message with parameters: a = %d, b = %d", a, b);
FSM_FATAL("Oppps.... a  FSM_FATAL message");
*/


/*
LGeneratorLogTest::Generate:15 : NOT EMPLEMENTED YET
LGeneratorLogTest::Generate : 20 : level = FATAL
LGeneratorLogTest::Generate : 20 : level = ERROR
LGeneratorLogTest::Generate : 20 : level = WARNING
LGeneratorLogTest::Generate : 20 : level = INFO
LGeneratorLogTest::Generate : 20 : level = DEBUG
LGeneratorLogTest::Generate : 25 : system = FSM
LGeneratorLogTest::Generate : 25 : system = MESSAGE
LGeneratorLogTest::Generate : 25 : system = COM
LGeneratorLogTest::Generate : 25 : system = XML
LGeneratorLogTest::Generate : 25 : system = DATABASE
*/