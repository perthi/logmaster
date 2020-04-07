

PROGRAM=logging-unit-tests

SRCCPP:=logging-unit-tests.cpp \
	TestLConfig.cpp \
	TestLConversion.cpp \
	TestLHashMaps.cpp \
	TestLTargets.cpp \
	TestCheckLevel.cpp \
	TestLFormat.cpp \
	TestLogging.cpp \
	TestSubscriber.cpp \
	GVersion.cpp 



include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -llogmaster -lcmdline -lexception  -lutilities -ltestlib -lexception
INCLUDES+=$(GTEST_INCLUDES)
