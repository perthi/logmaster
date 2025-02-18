// -*- mode: c++ -*-

#pragma once

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

#include "GDefinitions.h"
#include "GCommon.h"
#include "GLocation.h"

#include <string>
#include <random>
#include <typeinfo>
#include <limits.h>

#include <iostream>

#include <fmt/format.h>


using std::random_device;
using std::string;


class GRandom;

inline  GRandom * g_random();

/** @brief Interface for random number generation from a uniform, Gaussian or binominal distribution  */
class GRandom
{
public:
    GRandom() {};
    ~GRandom() {};
    inline string   Name(const string prefix = "", const string postfix = "");
    inline string   RandomString( const size_t size  );

    template<typename T> T
    inline Binominal(T n, double p, typename std::enable_if<std::is_integral<T>::value>::type* = 0)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::binomial_distribution<> d(n, p);
        return d(gen);
    }


    template<typename T>  T
    inline  Binominal(T n, double /*p*/, typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)
    {
        GCommon().HandleError(  fmt::format( "The parameter n mus be an integral value, n is of type {}", typeid(n).name()), GLOCATION, THROW_EXCEPTION  );
        return 0;
    }
  

    template< typename T>   T
    inline  Uniform(T  min, T max, typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)

    {
        if (min > max)
        {
            GCommon().HandleError( fmt::format(  "Min value must be lower than max value, you have entered  min = {} and max = {}", min, max  ), GLOCATION, THROW_EXCEPTION  );
            return -1;
        }
        else
        {
            static std::default_random_engine gens;
            static std::mt19937 gen(gens());
            std::uniform_real_distribution<T> uniform_dist(min, max);
            T tmp =   uniform_dist(gens);
            return  tmp;
        }
        return 0;
    }


    template< typename T>  T
    inline  Uniform(T min, T max, typename std::enable_if<std::is_integral<T>::value>::type* = 0)
    {
        if (  (min) > (max)  )
        {
            GCommon().HandleError(   fmt::format( "Min value must be lower than max value, you have entered  min = {} and max = {}", min, max  ), GLOCATION, false  );
            return -1;
        }
        else
        {
            static std::random_device rd;  //Will be used to obtain a seed for the random number engine
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<T>  uniform_dist(min, max);
            return  uniform_dist( gen );
        }
    }  
    

    template<typename T>  T
    inline   Gauss(T mean, T sigma, typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)
    {
        T num = -9999;
        if (sigma < 0)
        {
            GCommon().HandleError(  fmt::format( "Invalid sigma value {}, sigma must be positive", num ), GLOCATION, THROW_EXCEPTION  );
        }
        else
        {
            static std::random_device rd;  //Will be used to obtain a seed for the random number engine
            static std::mt19937 gen(rd());
            std::normal_distribution<T> gauss_dist(mean, sigma);
            num = gauss_dist(gen);
        }
        return num;
    }
    
    template<typename T>  T
    inline  Gauss(T /*mean*/, T /*sigma*/, typename std::enable_if<std::is_integral<T>::value>::type* = 0)
    {
        GCommon().HandleError(  fmt::format( "You cannot use the Gauss random generator with an integral type. \
                                           {} Is an integral type, use a binomial generator instead", typeid(T).name()), GLOCATION,   THROW_EXCEPTION  );
        return 0;
    }
};


inline string
GRandom::Name(const string prefix, const string postfix)
{
    static char name[4096];
    unsigned short num = Uniform<unsigned short>(0, USHRT_MAX);
    SPRINTF(name, 4096 - 1, "%s%05d%s", prefix.c_str(), num, postfix.c_str());
    return string(name);
}



inline string   
GRandom::RandomString( const size_t size  )
{
    string tmp = "";

    for(size_t i = 0; i <  size; i++ )
    {
        /** @bug magic numbers */
        char c = Uniform<int>(64, 90);
        tmp.push_back(c);
    }
    return tmp;
}


inline  GRandom  * g_random()
{
    static GRandom *instance = new GRandom();
    return instance;
}

