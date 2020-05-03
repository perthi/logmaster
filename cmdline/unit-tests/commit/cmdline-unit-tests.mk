

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -lcmdline -lexception -llogmaster -lutilities

LIBS+=  -lm


ifneq (arm, $(TARGET))
LIBS+= -lX11 -lreadline
endif

INCLUDES+=$(GTEST_INCLUDES)
