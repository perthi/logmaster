
PROGRAM:=message-example2

SRCCPP+=../message-example2.cpp \
	../GVersion.cpp


LIBS+=   -lcmdline  -lutilities  -lreadline -llogmaster -lxml-embc -lxml2 -lcommon  -lcom    -lpthread  
CPPFLAGS=$(CPPFLAGS_RELAXED)

include  ../../../../common.mk

