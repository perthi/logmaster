// -*- mode: c++ -*-

#ifndef _FSM_SUBSCIBER_H_
#define _FSM_SUBSCIBER_H_

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtCore/QObject>
#include <QtCore/QMutex>
#include <api/api-fsm/APIFSMNodeInfo.h>

#define GUIFSM_INTERVAL 1 //seconds between update

////@brief     Class to handle messages from the FSM
    class GUIFsmSubsciber : public QObject
    {
        Q_OBJECT

    public:
        static GUIFsmSubsciber* GetInstance();
        ~GUIFsmSubsciber();

        static void subscriberFunc(const vector<APIFSMNodeInfo>  &);
        
	public slots:

    signals:
	  void fsmUpdated(const vector<APIFSMNodeInfo>  &);

    private: // functions
	    explicit GUIFsmSubsciber();
	    GUIFsmSubsciber(const GUIFsmSubsciber &rhs);
	    GUIFsmSubsciber& operator=(const GUIFsmSubsciber &rhs);
        void timerEvent(QTimerEvent *event);
        void sendFsmUpdate(const vector<APIFSMNodeInfo>  &);

    private: // member objects
	     static GUIFsmSubsciber *fInstance;
	     mutable QMutex fMutex;
    };


#endif