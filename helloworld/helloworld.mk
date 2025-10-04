
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp \
        GVersion.cpp

LIBS+=     -Wl,--start-group -lcmdline -llogmaster  -lutilities -lconfigurator -lsqlite-embc -lxml-embc -Wl,--end-group  -lxml2 -lreadline -lhistory -lncurses -ldl -lpthread

include ../../common.mk
