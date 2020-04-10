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


enum class e
{
   ONE = 1,
   TWO = 10,
   TREE = 1,
   FOUR = 2
};


class A
{

};


int main()
{
   cout << "ONE = "  << (int)e::ONE << endl;
   cout << "TWO = "  << (int)e::TWO << endl;
   cout << "TREE = " << (int)e::TREE << endl;
   cout << "FOUR = " << (int)e::FOUR << endl;

   auto test = e::ONE;

//    switch (  test )
//    {
//    case e::ONE:
//       cout << "ONE" << endl;
//       break;
//    case e::TWO:
//       cout << "TWO" << endl;
//       break;
//      case e::TREE:
//       cout << "TWO" << endl;
//       break;
//   case e::FOUR:
//       cout << "TWO" << endl;
//       break;
//    default:
//       break;
//    }

   return 0;
   // string s_cwd(getcwd(NULL,0));
   // cout << "CWD is: " << s_cwd << endl;
  //  cout << "ssdir ="  <<  string(g_system()->GetExeDir()) << endl;;

//   printf("%s\n", get_current_dir_name());
 //   return 0;
    std::shared_ptr<A> a = std::make_shared<A>();



   const A * const a_ptr  = a.get();

    delete a_ptr;

}



