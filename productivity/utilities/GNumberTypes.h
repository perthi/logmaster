#pragma once
#include <utilities/GDefinitions.h>
#include <utilities/GString.h>
class GNumberTypes;

GNumberTypes  inline API* g_number_types( );

class GNumberTypes
{
public:
    API GNumberTypes( ) {};
    bool     API               IsAlphaNumber(const string &num);
    bool     API               IsBinary(const char* num) { return IsBinary(string(num)); };
    bool     API               IsBinary(const string &num);

    template<typename T>   bool   API  IsBinary(const T &num);

    bool            API               IsDecNumber(const string &num);
    bool            API               IsDigit(const char* num, const int base = 10) { return IsDigit(string(num), base); };
    bool            API               IsDigit(const string &num, const int base = 10);
    template<typename T>   bool  API  IsDigit(const T &num, const int base = 10);
    template<typename T>   bool  API  IsFloat(const T &num);
    bool            API               IsFloat(const char* num);
    bool            API               IsFloat(const string &num);
    bool            API               IsHex(const string &num);
    template<typename T>   bool  API  IsHex(const T &num);
    bool            API               IsHex(const char* num) { return IsHex(string(num)); };
    bool            API               IsInteger(const string &num);
    template<typename T>   bool  API  IsInteger(const T &num);
    bool            API               IsNumber(const string num);
    bool            API               IsNumber(const double num);


    template<typename T>  bool API    IsIntegerVType(T) { return IsIntegerVTypeS(typeid(T).name( )); }
    bool                       API    IsIntegerVTypeS(const string &type);

    template<typename T>  bool API    IsFundamentalVType(const T &) { return  IsFundamentalVTypeS(typeid(T).name( )); }
    bool                       API    IsFundamentalVTypeS(const string &type);

    template<typename T> bool  API    IsFloatVType(const T &) { return  IsFloatVTypeS(typeid(T).name( )); }
    bool                       API    IsFloatVTypeS(const string &type);

    template<typename T>  bool API IsFundamentalType(const T &) { return  IsFundamentalTypeS(typeid(T).name( )); }
    bool                       API IsFundamentalTypeS(const string &type);

    template<typename T>  bool API IsUnsignedType(const T &) { return  IsUnsignedTypeS(typeid(T).name( )); }
    bool                       API IsUnsignedTypeS(const string &type);

    template<typename T>  bool API  IsIntegerType(const T &) { return  IsIntegerTypeS(typeid(T).name( )); }
    bool                       API  IsIntegerTypeS(const string &type);
    template<typename T>  bool API  IsFloatType(const T&) { return IsFloatTypeS(typeid(T).name( )); }
    bool                       API  IsFloatTypeS(const string &type);



};


/** @todo remove singleton */
GNumberTypes  inline * g_number_types( )
{
    static GNumberTypes* instance = new GNumberTypes( );
    return instance;

}


template<typename T>
bool
GNumberTypes::IsBinary(const T &num)
{
    return IsBinary(g_string( )->ToString(num));
}


template<typename T>
bool
GNumberTypes::IsDigit(const T &num, const int base)
{
    std::stringstream stream;
    stream << std::hex << num;
    return IsDigit(g_string( )->ToString(stream.str( )), base);
}


template<typename T>
bool
GNumberTypes::IsFloat(const T &num)
{
    return IsFloat(g_string( )->ToString(num));
}


template<typename T>
bool
GNumberTypes::IsHex(const T &num)
{
    std::stringstream stream;
    stream << std::hex << num;
    return IsHex(g_string( )->ToString("0x" + stream.str( )));
}


template<typename T >
bool
GNumberTypes::IsInteger(const T &num)
{
    return IsInteger(g_string( )->ToString(num));
}


