
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=   -lutilities 
LIBS+=$(PROTOBUF_LIBS)



include ../../common.mk
