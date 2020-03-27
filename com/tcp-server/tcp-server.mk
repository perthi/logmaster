

PROGRAM:=tcp-server 

SRCCPP+=tcp-server.cpp 


LIBS+= -llogmaster  -lcom -lutilities  -lreadline -lboost_system -lboost_filesystem  -lpthread  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../common.mk

