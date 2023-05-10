

PROGRAM=logging-unit-tests


SRCCPP:=logging-unit-tests.cpp \
	TestLConfig.cpp \
	TestLConversion.cpp \
	TestException.cpp \
	TestLHashMaps.cpp \
	TestLTargets.cpp \
	TestCheckLevel.cpp \
	TestLFormat.cpp \
	TestLogging.cpp \
	TestSubscriber.cpp \
	TestLMessage2Json.cpp \
	TestLDatabase.cpp



include ../../../../common.mk
include ../../../../unittest-common.mk

CPPFLAGS+= -DLOGMASTER_HOME='"$(LOGMASTER_HOME)"'

LIBS+= -llogmaster  -lutilities  -lsqlite-embc -ldl -lgtest-embc -lpthread -lcmdline -llogmaster -lutilities \
-lreadline -lhistory -lncurses -ldl


INCLUDES+=$(GTEST_INCLUDES)
