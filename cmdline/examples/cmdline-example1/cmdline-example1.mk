
PROGRAM:=cmdline-example1



SRCCPP+=../cmdline-example1.cpp


LIBS+= -lcmdline -lexception  -llogmaster -lutilities -lreadline   -lpthread  

include ../../../../common.mk
