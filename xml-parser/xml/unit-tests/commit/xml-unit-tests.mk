
PROGRAM:=xml-unit-tests


SRCCPP += xml-unit-tests.cpp \
	TestGXmlClassFactory.cpp \
	TestGXmlValidatorImpl.cpp 

include ../../../../../common.mk
include ../../../../../unittest-common.mk

#LIBS+=  -lreadline -lxml-embc  -lxml2
LIBS+=  -lxml-embc  -lxml2 -lfmt -lutilities -llogmaster -lsqlite-embc -lutilities -lreadline

INCLUDES+=$(GTEST_INCLUDES)
