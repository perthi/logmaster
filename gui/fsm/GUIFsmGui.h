// -*- mode: c++ -*-

#ifndef _FSM_GUI_H_
#define _FSM_GUI_H_

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <common/FDefinitions.h>
#include <api/api-fsm/APIFSMNodeInfo.h>

#include <QtWidgets/QLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include "GUIFSMState.h"

#include <utilities/GDefinitions.h>

#include <string>
using std::string;


    class ScrollAreaContainer;

/**  @brief     Widget class to contain fsm controller GUI */
    class GUIFsmGui : public QWidget
    {
        Q_OBJECT
    
    public:
        explicit  API GUIFsmGui(bool inMainGui = true, QWidget *parent = 0);
		API ~GUIFsmGui();

    public slots:
#ifdef _WIN32
		void  __declspec(dllexport) ShowStateChildren(string node);
#else
		void  ShowStateChildren(string node);
#endif

    signals:
#ifdef _WIN32
		void    __declspec(dllexport) OpenStateDialog(string);
#else
		void   OpenStateDialog(string);
#endif
    private slots:
#ifdef _WIN32
        void     __declspec(dllexport) UpdateGui();
        void      __declspec(dllexport) UpdateFSM();
#else
		void      UpdateGui();
		void      UpdateFSM();
#endif

    private: 
         void      API   ConnectSignals();
         QLayout   API  * createMainGuiWidget();
         QLayout   API  * createDialogGuiWidget();

    private: 
        bool fInMainFsm;
        QVBoxLayout* fLayout;
        QWidget* fWidget;
        ScrollAreaContainer* fScrollArea;
        QVector<GUIFsmState*> fStatebuttons;
        string fSelectedState;
    };


#endif