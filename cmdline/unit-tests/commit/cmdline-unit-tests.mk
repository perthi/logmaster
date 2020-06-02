

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -lcmdline -lexception -llogmaster -lutilities -ldl -lpthread

LIBS+=  -lm


#ifneq (arm, $(TARGET))
#LIBS+= -lX11 -lreadline
#endif

ifneq (arm, $(TARGET))
LIBS+=  -lreadline
endif

INCLUDES+=$(GTEST_INCLUDES)
