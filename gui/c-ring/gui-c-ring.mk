# c-ring.mk


LIBNAME_SO=libc-ring.so
#LIBNAME_A=libc-ring.a

SRCCPP += GUICringWidget.cpp \
	GUICringWidget_moc.cpp \
	GUICringButtonGroup.cpp \
	GUICringButtonGroup_moc.cpp \
	GUICringController.cpp \
	GUICringController_moc.cpp \
	GUICringAbsolutePos.cpp \
	GUICringAbsolutePos_moc.cpp \
	GUICringController180.cpp \
	GUICringController180_moc.cpp \
	GUICringController360.cpp \
	GUICringController360_moc.cpp \
	GUICringGraphicalIndicators.cpp \
	GUICringGraphicalIndicators_moc.cpp \
	GUICringGraphicalGraph.cpp \
	GUICringGraphicalGraph_moc.cpp \
	GUICringQuadView.cpp \
	GUICringQuadView_moc.cpp \
	GUICringQuadView180.cpp \
	GUICringQuadView360.cpp

export CPPFLAGS := $(CPPFLAGS_RELAXED)
CPPFLAGS += -Wall -Wpedantic

ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../common.mk
include ../../../gui.mk
