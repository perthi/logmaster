


PROGRAM=configurator-unit-tests

#SRCCPP:=configurator-unit-tests.cpp \
		TestLGeneratorP.cpp \
		TestLXmlParser.cpp \
		TestLFileInfo.cpp \
		TestLUtilities.cpp \
		TestXMLInfo.cpp \
		GVersion.cpp


SRCCPP:=configurator-unit-tests.cpp \
        TestLGeneratorP.cpp


include  ../../../../common.mk
include ../../../../unittest-common.mk

LIBS+=  -lconfigurator -lxml-embc  -lxml2  -llogmaster  -lcmdline  -lutilities -lreadline -lhistory -lncurses -lsqlite-embc -ldl

CPP+=  -lmLOGMASTER_HOME=$(PW

INCLUDES+=$(GTEST_INCLUDES)
CPPFLAGS+= -DCONFIG_DIR='"$(CONFIG_DIR)"' -DLOGMASTER_HOME='"$(LOGMASTER_HOME)"'
