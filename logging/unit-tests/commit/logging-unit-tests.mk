

PROGRAM=logging-unit-tests

#SRCCPP:=logging-unit-tests.cpp \
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


SRCCPP:=logging-unit-tests.cpp \
	TestLDatabase.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk

CPPFLAGS+= -DLOGMASTER_HOME='"$(LOGMASTER_HOME)"'

LIBS+= -llogmaster  -lexception  -lutilities -ltestlib -lexception  -lsqlite-embc -ldl -lpthread


ifneq (arm, $(TARGET))
LIBS+=  -lreadline
endif

INCLUDES+=$(GTEST_INCLUDES)
