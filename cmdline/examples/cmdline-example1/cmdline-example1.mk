
PROGRAM:=cmdline-example1



SRCCPP+=../cmdline-example1.cpp


LIBS+= -lcmdline  -lutilities  -lexception  -llogmaster  -lreadline   -lpthread  

include ../../../../common.mk
