// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#ifndef _COMMON_GUI_H_
#define _COMMON_GUI_H_

#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QTableWidgetItem>
#include <QtCore/QString>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QComboBox>

#include <utilities/GDefinitions.h>

   QLayout  API * HELPER_wrapLabelAndCombo(QLabel **label, QComboBox **combo, QWidget *parent);

   QTableWidgetItem API  * HELPER_makeTableItem(const QString &text,
      int &width,
      bool isCheckable = false,
      QIcon *icon = 0,
      const QString &tooltip = "",
      const QVariant &data = QVariant(),
      bool isChecked = false);

/**  @brief    Common shared functionality */
   class GUINoWheelComboBox : public QComboBox
   {
      Q_OBJECT
         
   public:
      explicit  API GUINoWheelComboBox(QWidget *parent = 0);

   protected:
      virtual void wheelEvent(QWheelEvent *) override;
   };


#endif
