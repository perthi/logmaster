// -*- mode: c++ -*-
#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <utilities/GDefinitions.h>

class QApplication;

class GUIInitStyles
{
public:
	static void API Init(QApplication *app);

private:
	GUIInitStyles() {};
};

