

PROGRAM:=database-test
SRCCPP+=database-test.cpp

LIBS+=    -llogmaster  -lutilities  -lexception  -lreadline  -lsqlite-embc -ldl -lpthread
LIBS+=$(PROTOBUF_LIBS)



include ../../common.mk
