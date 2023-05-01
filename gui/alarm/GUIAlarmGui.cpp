// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtCore/QDebug>

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
// #include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtCore/QTimer>
#include <QtCore/QSettings>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QButtonGroup>
#include <QtCore/QDateTime>
#include <QtCore5Compat/QRegExp>
#include <QtCore/QMetaType>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>


#include <logging/LLogging.h>
//#include <logging/LHashMaps.h>

#include "GUIAlarmGui.h"
#include "GUIAlarm.h"

#include  <gui/common/GUIInitStyles.h>


using namespace LOGMASTER;

QMap<int, LMessage>    GUIAlarmGui::fLoggedMessages;
QMap<int, LMessage>    GUIAlarmGui::fNewMessages;


Q_DECLARE_METATYPE(QRegExp::PatternSyntax)

//GUIAlarmGui::GUIAlarmGui(GUIAlarm *alarm, QWidget *parent)
GUIAlarmGui::GUIAlarmGui(QWidget* parent)
   :
  //  fAlarm(alarm),
    QWidget(parent),
   fPlainTextEditLabel(0),
   fPlainTextEdit(0),
   fConfigureButton(0)
{

    
   InitGui();
   RetranslateUi();
   ConnectStuff();
   GetAllMessages();
}


GUIAlarmGui::~GUIAlarmGui()
{

}


void
GUIAlarmGui::StartTimer()
{
    this->startTimer(500);
  //  fAlarm->startTimer(1000);
}


void 
GUIAlarmGui::InitGui()
{
   QSplitter *splitter = new QSplitter(this);
   QWidget* right = InitRight();
   splitter->addWidget(right);
   QList<int> sizes;
   sizes.append(100000);
   splitter->setSizes(sizes);
   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget(splitter);
   this->setLayout(lay);
}


QWidget* 
GUIAlarmGui::InitRight()
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
GUIAlarmGui::RetranslateUi()
{
   fTEXT_messages = tr("Alarms");
      
   QSettings settings;
   settings.beginGroup("StyleSettings");
   QString currStyle = settings.value("currentStyle").toString();
   fPlainTextEditLabel->setText(fTEXT_messages);
 //  auto hash = LHashMaps::GetLevel2StringHash();
}

void
GUIAlarmGui::ConnectStuff()
{
   // connect( fAlarm, SIGNAL(newMessages(const MsgSeries )),
    //    this, SLOT(NewMessages(const this->MsgSeries &)));
}


void  
GUIAlarmGui::timerEvent(QTimerEvent* event)
{
   // fNewMessages2.insert(cnt, newmsg);

    COUT << "ALARM !!!!!!!!!!!!!!!!!!!!  ALARM" << endl;
    NewMessages2(fNewMessages);
}

//QMultiMap<int, LMessage>;


void  
GUIAlarmGui::NewMessage(int cnt, const LMessage& msg)
{
    COUT << "NEW MEASSAGE RECEIVED" << endl;
    fNewMessages.insert(cnt, msg);
}

void 
// GUIAlarmGui::NewMessages( MsgSeries *msgs)
GUIAlarmGui::NewMessages2( const QMap<int, LMessage> &msgs)
{
    COUT << "msg.size() = !!!!!!!!!!!!!!!!!! " << msgs.size() << endl;

    QMapIterator<int,   LMessage> i( msgs);
    while (i.hasNext())
    {
       static int cnt = 0;
       cnt ++; 
       i.next();
        LMessage msg(i.value());

        if (msg.fSystem == eMSGSYSTEM::SYS_ALARM)
        {

            //bool skip = true;
            QMap<eMSGSYSTEM, QCheckBox*>::iterator it;

            QTextCharFormat tf;
            tf = fPlainTextEdit->currentCharFormat();
            tf.setForeground(QBrush(QColor(msg.fRgBColor)));
            tf.setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
            fPlainTextEdit->setCurrentCharFormat(tf);

            QString str = QString("%1 %2").arg(i.key() % 10000, 4, 10, QLatin1Char('0')).arg(msg.fMsg);
            str.chop(1); //Remove trailing \n
            fPlainTextEdit->appendPlainText(str);

            //Scroll to end
            QScrollBar* sb = fPlainTextEdit->verticalScrollBar();
            sb->setValue(sb->maximum());
        }
    }
}



void
GUIAlarmGui::GetAllMessages()
{
    fPlainTextEdit->clear();
//    NewMessages(fAlarm->AllMsgs());
}


