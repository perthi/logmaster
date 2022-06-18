// -*- mode: c++ -*-

#pragma once

/***************************************************
* @copyright Kongsberg Ferrotech                   *
* @author Per Thomas Hille <pth@embc.no>           *
*                                                  *
* SW developed by Embedded Consulting AS           *
* for Semcon Norge AS                              *
****************************************************/

#include <QtCore/QObject>
#include <api/api-sensors/APISensorInfo.h>
#include <utilities/GDefinitions.h>
#include <QtWidgets/QHBoxLayout>
#include "GUISensorPushButton.h"


class GUISensorButtonGroup : public QObject
{
	Q_OBJECT


	public:
		API GUISensorButtonGroup(const APISensorInfo& info);
		QHBoxLayout API * GetLayout() { return  fLayout; };

public slots:
	void aslot();

private:
	GUISensorPushButton *fIP = nullptr;
	GUISensorPushButton* fType = nullptr;
	GUISensorPushButton *fValue = nullptr;
	GUISensorPushButton* fSubscript = nullptr;
	QHBoxLayout* fLayout = nullptr;
	APISensorInfo fSensorInfo;
};

