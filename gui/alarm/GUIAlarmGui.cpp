// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include "GUIAlarmGui.h"

#include <QtWidgets/QVBoxLayout>
#include <QtCore/QSettings>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>


QMap<int, LMessage>    GUIAlarmGui::fLoggedMessages;
QMap<int, LMessage>    GUIAlarmGui::fNewMessages;

GUIAlarmGui::GUIAlarmGui(QWidget* parent)
   :
   QWidget(parent),
   fPlainTextEditLabel(0),
   fPlainTextEdit(0)
{
   InitGui();
   RetranslateUi();
   // GetAllMessages();
}




GUIAlarmGui::~GUIAlarmGui()
{
    delete fPlainTextEditLabel;
    delete fPlainTextEdit;
}


void
GUIAlarmGui::StartTimer()
{
    this->startTimer(500);
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
   QHBoxLayout *llay = new QHBoxLayout();
   llay->addWidget( fPlainTextEditLabel);
   llay->addStretch();
   fPlainTextEdit = new QPlainTextEdit(this);
   fPlainTextEdit->setReadOnly(true);
   fPlainTextEdit->setWordWrapMode(QTextOption::NoWrap);
   fPlainTextEdit->setMaximumBlockCount(2000);

   QVBoxLayout *lay = new QVBoxLayout();
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
   QString TEXT_messages = tr("Alarms");
   QSettings settings;
   settings.beginGroup("StyleSettings");
   QString currStyle = settings.value("currentStyle").toString();
   fPlainTextEditLabel->setText(TEXT_messages);
}


void  
GUIAlarmGui::timerEvent(QTimerEvent* event)
{
    NewMessages(fNewMessages);
}


void  
GUIAlarmGui::NewMessage(int cnt, const LMessage& msg)
{
    fNewMessages.insert(cnt, msg);
}

void 
GUIAlarmGui::NewMessages( const QMap<int, LMessage> &msgs)
{
    QMapIterator<int,   LMessage> i( msgs);
    while (i.hasNext())
    {
       static int cnt = 0;
       cnt ++; 
       i.next();
        LMessage msg(i.value());

        if (msg.fSystem == eMSGSYSTEM::SYS_ALARM)
        {
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

