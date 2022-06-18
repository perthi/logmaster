

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include "MyWidget.h"


int main(int argc, char *argv[])
{	
    QApplication app(argc, argv);
    MyWidget* widget = new MyWidget();
    widget->show();
    app.exec();	
	return 0;
}
