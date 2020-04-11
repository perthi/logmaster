// -*- mode: c++ -*-
#ifndef LCONFIGURATOR_H
#define LCONFIGURATOR_H


/***************************************************
* @copyright Embedded Consulting                   *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <string>
using std::string;

class  LConfigurator
{
public:
    LConfigurator();
    virtual ~LConfigurator();
    void Dump( const string xml );
};

#endif
