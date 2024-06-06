

PROGRAM:=utilities-unit-tests


SRCCPP += utilities-unit-tests.cpp \
	TestGMath.cpp \
	TestGRandom.cpp \
	TestGString.cpp \
	TestGFileIOHandler.cpp  \
	TestGTokenizer.cpp \
	TestGRegexp.cpp \
	TestGTime.cpp \
	TestGUtilities.cpp \
	TestGNumbers.cpp \
    TestGCrc.cpp \
	TestGSystem.cpp \
	TestGFormatting.cpp \
	TestGLocation.cpp 



include ../../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=   -lutilities  -lsqlite-embc

ifdef HAS_LOGGING
LIBS+=  -llogmaster	  -lsqlite-embc -ldl -lpthread  
endif

LIBS+= -lreadline -lhistory -lncurses -lfmt

INCLUDES+=$(GTEST_INCLUDES)
