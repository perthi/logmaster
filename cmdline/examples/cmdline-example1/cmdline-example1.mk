
PROGRAM:=cmdline-example1



SRCCPP+=../cmdline-example1.cpp


LIBS+= -llogmaster  -lcmdline  -lutilities  -lexception  -lreadline   -lpthread  

include ../../../../common.mk
