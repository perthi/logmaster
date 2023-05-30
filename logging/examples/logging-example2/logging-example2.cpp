
#include <logging/LLogTestAutoGen.h>
#include <logging/LLogApi.h>
#include <logging/GException.h>
#include <logging/LHashMaps.h>

#include <cmdline/GLogApplication.h>

using namespace LOGMASTER;

#include <cmdline/GCmdWiki.h>

#include <iostream>

int main(int argc, const char **argv)
{

    ///GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel");


    try
    {
        GLogApplication( ).InitLogArgs( ).ScanArguments(argc, argv);
     //  GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel --blahhh");

        LHashMaps::Instance( )->DoxygenDoc("logmaster.h");

       // GLogApplication( ).InitLogArgs( ).ScanArguments("-loglevel")  ;

        FSM_FATAL("A fatal FSM message");
        ALARM_FATAL("A fatal alarm message");

        //FORCE_DEBUG("Hello world!");
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

