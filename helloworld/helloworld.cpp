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

#include <exception/GException.h>
#include <exception>

using namespace LOGMASTER;


#include <logging/LPublisher.h>



int main ()
{
   SET_LOGFORMAT("00000001");
    FORCE_DEBUG("This is a test");
    
    cout << LDoc::Instance()->Help() << endl;
    
    return 0;

}




///std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr<LMessage> > >  Ge
