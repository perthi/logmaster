

LIBNAME_SO=liblogmaster.so
LIBNAME_A=liblogmaster.a


SRCCPP:= LColorMap.cpp \
	LConversion.cpp \
	LHashMaps.cpp \
	LLogging.cpp \
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
	LEnum2String.cpp \
    LHashMapsAutoGen.cpp \
	LLogTestAutoGen.cpp \
	GException.cpp


#CPPFLAGS+= -Wno-format-truncation  -Wno-format-security


include ../../common.mk



