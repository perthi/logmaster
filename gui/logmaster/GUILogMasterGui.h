// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUILogMasterGui
///  @brief     GUI for controlling the Logmaster


#ifndef _LOGMASTER_GUI_H_
#define _LOGMASTER_GUI_H_

#include <common/FDefinitions.h>
#include <api/api-logmaster/APILogmaster.h>
#include <api/api-logmaster/APILogmasters.h>


#include  <QtWidgets/QWidget>

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtCore/QMap>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QComboBox>
#include <QtCore/QSignalMapper>

    class GUILogMasterGui : public QWidget
    {
        Q_OBJECT

    public:
        explicit API GUILogMasterGui(int target, APILogmaster* KALogmaster, QWidget *parent = 0);
        API ~GUILogMasterGui();

    //signals:

    private slots :
        void OutputTargetChecksClicked(QAbstractButton*);
        void MessageFormatChecksClicked(QAbstractButton*);
       // void SubsysAndLevelButtonClicked(QWidget* button);
        void SubsysAndLevelButtonClicked(QObject* button);
        void SubSystemControlClicked();
        void TestMessages();
        void ClearMessages();


    private: 
        void InitGui();
        void RetranslateUi();
        QGroupBox* InitOutputTarget();
        QGroupBox* InitMessageFormat();
        QGroupBox* InitSystemAndLevelControl();
        void UpdateTextMessagePanel();

        void RefreshSubsysAndLevel();
        void StoreSysLevMaps(QPair<int, int> sysLev, QPushButton* btn);
        void ClearSysLevMaps();

    private:
        GUILogMasterGui(const GUILogMasterGui&);
        GUILogMasterGui operator=(const GUILogMasterGui&); 

        APILogmaster* fKALogmaster = nullptr;     // Used to get one instance of KALogmaster
        APILogMasters* fAPILogMasters = nullptr;
       
        QGroupBox* fOutputTargetGb = nullptr;
        QGroupBox* fMessageFormatGb = nullptr;
        QGroupBox* fLogMasterGb = nullptr;

        QMap<QCheckBox*, int> fMessageFormatChecks{};
        
        QSignalMapper* fSubsystemSigActMapper = nullptr; 
        QMap<QPushButton*, QPair<int, int>> fSysLevControlButtons{}; // int1 = Y() and int 2 = X
        QMap<QPair<int, int>, QPushButton*> fSysLevControlButtonsInv{}; // int1 = Y and int 2 = X
        int fTarget = 0;

        QPushButton* fTestMessagesButton = nullptr;

        QLabel* fCommandToLogmasterLabel = nullptr;
        QPlainTextEdit* fPlainTextEdit = nullptr;

        QLabel* fSubsystemControlLabel = nullptr;
        QComboBox* fSubsystemCombo = nullptr;
        QPushButton* fClearMessagesButton = nullptr;

        QString fTEXT_outputTarget{};
        QString fTEXT_messageFormat{};
        QString fTEXT_logMaster{};
        QString fTEXT_testMessages{};
        QString fTEXT_commandToLogmaster{};
        QString fTEXT_subsystemControl{};
        QString fTEXT_clearMessages{};
    };


#endif
