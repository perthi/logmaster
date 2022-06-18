
PROGRAM:=gui-habitat-example1

SRCCPP+=../gui-habitat-example1.cpp

LIBS += -lhabitat \
	-lintercom -lcommon  -lgui-common  -lapi-hmi  -lcom      \
	-lprotocol -lconfiguration -lkf-commands  -lcom -lkf-com \
	-lkf-commands -lxml-embc -lxml2  -lcmdline -llogmaster   \
	-lutilities -lreadline -lboost_system -lboost_filesystem \
	-lQt5Charts -lpthread

LIBS += $(PROTOBUF_LIBS)
CPPFLAGS=$(CPPFLAGS_RELAXED)

INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../../../common.mk
include ../../../../../gui.mk
