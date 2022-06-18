

PROGRAM=api-hmi-unit-tests


SRCCPP:=api-hmi-tests.cpp \
	TestAPICRing.cpp \
	TestAPICRingInfo.cpp \
	TestAPIHmiOperation.cpp



include ../../../../../common.mk
include ../../../../../unittest-common.mk


LIBS+=  -ltestlib -llogmaster -lcommon -lcmdline -lapi-hmi -lintercom \
-lcommon  -lxml-embc -lxml2 -lconfiguration  -lprotocol -lkf-commands   -lcom
LIBS+= $(PROTOBUF_LIBS)
INCLUDES+=$(PROTOBUF_INCLUDES)

INCLUDES+=$(GTEST_INCLUDES)
