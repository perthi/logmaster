


PROGRAM=configurator-unit-tests


SRCCPP:=configurator-unit-tests.cpp   \
		TestLConfigurator.cpp \
		TestLXmlParser.cpp


include ../../../../common.mk
include ../../../../unittest-common.mk


#CPPFLAGS+= -DCONFIG_DIR='"$(CURDIR)"'  

CPPFLAGS+= -DCONFIG_DIR='"$(CONFIG_DIR)"' 

LIBS+= -llogmaster  -lexception  -lutilities -ltestlib -lconfigurator  -lexception  -lxml-embc   -lxml2  -lconfigurator 
INCLUDES+=$(GTEST_INCLUDES)

