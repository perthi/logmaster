

PROGRAM=com-unit-tests



SRCCPP:=com-unit-tests.cpp \
TestTCP.cpp \
TestUDP.cpp

include ../../../../common.mk
include ../../../../unittest-common.mk



LIBS+=  -lcom  -ltestlib -llogmaster  -lcmdline


INCLUDES+=$(GTEST_INCLUDES)

