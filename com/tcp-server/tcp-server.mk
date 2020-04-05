

PROGRAM:=tcp-server 

SRCCPP+=tcp-server.cpp 


LIBS+= -llogmaster  -lcom -lutilities  -lreadline  -lpthread  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../common.mk

