
PROGRAM:=message-example3-blocking

SRCCPP+=../message-example3-blocking.cpp  \
	../GVersion.cpp

LIBS+= -lcommon   -lcmdline  -lutilities -lreadline -llogmaster -lxml-embc -lxml2 -lcommon  -lcom   -lpthread  
CPPFLAGS=$(CPPFLAGS_RELAXED)

include ../../../../common.mk
