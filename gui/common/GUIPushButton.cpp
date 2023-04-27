// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "GUIPushButton.h"

GUIPushButton::GUIPushButton(const QString &text, QWidget *parent)
   :QPushButton(text, parent)
{

}

void GUIPushButton::mouseReleaseEvent(QMouseEvent* e)
{
	if(e->button() == Qt::RightButton){
		emit rightClicked();
	}
    if (e->button() == Qt::LeftButton) {
        emit leftClicked();
    }
}

void GUIPushButton::mouseDoubleClickEvent(QMouseEvent*)
{
    emit doubleClicked();
}