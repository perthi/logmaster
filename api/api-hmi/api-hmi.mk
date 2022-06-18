
LIBNAME_SO=libapi-hmi.so
#LIBNAME_A=libapi-hmi.a


SRCCPP:= APIHmi.cpp \
	 APIHmiCRing.cpp \
	 APIHmiCRing180.cpp \
	 APIHmiCRing360.cpp \
	 APIHmiOperation.cpp \
	 APIHmiOperationCoating.cpp \
	 APIHmiOperationSurfacePrep.cpp \
	 APIHmiOperationWrapping.cpp \
	 APIHmiOperationPatching.cpp \
	 APICRingInfo.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)
export INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../common.mk


ifneq (arm, $(TARGET))
LIBS+= -lX11
endif

