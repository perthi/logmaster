

PROGRAM=configurator-unit-tests

SRCCPP:=configurator-unit-tests.cpp   \
		TestLConfigurator.cpp


include ../../../../common.mk
include ../../../../unittest-common.mk


LIBS+= -llogmaster  -lexception  -lutilities -ltestlib -lconfigurator  -lexception  -lxml-embc   -lxml2
INCLUDES+=$(GTEST_INCLUDES)

