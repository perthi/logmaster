// -*- mode: c++ -*-
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include "LGenerator.h"
#include "LFileInfo.h"
#include "LCopyright.h"
#include <utilities/GString.h>
#include <logging/LLogApi.h>
#include <logging/GException.h>

using namespace LOGMASTER;


namespace CONFIGURATOR
{


	/** Class for auto-generated of files for the logging system.
	 * The .cpp/.h
	 * file is derived from the path to ensure that the class names is always the
	 * same as the file name (excluding the suffix) which must be the default for all
	 * classes
	 * @param[in] path File path to the directory where the generated file h/cpp files will be written.
	 * @param[in] xmlinfo Struct containing the name of the XML file defining logging macros
	 * etc, and the corresponding XSD file*/
	//LGenerator::LGenerator(const string path, const string classname, const  LXMLInfo xmlinfo) : fFilePath(path)
		LGenerator::LGenerator(const string path, const string classname, const  LXMLInfo xmlinfo) 
	{

		try
		{
			fFileInfo = std::make_shared<LFileInfo>(path, classname);

		}
		catch (std::exception &e)
		{
			CERR << e.what() << endl;
			exit(-1);
		}
		catch (...)
		{
			CERR << "Unknown exception caught, aborting" << ENDL;
			exit(-1);
		}

		//fClassName = g_string()->Path2ClassName(path);
	//	fClassName = classname;
		//XML_ASSERT_EXCEPTION( g_string()->EndsWith(classname)         );
	//	fSourceFileName = fClassName + ".cpp";
	//	fHeaderFileName = fClassName + "h";

		GenerateLicenseHeader(xmlinfo);
	}


	/** Generate header comments. GPL license as well
	 * as an auto-generated warning that will be included
	 * at the beginning of all generated files.
	 * @param[in] xmlinfo The name of the XML+ XSD files
	 * used. This is added for information only.*/
	void
		LGenerator::GenerateLicenseHeader(const LXMLInfo xmlinfo)
	{
	/** @todo Write shorter header to the .cpp file that just reference the .h file*/
        fFileContentSource.push_back(LCopyright::str(xmlinfo));
        fFileContentHeader.push_back(LCopyright::str(xmlinfo));
	
    }


	/*
	void 
		LGenerator::EnableSuffix()
	{
        //g_string()->EndsWith(fHeaderFileName)
		//fDoAddSuffix = true;
	}
	
    void 
		LGenerator::DisableSuffix()
	{
		
        fHeaderFileName = fClassName;
        fSourceFileName = fClassName;
		//fDoAddSuffix = false;
	}
	*/

}