
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -llogmaster  -lutilities  -lexception  -lreadline  -lsqlite-embc -ldl -lpthread
LIBS+=$(PROTOBUF_LIBS)



include ../../common.mk
