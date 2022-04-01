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

#include   <memory>
#include   <iostream> 
#include   <string>
#include   <logging/LLogApi.h>
#include   <logging/LDoc.h>
#include   <logging/LLogTest.h>
#include   <exception/GException.h>
#include   <exception>
using namespace LOGMASTER;
#include   <logging/LPublisher.h>
#include   <queue>
#include   <chrono>
#include   <thread>
#include   <algorithm>
#include   <ostream>
#include   <iostream>
#include   <fstream>
#include   <vector>


using std::vector;


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


template<typename T>
void print_modulo( const vector<T> & v, std::ostream & os, int m  )
{
  auto print =  [&os, m]( T x) {   os << x << " xxxx " << '\n';  };
  for_each( begin(v), end(v), print ); 

}





int main()
{

  LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
  SET_LOGLEVEL("--all-info");
  printf("line %d\t\t", __LINE__); G_INFO("This is a test (-1)");
  SET_LOGFORMAT("00000000");
  printf("line %d\t\t", __LINE__); G_INFO("This is a test (0)");

  SET_LOGFORMAT("10000000");
  printf("line %d\t\t", __LINE__);  G_INFO("This is a test (1)");

  SET_LOGFORMAT("01000000");
  printf("line %d\t\t", __LINE__);  G_INFO("This is a test (2)");

  SET_LOGFORMAT("00100000");
  printf("line %d\t\t", __LINE__); G_INFO("This is a test (3)");

  SET_LOGFORMAT("00010000");
  printf("line %d\t\t", __LINE__);  G_INFO("This is a test (4)");

  SET_LOGFORMAT("00001000");
  printf("line %d\t\t", __LINE__); G_INFO("This is a test (5)");

  SET_LOGFORMAT("00000100");
  printf("line %d\t", __LINE__); G_INFO("This is a test (6)");

  SET_LOGFORMAT("00000010");
  printf("line %d\t", __LINE__); G_INFO("This is a test (7)");

  SET_LOGFORMAT("00000001");
  printf("line %d\t", __LINE__); G_INFO("This is a test (8)");

 SET_LOGFORMAT("11111111");
  printf("line %d\t", __LINE__); G_INFO("This is a test (9)");


/*
  Less<int> lti;

  vector<int> test1 = {1,2,33,44,55,66,77};
  vector<double> test2 = {1.1,2.23,33.33,44.44,55.55,66.66,77.77 };
  vector<string> test3  {"ole", "dole", "doff", "kinkeliane", "koff" };

  int cnt =  count( 42, test1, lti );
  FORCE_DEBUG("The number of matches was %d", cnt );
  std::stringstream out;

  print_modulo( test1, out , 11);
  print_modulo( test2, out , 11);
  print_modulo( test3, out , 11);
  CERR << out.str()  << ENDL;
*/
}

