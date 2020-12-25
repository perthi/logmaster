
PROGRAM:=cmdline-example1



SRCCPP+=cmdline-example1.cpp


LIBS+= -lcmdline -lexception  -llogmaster -lutilities  -lpthread    -lsqlite-embc -ldl -lpthread

ifneq (arm, $(TARGET))
LIBS+=   -lreadline
endif

include ../../../../common.mk
