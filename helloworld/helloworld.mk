
PROGRAM:=helloworld
SRCCPP+=helloworld.cpp


LIBS+=    -llogmaster  -lutilities  -lexception  -lreadline  -lsqlite-embc
LIBS+=$(PROTOBUF_LIBS)



include ../../common.mk
