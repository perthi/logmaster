// -*- mode: c++ -*-

#ifndef _GUI_FSM_STATE_H_
#define _GUI_FSM_STATE_H_

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMenu>
#include <QtCore/QSignalMapper>
#include <QtCore/QMutex>
#include <api/api-fsm/APIFSMNodeInfo.h>

#include <utilities/GDefinitions.h>


 /// @brief     Widget class to contain state label, button and context menu in the FSM GUI
class GUIPushButton;
    class GUIFsmState : public QWidget
    {
        Q_OBJECT

    public:
		GUIFsmState(APIFSMNodeInfo, QWidget *parent);
		~GUIFsmState();
	
    signals:
        void  ShowStateChildren(string);
        void  OpenStateDialog(string);

    private slots :
        void ShowMenu();
        void ShowChildren();
        void OpenDialog();
        void SendAction(QString);

    private: // functions
       void InitGui(APIFSMNodeInfo);
       void ConnectSignals();

    private: // member objects
		GUIFsmState(GUIFsmState& o);
		GUIFsmState& operator=(GUIFsmState& rhs);
		QLabel* fLabel;
        GUIPushButton* fButton;
        QSignalMapper* fMenuSigActMapper;
        QMenu* fMenu;
		mutable QMutex fMutex;
		APIFSMNodeInfo fInfo;
    };



#endif