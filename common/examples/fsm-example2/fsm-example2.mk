
PROGRAM:=fsm-example2

SRCCPP+=../fsm-example2.cpp \
	../GVersion.cpp


LIBS+= -lcommon -llogmaster -lutilities -lreadline -lxml-embc -lxml2 -lcommon  -lpthread

CPPFLAGS=$(CPPFLAGS_RELAXED)

include ../../../../common.mk

