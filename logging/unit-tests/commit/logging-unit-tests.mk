

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
	TestLMessage2Json.cpp \
	TestLDatabase.cpp

#SRCCPP:=logging-unit-tests.cpp \
    	TestLogging.cpp \
	  	TestLMessage2Json.cpp \
	TestLDatabase.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk

CPPFLAGS+= -DLOGMASTER_HOME='"$(LOGMASTER_HOME)"'

LIBS+=  -lexception -llogmaster  -lutilities  -lsqlite-embc -ldl -lgtest-embc -lpthread -lcmdline -llogmaster -lutilities \
-lreadline -lhistory -lncurses -ldl


INCLUDES+=$(GTEST_INCLUDES)
