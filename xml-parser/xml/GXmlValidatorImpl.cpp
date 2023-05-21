// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "GXmlValidatorImpl.h"
#include "LEnums.h"
#include "GXmlMacros.h"
#include "GLocationXml.h"

#include <libxml/xmlschemastypes.h>
#include <libxml/xmlerror.h>
#include <libxml/xmlschemas.h>
#include <libxml/xmlschemastypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <libxml/xmlreader.h>
#include <libxml/encoding.h>
#include <libxml/xmlwriter.h>

#include <string.h>

#include <format>

using   std::format;

#undef HAS_LOGGING

#ifdef HAS_LOGGING
#include <exception/GException.h>
#endif

bool GXmlValidatorImpl::fHasError2 = false;


#define SETPOS_XML() { location = GLocationXml(__FILE__, __LINE__, __func__); }

static void schemaParseErrorHandler(void *  /*ctx*/, xmlErrorPtr error)
{
	char err[1024] = {0};

	#ifdef _WIN32
	strerror_s(err, 1024, errno);
	#else
	strerror_r(errno, err, 1024);
	#endif
	
	
	fprintf(stderr, "filename: %s\n", error->file );

#ifdef HAS_LOGGING
	g_common_xml()->HandleError(  GTextXml(  "Offending file: %s (error code %d) (from %s line[%d])",
	                                  error->message, error->code, __func__, __LINE__  ).str(),   
									  GLocationXml(error->file, error->line,  "" ), 
									  DISABLE_EXCEPTION    );
#else

	
	g_common_xml()->HandleError(  format( "{} line {} contains error(s)  !!!!!!!!", 
		                                 __func__, __LINE__  ),   GLocationXml(error->file, error->line,  "" ), DISABLE_EXCEPTION    );
	
#endif
	GXmlValidatorImpl::SetError(true);
}



void
GXmlValidatorImpl::SetError(const bool err)
{
	fHasError2 = err;
}

bool
GXmlValidatorImpl::HasError()
{
	return fHasError2;
}


bool 
GXmlValidatorImpl::DoExistFile( const string f  )
{

	FILE* fp = nullptr;
	
#ifdef _WIN32
	fopen_s(&fp,  f.c_str(), "r");
#else
	fp = fopen(f.c_str(), "r");
#endif // _WIN32

	

	if( fp == nullptr)
	{
		g_common_xml()->HandleError( format(  "Cannot find XML-file {}", f.c_str() ), GLOCATION_SRC, THROW_EXCEPTION );
		return false;
	}
	else
	{
		fclose(fp);
		return true;
	}
}


bool
GXmlValidatorImpl::IsValid( string xml ,  string xsd )
{
	int has_schema_errors = 0;

	try
	{
		GLocationXml location = GLocationXml(__FILE__, __LINE__, __func__);

		XML_ASSERT(  DoExistFile( xml ), format("could not open file {}", xml) , GLOCATION_SRC  ) ;
		XML_ASSERT(  DoExistFile( xsd ), format("could not open file {}", xsd), GLOCATION_SRC  ) ;

		::xmlSetGenericErrorFunc(&location, DoError);
		SETPOS_XML(); xmlSchemaParserCtxtPtr schemaTextParser = ::xmlSchemaNewParserCtxt(xsd.c_str());
		
		if( schemaTextParser == nullptr )
		{
			g_common_xml()->HandleError( "Could not create xmlSchemaParserCtxtPtr"   , GLOCATION_SRC, THROW_EXCEPTION );	
		}

		xmlSchemaSetParserErrors(schemaTextParser, DoError, DoWarning, &location);
		xmlSchemaSetParserStructuredErrors( schemaTextParser, schemaParseErrorHandler, &has_schema_errors);
		SETPOS_XML(); xmlSchemaPtr schema = xmlSchemaParse(schemaTextParser);

		if( HasError() == true )
		{
			SetError(false);
			g_common_xml()->HandleError( format(   "XML file {} contains errors", xsd), GLOCATION_SRC, THROW_EXCEPTION );
		}

		XML_ASSERT(schema != nullptr, "Could not parse xmlSchemaPtr", GLOCATION_SRC ) ;

		xmlSetGenericErrorFunc(&location, DoError );

		// schemaParseErrorHandler

		SETPOS_XML(); xmlSchemaValidCtxtPtr ctxt = xmlSchemaNewValidCtxt(schema);
		xmlSchemaSetValidStructuredErrors(ctxt, schemaParseErrorHandler, &has_schema_errors);
		
		XML_ASSERT ( has_schema_errors == false, "XML ore XSD contains errors", GLOCATION_SRC );
		XML_ASSERT (ctxt != nullptr, "Could not Create", GLOCATION_SRC );
		
		xmlSchemaSetValidErrors(ctxt, DoError, DoWarning, &location);
		if( HasError() == true )
		{
			SetError(false);
			g_common_xml()->HandleError( format( "XML file {} contains errors", xml) , GLOCATION_SRC, THROW_EXCEPTION  );
		}

		SETPOS_XML(); xmlDocPtr doc = xmlReadFile(xml.c_str(), nullptr, 0);
		XML_ASSERT(doc != nullptr,  format( "Could not parse {}", xml), GLOCATION_SRC );
		SETPOS_XML(); int ret = xmlSchemaValidateDoc(ctxt, doc);
		xmlSchemaFreeValidCtxt(ctxt);
		
		xmlFreeDoc(doc);
		
		XML_ASSERT( ret >= 0,  format( "{} validation generated an internal error", xml), GLOCATION_SRC  );

		return(ret == 0);
	}
	
	#ifdef HAS_LOGGING
	
	/*
	catch (GException & e)
	{
	//	g_common_xml()->HandleError(  GTextXml( "%s", e.what() ).str() , GLOCATION_SRC, DISABLE_EXCEPTION  );
		throw(e);	
		return false;
	}
	*/
	#endif
	
	catch( std::exception & e)
	{
		//g_common_xml()->HandleError(  GTextXml( "%s", e.what() ).str() , GLOCATION_SRC, DISABLE_EXCEPTION  );
		throw(e);
		return false;
	}
	catch(std::string & /*e*/ )
	{
		//CERR << e << endl;
	}
	catch (...)
	{
		g_common_xml()->HandleError( "Unknown exception caught !!", GLOCATION_SRC, DISABLE_EXCEPTION  );
		return false;
	}

	return true;
}


void GXmlValidatorImpl::DoError(void *ctx, const char *msg, ...)
{
//    XML_FATAL("Calling DO ERROR");
	GLocationXml location = *((GLocationXml*)ctx);
	char buff[10240];
	va_list ap;
	va_start(ap, msg);

	#ifdef _WIN32
	vsprintf_s(buff, sizeof(buff), msg, ap);
	#else
	vsnprintf (buff, sizeof(buff), msg, ap);
	#endif

	va_end(ap);

	g_common_xml()->HandleError( buff, location , DISABLE_EXCEPTION  );
}

void GXmlValidatorImpl::DoWarning(void * ctx, const char * msg, ...)
{
 //   XML_FATAL("Calling DO WARNING");
	
	GLocationXml location = *((GLocationXml*)ctx);
	char buff[10240];
	va_list ap;
	va_start(ap, msg);

	#ifdef _WIN32
	vsprintf_s(buff, sizeof(buff), msg, ap);
	#else
	vsnprintf (buff, sizeof(buff), msg, ap);
	#endif

	va_end(ap);
	g_common_xml()->HandleError( buff,  location, DISABLE_EXCEPTION  );
}



eLOGLEVEL
GXmlValidatorImpl::ErrorLevel2Loglevel(const int level)
{
	switch (level)
	{
	case XML_ERR_NONE:
		 return eLOGLEVEL::LOG_INFO;
		 break;
	case XML_ERR_WARNING:
		 return eLOGLEVEL::LOG_WARNING;
		 break;
	case XML_ERR_ERROR:
		 return eLOGLEVEL::LOG_ERROR;
		 break;
	case XML_ERR_FATAL:
		 return eLOGLEVEL::LOG_FATAL;
		 break;
	default:
		 return eLOGLEVEL::LOG_DEBUG;
		break;
	}

}
