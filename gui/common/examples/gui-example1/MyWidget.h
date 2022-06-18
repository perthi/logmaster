#pragma once

// Qt includes
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

#include <common/FDefinitions.h>

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget * parent = 0);
	public slots:
	void UpdateLabel();

private:
	QLabel *label;
	QLabel *label2;
};

