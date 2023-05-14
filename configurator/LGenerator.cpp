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

LGenerator::LGenerator( const string path,  const string xml, const string xsd) : fFilePath(path)
{
   fClassName = g_string()->Path2ClassName(path);
   fSourceFileName = fClassName + ".cpp";
   fHeaderFileName = fClassName + ".h";
   
  // FORCE_DEBUG("classname = %s", fClassName.c_str() );
   GenerateHeader(xml, xsd);

}


void   
LGenerator::GenerateHeader( const string xml, const string xsd )
{
	fFileLineEntries.push_back("// -*- mode: c++ -*-");
	fFileLineEntries.push_back(LCopyright::str(xml, xsd));
}