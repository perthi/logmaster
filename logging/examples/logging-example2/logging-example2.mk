
PROGRAM:=logging-example2

SRCCPP+=logging-example2.cpp \
        GVersion.cpp

LIBS+=  -lcmdline -llogmaster  -lutilities    -lsqlite-embc -lreadline -lhistory -lncurses -ldl -lpthread

# ifneq (arm, $(TARGET))
# LIBS+=   -lreadline
# endif

include ../../../../common.mk

