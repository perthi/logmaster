

PROGRAM=logging-unit-tests

SRCCPP:=logging-unit-tests.cpp \
	TestLConfig.cpp \
	TestLConversion.cpp \
	TestLHashMaps.cpp \
	TestLTargets.cpp \
	TestCheckLevel.cpp \
	TestLFormat.cpp \
	TestLogging.cpp \
	TestSubscriber.cpp

#SRCCPP:=logging-unit-tests.cpp \
	TestLogging.cpp 

#SRCCPP:=logging-unit-tests.cpp \
	TestLTargets.cpp \
	TestLogging.cpp 

include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -llogmaster  -lexception  -lutilities -ltestlib -lexception
INCLUDES+=$(GTEST_INCLUDES)
