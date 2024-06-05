

PROGRAM:= cmdline-unit-tests



SRCCPP+= cmdline-dll-test.cpp \
	TestGCommandLineArgument.cpp \
	TestGLogApplication.cpp \
	TestGCmdScan.cpp \
	TestGCmdScanMock.cpp

include  ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=  -llogmaster  -lcmdline   -lutilities -lreadline -lhistory -lncurses -lgmock -lsqlite-embc -ldl  -lfmt

LIBS+=  -lm -lfmt


INCLUDES+=$(GTEST_INCLUDES)
