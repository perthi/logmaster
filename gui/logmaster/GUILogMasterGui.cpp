// -*- mode: c++ -*-


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "GUILogMasterGui.h"

#include <bitset>
#include <QtCore/QDebug>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QButtonGroup>
#include <QtCore/QSettings>


#include <logging/LLogApi.h>

using namespace LOGMASTER;

GUILogMasterGui::GUILogMasterGui(int target, APILogmaster* KALogmaster, QWidget *parent)
    :QWidget(parent),
    fOutputTargetGb(0),
    fMessageFormatGb(0),
    fLogMasterGb(0),
    fSubsystemSigActMapper(0),
    fTestMessagesButton(0),
    fCommandToLogmasterLabel(0),
    fPlainTextEdit(0),
    fSubsystemControlLabel(0),
    fSubsystemCombo(0),
    fClearMessagesButton(0)
{
    fTarget = target;
    fKALogmaster = KALogmaster;
    InitGui();
    RetranslateUi();
}


GUILogMasterGui::~GUILogMasterGui()
{

}


/** @brief      InitGui
*   @details    This Function will make a new QHBoxLayout for:  InitOutputTarget()
                                                                InitMessageFormat()
                                                                fTestMessagesButton
                                                                InitSystemAndLevelControl()
                                                                fCommandToLogmasterLabel
                                                                fPlainTextEdit
                                                                fSubsystemCombo
                                                                fClearMessagesButton
                One layout will be populated for each Tab/target in the GUILogMasterTab class**/
void 
GUILogMasterGui::InitGui()
{
    fOutputTargetGb = InitOutputTarget();
    fMessageFormatGb = InitMessageFormat();

    //Test messages button:
    fTestMessagesButton = new QPushButton(this);
    connect(fTestMessagesButton, SIGNAL(clicked()),
        this, SLOT(TestMessages()));

    QVBoxLayout *leftLay = new QVBoxLayout;
    leftLay->addWidget(fOutputTargetGb);
    leftLay->addWidget(fMessageFormatGb);
    leftLay->addWidget(fTestMessagesButton);

    //Log Master Sub System and Level Control
    fLogMasterGb = InitSystemAndLevelControl();

    //Command label and window
    fCommandToLogmasterLabel = new QLabel(this);

    fPlainTextEdit = new QPlainTextEdit(this);
    fPlainTextEdit->setReadOnly(true);
    fPlainTextEdit->setWordWrapMode(QTextOption::NoWrap);
    fPlainTextEdit->setMaximumBlockCount(25);

    QVBoxLayout *commandLay = new QVBoxLayout;
    commandLay->addWidget(fCommandToLogmasterLabel);
    commandLay->addWidget(fPlainTextEdit);

    //Logmaster Subsystem Control label
    fSubsystemControlLabel = new QLabel(this);

    //Logmaster Subsystem Control ComboBox
    fSubsystemCombo = new QComboBox(this);
    for (auto &tag : fKALogmaster->GetSubSystemsControl())
    { 
       fSubsystemCombo->addItem(tag.GetName().c_str(), QVariant::fromValue( tag.GetValue()) ); 
    }

    connect(fSubsystemCombo, SIGNAL(currentIndexChanged(int)),
        this, SLOT(SubSystemControlClicked()));

    //Clear button
    fClearMessagesButton = new QPushButton(this);

    connect(fClearMessagesButton, SIGNAL(clicked()),
        this, SLOT(ClearMessages()));

    QVBoxLayout *comboAndButtonLay = new QVBoxLayout;
    comboAndButtonLay->addWidget(fSubsystemControlLabel);
    comboAndButtonLay->addWidget(fSubsystemCombo);
    comboAndButtonLay->addWidget(fClearMessagesButton);
    comboAndButtonLay->addStretch();

    //Layout bottom right
    QHBoxLayout *bottomRightLay = new QHBoxLayout;
    bottomRightLay->addLayout(commandLay);
    bottomRightLay->addLayout(comboAndButtonLay);

    //Layout right
    QVBoxLayout *rightLay = new QVBoxLayout;
    rightLay->addWidget(fLogMasterGb);
    rightLay->addLayout(bottomRightLay);

    //Main layout
    QHBoxLayout *lay = new QHBoxLayout;
    lay->addLayout(leftLay);
    lay->addLayout(rightLay);
    this->setLayout(lay);
}


/** @brief      RetranslateUi
*   @details    This Function will configure the panel according to the qrc stylesheet**/
void GUILogMasterGui::RetranslateUi()
{
    fTEXT_outputTarget = tr("Output Target");
    fTEXT_messageFormat = tr("Message Format");
    fTEXT_logMaster = tr("Logmaster System and Level Control");
    fTEXT_testMessages = tr("&Test Messages");
    fTEXT_commandToLogmaster = tr("Command to Logmaster System messages");
    fTEXT_subsystemControl = tr("Logmaster Subsystem Control");
    fTEXT_clearMessages = tr("Clear all messages");

    fOutputTargetGb->setTitle(fTEXT_outputTarget);
    fMessageFormatGb->setTitle(fTEXT_messageFormat);
    fLogMasterGb->setTitle(fTEXT_logMaster);

    fSubsystemControlLabel->setText(fTEXT_subsystemControl);
    fTestMessagesButton->setText(fTEXT_testMessages);
    fClearMessagesButton->setText(fTEXT_clearMessages);

    fCommandToLogmasterLabel->setText(fTEXT_commandToLogmaster);

    QSettings settings;
    settings.beginGroup("StyleSettings");
    QString currStyle = settings.value("currentStyle").toString();

    if (currStyle != "Ferrotech")
    {
        QString ss = QString("font: \"Courier\"; background-color:  #000000;");
        fPlainTextEdit->setStyleSheet(ss);
    }
    else
    {
        QString ss = QString("font: \"Courier\"; background-color:  #000000;");
        fPlainTextEdit->setStyleSheet(ss);
    }
    
}


/** @brief      InitOutputTarget
*   @details    This Function makes a new QGroupBox and populates One selected Output target for the "Output Target" field.
                The function returns a pointer to QGroupBox.**/
QGroupBox* GUILogMasterGui::InitOutputTarget()
{
    QGroupBox* outputTargetGb = new QGroupBox(this);

    QVBoxLayout* outputTargetLay = new QVBoxLayout;

    QButtonGroup* outputTargetChecks = new QButtonGroup(this);
    outputTargetChecks->setExclusive(false);

    for (auto &target : fKALogmaster->GetOutputTargets())
    {
        if(fTarget == target.GetValue())
        {
            QCheckBox* checkbox = new QCheckBox(this);
            checkbox->setChecked(target.GetEnabled());
            checkbox->setText(target.GetName().c_str());
            outputTargetChecks->addButton(checkbox);
            outputTargetLay->addWidget(checkbox);
        }
    }

    outputTargetLay->addStretch();
    outputTargetGb->setLayout(outputTargetLay);

    connect(outputTargetChecks, SIGNAL(buttonClicked(QAbstractButton *)),
        this, SLOT(OutputTargetChecksClicked(QAbstractButton *)));

    return outputTargetGb;
}


/** @brief      InitMessageFormat
*   @details    This Function makes a new QGroupBox and populates all message formats received from the API, a check box is made for every format.
                The function returns a pointer to QGroupBox.**/
QGroupBox* GUILogMasterGui::InitMessageFormat()
{
    QGroupBox* informationLevelGb = new QGroupBox(this);

    QVBoxLayout *informationLevelLay = new QVBoxLayout;
    QButtonGroup *informationLevelChecks = new QButtonGroup(this);
    informationLevelChecks->setExclusive(false);
   
    for(auto &format : fKALogmaster->GetMessageFormat() )
    {           
        QCheckBox* checkbox = new QCheckBox(this);
        checkbox->setChecked(format.GetEnabled());
        checkbox->setText(format.GetName().c_str());
        informationLevelChecks->addButton(checkbox);
        informationLevelLay->addWidget(checkbox);
        fMessageFormatChecks.insert(checkbox, format.GetValue());
    }

    informationLevelLay->addStretch();
    informationLevelGb->setLayout(informationLevelLay);
    
    connect(informationLevelChecks, SIGNAL(buttonClicked(QAbstractButton *)),
        this, SLOT(MessageFormatChecksClicked(QAbstractButton *)));

    return informationLevelGb;
}


/** @brief      InitSystemAndLevelControl
*   @details    This Function  makes a QGroupBox and populates all the various sub systems and levels from the API.
                A Slot is connected to the SubsysAndLevelButtonClicked() first before push buttons are populated with position information.
                Text, X/Y position and color is populated through the API
                The function returns a pointer to QGroupBox.**/
QGroupBox* GUILogMasterGui::InitSystemAndLevelControl()
{
    QGroupBox* logMasterGb = new QGroupBox(this);
    
    //void mappedObject(QObject*);
    
    fSubsystemSigActMapper = new QSignalMapper(this);
    
   // connect(fSubsystemSigActMapper, SIGNAL(mapped(QWidget*)),
   //     this, SLOT(SubsysAndLevelButtonClicked(QWidget*)));
                                          
  //  connect(fSubsystemSigActMapper, SIGNAL(mappedObject(QObject*)),
  //      this, SLOT(SubsysAndLevelButtonClicked(QWidget*)));

    connect(fSubsystemSigActMapper, SIGNAL(mappedObject(QObject*)),
        this, SLOT(SubsysAndLevelButtonClicked(QObject*)));



    QGridLayout* gridLay = new QGridLayout;
    QPushButton* pb;

    for (auto &sysLev : fKALogmaster->GetSubSysAndLevControl())
    {
        pb = new QPushButton(sysLev.GetName().c_str(), this);
        // Push data regarding QPushButton and x/y position into memory map
        StoreSysLevMaps(qMakePair(sysLev.GetYSystem(), sysLev.GetXLevel()), pb);
    
        // in QT, a X = a row, and Y = a column
        gridLay->addWidget(pb, sysLev.GetYSystem(), sysLev.GetXLevel());

        QColor color(sysLev.GetColor());
        QColor light = color.lighter();
        QString ss = QString(
            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 %1, stop: 1 %2);"
        ).arg(color.name()).arg(light.name());
        pb->setObjectName("LogMasterSubsystemButton"); //Use rest of style defined in norspace.qmm with #LogMasterSubsystemButton
        pb->setStyleSheet(ss);
        pb->setCheckable(true);
        pb->setChecked(sysLev.GetEnabled());

        connect(pb, SIGNAL(clicked()),
            fSubsystemSigActMapper, SLOT(map()));

        fSubsystemSigActMapper->setMapping(pb, qobject_cast<QWidget*>(pb));

    }
    logMasterGb->setLayout(gridLay);
   
    return logMasterGb;
}


/** @brief      OutputTargetChecksClicked
*   @details    This Function is a slot that is connected by InitOutputTarget().
                The QAbstractButton object is casted to a QCheckBox to get enabled, and string command to send to the API.
                Then the UpdateTextMessagePanel() function is called to show the commands sent via the API.
*   @param[in]  ab  */
void GUILogMasterGui::OutputTargetChecksClicked(QAbstractButton* ab)
{
    QCheckBox* cb = qobject_cast<QCheckBox*>(ab);
    
    bool enable = cb->isChecked();
    string target = cb->text().toStdString();
    fKALogmaster->SetOutputTarget(target, enable);

    UpdateTextMessagePanel();
}


/** @brief      MessageFormatChecksClicked
*   @details    This Function is a slot that is connected by InitMessageFormat().
                The QAbstractButton object is casted to a QCheckBox to get enabled, and string command to send to the API. 
                Then the UpdateTextMessagePanel() function is called to show the commands sent via the API.
                Then the checkboxes is updated by retrieving data from the API..
*   @param[in]  ab */
void GUILogMasterGui::MessageFormatChecksClicked(QAbstractButton* ab)
{
    QCheckBox* cb = qobject_cast<QCheckBox*>(ab);
    bool enable = cb->isChecked();
    string format = cb->text().toStdString();
    fKALogmaster->SetMessageFormat(format, enable);

    UpdateTextMessagePanel();
    
    
    // Update Checked buttons according to setting in Logging system
    for (auto it = fMessageFormatChecks.begin(); it != fMessageFormatChecks.end(); it++)
    {
        for (auto &f : fKALogmaster->GetMessageFormat())
        {
            if (f.GetValue() == it.value())
            {
                it.key()->setChecked(f.GetEnabled());
            }
        }
    }
}


/** @brief      SubsysAndLevelButtonClicked
*   @details    This Function is a slot that is connected by InitSystemAndLevelControl(). 
                The QWidget button object is used to identify level, system and enable that is input variables to the API SetSubSysAndLevControl() function.
                Then the UpdateTextMessagePanel() function is called to show the commands sent via the API.
                Then the RefreshSubsysAndLevel() function is called to refresh the System and Level fields.
*   @param[in]  button**/
void 
//GUILogMasterGui::SubsysAndLevelButtonClicked(QWidget* button)
GUILogMasterGui::SubsysAndLevelButtonClicked(QObject* button)
{
    // retrieve data from clicked button
    QPushButton* pb = qobject_cast<QPushButton*>(button);
    QPair<int, int> pair = fSysLevControlButtons.value(pb);

    int y_sys = pair.first;
    int x_lev = pair.second;
    bool enable = pb->isChecked();

    fKALogmaster->SetSubSysAndLevControl(x_lev, y_sys, enable);
        
    UpdateTextMessagePanel();

    RefreshSubsysAndLevel();

}

/** @brief      TestMessages
*   @details    This Function will write a set of predefined Test messages**/
void 
GUILogMasterGui::TestMessages()
{
    fKALogmaster->WriteTestMessages();
}


/** @brief      ClearMessages
*   @details    This Function will clear all messages in the GUI panel**/
void 
GUILogMasterGui::ClearMessages()
{
    fPlainTextEdit->clear();
}


/** @brief      SubSystemControlClicked
*   @details    This Function is triggered by an mouse click on the SubsystemCombo box. The selected text is collected from the combo box.
                Then the command is pushed to the API, next the UpdateTextMessagePanel() function is called to show the commands sent via the API.
                Then the RefreshSubsysAndLevel() function is called to refresh the System and Level fields.**/
void 
GUILogMasterGui::SubSystemControlClicked()
{
    QString cmd = fSubsystemCombo->currentText(); 
    string s =  cmd.toStdString();
  //  FORCE_DEBUG("cmd = %s", s.c_str() );
    fKALogmaster->SetSubSystem(cmd.toStdString());
    UpdateTextMessagePanel();
    RefreshSubsysAndLevel();
    
}

/** @brief      UpdateTextMessagePanel
*   @details    This Function ask the KALogmaster API for any messages sent to the Loggingsystem.
                The API is populating a vector, and tis function is iterating through and publishing the 
                commands to the GUI windows for all strings in the vector. In the end the the vector is cleared, making the function ready for new messages**/
void 
GUILogMasterGui::UpdateTextMessagePanel()
{
    std::vector<string> v = fKALogmaster->GetTextFieldData();
    
    for (size_t i = 0; i < v.size(); i++)
    {
        QString str = QString::fromStdString( v.at(i) );
        fPlainTextEdit->appendPlainText(str);
    }

    // Now all data is pushed out, clear the vector
    fKALogmaster->ClearTextFieldData();
}


/** @brief      RefreshSubsysAndLevel
*   @details    This Function will clear the SyslevMaps and then go through all Systems and 
                Levels from the Logging system API to update the GUI QPushButton's**/
void 
GUILogMasterGui::RefreshSubsysAndLevel()
{
    QPushButton* pb;
   // COUT << "size = " << fKALogmaster->GetSubSysAndLevControl().size() << endl;
    
    auto ctrl = fKALogmaster->GetSubSysAndLevControl(); 
    
    for (size_t i = 0; i < ctrl.size(); i++ )
    {   
        if(  ctrl.at(i).GetName() == "Xml" )
        {
            FORCE_DEBUG("%s\t %i %i %i %i %i", ctrl.at(i).GetName().c_str(), ctrl.at(i +1).GetEnabled(), ctrl.at(i +2).GetEnabled(), ctrl.at(i +3).GetEnabled(),  ctrl.at(i +4).GetEnabled(), ctrl.at(i +5).GetEnabled() ) ;
        }
        i+=5;
        if( (i-5) > ctrl.size() ) break;
    }    

    for (auto &sysLev : fKALogmaster->GetSubSysAndLevControl() )
    {   
        pb = fSysLevControlButtonsInv.find(qMakePair(sysLev.GetYSystem(), sysLev.GetXLevel())).value();
        pb->setChecked(sysLev.GetEnabled());
        pb->setText(sysLev.GetName().c_str());
       // FORCE_DEBUG("%i %i %i %s", sysLev.GetXLevel(), sysLev.GetYSystem(), sysLev.GetEnabled(), sysLev.GetName().c_str());

    }
    return;
}


/** @brief      StoreSysLevMaps
*   @details    This Function will store System and Level buttons x/y positions and the QPushButton 
                int two Maps, one inverted related to the other
*   @param[in]  sysLev int1 = y(row-system) position of the button, int2 = x(column-level) position of the button
*   @param[in]  btn a pointer to the actual QPushButton object.**/
void 
GUILogMasterGui::StoreSysLevMaps(QPair<int, int> sysLev, QPushButton* btn)
{

    fSysLevControlButtons.insert(btn, sysLev);
    fSysLevControlButtonsInv.insert(sysLev, btn);
}


/** @brief      ClearSysLevMaps
*   @details    This Function will clear both the fSysLevControlButtons Map and the 
                fSysLevControlButtonsInv Map**/
void 
GUILogMasterGui::ClearSysLevMaps()
{
    fSysLevControlButtons.clear();
    fSysLevControlButtonsInv.clear();
}