// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

///  @class GUIPushButton
///  @brief     Subclass of QPushButton which adds right click and double click


#ifndef _GUI_PUSH_BUTTON_H_
#define _GUI_PUSH_BUTTON_H_

#include <QtWidgets/QPushButton>
#include <QtGui/QMouseEvent>

#include <utilities/GDefinitions.h>

class GUIPushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit API GUIPushButton(const QString &text, QWidget* parent = 0);

private slots :
    void mouseReleaseEvent(QMouseEvent*);
    void mouseDoubleClickEvent(QMouseEvent*);

signals:
    void leftClicked();
	void rightClicked();
	void doubleClicked();
};

#endif
