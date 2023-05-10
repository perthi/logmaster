
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp \
        GVersion.cpp


LIBS+=    -lcmdline -llogmaster  -lutilities  -llogmaster  -lutilities -lsqlite-embc  -lreadline -lhistory -lncurses -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline 
endif

include ../../common.mk
