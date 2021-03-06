

PROGRAM=exception-unit-tests

SRCCPP:=exception-unit-tests.cpp \
	TestException.cpp



include ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+= -llogmaster   -lutilities -ltestlib -lexception  -lsqlite-embc -lreadline -lhistory -lncurses -ldl -lpthread
#LIBS+=$(PROTOBUF_LIBS)

ifneq (arm, $(TARGET))
LIBS+=   -lreadline
endif

INCLUDES+=$(GTEST_INCLUDES)
