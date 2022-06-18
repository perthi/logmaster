
#LIBNAME_SO=libapi-logmaster.so
LIBNAME_A=libapi-logmaster.a


SRCCPP:= APILogmasterBitmap.cpp \
	 APILogmaster.cpp \
	 APILogmasters.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk

#INCLUDES+= -I $(QT_DIR)/include/ -I $(QT_DIR)/include/QtCore  -I $(QT_DIR)/include/QtWidgets   

#LIBS+= -lboost_filesystem -lm

ifneq (arm, $(TARGET))
LIBS+= -lX11
endif

