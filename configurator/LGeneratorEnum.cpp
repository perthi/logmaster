// -*- mode: c++ -*-
#include "LGeneratorEnum.h"
#include <configurator/LXmlEntitySubSystem.h>

#include <utilities/GUtilities.h>
#include <utilities/GString.h>

#include <sstream>


#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <bitset>
LGeneratorEnum::LGeneratorEnum()
{

}


LGeneratorEnum::~LGeneratorEnum()
{

}


vector<string>   
LGeneratorEnum::Generate( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems   ) const
{
    vector<string> lines;

    int i = 1;

    for(auto sys: systems )
    {

        FORCE_DEBUG("sys = %s, \tbitmask = \t%s", sys->fName.c_str(),  ToHexString( 1 << i ).c_str()  );

        i ++;
    }

    return lines;
}


string 
LGeneratorEnum::ToHexString(int num ) const
{
    //std::bitset<16> x(num);
    std::stringstream buffer;
    buffer << std::hex << num;
    return buffer.str();

}

// char a = -58;    
// std::bitset<8> x(a);
// std::cout << x << '\n';

// short c = -315;
// std::bitset<16> y(c);
// std::cout << y << '\n';