
PROGRAM:=helloworld
SRCCPP+=../helloworld.cpp
		
		
#		../GVersion.cpp




LIBS+=   -lutilities 

LIBS+=$(PROTOBUF_LIBS)


INCLUDES+=$(PROTOBUF_INCLUDES)

CPPFLAGS=$(CPPFLAGS_RELAXED)
CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../common.mk
