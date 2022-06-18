// main.cpp
// karl eirik bang fossberg

#include <QtWidgets/QApplication>
#include <QtGStreamer/QGst/Init>

#include <iostream>
#include "MediaApllication.h"

int main(int argc, char** argv)
{

    QApplication application(argc, argv);
    QGst::init(&argc, &argv);

    MediaApplication media;
    media.show();

    return application.exec();
};
