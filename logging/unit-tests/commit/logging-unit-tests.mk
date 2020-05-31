

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
	TestLMessage2Json.cpp


include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -llogmaster  -lexception  -lutilities -ltestlib -lexception


ifneq (arm, $(TARGET))
LIBS+=  -lreadline
endif

INCLUDES+=$(GTEST_INCLUDES)
