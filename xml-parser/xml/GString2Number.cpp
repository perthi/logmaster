// -*- mode: c++ -*-


#include "GString2Number.h"
#include "GXmlMacros.h"
//#include "GLocationXml.h"

#include <iostream> 
#include <string>

#include <utilities/GCommon.h>

#include <format>
using std::format;



GString2Number::GString2Number()
{

}

GString2Number::~GString2Number()
{

}


double 
GString2Number::ToNumber( const string num )
{
    std::string::size_type sz = 0;
    double d = -9999;

    try
    {
        d = std::stoi(num, &sz);

        if (sz > 0)
        {
            return d;
        }
        else
        {
            d = std::stod(num, &sz);
        
             if (sz > 0)
            {
                return d;
            } 
        
        }
    }
    catch (const std::exception &e)
    {
        GCommon().HandleError(format("exception caught ( {} )trying to convert \"{}\" to a number ", e.what(), num), GLOCATION, THROW_EXCEPTION);
        return d;
    
    }

    return d;

}
