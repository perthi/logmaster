

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -llogmaster -lcmdline -lexception
INCLUDES+=$(GTEST_INCLUDES)
