
PROGRAM:=message-example4-timer

SRCCPP+=../message-example4-timer.cpp  \
	../GVersion.cpp

LIBS+= -lcommon   -lcmdline  -lutilities -lreadline -llogmaster -lxml-embc -lxml2 -lcommon \
-lapi-hmi -lintercom -lcom -lprotocol -lconfiguration  -lapi-hmi -lboost_system -lboost_filesystem  -lpthread  
CPPFLAGS=$(CPPFLAGS_RELAXED)

include  ../../../../common.mk
