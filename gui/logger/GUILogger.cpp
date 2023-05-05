// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <gui/common/GUIDefenitions.h>
#include <logging/LLogging.h>
#include <logging/LPublisher.h>
#include "GUILogger.h"
#include "GUILoggerGui.h"



using namespace LOGMASTER;

GUILogger *gui_instance =  new GUILogger(); /// CRAP PTH


void  logger_callback(const std::shared_ptr<LMessage>  m)
{
	static int cnt = 0;
	gui_instance->newMessage(cnt, *m);
	cnt++;
}


GUILogger::GUILogger()
{
	LLogging::Instance()->RegisterGuiSubscriber( logger_callback );
	auto subscribers = LLogging::Instance()->GetGuiSubscribers();
}


void 
GUILogger::newMessage(int cnt, const LMessage &msg)
{
	GUILoggerGui::AddMessage( cnt, msg );
}

