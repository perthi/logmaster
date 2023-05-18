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

#include "TestGNumberTypes.h"
//#include <utilities/GNumbers.h>
#include <utilities/GNumberTypes.h>
#include <utilities/GRandom.h>

#ifdef HAS_LOGGING
#include <logging/LMessageGenerator.h>
#endif



TEST_F(TestGNumberTypes, IsAlphaNumber)
{
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("A")); 
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("Q"));
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("ABC123"));
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("QXC678"));
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("    QXC678"));
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("    QXC678    "));
   EXPECT_TRUE( g_number_types()->IsAlphaNumber("QXC678    "));
   EXPECT_FALSE(g_number_types()->IsAlphaNumber("�"));
   EXPECT_FALSE(g_number_types()->IsAlphaNumber("�"));
   EXPECT_FALSE(g_number_types()->IsAlphaNumber(" ���wxz  "));
   EXPECT_FALSE(g_number_types()->IsAlphaNumber(" � � � �� � 123 345  "));
}


TEST_F(TestGNumberTypes, IsBinary)
{
    EXPECT_TRUE(  g_number_types()->IsBinary("0"));
    EXPECT_TRUE(  g_number_types()->IsBinary("1"));
    EXPECT_TRUE(  g_number_types()->IsBinary("110010110"));
    EXPECT_TRUE(  g_number_types()->IsBinary("   110010110"));
    EXPECT_TRUE(  g_number_types()->IsBinary("110010110   "));
    EXPECT_TRUE(  g_number_types()->IsBinary("     110010110  "));
    EXPECT_TRUE(  g_number_types()->IsBinary("1100101101111111100000111101101010"));
    EXPECT_FALSE( g_number_types()->IsBinary("110210110"));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("0")));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("1")));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("110010110")));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("   110010110")));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("110010110   ")));
    EXPECT_TRUE(  g_number_types()->IsBinary( string("     110010110  ")));
    EXPECT_TRUE(g_number_types()->IsBinary( string("1100101101111111100000111101101010")));
    EXPECT_FALSE(g_number_types()->IsBinary(string("110210110")));
}



TEST_F(TestGNumberTypes, IsDecNumber)
{
    EXPECT_TRUE(  g_number_types()->IsDecNumber("10") );
    EXPECT_TRUE(  g_number_types()->IsDecNumber("9223372036854775807"));
    EXPECT_FALSE( g_number_types()->IsDecNumber("0x10"));
    EXPECT_FALSE( g_number_types()->IsDecNumber("blahhhhh"));
}



TEST_F(TestGNumberTypes, IsInteger)
{
    EXPECT_TRUE(  g_number_types()->IsInteger("9223372036854775807"));
    EXPECT_TRUE(  g_number_types()->IsInteger("-9223372036854775807"));
    EXPECT_TRUE(  g_number_types()->IsInteger("123456789101112131"));
    EXPECT_TRUE(  g_number_types()->IsInteger(string("9223372036854775807")));
    EXPECT_TRUE(  g_number_types()->IsInteger(string("-9223372036854775807")));
    EXPECT_TRUE(  g_number_types()->IsInteger(string("123456789101112131")));
    EXPECT_TRUE(  g_number_types()->IsInteger( 9223372036854775807));
    EXPECT_TRUE(  g_number_types()->IsInteger(-9223372036854775807));
    EXPECT_TRUE(  g_number_types()->IsInteger(123456789101112131));
    EXPECT_FALSE( g_number_types()->IsInteger(1.5));
    EXPECT_FALSE( g_number_types()->IsInteger(1.61803398875));
    EXPECT_TRUE(  g_number_types()->IsInteger("1"));
    EXPECT_TRUE(  g_number_types()->IsInteger("01"));
    EXPECT_TRUE(  g_number_types()->IsInteger("9"));
    EXPECT_TRUE(  g_number_types()->IsInteger(" 9"));
    EXPECT_TRUE(  g_number_types()->IsInteger("     9  "));
    EXPECT_TRUE(  g_number_types()->IsInteger("07"));
    EXPECT_TRUE(  g_number_types()->IsInteger("1234567"));
    EXPECT_TRUE(  g_number_types()->IsInteger("     1234567"));
    EXPECT_TRUE(  g_number_types()->IsInteger("000001234567"));
    EXPECT_TRUE(  g_number_types()->IsInteger("77  "));
    EXPECT_TRUE(  g_number_types()->IsInteger("  77  "));
    EXPECT_TRUE(  g_number_types()->IsInteger("77"));
    EXPECT_FALSE( g_number_types()->IsInteger("1 2"));
    EXPECT_FALSE( g_number_types()->IsInteger("1 2 33 55"));
    EXPECT_FALSE( g_number_types()->IsInteger("Meeny"));
    EXPECT_FALSE( g_number_types()->IsInteger("1.33"));
}



TEST_F(TestGNumberTypes, IsNumber)
{
    EXPECT_TRUE(  g_number_types()->IsNumber("77  ") );
    EXPECT_TRUE(  g_number_types()->IsNumber("1.33") );
    EXPECT_TRUE(  g_number_types()->IsNumber("QXC678") );
    EXPECT_TRUE(  g_number_types()->IsNumber("0xabcd"));
    EXPECT_TRUE(  g_number_types()->IsNumber("   0xdef"));
    EXPECT_TRUE(  g_number_types()->IsNumber("   0xdead   "));
    EXPECT_TRUE(  g_number_types()->IsNumber("   NaN   "));
    EXPECT_FALSE( g_number_types()->IsNumber("lorem ipsum") );

    string tmp = "   0xffff   ";
    EXPECT_TRUE(g_number_types()->IsNumber(tmp));

    EXPECT_TRUE(g_number_types()->IsNumber("10000"));

}



TEST_F(TestGNumberTypes, NSR1033)
{
    EXPECT_TRUE(g_number_types()->IsNumber("10000\n"));
    EXPECT_TRUE(g_number_types()->IsNumber("10000\t\t"));
    EXPECT_TRUE(g_number_types()->IsNumber("10000 \t\t \n"));
    EXPECT_TRUE(g_number_types()->IsNumber("\t10000 \t\t \n"));
    EXPECT_TRUE(g_number_types()->IsNumber("\t\n10000 \t\t \n"));
    EXPECT_TRUE(g_number_types()->IsNumber("\t \n 10000 \t\t \n"));
    EXPECT_TRUE(g_number_types()->IsInteger("1234567 \t \n"));
    EXPECT_TRUE(g_number_types()->IsAlphaNumber("QXC678   \n "));
    EXPECT_TRUE(g_number_types()->IsFloat("3.14159265359\t"));
    EXPECT_TRUE(g_number_types()->IsFloat("3.14159265359\n"));
    EXPECT_TRUE(g_number_types()->IsFloat("3.14159265359\t\n"));
    EXPECT_DOUBLE_EQ(1.7976931348623158e+308, g_numbers()->ToFloat("1.7976931348623158e+308\n"));
    vector<string> int_array = { "0xa\n", "0Xabc\t", "0x12bc  ", "123     \n" };
    vector<long long int> num = g_numbers()->ToInteger< long long int >(int_array);
    EXPECT_EQ(0xa, num[0]);
    EXPECT_EQ(0xabc, num[1]);
    EXPECT_EQ(0x12bc, num[2]);
    EXPECT_EQ(123, num[3]);
}



TEST_F(TestGNumberTypes, IsFloat)
{
    EXPECT_TRUE(  g_number_types()->IsFloat("123456789101112131"));
    EXPECT_FALSE( g_number_types()->IsInteger("3.14"));
    EXPECT_FALSE( g_number_types()->IsInteger("   3.14  "));
    EXPECT_TRUE(  g_number_types()->IsFloat("3.14159265359"));
    EXPECT_TRUE(  g_number_types()->IsFloat("      3.14159265359"));
    EXPECT_TRUE(  g_number_types()->IsFloat("3.14159265359      "));
    EXPECT_TRUE(  g_number_types()->IsFloat("   3.14159265359   "));
    EXPECT_TRUE(  g_number_types()->IsFloat("-3.14159265359      "));
    EXPECT_TRUE(  g_number_types()->IsFloat("   -3.14159265359   "));
    EXPECT_TRUE(  g_number_types()->IsFloat("nan"));

    string goldencut = "  1.618033989   ";
    EXPECT_TRUE(  g_number_types()->IsFloat(goldencut));
    EXPECT_TRUE(  g_number_types()->IsFloat(goldencut.c_str() ));
    EXPECT_TRUE(  g_number_types()->IsFloat("1.7976931348623158e+308" ));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("123456789101112131")));
    EXPECT_FALSE( g_number_types()->IsInteger( string("3.14")) );
    EXPECT_FALSE( g_number_types()->IsInteger( string("   3.14  ")));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("3.14159265359") ));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("      3.14159265359")));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("3.14159265359      ")));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("   3.14159265359   ")));
    EXPECT_TRUE(  g_number_types()->IsFloat( string("-3.14159265359      ")));
    EXPECT_TRUE(  g_number_types()->IsFloat(string("   -3.14159265359   ")));
    EXPECT_TRUE(  g_number_types()->IsFloat(string("   -3,14159265359   ")));
    EXPECT_TRUE(  g_number_types()->IsFloat(string( "1.7976931348623158e+308")));
    EXPECT_TRUE(  g_number_types()->IsFloat(1.61803398875));
    EXPECT_TRUE(  g_number_types()->IsFloat(-1.61803398875));
    EXPECT_TRUE(  g_number_types()->IsFloat(9223372036854775807));
    EXPECT_TRUE(  g_number_types()->IsFloat(-1));
    EXPECT_TRUE(  g_number_types()->IsFloat( 1.7976931348623158e+308));
}



TEST_F(TestGNumberTypes, IsType)
{
    float   f1 = 0;
    double  f2 = 0;
    long  double f3 = 0;
    short i1 = 0;
    int i2 = 0;
    long int i3 = 0;
    long long int i4 = 0;
    unsigned short i5 = 0;
    unsigned  int i6 = 0;
    unsigned long int i7 = 0;
    unsigned  long long int i8 = 0;


    EXPECT_FALSE( g_number_types()->IsUnsignedType(f1));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(f2));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(f3));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(i1));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(i2));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(i3));
    EXPECT_FALSE( g_number_types()->IsUnsignedType(i4));
    EXPECT_TRUE(  g_number_types()->IsUnsignedType(i5));
    EXPECT_TRUE(  g_number_types()->IsUnsignedType(i6));
    EXPECT_TRUE(  g_number_types()->IsUnsignedType(i7));
    EXPECT_TRUE(  g_number_types()->IsUnsignedType(i8));
    EXPECT_TRUE(  g_number_types()->IsFloatType(f1));
    EXPECT_TRUE(  g_number_types()->IsFloatType(f2));
    EXPECT_TRUE(  g_number_types()->IsFloatType(f3));
    EXPECT_FALSE( g_number_types()->IsFloatType(i1));
    EXPECT_FALSE( g_number_types()->IsFloatType(i2));
    EXPECT_FALSE( g_number_types()->IsFloatType(i3));
    EXPECT_FALSE( g_number_types()->IsFloatType(i4));
    EXPECT_FALSE( g_number_types()->IsFloatType(i5));
    EXPECT_FALSE( g_number_types()->IsFloatType(i6));
    EXPECT_FALSE( g_number_types()->IsFloatType(i7));
    EXPECT_FALSE( g_number_types()->IsFloatType(i8));
    EXPECT_TRUE(  g_number_types()->IsFloatType(100.0));
    EXPECT_FALSE( g_number_types()->IsFloatType(100));
    EXPECT_FALSE( g_number_types()->IsIntegerType(f1));
    EXPECT_FALSE( g_number_types()->IsIntegerType(f2));
    EXPECT_TRUE(  g_number_types()->IsFloatType(f3));


    EXPECT_TRUE( g_number_types()->IsIntegerType(i1));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i2));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i3));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i4));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i5));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i6));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i7));
    EXPECT_TRUE( g_number_types()->IsIntegerType(i8));
    EXPECT_FALSE(g_number_types()->IsFloatType(string("0xabcd")));
}



TEST_F(TestGNumberTypes, IsFundamentalType)
{
    int i = 0;
    EXPECT_TRUE(g_number_types()->IsFundamentalType(i));
    string t = typeid(i).name();
    EXPECT_TRUE(g_number_types()->IsFundamentalTypeS(string(t.c_str())));
}



TEST_F(TestGNumberTypes, IsVType)
{
    vector<char>          vi1;
    vector<short>         vi2;
    vector<int>           vi3;
    vector<long int>      vi4;
    vector<long long int> vi5;
    vector<unsigned char>     vi6;
    vector<unsigned short>    vi7;
    vector<unsigned int>      vi8;
    vector<unsigned long int> vi9;
    vector<unsigned long long int> vi10;
    vector<float>   vf1;
    vector<double>  vf2;
    vector<long double>  vf3;

    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi1));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi2));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi3));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi4));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi5));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi6));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi7));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi8));
    EXPECT_TRUE( g_number_types()->IsIntegerVType(vi9));
    EXPECT_FALSE(g_number_types()->IsIntegerVType(vf1));
    EXPECT_FALSE(g_number_types()->IsIntegerVType(vf2));
    EXPECT_FALSE(g_number_types()->IsIntegerVType(vf3));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi1));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi2));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi3));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi4));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi5));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi6));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi7));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi8));
    EXPECT_FALSE(g_number_types()->IsFloatVType(vi9));
    EXPECT_TRUE( g_number_types()->IsFloatVType(vf1));
    EXPECT_TRUE( g_number_types()->IsFloatVType(vf2));
    EXPECT_TRUE( g_number_types()->IsFloatVType(vf3));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi1));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi2));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi3));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi4));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi5));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi6));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi7));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi8));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vi9));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vf1));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vf2));
    EXPECT_TRUE( g_number_types()->IsFundamentalVType(vf3));
}


TEST_F(TestGNumberTypes, IsDigit)
{
    EXPECT_TRUE(  g_number_types()->IsDigit(0));
    EXPECT_FALSE( g_number_types()->IsDigit("42"));
    EXPECT_FALSE( g_number_types()->IsDigit(" 42"));
    EXPECT_FALSE( g_number_types()->IsDigit(" 42   "));
    EXPECT_FALSE( g_number_types()->IsDigit("0.5"));
    EXPECT_FALSE( g_number_types()->IsDigit("3.14159265359"));
    EXPECT_TRUE(  g_number_types()->IsDigit("4"));
    EXPECT_TRUE(  g_number_types()->IsDigit(" 4"));
    EXPECT_TRUE(  g_number_types()->IsDigit(" 4   "));
    EXPECT_FALSE( g_number_types()->IsDigit("x"));
    EXPECT_FALSE( g_number_types()->IsDigit("xyz"));
    EXPECT_FALSE( g_number_types()->IsDigit("lorem ipsum"));
    EXPECT_FALSE( g_number_types()->IsDigit(42));
    EXPECT_FALSE( g_number_types()->IsDigit(1.2345));
    EXPECT_FALSE( g_number_types()->IsDigit(3.14159265359) );

    short ri =  g_random()->Uniform<short>(10, 100);
    double rd = g_random()->Uniform<double>(10, 100);

    EXPECT_FALSE( g_number_types()->IsDigit(ri)); 
    EXPECT_FALSE(g_number_types()->IsDigit(rd));

    for (int i = 10; i < 100; i++)
    {
        EXPECT_FALSE(g_number_types()->IsDigit(i));
    }
 
  //  Test some other bases also, for instance base 2, 8, 16
    vector<int> bases = { BASE_2, BASE_8, BASE_10, BASE_16 };
    for (unsigned int i = 0; i < bases.size(); i++)
    {
        for (int j = 0; j < bases[i]; j++)
        {
            EXPECT_TRUE(g_number_types()->IsDigit(j, bases[i]));
        }
    }
    
    EXPECT_TRUE(  g_number_types()->IsDigit("1", BASE_2)); 
    EXPECT_TRUE(  g_number_types()->IsDigit("0", BASE_2));
    EXPECT_FALSE( g_number_types()->IsDigit("3", BASE_2));
    EXPECT_FALSE( g_number_types()->IsDigit("6", BASE_2));
    EXPECT_FALSE( g_number_types()->IsDigit("9", BASE_2));
    EXPECT_TRUE(  g_number_types()->IsDigit("3", BASE_8));
    EXPECT_TRUE(  g_number_types()->IsDigit("7", BASE_8));
    EXPECT_FALSE( g_number_types()->IsDigit("8", BASE_8));
    EXPECT_FALSE( g_number_types()->IsDigit("9", BASE_8));
    EXPECT_FALSE( g_number_types()->IsDigit("f", BASE_8));
    EXPECT_TRUE(  g_number_types()->IsDigit("1", BASE_16));
    EXPECT_TRUE(  g_number_types()->IsDigit("7", BASE_16));
    EXPECT_TRUE(  g_number_types()->IsDigit("d", BASE_16));
    EXPECT_TRUE(  g_number_types()->IsDigit("e", BASE_16));
    EXPECT_TRUE(  g_number_types()->IsDigit("f", BASE_16));
    EXPECT_TRUE(  g_number_types()->IsDigit("f", BASE_16));
  }
  



TEST_F(TestGNumberTypes, IsHex) 
{
  // EXPECT_TRUE(g_numbers()->IsHex("0xffffff\n"));
   EXPECT_TRUE(  g_number_types()->IsHex("0x0"));
   EXPECT_FALSE( g_number_types()->IsHex("0x"));
   EXPECT_TRUE(  g_number_types()->IsHex("0xabcd"));
   EXPECT_TRUE(  g_number_types()->IsHex("   0xabcd"));
   EXPECT_TRUE(  g_number_types()->IsHex("0Xabcd"));
   EXPECT_TRUE(  g_number_types()->IsHex("   0Xabcd"));
   
   string test = "0x123abc";
   EXPECT_TRUE( g_number_types()->IsHex(test));
   EXPECT_TRUE( g_number_types()->IsHex(test.c_str() ));
   EXPECT_TRUE( g_number_types()->IsHex("0xabcd    "));
   EXPECT_TRUE( g_number_types()->IsHex("  0x12cf  "));
   EXPECT_TRUE( g_number_types()->IsHex("0x7FFFFFFFFFFFFFFF"));
   EXPECT_TRUE( g_number_types()->IsHex(string("0x0")));
   EXPECT_FALSE(g_number_types()->IsHex(string("0x")));
   EXPECT_TRUE( g_number_types()->IsHex(string("0xabcd")));
   EXPECT_TRUE( g_number_types()->IsHex(string("   0xabcd")));
   EXPECT_TRUE( g_number_types()->IsHex(string("0xabcd    ")));
   EXPECT_TRUE( g_number_types()->IsHex(string("  0x12cf  ")));
   EXPECT_TRUE( g_number_types()->IsHex(string("0x7FFFFFFFFFFFFFFF")));
   EXPECT_TRUE( g_number_types()->IsHex("-0x0"));
   EXPECT_FALSE(g_number_types()->IsHex("-0x"));
   EXPECT_TRUE( g_number_types()->IsHex("-0xabcd"));
   EXPECT_TRUE( g_number_types()->IsHex("   -0xabcd"));
   EXPECT_TRUE( g_number_types()->IsHex("-0xabcd    "));
   EXPECT_TRUE( g_number_types()->IsHex("  -0x12cf  "));
   EXPECT_TRUE( g_number_types()->IsHex("-0x7FFFFFFFFFFFFFFF"));
   EXPECT_TRUE( g_number_types()->IsHex(0x0));
   EXPECT_TRUE( g_number_types()->IsHex(0x3) );
   EXPECT_TRUE( g_number_types()->IsHex(100));
   EXPECT_TRUE( g_number_types()->IsHex(200));
   EXPECT_TRUE( g_number_types()->IsHex(0xabcd));
   EXPECT_TRUE( g_number_types()->IsHex(9223372036854775807));
   EXPECT_FALSE(g_number_types()->IsHex(1.4));
   EXPECT_FALSE(g_number_types()->IsHex(3.14));
   EXPECT_FALSE(g_number_types()->IsHex("abc0x4bc"));
   EXPECT_FALSE(g_number_types()->IsHex("lorem ipsum"));
   EXPECT_FALSE(g_number_types()->IsHex("Meeny"));
}



#ifdef HAS_LOGGING
TEST_F(TestGNumberTypes, NSR1988DisableError)
{    
    
    #undef G_STANDALONE
    EXPECT_ANY_THROW( g_numbers()->ToNumber<float>("blahhhh") );
    GException::DisableException();
    g_numbers()->DisableError();
    EXPECT_NO_THROW(  g_numbers()->ToNumber<float>("blahhhh") );
    g_numbers()->DisableError();
    EXPECT_NO_THROW(g_numbers()->ToNumber<float>("blahhhh"));
    EXPECT_NO_THROW(g_numbers()->ToHex("blahhhh"));
    EXPECT_NO_THROW(g_numbers()->BinaryStringToNumber("blahhhh"));
    g_numbers()->EnableError();
    GException::EnableException();
}
#endif
