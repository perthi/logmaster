// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "LGenerator.h"
#include "LCopyright.h"
#include <utilities/GString.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;

namespace CONFIGURATOR
{


	/** Class for auto-generated of files for the logging system.
	 * The .cpp/.h
	 * file is derived from the path to ensure that the class names is always the
	 * same as the file name (excluding the suffix) which must be the default for all
	 * classes
	 * @param[in] path File path where the generated file will be written.
	 * @param[in] xmlinfo Struct containing the name of the XML file defining logging macros
	 * etc, and the corresponding XSD file*/
	LGenerator::LGenerator(const string path, const  LXMLInfo xmlinfo) : fFilePath(path)
	{
		fClassName = g_string()->Path2ClassName(path);
		fSourceFileName = fClassName + ".cpp";
		fHeaderFileName = fClassName + ".h";
		GenerateHeader(xmlinfo);

	}


	/** Generate header comments. GPL license as well
	 * as an auto-generated warning that will be included
	 * at the beginning of all generated files.
	 * @param[in] xmlinfo The name of the XML+ XSD files
	 * used. This is added for information only.*/
	void
		LGenerator::GenerateHeader(const LXMLInfo xmlinfo)
	{
		//fFileLineEntries.push_back("// -*- mode: c++ -*-");
		fFileLineEntries.push_back(LCopyright::str(xmlinfo));
	}

}