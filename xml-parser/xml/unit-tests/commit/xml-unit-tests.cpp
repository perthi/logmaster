// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/



#include <utilities/GDefinitions.h>
#ifdef _WIN32
#include <gtest/gtest.h>
#else
#include <gtest-embc/gtest.h>
#endif

#ifdef HAS_LOGGING
#include  <cmdline/GLogApplication.h>
#endif

#include <testlib/TestBase.h>

//#define G_STANDALONE

MAIN_UNITTEST()