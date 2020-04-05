

PROGRAM:=tcp-example1 

SRCCPP+=tcp-example1.cpp 


LIBS+= -llogmaster  -lcom -lutilities  -lcom  -lpthread   -lreadline  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../../common.mk

