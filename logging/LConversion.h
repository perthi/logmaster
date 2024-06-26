// -*- mode: c++ -*-
#pragma once


/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
*****************************************************************************/


#include  "LDefinitions.h"
#include  "LEnums.h"

#include  <utilities/GNumbers.h>
#include  <utilities/GNumberTypes.h>
#include  <utilities/GDefinitions.h>


#include  <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_map>
#include <map>


using namespace LOGMASTER;

using target_info = vector<std::pair<eMSGTARGET, string> > ;

namespace LOGMASTER
{
    class LHashMaps;

    /** Helper class that converts from strings to the
    *  corresponding internal representation eMSGFORMAT, eMSGTARGET, eLOGLEVEL, eMSGSYSTEM enumerators
    *  This class is used by the logging system when converting string values
    *  applied either from the code or form the command line to configure
    *  the logging systems.*/
    class LConversion
    {
    public:      
        static eMSGFORMAT API String2Format(   const  string  &in );
        static eMSGTARGET API String2Target(   const  string  &in );
        static eLOGLEVEL  API String2Level(    const  string  &in );
        static eMSGSYSTEM API String2System(   const  string  &in );

        static eMSGSYSTEM API Hash2System(  const  string  &in );
        static eLOGLEVEL  API Hash2Level(   const  string  &in );
        static eMSGTARGET API Hash2Target(  const  string  &in );
        static eMSGFORMAT API Hash2Format(  const  string  &in );

        static eMSGSYSTEM API BinaryString2System(  const  string  &in );
        static eLOGLEVEL  API BinaryString2Level(   const  string  &in );
        static eMSGTARGET API BinaryString2Target(  const  string  &in );
        static eMSGFORMAT API BinaryString2Format(  const  string  &in );

        static eMSGSYSTEM API HexString2System(  const  string  &in );
        static eLOGLEVEL  API HexString2Level(   const  string  &in );
        static eMSGTARGET API HexString2Target( const string &in );
        static eMSGFORMAT API HexString2Format( const string &in );

        static target_info API SplitByTarget(const string in);
        
        static void  CheckWidth( const string &in, const int widt );

        template<typename T> T
            static API String2Enum( const string &in, const int pos, const int width );
    };


    /** Converts a string to an enum which can be either  eMSGSYSTEM, eLOGLEVEL, eMSGTARGET or eMSGFORMAT   
     * @tparam T  The enum type to convert to
     * @param[in] in The string to convert. The string must be either on hex or binary format
     * @param[in] pos he position of the bits. For instance if pos = 8 then the least significant 8 bit after conversion
     * will be discarded, and the bit filed shifted 8 places to the right.
     * @param[in] width The number of bits of the number is a bit field */
    template<typename T>
    inline T
        LConversion::String2Enum( const string & in, const int pos, const int width )
    {
        int64_t tmp  = 0;
        int64_t mask = 0;

        mask = PAD( (1LL << (pos + width - 1)) );

        if ( g_number_types()->IsBinary( in ) )
        {
            tmp = g_numbers()->BinaryString2Number( in );
        }
        else if ( g_number_types()->IsHex( in ) )
        {
            tmp = g_numbers()->HexString2Number( in );
        }
        else
        {
            std::stringstream buffer;

            buffer << "The function takes either a binary number containing zero and ones or a hex number staring with 0x" << in << " is neither";
            #ifdef _WIN32
            throw(std::exception( buffer.str().c_str() ));
            #else
            throw(std::invalid_argument( buffer.str().c_str() ));
            #endif
            
        }
        tmp = tmp >> pos;
        tmp = tmp & mask;
        return (T)tmp;
    }
    

}
