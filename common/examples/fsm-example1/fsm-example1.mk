
PROGRAM:=fsm-example1

SRCCPP+=../fsm-example1.cpp  \
	../GVersion.cpp


LIBS+=  -llogmaster  -lcommon   -lcom  -lxml-embc -lxml2 -lutilities -lreadline -lpthread  

CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../../common.mk

