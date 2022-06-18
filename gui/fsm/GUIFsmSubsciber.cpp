// -*- mode: c++ -*-


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtCore/QDebug>
#include <QtCore/QMutexLocker>
#include <QtCore/QDateTime>
#include <api/api-fsm/APIFSMController.h>
#include "GUIFsmSubsciber.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;


GUIFsmSubsciber* GUIFsmSubsciber::fInstance = 0;

GUIFsmSubsciber::GUIFsmSubsciber()
	:QObject(0)
{
    //Register subscriber function for receiving FSM updates
	APIFSMController::Instance()->RegisterSubscriber(subscriberFunc);
    this->startTimer(GUIFSM_INTERVAL*1000);	//original 1000
}

GUIFsmSubsciber::~GUIFsmSubsciber()
{
	delete fInstance;
	fInstance = 0;
}

void
GUIFsmSubsciber::timerEvent(QTimerEvent *)
{
    QMutexLocker locker(&fMutex);
	FSM_DEBUG("Calling Update !!!");
	APIFSMController::Instance()->Update();
}


GUIFsmSubsciber* 
GUIFsmSubsciber::GetInstance()
{
	if (0 == fInstance)
	{
		static QMutex mut;
		mut.lock();
		if (0 == fInstance)
		{
			fInstance = new GUIFsmSubsciber();
		}
		mut.unlock();
	}
	return fInstance;
}


void
GUIFsmSubsciber::subscriberFunc(const vector<APIFSMNodeInfo>  &info)
{
    //for (uint i = 0; i < info.size(); i++)
    //{
    //    qDebug() << "Node:" << info[i].fName.c_str() << "\tState: " << info[i].fState.c_str();
    //}
    GetInstance()->sendFsmUpdate(info);
}

void
GUIFsmSubsciber::sendFsmUpdate(const vector<APIFSMNodeInfo>  &info)
{
    emit fsmUpdated(info);
}