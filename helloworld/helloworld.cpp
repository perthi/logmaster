// -*- mode: c++ -*-


#ifdef _WIN32
#include <Windows.h>
#endif




//#include <utilities/GSystem.h>
// auto client = std::make_shared<KFClientMain >(argc, argv);
 //       th1 = thread( &KFClientMain::Run, client  );

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

#include <string>
using std::string;

#include <iostream>
using std::endl;
using std::cout;


#include <memory>

#include <iostream> 
#include <string>


int main ()
{

 //  int *test = new int(100);
   std::shared_ptr<int>  test = std::make_shared<int>(222);

/*
   cout << "int = " << *test << endl; 


  std::string str_dec = "2001, A Space Odyssey";
  std::string str_hex = "40c3";
  std::string str_bin = "-10010110001";
  std::string str_auto = "0x7f";

  std::string::size_type sz;   // alias of size_t

  int i_dec = std::stoi (str_dec,&sz);
  int i_hex = std::stoi (str_hex,nullptr,16);
  int i_bin = std::stoi (str_bin,nullptr,2);
  int i_auto = std::stoi (str_auto,nullptr,0);

  std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  std::cout << str_hex << ": " << i_hex << '\n';
  std::cout << str_bin << ": " << i_bin << '\n';
  std::cout << str_auto << ": " << i_auto << '\n';
*/

   int num = -1;
   
   double f = -1;
   
   std::string::size_type sz = 99; 

   try
   {
      //  num = std::stoi("123345blahhhh456", &sz); 
        num = std::stoi("0", &sz); 
       f  = std::stod("3.15");
   }
   catch(const std::exception& e)
   {
      std::cout  <<  string ( e.what() ) << endl; ;
   }
   
   cout << "num = " << num << endl;
    cout << "f = " << f << endl;
   cout << "sz = " << sz << endl;
   



  return 0;
}


