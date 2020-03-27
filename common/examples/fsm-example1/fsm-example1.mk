
PROGRAM:=fsm-example1

SRCCPP+=../fsm-example1.cpp  \
	../GVersion.cpp


LIBS+= -lcommon -llogmaster -lutilities -lreadline -lxml-embc -lxml2 -lcommon -lapi-fsm -lapi-hmi -lintercom -lcom -lprotocol -lconfiguration -lboost_system -lboost_filesystem  -lpthread  

CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../../common.mk

