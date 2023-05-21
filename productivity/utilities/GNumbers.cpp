// -*- mode: c++ -*-

/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/


#include "GNumbers.h"
#include "GNumberTypes.h"

#include <sstream>
#include <bitset>
#include <format>

//#ifndef GNUMBERSXXX_CPP
//#define GNUMBERSXXX_CPP



GNumbers * g_numbers()
{
    static GNumbers *instance = new GNumbers();
    return instance;
}


void
GNumbers::DisableError()
{
    fIsDisabledError = true;
}


void
GNumbers::EnableError()
{
    fIsDisabledError = false;
}


/**
* Converting a number on hexadecimal form represented as a string into
* the same number written on decimal base 10 format (also represented as a string)
* @param str Input string on hex format. NB it must start with either 0x or 0X succeed
* with a valid sequence of hex digits (0-F) otherwise and exception will be thrown.
* @return The input number on decimal base 10 format. */
 string
GNumbers::Hex2Dec(const string  str)
{
    std::stringstream buffer;
    long long int     num = HexString2Number(str);
    buffer << num;
    return buffer.str();
}


/**
* Converting a number on decimal from (base 10) form represented as a string into
* the same number written on hexadecimal format (also represented as a string)
* @param str Input string on DEC format.
* with a valid sequence of hex digits (0-F) otherwise and exception will be thrown.
* @return The input number on hexadecimal form. */
string
GNumbers::Dec2Hex(const string  str)
{
    std::stringstream buffer;
    if ( g_number_types( )->IsHex(str) == true)
    {
        string message = str + " is not a decimal number, it is a HEX number, but this function converts from dec to hex";
        GCommon().HandleError ( message, GLOCATION, IsDisabledError());
        return "";
    }
    else
    {
        long long int     num = ToInteger<long long int>(str);
        buffer << std::hex << "0x" << num;
    }
    return buffer.str();
}



/**@{
 /** Converts a number to a binary/hex string representation
 * @param number The number that will be represented as a binary/hex string
 * @widt The number of digits in the string, regardless of the value of "num".
 * The string will be padded with zeros. The default width is 64 bits.
 * @param shift The number will be shifted (to the left) by this number of
 * bits. The default is no shift.
 * @return The binary representation of the string */
 string
     GNumbers::Number2BinaryString(const uint64_t number, const int width, const int shift)
 {

     auto num_l = (number << shift);
     /** @todo warn or throw exception if overflow after bit shifting */

     if ( width <= 64 && width > 0 )
     {
         std::bitset<64> num(num_l);
         std::stringstream buffer;
         buffer << num << std::setfill('0');

         return  buffer.str( ).substr(64 - width);
     }
     else
     {
         return std::format("{:b}", num_l);
     }
 }


 //unsigned char a = -58;
 //std::cout << std::format("{:b}", a);

 string    
 GNumbers::Number2HexString(const uint64_t number, const int width, const int shift)
 {
     /** @todo warn or throw exception if overflow after bit shifting */
     int64_t num = shift > 0 ?  (number << shift) : number;
     std::stringstream buffer;
     if (width > 0)
     {
         buffer << std::setfill('0') << std::setw(width);
     }

     buffer << std::hex << num;
    
     return buffer.str();
 }

 /*
 stream << std::setfill('0') << std::setw(sizeof(your_type) * 2)
     << std::hex << your_int;
     */


 /**@}


 /**@{
/* @brief Converts a binary/hex number string to a 64 bits integer. The string is interpreted assuming radix 2 (i.e binary)
*  @param[in] b  The string to convert
*  @return the corresponding number as a 64 bit int
*  @exception GException  if the system dependent maximum  number if bits is exceeded, or if the string has wrong format. Ths is,
*  not valid binary string format containing 0'oes and 1'nes, and/or an optional preceding minus sign. */
 int64_t
GNumbers::BinaryString2Number(const string b)
{
    string s = b;
    g_string()->Trim(s);
    bool negative = g_string()->BeginsWith(s, "-", false);
    int64_t tmp = 0;
    int64_t maxbits = sizeof(long long) * 8;
    int64_t BitWidths = BitWidth(s);

    if (BitWidths > maxbits)
    {
        char message[512];
        #ifdef ARM
        snprintf(message, 512,"Bit-stream contains %lld bits, ( bit-string = %s ). The max number of bits is: %lld", BitWidths, b.c_str(), maxbits);
#endif
#ifdef _WIN32
        SPRINTF(message, 512,"Bit-stream contains %lld bits, ( bit-string = %s ). The max number of bits is: %lld", BitWidths, b.c_str(), maxbits);
#else
#ifdef ARM

        SPRINTF(message, 512, "Bit-stream contains %lld bits, ( bit-string = %s ). The max number of bits is: %lld", BitWidths, b.c_str(), maxbits);
#else
        SPRINTF(message, 512, "Bit-stream contains %ld bits, ( bit-string = %s ). The max number of bits is: %ld", BitWidths, b.c_str(), maxbits);
#endif
#endif
        GCommon().HandleError(message, GLOCATION, IsDisabledError() );
    }

    if ( g_number_types()->IsBinary(s) == true)
    {
        size_t n = s.size();
        for (size_t i = 0; i < n; i++)
        {
            if (s[n - i - 1] == '1')
            {
#ifdef _WIN32
                tmp = tmp | (1i64 << i);
#else
                tmp = tmp | (1 << i);
#endif
            }
        }
    }
    else
    {
        string message = s + "\t is not a binary number string, the string must contain only ZERO and ONES prefixed by an optional - (minus) sign";
        GCommon().HandleError( message, GLOCATION, IsDisabledError() );
    }
    return negative == true ?  -tmp : tmp;
}
 

 int64_t
 GNumbers::HexString2Number(const string num)
 {
     string s = num;
     g_string()->Trim(s);
     if (g_number_types()->IsHex(s))
     {
         return stoull(s, 0, 16);
     }
     else
     {
         string message = s + " is NOT a valid hex number string, please make sure that the number starts with 0x followed by valid hex digits(0 - F)";
         GCommon().HandleError(message, GLOCATION, IsDisabledError());
     }
     return -99999; // Never reached, but just in case
 }
 /**@}


/**@{
* Evaluates the width of the binary number "in" represented on string format in number of bits.
* For example "0010101" is 5 bits wide (discarding proceeding zeros), "111" is 3 bits wide, etc
* @param[in] in Must be a binary number, i.e  a string containing only "0" and "1".
* @exception std::exception if the string "in" is not a valid binary number
* @return The width in number of bits */
int64_t
GNumbers::BitWidth(const char *in)
{
    return BitWidth(string(in));
}

int64_t
GNumbers::BitWidth(const string in)
{
    int64_t npos = 0;

    if (  g_number_types()->IsBinary(in) == false)
    {
        string message = in + "%is not a valid binary number: The string must contain only zeros and ones, and start with a b";
        GCommon().HandleError(message, GLOCATION, IsDisabledError() );
        return -1;
    }
    else
    {
        npos = in.size() - in.find_first_of('1');
        return npos;
    }
}
/**@}*/

