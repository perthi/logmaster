


/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtGui/QIcon>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStatusBar>



#include "GUISettingsDialog.h"
#include "GUISettingsLanguage.h"
#include "GUISettingsStyle.h"



	GUISettingsDialog::GUISettingsDialog( QWidget *parent )
		:QDialog( parent ),
		fOkButton( 0 ),
		fStackedOptions( 0 ),
		fOptionsList( 0 ),
		fStatus( 0 )
	{
		InitGui();
		RetranslateUi();
		fOptionsList->setCurrentRow( Style );
		fStackedOptions->setCurrentIndex( Style );
	}


	GUISettingsDialog::~GUISettingsDialog()
	{

	}


	void
		GUISettingsDialog::InitGui()
	{
		this->setWindowIcon( QIcon( ":/images/instrumentsettings.png" ) );

		fOptionsList = new QListWidget( this );
		fOptionsList->insertItem( Style, tr( "Style" ) );
		fOptionsList->insertItem( Language, tr( "Language" ) );

		connect( fOptionsList, SIGNAL( currentRowChanged( int ) ),
			this, SLOT( CurrentItemChanged( int ) ) );

		fStackedOptions = new QStackedWidget( this );

		GUISettingsStyle *styles = new GUISettingsStyle( this );
		connect( styles, SIGNAL( StyleChanged( const QString & ) ),
			this, SLOT( StyleChanged( const QString & ) ) );
		fStackedOptions->insertWidget( Style, styles );
		fStackedWidgets[Style] = styles;

		GUISettingsLanguage *languages = new GUISettingsLanguage( this );
		connect( languages, SIGNAL( languageChanged( int ) ),
			this, SLOT( LanguageChanged( int ) ) );

		fStackedOptions->insertWidget( Language, languages );
		fStackedWidgets[Language] = languages;

		QSplitter *topSplit = new QSplitter( this );
		topSplit->addWidget( fOptionsList );
		topSplit->addWidget( fStackedOptions );

		fOkButton = new QToolButton( this );
		fOkButton->setIcon( QIcon( ":/images/ok.png" ) );
		fOkButton->setIconSize( QSize( 32, 32 ) );

		connect( fOkButton, SIGNAL( clicked() ),
			this, SLOT( OkClicked() ) );

		QHBoxLayout *bottomLay = new QHBoxLayout;
		bottomLay->addStretch();
		bottomLay->addWidget( fOkButton );

		fStatus = new QStatusBar( this );

		QVBoxLayout *lay = new QVBoxLayout;
		lay->addWidget( topSplit );
		lay->addLayout( bottomLay );
		lay->addWidget( fStatus );

		this->setLayout( lay );
	}


	void
		GUISettingsDialog::OkClicked()
	{
		this->accept();
	}


	void
		GUISettingsDialog::CurrentItemChanged( int settingsChoice )
	{
		fStackedOptions->setCurrentIndex( settingsChoice );
	}


	void
		GUISettingsDialog::StyleChanged( const QString &style )
	{
		fStatus->showMessage( fTEXT__styleChanged + style, 5000 );
		emit UpdateStyle();
	}


	void
		GUISettingsDialog::LanguageChanged( int language )
	{
		emit DoRetranslateUi();
		fStatus->showMessage( fTEXT__languageChanged + LanguageChoice_toString( static_cast<LanguageChoice>(language) ), 5000 );
		RetranslateUi();
	}


	void
		GUISettingsDialog::RetranslateUi()
	{
		fTEXT__languageChanged = tr( "Language changed to " );
		fTEXT__styleChanged = tr( "Style changed to " );

		static QString
			TEXT__thisWindowTitle = tr( "Settings" ),
			TEXT__optionStyle = tr( "Style" ),
			TEXT__optionLanguage = tr( "Language" ),
			TEXT__m_okButton_toolTop = tr( "This will close this dialog" );

		this->setWindowTitle( TEXT__thisWindowTitle );
		for ( int i = 0; i < fOptionsList->count(); i++ )
		{
			SettingChoice opt = static_cast<SettingChoice>(i);
			switch ( opt )
			{
			case Style:
				fOptionsList->item( i )->setText( TEXT__optionStyle );
				break;

			case Language:
				fOptionsList->item( i )->setText( TEXT__optionLanguage );
				break;
			}
		}
		fOkButton->setToolTip( TEXT__m_okButton_toolTop );
	}
