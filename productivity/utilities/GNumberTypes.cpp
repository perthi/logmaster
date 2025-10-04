
#include "GNumberTypes.h"
#include "GString.h"

#include <limits>


bool
GNumberTypes::IsFloatTypeS(const string &type)
{
    const string t = string(type);

    if ( t == typeid(float).name( ) ||
        t == typeid(double).name( ) ||
        t == typeid(long double).name( ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GNumberTypes::IsAlphaNumber(const string &n)
{
    string num = n;
    num = g_string( )->Trim(num, { ' ', '\t', '\n' });

    for ( uint16_t i = 0; i < num.size( ); i++ )
    {
        int val = (int)num[i];
        if ( val >= 0 && val <= 255 )
        {
            if ( !isalnum(num[i]) )
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}


bool
GNumberTypes::IsBinary(const string &n)
{
    string num = n;
    g_string( )->Trim(num);
    g_string( )->Ltrim(num, '-');
    for ( uint16_t i = 0; i < num.size( ); i++ )
    {
        if ( num[i] != '1' && num[i] != '0' )
        {
            return false;
        }
    }
    return true;
}



bool
GNumberTypes::IsDecNumber(const string  &num)
{
    if ( IsDigit(num) || IsFloat(num) )
    {
        if ( IsHex(num) )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}



/** @brief Whether or not the string "num" is digit in base given by "base". For base 10
*   @details The digits shall be 0-9, for base 16 0-F  etc..
*   @param num  The string representation of the digit
*   @param base the base, or radix of the number "num"
*   @return  true if the number given by "num" is a valid digit in the base "base", false othervise */
bool
GNumberTypes::IsDigit(const string &num, const int base)
{
    string tmp = num;
    g_string( )->Trim(tmp, ' ');

    if ( tmp == "0" )
    {
        return true;
    }
    else
    {
        g_string( )->Ltrim(tmp, '0');
    }
    if ( tmp.size( ) != 1 ) return false;

    bool iret = false;
    try
    {
        return iret = stoul(tmp, 0, base) == 0 ? false : true;
    }
    catch ( ... )
    {
        return false;
    }
}



bool
GNumberTypes::IsHex(const string &in)
{
    string s = in;
    g_string( )->Trim(s);
    g_string( )->Ltrim(s, '-');
    if ( (g_string( )->BeginsWith(s, "0x", true)) && ((s.size( ) > 2)) )
    {
        for ( uint16_t i = 2; i < s.size( ); i++ )
        {

            if ( isxdigit(s[i]) == false )
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
    return false;
}


bool
GNumberTypes::IsInteger(const string &num)
{
    string tmp = num;
    g_string( )->Trim(tmp, { ' ', '\t', '\n' });

    if ( IsFloat(tmp) == true )
    {
        return   std::stold(tmp.c_str( )) - std::atoll(tmp.c_str( )) == 0 ? true : false;
    }
    return false;
}




bool
GNumberTypes::IsNumber(const double num)
{
    return IsNumber(g_string( )->ToString(num));
}


bool
GNumberTypes::IsNumber(const string  num)
{
    string trimmed = num;
    g_string( )->Trim(trimmed, { ' ', '\t', '\n' });

    if ( IsHex(trimmed) || IsBinary(trimmed) || IsDigit(trimmed) || IsFloat(trimmed) || IsAlphaNumber(trimmed) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool
GNumberTypes::IsFundamentalTypeS(const string &type)
{
    if ( string(type) == typeid(bool).name( ) ||
        IsFloatTypeS(string(type)) ||
        IsIntegerTypeS(string(type)) )
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool
GNumberTypes::IsUnsignedTypeS(const string &type)
{
    const string  t = string(type);
    if (
        string(type) == typeid(unsigned char).name( ) ||
        t == typeid(unsigned short).name( ) ||
        t == typeid(unsigned int).name( ) ||
        t == typeid(unsigned long int).name( ) ||
        t == typeid(unsigned long long int).name( ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GNumberTypes::IsFundamentalVTypeS(const string &type)
{
    if ( type == typeid(vector<bool>).name( ) ||
        IsFloatVTypeS(type) ||
        IsIntegerVTypeS(type) )
    {
        return true;
    }
    else
    {
        return false;
    }

}



bool
GNumberTypes::IsFloatVTypeS(const string &type)
{
    //    string type = typeid(T).name();
    if ( type == typeid(vector<float>).name( ) ||
        type == typeid(vector<double>).name( ) ||
        type == typeid(vector<long double>).name( ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GNumberTypes::IsIntegerVTypeS(const string &type)
{
    if ( type == typeid(vector<char>).name( ) ||
        type == typeid(vector<short>).name( ) ||
        type == typeid(vector<int>).name( ) ||
        type == typeid(vector<long int>).name( ) ||
        type == typeid(vector<long long int>).name( ) ||
        type == typeid(vector<unsigned char>).name( ) ||
        type == typeid(vector<unsigned short>).name( ) ||
        type == typeid(vector<unsigned int>).name( ) ||
        type == typeid(vector<unsigned long int>).name( ) ||
        type == typeid(vector<unsigned long long int>).name( ) )
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}


bool
GNumberTypes::IsIntegerTypeS(const string &t)
{
    if ( t == string(typeid(short).name( )) ||
        t == string(typeid(int).name( )) ||
        t == string(typeid(long int).name( )) ||
        t == string(typeid(long long int).name( )) || IsUnsignedTypeS(t) )
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
GNumberTypes::IsFloat(const char* num)
{
    return IsFloat(string(num));
}


bool
GNumberTypes::IsFloat(const string &n)
{
    string num  = n;
    num = g_string( )->Trim(num, { ' ', '\t', '\n' });

    // Exceptions is a pain, so lets remove some common causes.
    if ( num == "," )
    {
        return false;
    }
    if ( g_string( )->BeginsWith(num, "--") )
    {
        return false;
    }
    if ( (num.size( ) == 3) && (::tolower(num.at(0)) == 'n') && (::tolower(num.at(1)) == 'a') && (::tolower(num.at(2)) == 'n') )
    {
        return true;
    }
    const char* p = num.c_str( );
    while ( *p )
    {
        if ( (*p == 'E') || (*p == 'e') || (*p == '.') || (*p == ',') || (*p == '-') || (*p == '+') || (*p >= '0' && *p <= '9') )
        {
            p++;
        }
        else
        {
            return false;
        }
    }

    try
    {
#ifdef __linux__
        std::stold(num);
#else
        auto t = std::stold(num);
#endif
    }
    catch ( ... )
    {
        return false;
    }

    return true;

}
