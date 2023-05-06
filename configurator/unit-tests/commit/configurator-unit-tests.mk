


PROGRAM=configurator-unit-tests

SRCCPP:=configurator-unit-tests.cpp \
		TestLConfigurator.cpp \
		TestLXmlParser.cpp

include  ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=  -lconfigurator -lxml-embc  -lxml2  -llogmaster  -lcmdline  -lutilities -lreadline -lhistory -lncurses -lsqlite-embc -ldl

LIBS+=  -lm


INCLUDES+=$(GTEST_INCLUDES)
CPPFLAGS+= -DCONFIG_DIR='"$(CONFIG_DIR)"' 
