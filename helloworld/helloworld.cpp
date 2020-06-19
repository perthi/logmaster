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


void exiting1() 
{
    std::cout << "Exiting 1" << endl;
}


void exiting2() 
{
    std::cout << "Exiting 2" << endl;
}

class A
{
  public:
    static void exiting3()
    {
         std::cout << "A::Exiting 3" << endl;
    } 

};

int main ()
{
   
   std::atexit(exiting1);
   std::atexit(exiting2);
   std::atexit( A::exiting3 );


   SET_LOGLEVEL("--all-debug");
   SET_LOGTARGET("--target-all");
   SET_LOGFORMAT("11111111");
   FORCE_DEBUG("This is a test");
   std::this_thread::sleep_for( std::chrono::milliseconds(200));
   




   
   
   ///return 0;

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
   SET_LOGLEVEL("--all-debug");
   SET_LOGTARGET("--target-all");
   SET_LOGFORMAT("11111111");


    for(int i = 0; i < 10; i++ )
    {
        LLogTest::WriteMessages();
       // std::this_thread::sleep_for( std::chrono::milliseconds(200));
    }

    
   /// std::this_thread::sleep_for( std::chrono::milliseconds(2000));

    CERR << "Done sleeping" << endl;

//    FORCE_DEBUG("done sleeping");
   return 0;

}




///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
