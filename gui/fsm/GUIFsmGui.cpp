// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtGui/QPainter>
#include <QtGui/QPicture>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QScrollBar>
#include <api/api-fsm/APIFSMController.h>
#include <QtCore/QDebug>

#include "GUIFsmSubsciber.h"
#include "GUIFsmGui.h"

	class ScrollAreaContainer : public QScrollArea
	{
	public:
		ScrollAreaContainer( QWidget *insert, QWidget *parent ) :QScrollArea( parent ), fInsert( insert )
		{
			setWidget( fInsert );
			setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
			setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
			setContentsMargins( 0, 0, 0, 0 );
			setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Preferred );
		};

		virtual QSize sizeHint() const override
		{
			int max_height = QApplication::desktop()->availableGeometry().height() - 300;
			int width = fInsert->sizeHint().width() + verticalScrollBar()->sizeHint().width() + 5;
			int height = qMin( max_height, fInsert->sizeHint().height() );
			return QSize( width, height );
		}
	private:
		QWidget* fInsert;
	};


	GUIFsmGui::GUIFsmGui( bool inMainGui, QWidget *parent )
		:QWidget( parent )
		, fInMainFsm( inMainGui )
		, fWidget( 0 )
		, fScrollArea( 0 )
		, fLayout( 0 )
	{
		qRegisterMetaType<vector<APIFSMNodeInfo>>( "vector<APIFSMNodeInfo>" );
		UpdateGui();
		ConnectSignals();
	}


	GUIFsmGui::~GUIFsmGui()
	{

	}

	void
	GUIFsmGui::UpdateGui()
	{
		//Replacing widget on updates
		if ( fWidget )
		{
			fLayout->removeWidget( fScrollArea );
			fWidget->deleteLater();
			fScrollArea->deleteLater();
		}

		fWidget = new QWidget( this );

		QLayout* layout;
		if ( fInMainFsm )
		{
			//create widget with layout for main GUI
			layout = createMainGuiWidget();
		}
		else
		{
			//create widget for standalone dialog
			layout = createDialogGuiWidget();
		}

		fWidget->setLayout( layout );
		fWidget->setObjectName( "GUIWidget" );

		fScrollArea = new ScrollAreaContainer( fWidget, this );
		fScrollArea->setObjectName( "GUIWidget" );

		if ( !fLayout )
			fLayout = new QVBoxLayout;

		fLayout->addWidget( fScrollArea );

		this->setLayout( fLayout );
	}

	void
	GUIFsmGui::UpdateFSM()
	{
		APIFSMController::Instance()->Update();
	}

	QLayout*
	GUIFsmGui::createMainGuiWidget()
	{
		vector<APIFSMNodeInfo> info = APIFSMController::Instance()->GetNodeInfo();

		//Sort the info list
		std::multimap<int, APIFSMNodeInfo> sorted_info;
		for ( auto node : info )
		{
			sorted_info.insert( std::pair<int, APIFSMNodeInfo>( node.fLevel, node ) );
		}

		QVBoxLayout* layout = new QVBoxLayout;
		layout->setContentsMargins( 0, 0, 0, 0 );

		QPushButton* updateButton = new QPushButton( tr( "Update" ), this );
		connect( updateButton, SIGNAL( clicked() ),
			this, SLOT( UpdateFSM() ) );
		layout->addWidget( updateButton );

		int lastLevel = 0;
		for ( auto mn : sorted_info )
		{
			APIFSMNodeInfo node = mn.second;
			if ( node.fMother != fSelectedState && node.fLevel > 1 )
			{
				continue;
			}

			GUIFsmState* state = new GUIFsmState( node, fWidget );
			connect( state, SIGNAL( ShowStateChildren( string ) ),
				this, SLOT( ShowStateChildren( string ) ) );
			connect( state, SIGNAL( OpenStateDialog( string ) ),
				this, SIGNAL( OpenStateDialog( string ) ) );
			fStatebuttons.append( state );

			if ( lastLevel != node.fLevel )
			{
				layout->addSpacing( 30 );
			}
			layout->addWidget( state );
			lastLevel = node.fLevel;
		}

		layout->addStretch();

		return layout;
	}

	QLayout*
		GUIFsmGui::createDialogGuiWidget()
	{
		vector<APIFSMNodeInfo> info = APIFSMController::Instance()->GetNodeInfo();

		QGridLayout* layout = new QGridLayout;
		layout->setContentsMargins( 0, 0, 0, 0 );

		int i = 0;
		QList<string> selectedNodeChildren;
		selectedNodeChildren.append( fSelectedState );

		for ( auto node : info )
		{
			if ( selectedNodeChildren.contains( node.fMother ) || selectedNodeChildren.contains( node.fName ) )
			{
				selectedNodeChildren.append( node.fName );
			}
			else
			{
				continue;
			}


			GUIFsmState* state = new GUIFsmState( node, this );
			connect( state, SIGNAL( OpenStateDialog( string ) ),
				this, SIGNAL( OpenStateDialog( string ) ) );
			int sh = state->height();
			state->setFixedWidth( sh * 10 );
			fStatebuttons.append( state );

			if ( node.fLevel > 0 )
			{
				//Draw graphics to indicate state relationship
				QLabel* label = new QLabel( this );
				QPicture pic;
				pic.setBoundingRect( QRect( 0, 0, sh, sh ) );
				label->setFixedWidth( sh );
				QPainter p( &pic );

				p.setRenderHint( QPainter::Antialiasing );
				p.setPen( QPen( Qt::gray, 2, Qt::SolidLine, Qt::RoundCap ) );
				p.drawLine( sh / 2, 0, sh / 2, sh / 2 );
				p.drawLine( sh / 2, sh / 2, sh, sh / 2 );
				p.end();
				label->setPicture( pic );
				layout->addWidget( label, i, node.fLevel - 1, 1, 1 );
			}

			layout->addWidget( state, i, node.fLevel, 1, 10 );
			i++;
		}

		return layout;
	}

	void
		GUIFsmGui::ConnectSignals()
	{
		connect( GUIFsmSubsciber::GetInstance(), SIGNAL( fsmUpdated( const vector<APIFSMNodeInfo>  & ) ),
			this, SLOT( UpdateGui() ) );
	}

	void
		GUIFsmGui::ShowStateChildren( string node )
	{
		fSelectedState = node;
		UpdateGui();
	}
