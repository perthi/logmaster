
PROGRAM:=logging-example1

SRCCPP+=logging-example1.cpp 


LIBS+=  -lcmdline -llogmaster  -lutilities  -lexception  -lpthread    -lsqlite-embc -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline
endif

include ../../../../common.mk

