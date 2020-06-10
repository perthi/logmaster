// -*- mode: c++ -*-


#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
//#include <unistd.h>
#include <string>
using std::string;

#include <iostream>
using std::endl;
using std::cout;

#include <memory>
#include <iostream> 
#include <string>
#include <logging/LLogApi.h>
#include <logging/LDoc.h>

#include <logging/LLogTest.h>

#include <exception/GException.h>
#include <exception>






using namespace LOGMASTER;

#include <logging/LPublisher.h>

#include <queue>
#include <chrono>
#include <thread>







int main ()
{
    SET_LOGLEVEL("--all-debug");

 //  SET_LOGFORMAT("00000001");
 //  FORCE_DEBUG("This is a test");
    
 //  cout << LDoc::Instance()->Help() << endl;
   std::queue<int> test;
   test.push(1);
   test.push(2);
   test.push(3);
   test.push(4);
   


   FORCE_DEBUG("front = %d",  test.front() );
    test.pop();
   FORCE_DEBUG("front = %d",  test.front() ); 

 FORCE_DEBUG("back = %d",  test.back() ); 
    
    for(int i = 0; i < 10; i++ )
    {
        LLogTest::WriteMessages();
    }

    
    std::this_thread::sleep_for( std::chrono::milliseconds(2000));

    CERR << "Done sleeping" << endl;

//    FORCE_DEBUG("done sleeping");
   return 0;

}




///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
