
#LIBNAME_SO=libapi-logmaster.so
LIBNAME_A=libapi-logmaster.a


SRCCPP:= APILogmasterBitmap.cpp \
	 APILogmaster.cpp \
	 APILogmasters.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk


ifneq (arm, $(TARGET))
LIBS+= -lX11
endif

