
PROGRAM:=logging-example1

SRCCPP+=../logging-example1.cpp \
	../GVersion.cpp


LIBS+=  -lcmdline -llogmaster  -lutilities  -lexception -lreadline -lpthread  


include ../../../../common.mk

