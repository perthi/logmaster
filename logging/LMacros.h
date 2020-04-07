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

#include <stdint.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
#include <sstream>
using std::string;

#include <type_traits>


#ifdef _WIN64f

#define __CALL__  _fastcall 
#else
#ifdef _WIN32
#define __CALL__  _stdcall 
#endif
#endif

#ifdef _WIN32
#define API __declspec(dllexport)
#else
#define API
#endif


#ifdef _WIN32
#define SPRINTF sprintf_s
#else
#define SPRINTF snprintf
#endif


#ifdef _WIN32
#define SPRINTF_S(buffer, input) sprintf_s(buffer, sizeof(buffer) -1, "%s", input.c_str() )
#else
#define SPRINTF_S(buffer, input) snprintf(buffer, sizeof(buffer) -1, "%s", input.c_str() ) 
#endif






#define MAIN_UNITTEST() \
int argc_ = 0; \
char** argv_ = nullptr; \
int  main(int argc, char** argv) \
{ \
 	argc_ = argc; \
    argv_ = argv; \
	GLogApplication((const int)argc, (const char **)argv); \
\
	/* The method is initializes the Google framework and must be called before RUN_ALL_TESTS */ \
	::testing::InitGoogleTest(&argc, argv); \
\
        /* RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.*/\
/* It's must be called only once in the code because multiple calls lead to conflicts and, */ \
/*therefore, are not supported. */ \
	return  RUN_ALL_TESTS(); \
} 



