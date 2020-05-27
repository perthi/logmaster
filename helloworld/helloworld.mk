
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -llogmaster  -lutilities  -lexception  -lreadline
LIBS+=$(PROTOBUF_LIBS)



include ../../common.mk
