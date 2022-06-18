
PROGRAM:=gui-operations-example1

SRCCPP+=../gui-operations-example1.cpp


LIBS+= $(PROTOBUF_LIBS)
LIBS += -lQt5Core -lQt5Widgets -lQt5Gui -lQt5Charts  \
	-lc-ring -lgui-operations -lsequence -lapi-hmi -lcommon -lgui-common \
	-lintercom -lconfiguration  -lprotocol -lutilities -lcom  -lkf-commands -lintercom -lkf-com -lkf-commands \
	-lxml-embc -lxml2 -lcmdline -lutilities -llogmaster \
	-lreadline -lboost_system -lboost_filesystem  -lQt5Charts -lpthread
LIBS += $(PROTOBUF_LIBS)
CPPFLAGS=$(CPPFLAGS_RELAXED)
INCLUDES+=$(PROTOBUF_INCLUDES)


include ../../../../../common.mk
include ../../../../../gui.mk
