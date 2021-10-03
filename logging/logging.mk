

LIBNAME_SO=liblogmaster.so
LIBNAME_A=liblogmaster.a


SRCCPP:= LColorMap.cpp \
	LConversion.cpp \
	LHashMaps.cpp \
    LHashMapsBase.cpp \
	LLogging.cpp \
	LLogTest.cpp \
	LMessageFactory.cpp \
	LValidateArgs.cpp \
	LConfig.cpp \
	LDoc.cpp \
	LLogApi.cpp \
	LMessage.cpp \
	LMessageGenerator.cpp \
	LPublisher.cpp \
	LMessage2Json.cpp \
	LDatabase.cpp \
	LEnum2String.cpp



#CPPFLAGS+= -Wno-format-truncation  -Wno-format-security


include ../../common.mk



