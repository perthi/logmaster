#pragma once
#include <utilities/GDefinitions.h>
#include <utilities/GString.h>
class GNumberTypes;

GNumberTypes  inline API* g_number_types( );

class GNumberTypes
{
public:
    API GNumberTypes( ) {};
    bool     API               IsAlphaNumber(string num);
    bool     API               IsBinary(const char* num) { return IsBinary(string(num)); };
    bool     API               IsBinary(string num);

    template<typename T>   bool   API  IsBinary(T num);

    bool            API            IsDecNumber(const string num);
    bool            API            IsDigit(const char* num, const int base = 10) { return IsDigit(string(num), base); };
    bool            API            IsDigit(const string num, const int base = 10);
    template<typename T>   bool  API   IsDigit(T num, const int base = 10);
    template<typename T>   bool  API  IsFloat(T num);
    bool          API              IsFloat(const char* num);
    bool          API              IsFloat(const string num);
    bool           API             IsHex(const string num);
    template<typename T>   bool  API  IsHex(const T num);
    bool           API             IsHex(const char* num) { return IsHex(string(num)); };
    bool           API             IsInteger(const string num);
    template<typename T>   bool  API  IsInteger(T num);
    bool           API             IsNumber(const string num);
    bool          API              IsNumber(const double num);


    template<typename T>  bool API IsIntegerVType(T) { return IsIntegerVTypeS(typeid(T).name( )); }
    bool           API     IsIntegerVTypeS(string type);

    template<typename T>  bool API IsFundamentalVType(T) { return  IsFundamentalVTypeS(typeid(T).name( )); }
    bool                      API IsFundamentalVTypeS(string type);

    template<typename T> bool API IsFloatVType(T) { return  IsFloatVTypeS(typeid(T).name( )); }
    bool                     API  IsFloatVTypeS(string type);

    template<typename T>  bool API IsFundamentalType(T) { return  IsFundamentalTypeS(typeid(T).name( )); }
    bool             API IsFundamentalTypeS(string type);

    template<typename T>  bool API IsUnsignedType(T) { return  IsUnsignedTypeS(typeid(T).name( )); }
    bool             API IsUnsignedTypeS(string type);

    template<typename T>  bool API IsIntegerType(T) { return  IsIntegerTypeS(typeid(T).name( )); }

    bool             API IsIntegerTypeS(string type);

    template<typename T>  bool API IsFloatType(T) { return IsFloatTypeS(typeid(T).name( )); }
    bool             API IsFloatTypeS(string type);



};


GNumberTypes  inline * g_number_types( )
{
    static GNumberTypes* instance = new GNumberTypes( );
    return instance;

}


template<typename T>
bool
GNumberTypes::IsBinary(T num)
{
    return IsBinary(g_string( )->ToString(num));
}


template<typename T>
bool
GNumberTypes::IsDigit(T num, const int base)
{
    std::stringstream stream;
    stream << std::hex << num;
    return IsDigit(g_string( )->ToString(stream.str( )), base);
}


template<typename T>
bool
GNumberTypes::IsFloat(T num)
{
    return IsFloat(g_string( )->ToString(num));
}


template<typename T>
bool
GNumberTypes::IsHex(const T num)
{
    std::stringstream stream;
    stream << std::hex << num;
    return IsHex(g_string( )->ToString("0x" + stream.str( )));
}


template<typename T >
bool
GNumberTypes::IsInteger(T num)
{
    return IsInteger(g_string( )->ToString(num));
}


