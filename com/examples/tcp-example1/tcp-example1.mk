

PROGRAM:=tcp-example1 

SRCCPP+=tcp-example1.cpp 


LIBS+= -llogmaster  -lcom -lutilities -lapi-hmi -lintercom -lcom -lprotocol -lconfiguration -lpthread -lboost_system -lboost_filesystem  -lreadline  

#CPPFLAGS=$(CPPFLAGS_RELAXED)


include ../../../../common.mk

