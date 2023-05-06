
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -lcmdline -llogmaster  -lutilities  -llogmaster  -lcmdline -lsqlite-embc  -lreadline -lhistory -lncurses -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline 
endif

include ../../common.mk
