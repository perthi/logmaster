
PROGRAM:=helloworld
SRCCPP+=../helloworld.cpp \
		../GVersion.cpp




LIBS+=   -lcom  -lutilities   -lxml-embc -lxml2 -lcommon -lcmdline -llogmaster  \
 -lutilities -lreadline   -lboost_system  -lboost_filesystem -lpthread

LIBS+=$(PROTOBUF_LIBS)


INCLUDES+=$(PROTOBUF_INCLUDES)

CPPFLAGS=$(CPPFLAGS_RELAXED)
CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../common.mk
