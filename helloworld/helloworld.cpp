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







template< typename T >
class Less
{
  public:
    bool operator( )( const T & x,  const T & y ) const  { return  x < y; };
};



template<typename C, typename P>
int count (  const int lim,const C& c, P pred )
{
  int cnt = 0;
  for( const auto x : c )
  {
    FORCE_DEBUG(" %d is less than %d ? :  %s", lim, x, pred(x, lim )  == true ? "TRUE" : "FALSE"); 
    
    if(pred(x, lim))
    {
      cnt ++;
    }
  }
  return cnt;
}


int main()
{
  Less<int> lti;
  vector<int> test = {1,2,33,44,55,66,77};
  int cnt =  count( 42, test, lti );
  FORCE_DEBUG("The number of matches was %d", cnt );
  
  char buf[255];

  for(int i=0; i < 1000; i++)
  {
    sprintf(buf, "Hello%d", i );
    FORCE_DEBUG("%s", buf);

  }
  
  ///std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

