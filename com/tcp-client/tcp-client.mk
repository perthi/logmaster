

PROGRAM:=tcp-client 

SRCCPP+=tcp-client.cpp 


LIBS+= -lcom  -lutilities  -lreadline -llogmaster -lboost_system -lboost_filesystem  -lpthread  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../common.mk

