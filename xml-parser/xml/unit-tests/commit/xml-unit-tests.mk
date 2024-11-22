
PROGRAM:=xml-unit-tests


SRCCPP += xml-unit-tests.cpp \
	TestGXmlClassFactory.cpp \
	TestGXmlValidatorImpl.cpp 

include ../../../../../common.mk
include ../../../../../unittest-common.mk


LIBS+=  -lxml-embc  -lxml2  -lutilities -llogmaster -lsqlite-embc -lutilities -lreadline

INCLUDES+=$(GTEST_INCLUDES)
