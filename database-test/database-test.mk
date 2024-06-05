

PROGRAM:=database-test
SRCCPP+=database-test.cpp \
        GVersion.cpp  

LIBS+=    -llogmaster  -lutilities  -lcmdline -lutilities -llogmaster  -lsqlite-embc -ldl -lreadline -lhistory -lncurses -ldl -lpthread -lfmt


ifneq (arm, $(TARGET))
LIBS+=  -lreadline
endif

include ../../common.mk
