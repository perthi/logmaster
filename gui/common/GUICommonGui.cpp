// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtGui/QWheelEvent>
#include "GUICommonGui.h"

	QLayout*
		HELPER_wrapLabelAndCombo( QLabel **label, QComboBox **combo, QWidget *parent )
	{
		*label = new QLabel( parent );
		QHBoxLayout *labellay = new QHBoxLayout;
		labellay->addWidget( *label );
		labellay->addStretch();
		*combo = new QComboBox( parent );
		QVBoxLayout *lay = new QVBoxLayout;
		lay->addStretch();
		lay->addLayout( labellay );
		lay->addWidget( *combo );
		lay->addStretch();
		return lay;
	}


	QTableWidgetItem*
		HELPER_makeTableItem( const QString &text,
			int &width,
			bool isCheckable,
			QIcon *icon,
			const QString &tooltip,
			const QVariant &data,
			bool isChecked )
	{
		QTableWidgetItem *item = new QTableWidgetItem;
		QFontMetrics metr( item->font() );
		width = metr.width( text );
		item->setText( text );
		if ( isCheckable )
		{
			if ( isChecked )
			{
				item->setCheckState( Qt::Checked );
			}
			else
			{
				item->setCheckState( Qt::Unchecked );
			}
			item->setFlags( Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable );
			width += 35;
		}
		else
		{
			item->setFlags( Qt::ItemIsEnabled | Qt::ItemIsSelectable );
		}

		if ( tooltip != "" )
		{
			item->setToolTip( tooltip );
		}

		if ( !data.isNull() )
		{
			item->setData( Qt::UserRole, data );
		}

		item->setTextAlignment( Qt::AlignCenter );
		if ( 0 != icon )
		{
			item->setIcon( *icon );
			int largestWidth = 0;
			QList<QSize> iconSizes = icon->availableSizes();
			for ( int i = 0; i < iconSizes.count(); i++ )
			{
				if ( iconSizes.at( i ).width() > largestWidth )
				{
					largestWidth = iconSizes.at( i ).width();
				}
			}
			width += largestWidth;
		}

		if ( width < 15 )
		{
			width = 15;
		}

		return item;
	}


GUINoWheelComboBox::GUINoWheelComboBox(QWidget *parent) : QComboBox(parent)
{

}


void 
GUINoWheelComboBox::wheelEvent(QWheelEvent *e)
{
   e->ignore();
}
