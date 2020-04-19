// -*- mode: c++ -*-
#include "LGeneratorEnum.h"
#include <configurator/LXmlEntitySubSystem.h>
#include <utilities/GUtilities.h>
#include <utilities/GString.h>
#include <sstream>

#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <bitset>


LGeneratorEnum::LGeneratorEnum( const string fname ) : LGenerator( fname )
{

}


LGeneratorEnum::~LGeneratorEnum()
{

}


vector<string>  
 LGeneratorEnum::Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  /*levels*/,
	                        vector< std::shared_ptr<LXmlEntitySubSystem > >  /*systems*/ ) const
{
    vector<string> lines;

    //for(auto sys: systems )
    for( int i =0; i < 12; i ++ )
    {
      //  FORCE_DEBUG("sys = %s, \thex = \t%s\tbitmask = %s", sys->fName.c_str(),  ToHexString( 1 << i ).c_str(),  ToBinaryString( 1 << i ).c_str()   );
        FORCE_DEBUG("\thex = \t%s\tbitmask = %s (i =%d)", ToHexString( 1 << i ).c_str(),  ToBinaryString( 1 << i ).c_str(), i   );
    }

    return lines;
}


string 
LGeneratorEnum::ToHexString(int num ) const
{
    //std::bitset<16> x(num);
    std::stringstream buffer;
    buffer << "0x" <<  std::hex <<  std::setw(4)  << std::setfill('0') << num;
    return buffer.str();

}


string 
LGeneratorEnum::ToBinaryString(int num ) const
{
    int upper = (num & 0xff00) >> 8;
    int lower = num & 0x00ff;

    std::bitset<8> x1(upper);
    std::bitset<8> x2(lower);
    std::stringstream buffer1;
    buffer1 << x1 << " "<< x2 << std::setfill('0');
    return buffer1.str();
}