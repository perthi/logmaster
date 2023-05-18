// -*- mode: c++ -*-

#ifndef GNUMBERSXXX_H
#define GNUMBERSXXX_H

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/


#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <stdlib.h>     /* strtod */
#include <stdint.h>

#include "GCommon.h"
#include "GString.h"
#include "GTokenizer.h"
#include "GDefinitions.h"
#include "GUtilities.h"
#include "GString.h"

#include "GNumberTypes.h"


using std::hex;
using std::string;
using std::vector;

#define BASE_2  2
#define BASE_8  8
#define BASE_10 10
#define BASE_16 16

#define  BIN(in)  g_numbers()->BinaryString2Number(in)
#define  PAD(in)  g_numbers()->PadOnes(in)


class TestGNumbers_PrivateFunctions_Test; // forward declaration for google test


class GNumbers;

GNumbers API * g_numbers();


/** @brief various function for number to string and string to number manipulations  */
class GNumbers
{
    friend  TestGNumbers_PrivateFunctions_Test;
    friend GNumbers * g_numbers();

public:
    void    API  DisableError();
    void    API  EnableError();
    bool    API  IsDisabledError() { return fIsDisabledError; };
    string  API  Dec2Hex(const string s);
    string  API  Hex2Dec(const string s);

    template<typename T>   int64_t  API  PadOnes(const T in);
    template<typename T> int64_t    API  BitWidth(const T in);
    int64_t                         API  BitWidth(const char* in);
    int64_t                         API  BitWidth(const string in);
    
  
    int64_t		        API     BinaryString2Number(const string num);
    string              API     Number2BinaryString(const uint64_t, const int width = 64, const int shift = 0);
    int64_t             API     HexString2Number(const string num);
    
    template<typename T = long double>     vector<T> API ToFloat(const vector<string> num);
    template<typename T = long double>    T          API ToFloat(const string num);
   // int64_t                  API            ToHex(const string num);
    
    template<typename T =  int64_t>  T      API    ToInteger(const string num);
    template<typename T>   vector<T>            API    ToInteger(const vector<string> num);
    
    template< typename  T >  typename std::enable_if<std::is_integral<T>::value, T>::type 
        API ToNumber(const string num) {return ToInteger<T>(num);}
    
    template< typename  T >  typename std::enable_if< std::is_floating_point <T>::value, T>::type
       API    ToNumber(const string num){return ToFloat<T>(num);}
    
    template <typename T> 
    int API CountBits(const T in);
    
private:
    GNumbers() : fIsDisabledError(false) {};
    ~GNumbers() {};
    template<typename T>   void    API CheckUnsigned(const string num);
    template<typename T>   void    API CheckUnsigned(const vector<string> num);
	bool fIsDisabledError = false;
};


/**@{
 * Checks the signedness of the template parameter T against the number represented by the parameter "num" <br>
 * example1: CheckUnsigned<unsigned int>("-1"); // Throws an exception because T is unsigned whereas num is negative <br>
 * example2: CheckUnsigned<int>("-1"); // OK, num is negative, but T is signed so it can represent a negative number <br>
 * example2: CheckUnsigned<unsigned int>("42"); // OK, T is unsigned, but "num" is positive
 * @tparam T The type to check for signedness
 * @param     num The number on string format eg. "1234"  etc..  (or a vector of strings)
 * @exception std::out_of_range T is an unsigned type, and the number represented by num is negative
 * @exception std::invalid_argument num does not represent a valid number*/
template<typename T>
void GNumbers::CheckUnsigned(const string num)
{
    string message;

    if ( g_number_types()->IsNumber(num) == false)
    {
        message = "\"" + num + "\"" + " is not a number ";
        GCommon().HandleError(message, GLOCATION, IsDisabledError() );
    }

    string tmp = typeid(T).name();

    if( g_string()->BeginsWith(num, "-", false) && g_number_types()->IsUnsignedTypeS( tmp) )
    {

        message = string("Illegal operation, you have tried to convert the unsigned type") + typeid(T).name() + string("to a negative number ");
        GCommon().HandleError(message, GLOCATION, IsDisabledError() );
    }
}


template<typename T>
void GNumbers::CheckUnsigned(const vector<string> num)
{
    for (uint16_t i = 0; i < num.size(); i++)
    {
        CheckUnsigned<T>(num[i]);
    }
}
/**@}*/





template<typename T> T
GNumbers::ToInteger(const string num)
{

    string trimmed = num;
    trimmed = g_string()->Trim(trimmed, { ' ', '\t', '\n' });

    if ( g_number_types()->IsInteger(trimmed) == false && g_number_types()->IsHex(trimmed) == false)
    {

      string message = num + " is NOT an Integer or hex number, aborting, ..";
	    GCommon().HandleError(message, GLOCATION, IsDisabledError() );
    }

    CheckUnsigned<T>(trimmed);
    long long int number = atoll(trimmed.c_str());

    if (g_number_types()->IsHex(trimmed))
    {
        return (T)HexString2Number(trimmed);
    }
    else
    {
        return (T)number;
    }
  }



template<typename T> vector<T>
GNumbers::ToInteger(const vector<string> num)
{
     CheckUnsigned<T>(num);
     vector<T> tmp;
     for (uint16_t i = 0; i < num.size(); i++)
     {
         tmp.push_back(ToInteger<T>(num[i]));
     }
     return tmp;
}



/** Pads the binary representation of "in" with ones, for instance the number 00101101  (0x2d)
 *  will be padded to 00111111  (0x3f)
 *  @tparam int The input number to pad. The template parameter must be of integral type
 *  @return The padded number */
template <typename T>
int64_t
GNumbers::PadOnes(const T in)
{
    int64_t n = BitWidth(in);
    int64_t tmp = (int64_t)in;

    for (int64_t i = 0; i < n; i++)
    {
        tmp = tmp | ((int64_t)1 << i);
    }
    return tmp;
}


template<typename T>
int64_t
GNumbers::BitWidth(const T in)
{
    const int BitWidths = sizeof(in) * 8;
    int pos = 0;

    for (int i = 0; i < BitWidths; i++)
    {
    //    if ((  in & (T)1  <<  i )  != 0 )
        if ((  (int64_t)in & ( (int64_t)1  <<  i ) )  != 0 )
        {
            pos = i;
        }
    }
    return pos;
}


template<typename T>
T
GNumbers::ToFloat(const string num)
{
    T ret = (T)-1;
    string trimmed = num;
    trimmed = g_string()->Trim(trimmed, { ' ', '\t', '\n' });
	trimmed  = g_string()->Replace(trimmed, ",", ".");

    if (( g_number_types()->IsNumber(trimmed) == true) && ( g_number_types()->IsFloat(trimmed) == true))
    {
		ret = (T)std::stod(trimmed);
	}
    else
    {
        string message = "The number:" + num + ":is NOT a number, aborting,..";
         GCommon().HandleError(message, GLOCATION, IsDisabledError() );
    }
    return ret;
}


template<typename T>
vector<T>
GNumbers::ToFloat(const vector<string> num)
{
    vector<T> tmp;

    for (uint16_t i = 0; i < num.size(); i++)
    {
        tmp.push_back(ToFloat<T>(num[i]));
    }
    return tmp;
}


template <typename T> int 
GNumbers::CountBits( const T in )
{
    int64_t tmp = (int64_t)in;
    int cnt = 0;

    for ( int i = 0; i < 64; i++ )
    {
        int64_t mask = 0;
        mask = 1LL << i;
        
        if ( ( mask & tmp ) != 0 )
        {
            cnt++;
        }
    }
    return cnt;
}


#endif

