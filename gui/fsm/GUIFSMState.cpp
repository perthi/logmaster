// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtWidgets/QHBoxLayout>
#include <QtCore/QMutexLocker>

#include <api/api-fsm/APIFSMController.h>
#include <gui/common/GUIPushButton.h>
#include "GUIFSMState.h"


#include <logging/LLogApi.h>

using namespace LOGMASTER;

GUIFsmState::GUIFsmState(APIFSMNodeInfo info, QWidget *parent)
   :QWidget(parent),
fMutex(QMutex::Recursive),
    fLabel(0),
    fButton(0),
    fMenuSigActMapper(0),
    fMenu(0)
{
	///FORCE_DEBUG("Calling Constructor GUIFsmState");
    InitGui(info);
    ConnectSignals();
}


GUIFsmState::~GUIFsmState()
{
	QMutexLocker locker(&fMutex);

	///FORCE_DEBUG("Calling Destructor!!");

	if ((this == nullptr) || (((size_t)this) < 256))
	{
		FSM_FATAL("GUIFsmState is NULL in destructor");
		return;
	}

	if (fLabel != nullptr)
	{
		delete fLabel;
		fLabel = nullptr;
	}
	if (fButton != nullptr)
	{
		delete fButton;
		fButton = nullptr;
	}
	if (fMenuSigActMapper != nullptr)
	{
		delete fMenuSigActMapper;
		fMenuSigActMapper = nullptr;
	}
	if (fMenu != nullptr)
	{
		delete fMenu;
		fMenu = nullptr;
	}
}


void 
GUIFsmState::InitGui(APIFSMNodeInfo info)
{
	QMutexLocker locker(&fMutex);

   fInfo = info;
   fLabel = new QLabel(info.fName.c_str(), this); 
   fButton = new GUIPushButton(info.fState.c_str(), this);
   
   //Set color
   QColor color(info.fColor);
   QColor light(color);
   light = light.lighter(150);
   QString ss = QString(
       "border: 2px solid #8f8f91;"
       "border-radius: 6px;"
       "color: #000000;"
       "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 %1, stop: 1 %2);"
       "min-width: 120px;"
       "min-height: 40px;"
   ).arg(color.name()).arg(light.name());
   fButton->setStyleSheet(ss);
   
   fMenuSigActMapper = new QSignalMapper(this);
   connect(fMenuSigActMapper, SIGNAL(mapped(QString)),
       this, SLOT(SendAction(QString)));

   fMenu = new QMenu(this);
   for (auto action : info.fValidActions) 
   {
       QString s =   QString( std::get<0>(action).c_str()) + " -> " + QString(std::get<1>(action).c_str());  

       QAction* act = new QAction( s, this );

       fMenu->addAction(act);
	   connect(act, SIGNAL(triggered()), fMenuSigActMapper, SLOT(map()));
       fMenuSigActMapper->setMapping(act, QString(std::get<0>(action).c_str()));
   }

   QHBoxLayout *lay = new QHBoxLayout;
   lay->setContentsMargins(0, 0, 0, 0);
   lay->addWidget(fLabel);
   lay->addWidget(fButton);   
   this->setLayout(lay);

}

void
GUIFsmState::ConnectSignals()
{
	QMutexLocker locker(&fMutex);

    connect(fButton, SIGNAL(rightClicked()),
        this, SLOT(ShowMenu()));

    connect(fButton, SIGNAL(leftClicked()),
        this, SLOT(ShowChildren()));

    connect(fButton, SIGNAL(doubleClicked()),
        this, SLOT(OpenDialog()));
}


GUIFsmState::GUIFsmState(GUIFsmState & o)
{

}

GUIFsmState & 
GUIFsmState::operator=(GUIFsmState & rhs)
{
	return(rhs);
}

void
GUIFsmState::ShowMenu()
{
	QMutexLocker locker(&fMutex);

    fMenu->popup(mapToGlobal(fButton->rect().bottomRight()));
}

void
GUIFsmState::ShowChildren()
{
	QMutexLocker locker(&fMutex);
    if (fInfo.fLevel < 2) {
        emit ShowStateChildren(fInfo.fName);
    }
}

void
GUIFsmState::OpenDialog()
{
	QMutexLocker locker(&fMutex);

    //undo the first click
    ShowChildren();

    emit OpenStateDialog(fInfo.fName);
}

void
GUIFsmState::SendAction(QString action)
{
	QMutexLocker locker(&fMutex);

	APIFSMController::Instance()->Excec(action.toUtf8().constData(), fInfo.fName);
}
