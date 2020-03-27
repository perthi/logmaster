
PROGRAM:=message-example2

SRCCPP+=../message-example2.cpp \
	../GVersion.cpp


LIBS+= -lcommon   -lcmdline  -lutilities  -lreadline -llogmaster -lxml-embc -lxml2 -lcommon -lapi-hmi -lintercom -lcom -lprotocol -lconfiguration  -lboost_system -lboost_filesystem  -lpthread  
CPPFLAGS=$(CPPFLAGS_RELAXED)

include  ../../../../common.mk

