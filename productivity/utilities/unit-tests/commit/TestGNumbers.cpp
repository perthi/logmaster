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

#include "TestGNumbers.h"
#include <utilities/GNumbers.h>
#include <utilities/GNumberTypes.h>
#include <utilities/GRandom.h>

#ifdef HAS_LOGGING
#include <logging/LMessageGenerator.h>
#endif




TEST_F(TestGNumbers, count_ones)
{
    EXPECT_EQ( 0, g_numbers()->CountBits(0) );
    EXPECT_EQ( 1, g_numbers()->CountBits(0x1) );
    EXPECT_EQ( 1, g_numbers()->CountBits(0x2) );
    EXPECT_EQ( 2, g_numbers()->CountBits(0x3) );
    EXPECT_EQ( 5, g_numbers()->CountBits(181) );
    EXPECT_EQ( 9, g_numbers()->CountBits(14579) );
}


TEST_F(TestGNumbers, Dec2Hex)
{
    EXPECT_EQ( "0xa", g_numbers()->Dec2Hex("10") );
    EXPECT_EQ("0xabcdef", g_numbers()->Dec2Hex("11259375"));
    EXPECT_ANY_THROW( g_numbers()->Dec2Hex("notanumber") );
    EXPECT_ANY_THROW(g_numbers()->Dec2Hex("0xabc"));
}


TEST_F(TestGNumbers, Hex2Dec)
{
    EXPECT_EQ("11259375", g_numbers()->Hex2Dec("0xabcdef"));
    EXPECT_EQ("10", g_numbers()->Hex2Dec("0xa"));
    EXPECT_ANY_THROW(g_numbers()->Hex2Dec("notanumber"));
    EXPECT_ANY_THROW(g_numbers()->Hex2Dec("2748"));
}


TEST_F(TestGNumbers, Hex2DecDec2Hex)
{
    EXPECT_EQ("11259375", g_numbers()->Hex2Dec(g_numbers()->Dec2Hex("11259375")));
    EXPECT_EQ("300", g_numbers()->Hex2Dec(g_numbers()->Dec2Hex("300")));
    EXPECT_EQ("123456789", g_numbers()->Hex2Dec(g_numbers()->Dec2Hex("123456789")));

    EXPECT_EQ("0x300", g_numbers()->Dec2Hex(g_numbers()->Hex2Dec("0x300")));
    EXPECT_EQ("0xdead", g_numbers()->Dec2Hex(g_numbers()->Hex2Dec("0xdead")));
    EXPECT_EQ("0xdeaddead", g_numbers()->Dec2Hex(g_numbers()->Hex2Dec("0xdeaddead")));
}




TEST_F(TestGNumbers, IsAlphaNumber)
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


TEST_F(TestGNumbers, IsBinary)
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



TEST_F(TestGNumbers, number2binary_widt)
{
    auto num_s = g_numbers()->Number2BinaryString(1);
    EXPECT_EQ(num_s, "0000000000000000000000000000000000000000000000000000000000000001");
    num_s = g_numbers( )->Number2BinaryString(1, 32);
    EXPECT_EQ(num_s, "00000000000000000000000000000001");
    
    num_s = g_numbers( )->Number2BinaryString(1, 24);
    EXPECT_EQ(num_s, "000000000000000000000001");

    num_s = g_numbers( )->Number2BinaryString(1,16);
    EXPECT_EQ(num_s, "0000000000000001");
    
    num_s = g_numbers( )->Number2BinaryString(1, 8);
    EXPECT_EQ(num_s, "00000001");


    num_s = g_numbers( )->Number2BinaryString(17);
    EXPECT_EQ(num_s, "0000000000000000000000000000000000000000000000000000000000010001");
    num_s = g_numbers( )->Number2BinaryString(17, 32);
    EXPECT_EQ(num_s, "00000000000000000000000000010001");

    num_s = g_numbers( )->Number2BinaryString(17, 24);
    EXPECT_EQ(num_s, "000000000000000000010001");

    num_s = g_numbers( )->Number2BinaryString(17, 16);
    EXPECT_EQ(num_s, "0000000000010001");

    num_s = g_numbers( )->Number2BinaryString(17, 8);
    EXPECT_EQ(num_s, "00010001");


}



TEST_F(TestGNumbers, number2binary_shift)
{
    string num_s = g_numbers( )->Number2BinaryString(7, 32);
    EXPECT_EQ(num_s, "00000000000000000000000000000111");
    num_s = g_numbers( )->Number2BinaryString(7, 32, 1);
    EXPECT_EQ(num_s, "00000000000000000000000000001110");
    num_s = g_numbers( )->Number2BinaryString(7, 32, 5);
    EXPECT_EQ(num_s, "00000000000000000000000011100000");
    num_s = g_numbers( )->Number2BinaryString(7, 32, 10);
    EXPECT_EQ(num_s, "00000000000000000001110000000000");
}



TEST_F(TestGNumbers, binary2number)
{
    EXPECT_EQ(457893, g_numbers()->BinaryString2Number("1101111110010100101"));
    EXPECT_EQ(0, g_numbers()->BinaryString2Number("0"));
    EXPECT_EQ(1, g_numbers()->BinaryString2Number("1"));
    EXPECT_EQ(15, g_numbers()->BinaryString2Number ("1111"));
    EXPECT_EQ(6, g_numbers()->BinaryString2Number("110"));
    EXPECT_EQ(15, g_numbers()->BinaryString2Number("  1111"));
    EXPECT_EQ(6, g_numbers()->BinaryString2Number("110  "));
    EXPECT_EQ(6, g_numbers()->BinaryString2Number("   110     "));
    EXPECT_EQ(123456, g_numbers()->BinaryString2Number("11110001001000000") );
    
    #ifdef _WIN32
    EXPECT_EQ(9223372036854775807, g_numbers()->BinaryString2Number("  111111111111111111111111111111111111111111111111111111111111111"));
    EXPECT_EQ(-9223372036854775807, g_numbers()->BinaryString2Number("-111111111111111111111111111111111111111111111111111111111111111"));
    #endif

    EXPECT_EQ(-7, g_numbers()->BinaryString2Number("-111"));
    EXPECT_EQ(-6, g_numbers()->BinaryString2Number("-110"));
    EXPECT_ANY_THROW(g_numbers()->BinaryString2Number("12345"));
}




TEST_F(TestGNumbers, IsDecNumber)
{
    EXPECT_TRUE(  g_number_types()->IsDecNumber("10") );
    EXPECT_TRUE(  g_number_types()->IsDecNumber("9223372036854775807"));
    EXPECT_FALSE( g_number_types()->IsDecNumber("0x10"));
    EXPECT_FALSE( g_number_types()->IsDecNumber("blahhhhh"));
}



TEST_F(TestGNumbers, IsInteger)
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



TEST_F(TestGNumbers, IsNumber)
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



TEST_F(TestGNumbers, NSR1033)
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


TEST_F(TestGNumbers, ToNumber)
{
    EXPECT_EQ(9223372036854775807, g_numbers()->ToNumber<long long int>("9223372036854775807"));
    EXPECT_DOUBLE_EQ(1.7676931348623158e+308, g_numbers()->ToNumber<long double>("1.7676931348623158e+308\n"));
}

TEST_F(TestGNumbers, ToInteger)
{
    EXPECT_EQ(9223372036854775807,  g_numbers()->ToInteger("9223372036854775807") );
    EXPECT_EQ(-9223372036854775807, g_numbers()->ToInteger("-9223372036854775807"));
    EXPECT_EQ(0xabcdef, g_numbers()->ToInteger("0xabcdef"));
    vector<string> int_array = {"0xa", "0Xb", "0x12bc", "123"};
    vector<long long int> num = g_numbers()->ToInteger< long long int >(int_array);
    EXPECT_EQ(0xa, num[0]);
    EXPECT_EQ(0xb, num[1]);
    EXPECT_EQ(0x12bc, num[2]);
    EXPECT_EQ(123, num[3]);
}



TEST_F(TestGNumbers, IsFloat)
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



TEST_F(TestGNumbers, IsType)
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



TEST_F(TestGNumbers, IsFundamentalType)
{
    int i = 0;
    EXPECT_TRUE(g_number_types()->IsFundamentalType(i));
    string t = typeid(i).name();
    EXPECT_TRUE(g_number_types()->IsFundamentalTypeS(string(t.c_str())));
}



TEST_F(TestGNumbers, IsVType)
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


TEST_F(TestGNumbers, ToFloat)
{
    EXPECT_DOUBLE_EQ( 1.7976931348623158e+308, g_numbers()->ToFloat("1.7976931348623158e+308"));
    EXPECT_DOUBLE_EQ( -1.7976931348623158e+308, g_numbers()->ToFloat("-1.7976931348623158e+308"));
    EXPECT_DOUBLE_EQ(3.14159265359,  g_numbers()->ToFloat("      3.14159265359"));
    EXPECT_DOUBLE_EQ(3.14159265359,  g_numbers()->ToFloat("3.14159265359      "));
    EXPECT_DOUBLE_EQ(3.14159265359, g_numbers()->ToFloat("   3.14159265359   "));
    EXPECT_DOUBLE_EQ(3.14159265359, g_numbers()->ToFloat("   3,14159265359   "));
    
    try
    {
        g_numbers()->ToFloat("   3,14159265359   ");
    }
    #ifdef HAS_LOGGING
    catch (GException &e)
    {
        CERR << e.what() << ENDL;
    }
    #endif
    catch(std::exception &e)
    {
        CERR << e.what() << ENDL;
    }
    catch (std::string s)
    {
        CERR << s << ENDL;
    }
    catch (...)
    {
        CERR << "Unknown exception caught" << ENDL;
    }


    EXPECT_DOUBLE_EQ((long double)9223372036854775807, g_numbers()->ToFloat("9223372036854775807"));
    EXPECT_DOUBLE_EQ((long double)-9223372036854775807, g_numbers()->ToFloat("-9223372036854775807"));
}



TEST_F(TestGNumbers, IsDigit)
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
  



TEST_F(TestGNumbers, IsHex) 
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



TEST_F(TestGNumbers, ToHex)
{
    EXPECT_EQ(9223372036854775807,  g_numbers()->ToHex("0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-9223372036854775807, g_numbers()->ToHex("-0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ( 0x7FFFFFFFFFFFFFFF,  g_numbers()->ToHex("0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-0x7FFFFFFFFFFFFFFF,  g_numbers()->ToHex("-0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-0xadef123, g_numbers()->ToHex("-0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->ToHex("0xadef123"));
    EXPECT_EQ(-0xadef123, g_numbers()->ToHex("     -0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->ToHex("0xadef123"      ));
    EXPECT_EQ(-0xadef123, g_numbers()->ToHex("-0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->ToHex(       "0xadef123"     ));
}



TEST_F(TestGNumbers, PrivateFunctions)
{
    EXPECT_ANY_THROW( g_numbers()->CheckUnsigned<uint16_t>(  "-1" ));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<unsigned short>("-66"));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<unsigned int>("-66"));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<unsigned long int>("-66"));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<unsigned long long>("-66"));

    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<unsigned short>("66"));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<unsigned int>("66"));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<unsigned long int>("66"));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<unsigned long long>("66"));

    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<int>("-66"));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<float>("-66"));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<double>("-66"));

    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<uint16_t>("not a number"));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<int>("not a number"));
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<long double>("not a number"));

    vector<string>  vec = { "0", "0x456bc", "-13", "72", "42", "300", "44","1066"};
    EXPECT_ANY_THROW(g_numbers()->CheckUnsigned<unsigned long>(vec));
    EXPECT_NO_THROW(g_numbers()->CheckUnsigned<int>(vec));
}



TEST_F(TestGNumbers, BitWidth)
{
    EXPECT_ANY_THROW( g_numbers()->BitWidth("notanumber"));
    EXPECT_ANY_THROW( g_numbers()->BitWidth("1234"));
    EXPECT_EQ(1,      g_numbers()->BitWidth("1"));
    EXPECT_EQ(3,      g_numbers()->BitWidth("111"));
    EXPECT_EQ(3, g_numbers()->BitWidth("0111"));
    EXPECT_EQ(3, g_numbers()->BitWidth("000111"));
    EXPECT_EQ(3, g_numbers()->BitWidth("00000000111"));
    EXPECT_EQ(5, g_numbers()->BitWidth("011100"));
    EXPECT_EQ(5, g_numbers()->BitWidth("00011100"));
    EXPECT_EQ(5, g_numbers()->BitWidth("0000000011100"));
}



TEST_F(TestGNumbers, PadOnes)
{
    int unpadded = 0x2D; // = 101101
    int padded = 0x3f;   // = 111111

    EXPECT_EQ(padded, g_numbers()->PadOnes(unpadded));
}


#ifdef HAS_LOGGING
TEST_F(TestGNumbers, NSR1988DisableError)
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
