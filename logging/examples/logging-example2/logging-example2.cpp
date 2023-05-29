
#include <logging/LLogTestAutoGen.h>
#include <logging/LLogApi.h>
#include <logging/GException.h>

#include <cmdline/GLogApplication.h>

using namespace LOGMASTER;

#include <cmdline/GCmdWiki.h>

#include <iostream>

int main(int argc, const char **argv)
{

    ///GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel");


    try
    {
      //  GLogApplication( ).InitLogArgs( ).ScanArguments(argc, argv);
     //  GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel --blahhh");
         
        GLogApplication g;
        g.InitLogArgs( );

        arg_deque args = g.GetArguments( );

        GCmdWiki::GenerateWiki(args, "wiki.h");

        GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel")  ;

        FORCE_DEBUG("Hello world!");
    }
  
    catch ( GException& e )
    {
        cout << e.what( ) << endl;
    }
    catch ( std::exception& e )
    {
        cout << e.what( ) << endl;
    }
    catch ( ... )
    {
        cout << "Unknown exception caught" << endl;
    }
    


}

