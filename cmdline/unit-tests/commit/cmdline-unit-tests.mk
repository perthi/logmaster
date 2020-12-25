

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp

include  ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=  -llogmaster  -lcmdline  -lexception -lutilities -lreadline -lhistory -lncurses -lsqlite-embc -ldl

LIBS+=  -lm


INCLUDES+=$(GTEST_INCLUDES)
