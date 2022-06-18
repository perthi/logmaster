PROGRAM:=gui-qt-fsm-example1

SRCCPP+=../gui-qt-fsm-example1.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)

LIBS+=  -lapi-fsm -lgui-fsm  -lgui-common -lcommon -lxml-embc -lxml2  -lcmdline  -llogmaster -lutilities \
 -lreadline -lboost_system  -lapi-hmi -lintercom -lcom -lprotocol -lconfiguration -lboost_filesystem -lpthread

include ../../../../../common.mk
include ../../../../../gui.mk

