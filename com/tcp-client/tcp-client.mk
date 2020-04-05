

PROGRAM:=tcp-client 

SRCCPP+=tcp-client.cpp 


LIBS+= -lcom  -lutilities  -lreadline -llogmaster   -lpthread  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../common.mk

