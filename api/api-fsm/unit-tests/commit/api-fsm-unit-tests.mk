

PROGRAM=api-fsm-unit-tests

SRCCPP:=api-fsm-unit-tests.cpp \
	TestAPIFSMController.cpp 



include ../../../../../common.mk
include ../../../../../unittest-common.mk


LIBS+=  -ltestlib -llogmaster -lcmdline -lcommon -lapi-fsm -lcommon -lxml-embc -lxml2 -lapi-hmi -lintercom -lcom -lprotocol -lconfiguration 
LIBS+= $(PROTOBUF_LIBS)
INCLUDES+=$(PROTOBUF_INCLUDES)

INCLUDES+=$(GTEST_INCLUDES)
