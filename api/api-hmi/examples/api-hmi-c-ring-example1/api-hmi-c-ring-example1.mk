
PROGRAM:=api-hmi-c-ring-example1

SRCCPP+=../api-hmi-c-ring-example1.cpp


LIBS+=   -lconfiguration  -lcommon -lxml-embc -lxml2  -lapi-hmi  -lintercom  -lprotocol -lcom -lkf-commands \
		-llogmaster  -lutilities -lcmdline -lreadline -llogmaster -lboost_system -lboost_filesystem  -lpthread 

LIBS+= $(PROTOBUF_LIBS)
INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../../../common.mk

