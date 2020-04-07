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

class A
{

};

int main()
{
   // string s_cwd(getcwd(NULL,0));
   // cout << "CWD is: " << s_cwd << endl;
  //  cout << "ssdir ="  <<  string(g_system()->GetExeDir()) << endl;;

//   printf("%s\n", get_current_dir_name());
 //   return 0;
    std::shared_ptr<A> a = std::make_shared<A>();



   const A * const a_ptr  = a.get();

    delete a_ptr;

}



