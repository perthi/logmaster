
PROGRAM:=c-ring-example1

SRCCPP+=../c-ring-example1.cpp


#LIBS+= -lcommon -llogmaster -lutilities -lreadline -lxml-embc -lxml2 -lcommon -lapi-fsm  -lc-ring -lboost_system -lboost_filesystem  -lpthread

#LIBS+= $(PROTOBUF_LIBS)




#LIBS += -lc-ring  -lgui-common -lQt5Core -lQt5Widgets -lQt5Gui -lQt5Charts -lapi-hmi 
LIBS +=    -lc-ring  -lapi-hmi \
-lintercom   -lcommon  -lgui-common  -lapi-hmi  -lcom  \
 -lprotocol -lconfiguration -lkf-commands  -lcom -lkf-com -lkf-commands -lxml-embc -lxml2  \
 -lcmdline  -llogmaster -lutilities   -lreadline \
 -lboost_system -lboost_filesystem -lQt5Charts -lpthread
LIBS += $(PROTOBUF_LIBS)
CPPFLAGS=$(CPPFLAGS_RELAXED)

INCLUDES+=$(PROTOBUF_INCLUDES)


include ../../../../../common.mk
include ../../../../../gui.mk
