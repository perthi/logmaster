// -*- mode: c++ -*-

#include <xml/GXmlValidator.h>

#include <iostream>
using std::cout;
using std::endl;

#include <memory>
#include <functional>
#include  <utilities/GDefinitions.h>
#include <xml/GXmlValidator.h>

#include  <xml/GXmlMacros.h>
#include  <logging/LEnums.h>
#include  <utilities/GColor.h>
#include  <utilities/GLocation.h>
#include   <utilities/GCommon.h>

#include <format.h>


bool help(  const string exename );
void ScanArguments( int argc, const char ** argv, string &xml, string &xsd );


int main(int argc, const char **  argv )
{
    string xml =  "";
    string xsd =  "";

    ScanArguments( argc, argv, xml, xsd );

    bool has_error = false;
    auto  validator = std::make_shared<GXmlValidator>();

    try
    {
        if( validator->IsValid(xml, xsd) ==  true )
        {
            GCommon().HandleError( fmt::format("SUCCSESS !!, {} is well formed and validated against {}", xml, xsd), GLOCATION, DISABLE_EXCEPTION );
        }
        else
        {
            GCommon().HandleError( fmt::format(  "Failed to validate {} against {}", xml, xsd), 
                GLOCATION, DISABLE_EXCEPTION   );
            help( string( argv[0] )  );
            has_error = true;
            return -1;
        }
    }
    catch(const std::exception&  /*e*/)
    {
        //PrintMessage(  string( e.what()), GLOCATION, eLOGLEVEL::LOG_FATAL   );
        help( string( argv[0] )  );
        has_error = true;
    }
    catch( const string e)
    {
        ///PrintMessage(  e,  GLOCATION, eLOGLEVEL::LOG_FATAL   );
        has_error = true;
    }
    catch(...)
    {
        ///PrintMessage(   GTextXml( "Unknown exception caught parsing files: xml = %s\txsd = %s", xml.c_str(), xsd.c_str() ).str()  ,     GLOCATION, eLOGLEVEL::LOG_ERROR   );
        help( string( argv[0] )  );
        has_error = true;
    }
    if( has_error == true )
    {
        return -1;
    }
    else
    {
        return -1;
    }

    return 0;
}


void 
ScanArguments( int argc, const char ** argv, string &xml, string &xsd )
{
    if( argc < 2 || argc > 3 )
    {
        help( argv[0] );
    }
    else
    if( argc  == 2 &&   ( string(argv[1]) == "-h"  || string(argv[1]) == "--help"   ) )
    {
        help( argv[0] );
    } 
    else
    {
        xml = string(argv[1]);
        xsd = string( argv[2]);
    }
}



bool
help( const string ex )
{
    cout << endl;
    GCommon().HandleError(fmt::format("Usage: {}  [xml-file]  [xsd-file]", ex), GLOCATION, DISABLE_EXCEPTION );
    cout << endl;
    return true;
}