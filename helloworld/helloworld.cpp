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


// template<typename T>
// void print_modulo( const vector<T> & v, std::ostream & os, int m  )
// {
//   for_each( begin(v), end(v),  [&os, m ](auto x) 
//   {
//   // if(x%m == 0) os << x << '\n'; 
//     os << x << '\n'; 
//   } );
// }


template<typename T>
void print_modulo( const vector<T> & v, std::ostream & os, int m  )
{
  auto print =  [&os, m]( T x) {   os << x << " xxxx " << '\n';  };
  for_each( begin(v), end(v), print ); 

}



int main()
{
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

  CERR << out.str()  << endl;

  // char buf[255];
  // for(int i=0; i < 1000; i++)
  // {
  //   sprintf(buf, "Hello%d", i );
  //   FORCE_DEBUG("%s", buf);
  // }
  ///std::this_thread::sleep_for(std::chrono::milliseconds(2000));

}

