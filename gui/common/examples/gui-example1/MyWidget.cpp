
#include "MyWidget.h"

MyWidget::MyWidget(QWidget * parent) : QWidget(parent)
{
	QPushButton * button = new QPushButton(this);
	label = new QLabel(this);

	QHBoxLayout* lay = new QHBoxLayout();
	lay->addWidget(button);
	lay->addWidget(label);

	button->setText("test");
	label->setText("label");

	QHBoxLayout* lay2 = new QHBoxLayout();
	QPushButton * button2 = new QPushButton(this);
	label2 = new QLabel(this);

	button2->setText("test2");
	label2->setText("label2");

	lay2->addWidget(button2);
	lay2->addWidget(label2);

	QVBoxLayout* mainLay = new QVBoxLayout();
	mainLay->addLayout(lay);
	mainLay->addLayout(lay2);

	this->setLayout(mainLay);

	connect(button, SIGNAL(clicked()), this, SLOT(UpdateLabel()));
}


void 
MyWidget::UpdateLabel()
{
	label->setText("updated text");
}