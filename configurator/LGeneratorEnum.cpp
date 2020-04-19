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
	                        vector< std::shared_ptr<LXmlEntitySubSystem > >   systems ) const
{
    vector<string> lines;
    lines.push_back("// -*- mode: c++ -*-/n/n");
    lines.push_back("#pragma once\n\n");
    lines.push_back(" #ifdef __cplusplus");
    lines.push_back("enum class " + fSystemEnumName);
    lines.push_back("#else");
    lines.push_back("enum  " + fSystemEnumName);
    lines.push_back("#endif");
    lines.push_back(" {");
    lines.push_back("\tSYS_NONE\t\t=  0x0000,    //  00000000 00000000    No sub system");
    lines.push_back("\tSYS_EX\t\t\t=  0x0001,    //  00000000 00000001    The exeption handling sub system");
    lines.push_back("\tSYS_USER\t\t=  0x0002,    //  00000000 00000010    User messages");
    lines.push_back("\tSYS_GENERAL\t\t=  0x0004,    //  00000000 00000100    No specific sub system (i.e general message)");

    int i = 4;

    for(auto sys: systems )
    //for( int i =0; i < 12; i ++ )
    {
        
      //   FORCE_DEBUG("sys = %s, \thex = \t%s\tbitmask = %s", sys->fName.c_str(),  ToHexString( 1 << i ).c_str(),  ToBinaryString( 1 << i ).c_str()   );
      //   FORCE_DEBUG("\thex = \t%s\tbitmask = %s (i =%d)", ToHexString( 1 << i ).c_str(),  ToBinaryString( 1 << i ).c_str(), i   );
        string line =   g_utilities()->TabAlign("\tSYS_" +  sys->fName + " ", 3 )  + "=  " + ToHexString( 1 << i ) +   ",    //  " + ToBinaryString( 1 << i ); 
        lines.push_back(line);
        i ++;
    }

    lines.push_back("\tSYS_ALL\t\t\t=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)");
    lines.push_back("};");

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