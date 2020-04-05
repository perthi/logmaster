
PROGRAM:=message-example4-timer

SRCCPP+=../message-example4-timer.cpp  \
	../GVersion.cpp

LIBS+=  -lcmdline  -lutilities -lreadline -llogmaster  -lcommon  -lcom -lxml-embc -lxml2  -lpthread    
CPPFLAGS=$(CPPFLAGS_RELAXED)

include  ../../../../common.mk
