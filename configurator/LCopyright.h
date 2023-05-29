// -*- mode: c++ -*-
#ifndef LGENERATORCOPYRIGHT_H
#define LGENERATORCOPYRIGHT_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LDefinitions.h"



#include <string>
using std::string;


namespace CONFIGURATOR
{
    class  LXMLInfo;

    class  LCopyright
    {
    public:
        LCopyright() = default;
        virtual ~LCopyright() = default;
        static string long_version(LXMLInfo info);
        static string short_version(LXMLInfo info);
       

    private:
        static string common(const LXMLInfo info);

    };

}

#endif
