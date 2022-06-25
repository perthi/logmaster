// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#ifndef _MAIN_CENTRAL_PLACEHOLDER_H_
#define _MAIN_CENTRAL_PLACEHOLDER_H_

// Qt includes
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include <utilities/GDefinitions.h>
    

   class GUICentralPlaceholder : public QWidget
   {
      Q_OBJECT

   public:
      explicit API GUICentralPlaceholder(QWidget *parent = 0);
      API ~GUICentralPlaceholder();

//   signals:
 //     void RequestAuth();

   private slots:
  //    void LoginClicked();
      void InfoClicked();

   private: // functions
      void InitGui();
      void RetranslateUi();

   private: // member objects
      GUICentralPlaceholder(const GUICentralPlaceholder&);
      GUICentralPlaceholder operator=(const GUICentralPlaceholder&);

      QLabel *fLogo = nullptr;
      QLabel *fHeaderLabel = nullptr;
      QLabel *fFirstContentLabel = nullptr;
 //     QPushButton *fLoginButton;
      QPushButton *fInfoButton = nullptr;
      QPushButton *fExitButton = nullptr;

  //    QString fTEXT__m_loginButton_tooltip;
      QString fTEXT__m_infoButton_tooltip{};
      QString fTEXT__m_exitButton_tooltip{};
   };


#endif
