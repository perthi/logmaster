
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -llogmaster  -lutilities  -lexception   -lsqlite-embc  -lreadline -lhistory -lncurses -ldl -lpthread
#LIBS+=$(PROTOBUF_LIBS)

ifneq (arm, $(TARGET))
LIBS+=   -lreadline 
endif

include ../../common.mk
