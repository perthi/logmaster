
#include "LGeneratorLogTest.h"

#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <utilities/GRandom.h>
#include "LFileInfo.h"

#include <sstream>

using std::vector;


namespace CONFIGURATOR
{

	/** @copydoc LGenerator */
	LGeneratorLogTest::LGeneratorLogTest(const string path, const string classname, const  LXMLInfo xmlinfo) : 
		LGenerator(path, classname,  xmlinfo)
	{
        fDoGenerateSource = true;
	}


	void
		LGeneratorLogTest::GenerateContent(vector<std::shared_ptr<LXmlEntityLogLevel>> levels, vector<std::shared_ptr<LXmlEntitySubSystem>>  systems)
	{
        //fFileContentSource

		fFileContentSource.push_back(string("\n\n"));
		//fFileContentSource.push_back("#include \"" +  fHeaderFileName + "\"");
		fFileContentSource.push_back("#include \"" + fFileInfo->GetHeaderName()  + "\"");

		fFileContentSource.push_back("#include \"LLogApi.h\"");
		fFileContentSource.push_back("#include <utilities/GRandom.h>");
		fFileContentSource.push_back("#include <utilities/GLocation.h>\n");
		fFileContentSource.push_back("#include <iostream>");
		fFileContentSource.push_back("using std::endl;");
		fFileContentSource.push_back("using std::cout;");
		fFileContentSource.push_back("\n\n\n");
		fFileContentSource.push_back(" namespace LOGMASTER ");
		fFileContentSource.push_back("{");
		fFileContentSource.push_back("void");
		fFileContentSource.push_back(  fFileInfo->GetClassName() + "::WriteMessages()");
		fFileContentSource.push_back("{");
		fFileContentSource.push_back("    float fval = 0;");
		fFileContentSource.push_back("    int ival = 0;");

		for (auto& s : systems)
		{
			fFileContentSource.push_back("\n");
			fFileContentSource.push_back("        fval = g_random()->Uniform<float>(-10, 100);");
			fFileContentSource.push_back("        ival = g_random()->Uniform<int>(-10, 1000);");

			for (auto l : levels)
			{
				string macroname = s->fName + "_" + l->fName;
				std::stringstream buffer;
				buffer << "        " << macroname << "(\"This is a " << macroname << "  test message with parameter: ival = %d, fval = %f\", ival, fval );";
				fFileContentSource.push_back(buffer.str());
			}

		}


		fFileContentSource.push_back("    cout << endl;");
		fFileContentSource.push_back("}");
		fFileContentSource.push_back("}");
	}

}