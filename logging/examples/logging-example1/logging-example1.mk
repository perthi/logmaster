
PROGRAM:=logging-example1

SRCCPP+=logging-example1.cpp \
        GVersion.cpp


LIBS+=  -lcmdline -llogmaster  -lutilities  -lpthread  -lsqlite-embc  -lreadline -lhistory -lncurses -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline
endif

include ../../../../common.mk

