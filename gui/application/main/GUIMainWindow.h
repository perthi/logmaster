// -*- mode: c++ -*-

#ifndef _MAIN_APP_MAINWINDOW_H_
#define _MAIN_APP_MAINWINDOW_H_



/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include <QtWidgets/QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtCore/QTranslator>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QDockWidget>

#include <gui/common/GUICentralPlaceholder.h>
#include <gui/fsm/GUIFsmGui.h>
#include <gui/logger/GUILoggerGui.h>
#include <gui/sensors/GUISensorWidget.h>
#include <gui/alarm/GUIAlarmGui.h>

class GUICringWidget;
class GUICringOperationsSequencer;
class GUICringOperationsCoating;
class GUICringOperationsPatching;
class GUICringOperationsSurfacePrep;
class GUICringOperationsWrapping;

class GUIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    API GUIMainWindow(QWidget *parent = nullptr);
    API ~GUIMainWindow();

public slots:
    void OpenStateDialog(string);


private slots:
    void RetranslateUi();
    void UpdateStyle();
    void Close();

protected:
    virtual void closeEvent(QCloseEvent *event) override;

private:
    void InitGui();
    void InitMenus();
    void InitCentralWidget();
    void InitToolbar();
    void CreatePanel(QWidget *w);

private:
    QAction *fExitAction;
    QMenu *fToolsMenu;
    QMenu *fFileMenu;
    QMenu *fViewMenu;
    QToolBar *fMainToolbar;
    QToolButton *fUserButton;
    QStackedWidget *fStackWidget;
    GUICentralPlaceholder *fCentralPlaceholder;

    GUIFsmGui *fFsmGui;
    GUILoggerGui *fLogModule;
    GUISensorWidget* fSensorModule;
    GUIAlarmGui* fAlarmGui;
    GUICringWidget* fCRingWidget;
    GUICringOperationsSequencer *fOperationsSequencer;
    GUICringOperationsCoating *fOperationsCoating;
    GUICringOperationsPatching *fOperationsPatching;
    GUICringOperationsWrapping *fOperationsWrapping;
    GUICringOperationsSurfacePrep *fOperationsSurfacePrep;

    QDockWidget* fFsmDock;
    QDockWidget* fLogDock;
    QDockWidget* fSensorDock;
    QDockWidget* fAlarmDock;
    QDockWidget* fCRingDock;
    QDockWidget* fOperationsSequencerDock;
    QDockWidget* fOperationsCoatingDock;
    QDockWidget* fOperationsPatchingDock;
    QDockWidget* fOperationsSurfacePrepDock;
    QDockWidget* fOperationsWrappingDock;

    QTranslator fTranslator_MainWindow;
    QTranslator fTranslator_SettingsDialog;
    QTranslator fTranslator_StyleSettings;
    QTranslator fTranslator_LanguageSettings;
    QString fTEXT_STATUS_showSignal;
};


#endif










