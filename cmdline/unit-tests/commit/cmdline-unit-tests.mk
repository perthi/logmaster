

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp \
	TestGArgument.cpp \
	TestGCmdScanMock.cpp

include  ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=  -llogmaster  -lcmdline   -lutilities -lreadline -lhistory -lncurses -lgmock -lsqlite-embc -ldl

LIBS+=  -lm


INCLUDES+=$(GTEST_INCLUDES)
