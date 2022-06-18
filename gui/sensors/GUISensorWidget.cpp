// -*- mode: c++ -*-



/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/


#include "GUISensorWidget.h"

#include <api/api-sensors/APISensors.h>
#include <api/api-sensors/APISensorInfo.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtCore/QTimer>

#include  <gui/sensors/GUISensorPushButton.h>
#include  <gui/sensors/GUISensorButtonGroup.h>
#include <vector>
using std::vector;


GUISensorWidget::GUISensorWidget()
{
	this->setLayout(GenerateLayout());
}


GUISensorWidget::~GUISensorWidget()
{

}


QVBoxLayout  *
GUISensorWidget::GenerateLayout()
{
    vector<APISensorInfo> s_info_v = APISensors::Instance()->QuerySensorList();
	QVBoxLayout* layout_v = new QVBoxLayout();
	GUISensorPushButton* update = new  GUISensorPushButton("update");
	QTimer* timer = new QTimer( );
	timer->start(1000);
	layout_v->addWidget(update);

	for (size_t i = 0; i < s_info_v.size(); i++)
	{
		GUISensorButtonGroup* g = new  GUISensorButtonGroup( s_info_v.at(i) );
		update->connect(update, SIGNAL(clicked()), g , SLOT(aslot()));
		update->connect(timer, SIGNAL(timeout()), g, SLOT(aslot()));
		layout_v->addLayout(g->GetLayout());
	}





    return layout_v;


}