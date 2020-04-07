

LIBNAME_SO:=libexception.so
LIBNAME_A:=libexception.a


SRCCPP+= GStackTrace.cpp \
	 GException.cpp



include ../../common.mk
