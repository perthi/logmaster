
LIBNAME_SO=libgui-sensors.so
#LIBNAME_A=libgui-sensors.a

SRCCPP+=GUISensorButtonGroup.cpp \
	GUISensorButtonGroup_moc.cpp \
	GUISensorPushButton.cpp \
	GUISensorPushButton_moc.cpp \
	GUISensors.cpp \
	GUISensors_moc.cpp \
	GUISensorWidget.cpp



export CPPFLAGS:=$(CPPFLAGS_RELAXED)
export INCLUDES+=$(PROTOBUF_INCLUDES)

include ../../../common.mk
INCLUDES+= -I $(QT_INCLUDE) 
