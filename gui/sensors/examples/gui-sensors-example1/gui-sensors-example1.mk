PROGRAM:=gui-sensors-example1

SRCCPP+=../gui-sensors-example1.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)


LIBS+= -lgui-sensors  -lgui-settings  -lgui-common  -lapi-sensors  -lcontrol-engine   \
  -lconfiguration -lxml-embc -lxml2 -lintercom  -lcom  -lkf-com -lcommon  -lprotocol -lutilities \
  -lkf-commands -lcmdline -llogmaster -lutilities -lreadline  -lboost_system  -lboost_filesystem  -lpthread


include ../../../../../common.mk
include ../../../../../gui.mk


