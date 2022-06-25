// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtCore/QDebug>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtCore/QTimer>
#include <QtCore/QSettings>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QButtonGroup>
#include <QtCore/QDateTime>
#include <QtCore/QRegExp>
#include <QtCore/QMetaType>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QMessageBox>

#include <logging/LLogging.h>
#include <logging/LHashMaps.h>
#include "GUILoggerGui.h"
#include <gui/logmaster/GUILogMasterTab.h>

using namespace LOGMASTER;

Q_DECLARE_METATYPE(QRegExp::PatternSyntax)




GUILoggerGui::GUILoggerGui(QWidget *parent)
   :QWidget(parent),
   fPlainTextEditLabel(0),
   fPlainTextEdit(0),
   fLogLevelLabel(0),
   fLogLevelCombo(0),
   fSubSystemLabel(0),
   fChecFSM(0),
   fCheckDriver(0),
   fCheckDatabase(0),
   fCheckQa(0),
   fCheckUser(0),
   fCheckEx(0),
   fRegExpLabel(0),
   fRegExpCombo(0),
   fRegExpEdit(0),
   fConfigureButton(0),
   fClearButton(0),
   fRefreshButton(0),
   fPauseButton(0)
{
   InitGui();
   RetranslateUi();
   ConnectStuff();
   GetAllMessages();
}


GUILoggerGui::~GUILoggerGui()
{

}


void 
GUILoggerGui::InitGui()
{
   QSplitter *splitter = new QSplitter(this);
   QWidget* left = InitLeft();
   QWidget* right = InitRight();
   splitter->addWidget(left);
   splitter->addWidget(right);
   QList<int> sizes;
   sizes.append(left->sizeHint().width());
   sizes.append(100000);
   splitter->setSizes(sizes);
   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget(splitter);
   this->setLayout(lay);
}


QWidget* 
GUILoggerGui::InitLeft()
{
   fLogLevelLabel = new QLabel(this);
   fLogLevelCombo = new QComboBox(this);

   QVBoxLayout *checksLay = new QVBoxLayout;
   fSubSystemLabel = new QLabel(this);
   checksLay->addWidget(fSubSystemLabel);
   QButtonGroup *checks = new QButtonGroup(this);
   checks->setExclusive(false);


   auto hash = LHashMaps::Instance()->GetSystem2StringHash();

  for(auto it = hash->begin(); it != hash->end(); it ++ )
   {
       //Skip all and none systems
       if (it->first == eMSGSYSTEM::SYS_NONE)continue;
       if (it->first == eMSGSYSTEM::SYS_ALL )continue;

       QCheckBox* checkbox = new QCheckBox(this);
       checkbox->setChecked(true);
       checkbox->setText(it->second.c_str());
       checkbox->setProperty("value", (int32_t)it->first);
       checks->addButton(checkbox);
       checksLay->addWidget(checkbox);
       fCheckBoxes.insert(it->first, checkbox);
   }

 
   fRegExpLabel = new QLabel(this);
   fRegExpCombo = new QComboBox(this);

   int re_index = 0;
   //fRegExpCombo->addItem("RegExp", qVariantFromValue(QRegExp::RegExp));
   fRegExpCombo->addItem("RegExp", QVariant::fromValue(QRegExp::RegExp));
   
   fRegExpCombo->setItemData(re_index++, "A rich Perl - like pattern matching syntax.This is the default.", Qt::ToolTipRole);
   fRegExpCombo->addItem("RegExp2", QVariant::fromValue(QRegExp::RegExp2));
   fRegExpCombo->setItemData(re_index++, "Like RegExp, but with greedy quantifiers. (Introduced in Qt 4.2.)", Qt::ToolTipRole);
   fRegExpCombo->addItem("Wildcard", QVariant::fromValue(QRegExp::Wildcard));
   fRegExpCombo->setItemData(re_index++, "This provides a simple pattern matching syntax similar to that used by shells(command interpreters) for \"file globbing\".See QRegExp wildcard matching.", Qt::ToolTipRole);
   fRegExpCombo->addItem("WildcardUnix", QVariant::fromValue(QRegExp::WildcardUnix));
   fRegExpCombo->setItemData(re_index++, "This is similar to Wildcard but with the behavior of a Unix shell.The wildcard characters can be escaped with the character \"\\\".", Qt::ToolTipRole);
   fRegExpCombo->addItem("FixedString", QVariant::fromValue(QRegExp::FixedString));
   fRegExpCombo->setItemData(re_index++, "The pattern is a fixed string.This is equivalent to using the RegExp pattern on a string in which all metacharacters are escaped using escape().", Qt::ToolTipRole);
   fRegExpCombo->addItem("W3CXmlSchema11", QVariant::fromValue(QRegExp::W3CXmlSchema11));
   fRegExpCombo->setItemData(re_index++, "The pattern is a regular expression as defined by the W3C XML Schema 1.1 specification.", Qt::ToolTipRole);

   connect(fRegExpCombo, SIGNAL(currentIndexChanged(int)),
       this, SLOT(RegExpSyntaxUpdated()));

   fRegExpEdit = new QLineEdit(this);
   connect(fRegExpEdit, SIGNAL(editingFinished()),
       this, SLOT(RegExpUpdated()));

   QHBoxLayout *regExpLay = new QHBoxLayout;
   regExpLay->addWidget(fRegExpEdit);
   regExpLay->addWidget(fRegExpCombo);

   fConfigureButton = new QPushButton(this);
   fConfigureButton->setFixedSize(65, 25);
   connect(fConfigureButton, SIGNAL(clicked()),
       this, SLOT(OpenLogMasterDialog()));

   fClearButton = new QPushButton(this);
   fClearButton->setFixedSize(65,25);
   connect(fClearButton, SIGNAL(clicked()),
       this, SLOT(ClearLog()));

   fRefreshButton = new QPushButton(this);
   fRefreshButton->setFixedSize(65, 25);
   connect(fRefreshButton, SIGNAL(clicked()),
       this, SLOT(GetAllMessages()));

   fPauseButton = new QPushButton(this);
   fPauseButton->setFixedSize(65, 25);
   fPauseButton->setCheckable(true);
   connect(fPauseButton, SIGNAL(clicked()),
       this, SLOT(Pause()));

   QHBoxLayout *buttonLay = new QHBoxLayout;
   buttonLay->addWidget(fConfigureButton);
   buttonLay->addWidget(fClearButton);
   buttonLay->addWidget(fRefreshButton);
   buttonLay->addWidget(fPauseButton);
   buttonLay->addStretch();

   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget(  fLogLevelLabel );
   lay->addWidget(  fLogLevelCombo );
   lay->addLayout(checksLay);
   lay->addStretch();
   lay->addWidget(fRegExpLabel);
   lay->addLayout(regExpLay);
   lay->addLayout(buttonLay);

   //Setting object names for styling
   fRegExpCombo->setObjectName("LoggingWindow");
   fRegExpLabel->setObjectName("LoggingWindow");
   fRegExpEdit->setObjectName("LoggingWindow");
   fConfigureButton->setObjectName("LoggingWindow");
   fClearButton->setObjectName("LoggingWindow");
   fRefreshButton->setObjectName("LoggingWindow");
   fPauseButton->setObjectName("LoggingWindow");

   QWidget *w = new QWidget(this);
   w->setLayout(lay);
   w->setObjectName("GUIWidget");
   return w;
}


QWidget* 
GUILoggerGui::InitRight()
{
   fPlainTextEditLabel = new QLabel(this);
   QHBoxLayout *llay = new QHBoxLayout;
   llay->addWidget( fPlainTextEditLabel);
   llay->addStretch();
   fPlainTextEdit = new QPlainTextEdit(this);
   fPlainTextEdit->setReadOnly(true);
   fPlainTextEdit->setWordWrapMode(QTextOption::NoWrap);
   fPlainTextEdit->setMaximumBlockCount(2000);

   QVBoxLayout *lay = new QVBoxLayout;
   lay->addLayout(llay);
   lay->addWidget( fPlainTextEdit );
   QWidget *w = new QWidget(this);
   w->setLayout(lay);
   w->setObjectName("GUIWidget");
   return w;
}


void 
GUILoggerGui::RetranslateUi()
{
   fTEXT_messages = tr("Messages");
   fTEXT_logLevel = tr("Log Level");
   fTEXT_subSystems = tr("Sub Systems");
   fTEXT_regExp = tr("Reg Exp");
   fTEXT_configure = tr("Configure");
   fTEXT_clear = tr("Clear");
   fTEXT_refresh = tr("Refresh");
   fTEXT_pause = tr("Pause");
   fTEXT_unpause = tr("Unpause");
      
   QSettings settings;
   settings.beginGroup("StyleSettings");
   QString currStyle = settings.value("currentStyle").toString();
   if (currStyle == "Ferrotech")
   {
      QString _font = "QLabel { font: \"Courier\" 18px; color: white; }";
      fLogLevelLabel->setStyleSheet(_font);
      COUT << "STYLE IS FERROTECH" << endl;  
   }
   else {
        COUT << "STYLE IS NOT FERROTECH" << endl;  
       QString ss = QString("QPlainTextEdit{ background-color:  #000000; }");
       fPlainTextEdit->setStyleSheet(ss);

   }
   fPlainTextEditLabel->setText(fTEXT_messages);
   fLogLevelLabel->setText(fTEXT_logLevel);
   fSubSystemLabel->setText(fTEXT_subSystems);
   fRegExpLabel->setText(fTEXT_regExp);
   fConfigureButton->setText(fTEXT_configure);
   fClearButton->setText(fTEXT_clear);
   fRefreshButton->setText(fTEXT_refresh);
   fPauseButton->setText(fTEXT_pause);

   fLogLevelCombo->clear();

   auto hash = LHashMaps::Instance()->GetLevel2StringHash();

   for(auto it = hash->begin(); it != hash->end(); it ++  )
   {
       ///qDebug() << "lvl.first: " << (int)it->first;
       fLogLevelCombo->addItem(it->second.c_str(), (int)it->first);
   }

   // Adjust to LOG_INFO to get INFO messages from Analyse and User
   for (int i = fLogLevelCombo->count(); i > 0; i--)
   {
       fLogLevelCombo->setCurrentIndex(i - 1);
       int currentLevel = fLogLevelCombo->currentData().toInt();

       if(currentLevel == (int)eMSGLEVEL::LOG_INFO)
       {
           break;
       }
   }
}

void
GUILoggerGui::ConnectStuff()
{
    connect(GUILogger::GetInstance(), SIGNAL(newMessages(const MsgSeries &)),
        this, SLOT(NewMessages(const MsgSeries &)));
}


void 
GUILoggerGui::NewMessages(const MsgSeries &msgs)
{
    QMapIterator<int, LMessage> i(msgs);
    while (i.hasNext())
    {
        i.next();
        LMessage msg(i.value());

        if (fPauseButton->isChecked())
        {
            //Pause enabled, skip new messages
            continue;
        }

        //Filter severity:
        
        //fLogLevelCombo->
        
        int value = (int)fLogLevelCombo->itemData(  fLogLevelCombo->currentIndex() ).toInt();

//        if (  fLogLevelCombo->itemData(  fLogLevelCombo->currentIndex())  < (int)msg.fLevel) 
       
       if (  value  < (int)msg.fLevel) 
     //   if (fLogLevelCombo->currentData() < (int)msg.fLevel) 
        {
         
          //Log level too low, skip msg
          continue;
        }

        //Filter subsystem
        bool skip = true;
        QMap<eMSGSYSTEM, QCheckBox*>::iterator it;
        for (it = fCheckBoxes.begin(); it != fCheckBoxes.end(); it++) 
        {
            if ( (int)msg.fSystem & (int)it.key() )
            {
                if (it.value()->checkState() == Qt::Checked)
                    skip = false;
            }
        }
        if (skip) {
            //Subsystem does not match, skip msg
            continue;
        }

        //Filter regexp
        if (fRegExp.pattern().size() && !fRegExp.exactMatch(msg.fMsgBody)) {
            //Reg exp does not match, skip msg
            continue;
        }

        //Set color:
        QTextCharFormat tf;
        tf = fPlainTextEdit->currentCharFormat();
        tf.setForeground(QBrush(QColor(msg.fRgBColor)));
        tf.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
        fPlainTextEdit->setCurrentCharFormat(tf);

        QString str = QString("%1 %2").arg(i.key()%10000, 4,10, QLatin1Char('0')).arg(msg.fMsg);
        str.chop(1); //Remove trailing \n
        fPlainTextEdit->appendPlainText(str);

        //Scroll to end
        QScrollBar* sb = fPlainTextEdit->verticalScrollBar();
        sb->setValue(sb->maximum());
    }
}


void
GUILoggerGui::RegExpUpdated()
{
    fRegExp.setPattern(fRegExpEdit->text());
}

void
GUILoggerGui::RegExpSyntaxUpdated()
{
    fRegExp.setPatternSyntax(fRegExpCombo->currentData().value<QRegExp::PatternSyntax>());
}

void
GUILoggerGui::ClearLog()
{
    GUILogger::GetInstance()->ClearMsgs();
    fPlainTextEdit->clear();
}

void
GUILoggerGui::OpenLogMasterDialog()
{
    if(fLogMasterGuiDialog == nullptr)
    {
        fLogMasterGuiDialog = new QWidget(nullptr);
        fLogMasterGuiDialog->setObjectName("GUIWidget");
        fLogMasterGuiDialog->setWindowFlags(Qt::Window);
        QVBoxLayout *lay = new QVBoxLayout;
        lay->setContentsMargins(0, 0, 0, 0);
        GUILogMasterTab* logMasterGui = new GUILogMasterTab(fLogMasterGuiDialog);
        lay->addWidget(logMasterGui);
        fLogMasterGuiDialog->setLayout(lay);
    }

    fLogMasterGuiDialog->show();
    fLogMasterGuiDialog->setFocus();
    fLogMasterGuiDialog->activateWindow();
    fLogMasterGuiDialog->raise();
}



void
GUILoggerGui::GetAllMessages()
{
    fPlainTextEdit->clear();
    NewMessages(GUILogger::GetInstance()->AllMsgs());
}

void
GUILoggerGui::Pause()
{
    if (fPauseButton->isChecked())
    {
        fPauseButton->setText(fTEXT_unpause);
    }
    else
    {
        fPauseButton->setText(fTEXT_pause);
    }   
}
