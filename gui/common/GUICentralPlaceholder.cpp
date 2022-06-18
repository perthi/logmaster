// -*- mode: c++ -*-

#include <QtCore/QSettings>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QtGui/QDesktopServices>
#include <QtCore/QUrl>
#include "GUICentralPlaceholder.h"


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/




    /**  @class     GUICentralPlaceholder
      *  @brief     Widget class to hold the central position when user isnt logged in */


    GUICentralPlaceholder::GUICentralPlaceholder( QWidget *parent )
        :QWidget( parent ),
        fHeaderLabel( 0 ),
        fFirstContentLabel( 0 ),
    //  fLoginButton( 0 ),
        fInfoButton( 0 ),
        fExitButton( 0 )
    {
        InitGui();
        RetranslateUi();

    //  connect( this, SIGNAL( RequestAuth() ),
    //      GUILogin::getInstance(), SLOT( RequestAuth() ) );
    }


    GUICentralPlaceholder::~GUICentralPlaceholder()
    {

    }


    void
        GUICentralPlaceholder::InitGui()
    {
        fLogo = new QLabel( this );

    //  QPixmap logo( ":/images/km_large.jpg" );
        QPixmap logo(":/images/ferrotech.jpg");
        fLogo->setPixmap( logo.scaled( 200, 300, Qt::KeepAspectRatio ) );
        QHBoxLayout *logoLay = new QHBoxLayout;
        logoLay->addStretch();
        logoLay->addWidget( fLogo );
        logoLay->addStretch();

        fHeaderLabel = new QLabel( this );
        fHeaderLabel->setAlignment( Qt::AlignCenter );
        QHBoxLayout *headerLay = new QHBoxLayout;
        headerLay->addStretch();
        headerLay->addWidget( fHeaderLabel );
        headerLay->addStretch();

        fFirstContentLabel = new QLabel( this );
        fFirstContentLabel->setAlignment( Qt::AlignCenter );
        QHBoxLayout *firstContentLay = new QHBoxLayout;
        firstContentLay->addStretch();
        firstContentLay->addWidget( fFirstContentLabel );
        firstContentLay->addStretch();

        /*fLoginButton = new QPushButton( this );
        fLoginButton->setIcon( QIcon( ":/images/password.png" ) );
        fLoginButton->setIconSize( QSize( 64, 64 ) );
        connect( fLoginButton, SIGNAL( clicked() ),
            this, SLOT( LoginClicked() ) );*/

        fInfoButton = new QPushButton( this );
        fInfoButton->setIcon( QIcon( ":/images/info.png" ) );
        fInfoButton->setIconSize( QSize( 64, 64 ) );
        connect( fInfoButton, SIGNAL( clicked() ),
            this, SLOT( InfoClicked() ) );

        fExitButton = new QPushButton( this );
        fExitButton->setIcon( QIcon( ":/images/quit.png" ) );
        fExitButton->setIconSize( QSize( 64, 64 ) );
        connect( fExitButton, SIGNAL( clicked() ),
            qApp, SLOT( quit() ) );

        fHeaderLabel->setObjectName( "CentralPlaceHolderHeader" );
        fFirstContentLabel->setObjectName( "CentralPlaceHolderFirstContent" );

        QHBoxLayout *blay = new QHBoxLayout;
        blay->addStretch();
//      blay->addWidget( fLoginButton );
        blay->addWidget( fInfoButton );
        blay->addWidget( fExitButton );
        blay->addStretch();

        QVBoxLayout *lay = new QVBoxLayout;
        lay->addLayout( logoLay );
        lay->addLayout( headerLay );
        QSpacerItem* space = new QSpacerItem( 0, 50, QSizePolicy::Preferred, QSizePolicy::Preferred );
        lay->addSpacerItem( space );
        lay->addLayout( firstContentLay );
        space = new QSpacerItem( 0, 50, QSizePolicy::Preferred, QSizePolicy::Preferred );
        lay->addSpacerItem( space );
        lay->addLayout( blay );
        this->setLayout( lay );
    }


    void
    GUICentralPlaceholder::RetranslateUi()
    {
        QSettings settings;
        settings.beginGroup("StyleSettings");
        QString currStyle = settings.value("currentStyle").toString();
        if (currStyle == "Native Windows")
        {
            fHeaderLabel->setStyleSheet(QString("QLabel { font: bold 26px; }"));
            fFirstContentLabel->setStyleSheet(QString("QLabel { font: bold 18px; }"));
        }

        static QString
            TEXT__m_headerLabel = tr("Welcome to the Kongsberg Ferrotech Operator GUI"),
            TEXT__m_firstContentLabel = tr("You are currently not logged in.\nPlease identify yourself.");

    //  fTEXT__m_loginButton_tooltip = tr("Open up the login-panel");
        fTEXT__m_infoButton_tooltip = tr( "Look for more information about\nthis application online" );
        fTEXT__m_exitButton_tooltip = tr("Exit the application");

        fHeaderLabel->setText(TEXT__m_headerLabel);
        fFirstContentLabel->setText(TEXT__m_firstContentLabel);
//      fLoginButton->setToolTip( fTEXT__m_loginButton_tooltip );
        fInfoButton->setToolTip(fTEXT__m_infoButton_tooltip);
        fExitButton->setToolTip(fTEXT__m_exitButton_tooltip);
    }


    /*void
        GUICentralPlaceholder::LoginClicked()
    {
        emit RequestAuth();
    }
*/

    void
    GUICentralPlaceholder::InfoClicked()
    {
        QDesktopServices::openUrl(QUrl("https://www.kferrotech.no/"));

    }


