// -*- mode: c++ -*-

#include <logging/LLogApi.h>
#include <utilities/GDefinitions.h>

using namespace LOGMASTER;
#include <iostream>
using std::cout;
using std::endl;

#ifdef _WIN32
#include <Windows.h>
#endif

#include <utilities/GException.h>
#include <utilities/GUtilities.h>
#include <utilities/GTime.h>


#include <thread>
#include <chrono>
#include <memory>
#include <ctime>

#include <com/GCom.h>
#include <map>

// auto client = std::make_shared<KFClientMain >(argc, argv);
 //       th1 = thread( &KFClientMain::Run, client  );

void help();

bool do_run = true;

void get_device_info( vector<string> ids );


int main(int /*argc*/, const char **  /*argv*/ )
{

    return 0;
}


/*
void get_device_info( vector<string> ids )
{
    while (do_run == true)
    {
        for(size_t i=0; i < ids.size; i++ )
        {
       //     auto d = ic->Get

        }


    } 


}
*/



void help()
{
    cout << "\t" << g_utilities()->TabAlign("h") <<  "Prints help menu (this menu)" << endl;
    cout << "\t" << g_utilities()->TabAlign("q") <<  "Quits the application" << endl;
    cout << "\t" << g_utilities()->TabAlign("p") <<  "Prints all sensor values" << endl;
    cout << "\t" << g_utilities()->TabAlign("d [device_id]") <<  "Prints info for a given device" << endl;
}



