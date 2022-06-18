
LIBNAME_SO:= libgui-operations.so

SRCCPP += \
	GUICringOperationsButtonGroup.cpp \
	GUICringOperationsButtonGroup_moc.cpp \
	GUICringOperationsIndicatorBar.cpp \
	GUICringOperationsSliderBar.cpp \
	GUICringOperationsSliderBar_moc.cpp \
	GUICringOperationsGraph.cpp \
	GUICringOperationsGraph_moc.cpp \
	GUICringOperationsBase.cpp \
	GUICringOperationsBase_moc.cpp \
	GUICringOperationsShowAll.cpp \
	GUICringOperationsSurfacePrep.cpp \
	GUICringOperationsSurfacePrep_moc.cpp \
	GUICringOperationsPatching.cpp \
	GUICringOperationsPatching_moc.cpp \
	GUICringOperationsWrapping.cpp \
	GUICringOperationsCoating.cpp \
	GUICringOperationsCoating_moc.cpp \
	GUICringOperationsSequencer.cpp \
	GUICringOperationsSequencer_moc.cpp



export CPPFLAGS := $(CPPFLAGS_RELAXED)
CPPFLAGS += -Wall -Wpedantic

#LIBS += -lapi-hmi -lsequence -lc-ring -lQt5Charts

INCLUDES+=$(PROTOBUF_INCLUDES)


include ../../../common.mk
include ../../../gui.mk
