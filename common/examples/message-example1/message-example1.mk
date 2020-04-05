
PROGRAM:=message-example1

SRCCPP+=../message-example1.cpp \
	../GVersion.cpp


LIBS+= -lcommon   -lcmdline  -lutilities  -lreadline -llogmaster -lxml-embc -lxml2 -lcommon  -lpthread  

CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../../common.mk

