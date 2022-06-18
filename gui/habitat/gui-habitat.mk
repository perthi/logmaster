# c-ring.mk


LIBNAME_SO=libhabitat.so

SRCCPP += GUIHabitatWidget.cpp

export CPPFLAGS := $(CPPFLAGS_RELAXED)
CPPFLAGS += -Wall -Wpedantic

ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../common.mk
include ../../../gui.mk
