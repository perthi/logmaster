
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -llogmaster  -lutilities  -llogmaster -lsqlite-embc  -lreadline -lhistory -lncurses -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline 
endif

include ../../common.mk
