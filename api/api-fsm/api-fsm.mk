
LIBNAME_SO=libapi-fsm.so
#LIBNAME_A=libapi-fsm.a


SRCCPP:= APIFSMController.cpp \
	APIFSMControllerDebug.cpp \
	APIFSMNodeInfo.cpp



export CPPFLAGS:=$(CPPFLAGS_RELAXED)

export INCLUDES+= $(PROTOBUF_INCLUDES)


# LIBS += -lgui-operations


include ../../../common.mk

ifneq (arm, $(TARGET))
LIBS+= -lX11
endif

