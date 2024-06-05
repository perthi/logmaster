
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp \
        GVersion.cpp


LIBS+=    -lcmdline -llogmaster  -lutilities  -llogmaster  -lutilities  -lconfigurator -lsqlite-embc -lxml-embc  -lxml2 -lreadline -lhistory -lncurses -ldl -lpthread -lfmt

ifneq (arm, $(TARGET))
LIBS+=   -lreadline 
endif

include ../../common.mk