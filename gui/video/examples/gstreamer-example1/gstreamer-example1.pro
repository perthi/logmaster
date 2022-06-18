# minimal-working-example.pro
# karl eirik bang fossberg


QT += core widgets gui

CONFIG += link_pkgconfig

PKGCONFIG += Qt5GStreamer-1.0
PKGCONFIG += Qt5GStreamerUi-1.0

SOURCES += \
    ../../src/main.cpp \
    ../../src/mediaapplication.cpp \
    ../../src/mediaplayer.cpp

HEADERS += \
    ../../src/mediaapplication.hpp \
    ../../src/mediaplayer.hpp


