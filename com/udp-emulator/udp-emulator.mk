

PROGRAM:=udp-emulator

SRCCPP+=udp-emulator.cpp \
	GVersion.cpp \
	GVersionMenu.cpp 


LIBS+=  -lintercom   -lkf-commands   -lprotocol  -lconfiguration \
-lxml-embc -lxml2  -lcommon  -lkf-com -lcom -lpthread \
 -llogmaster -lcmdline -lutilities -lreadline -lboost_system -lboost_filesystem 


# CPPFLAGS=$(CPPFLAGS_RELAXED)
INCLUDES+=$(PROTOBUF_INCLUDES)
LIBS+=$(PROTOBUF_LIBS)

include ../../../common.mk

