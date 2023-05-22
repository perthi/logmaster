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


/*
TEST_F(TestGNumbers, number2binary)
{
    auto num_s = g_numbers()->Number2BinaryString(1);
    EXPECT_EQ(num_s, "1");
    
    num_s = g_numbers()->Number2BinaryString(3);
    EXPECT_EQ(num_s, "11");

    num_s = g_numbers()->Number2BinaryString(8);
    EXPECT_EQ(num_s, "1000");

    num_s = g_numbers()->Number2BinaryString(7);
    EXPECT_EQ(num_s, "111");

    num_s = g_numbers()->Number2BinaryString(7, 0, 3);
    EXPECT_EQ(num_s, "111000");

    num_s = g_numbers()->Number2BinaryString(7, 0, 6);
    EXPECT_EQ(num_s, "111000000");
 }
 */

/*
TEST_F(TestGNumbers, number2binary_widt)
{
    auto num_s = g_numbers()->Number2BinaryString(1, 64);
    EXPECT_EQ(num_s, "0000000000000000000000000000000000000000000000000000000000000001");
    num_s = g_numbers( )->Number2BinaryString(1, 32);
    EXPECT_EQ(num_s, "00000000000000000000000000000001");
    
    num_s = g_numbers( )->Number2BinaryString(1, 24);
    EXPECT_EQ(num_s, "000000000000000000000001");

    num_s = g_numbers( )->Number2BinaryString(1,16);
    EXPECT_EQ(num_s, "0000000000000001");
    
    num_s = g_numbers( )->Number2BinaryString(1, 8);
    EXPECT_EQ(num_s, "00000001");


    num_s = g_numbers( )->Number2BinaryString(17, 64);
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
*/

/*
TEST_F(TestGNumbers, number2binary_shift_width)
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
*/


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



TEST_F(TestGNumbers, ToNumber)
{
    EXPECT_EQ(9223372036854775807, g_numbers()->ToNumber<long long int>("9223372036854775807"));
    EXPECT_DOUBLE_EQ(1.7676931348623158e+308, g_numbers()->ToNumber<long double>("1.7676931348623158e+308\n"));
}

TEST_F(TestGNumbers, ToInteger)
{
    EXPECT_EQ(9223372036854775807,  g_numbers()->ToInteger<long long>("9223372036854775807") );
    EXPECT_EQ(-9223372036854775807, g_numbers()->ToInteger<long long>("-9223372036854775807"));
    
    EXPECT_EQ(0xabcdef, g_numbers()->ToInteger<long>("0xabcdef"));
    vector<string> int_array = {"0xa", "0Xb", "0x12bc", "123"};
    vector<long long int> num = g_numbers()->ToInteger< long long int >(int_array);
    EXPECT_EQ(0xa, num[0]);
    EXPECT_EQ(0xb, num[1]);
    EXPECT_EQ(0x12bc, num[2]);
    EXPECT_EQ(123, num[3]);
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


    EXPECT_DOUBLE_EQ((long double)9223372036854775807, g_numbers()->ToFloat<long double>("9223372036854775807"));
    EXPECT_DOUBLE_EQ((long double)-9223372036854775807, g_numbers()->ToFloat<long double>("-9223372036854775807"));
}



TEST_F(TestGNumbers, HexString2Number)
{
    EXPECT_EQ(9223372036854775807,  g_numbers()->HexString2Number("0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-9223372036854775807, g_numbers()->HexString2Number("-0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ( 0x7FFFFFFFFFFFFFFF,  g_numbers()->HexString2Number("0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-0x7FFFFFFFFFFFFFFF,  g_numbers()->HexString2Number("-0x7FFFFFFFFFFFFFFF"));
    EXPECT_EQ(-0xadef123, g_numbers()->HexString2Number("-0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->HexString2Number("0xadef123"));
    EXPECT_EQ(-0xadef123, g_numbers()->HexString2Number("     -0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->HexString2Number("0xadef123"      ));
    EXPECT_EQ(-0xadef123, g_numbers()->HexString2Number("-0xadef123"));
    EXPECT_EQ(0xadef123, g_numbers()->HexString2Number(       "0xadef123"     ));
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

