
LIBNAME_SO=libapi-sensors.so
#LIBNAME_A=libapi-sensors.a


SRCCPP:= APISensorInfo.cpp \
	APISensors.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)
export INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../common.mk



ifneq (arm, $(TARGET))
LIBS+= -lX11
endif

