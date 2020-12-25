

PROGRAM:=database-test
SRCCPP+=database-test.cpp

LIBS+=    -llogmaster  -lutilities  -lexception   -lsqlite-embc -ldl -lpthread


ifneq (arm, $(TARGET))
LIBS+=  -lreadline
endif

include ../../common.mk
