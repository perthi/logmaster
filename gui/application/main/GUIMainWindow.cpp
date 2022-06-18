// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <QtCore/QDebug>
#include <QtCore/QTimer>

#include <QtWidgets/QApplication>
#include <QtCore/QResource>
#include <QtWidgets/QMenuBar>
#include <QtCore/QSettings>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtWidgets/QLayout>
#include <QtWidgets/QDockWidget>
#include <QtGui/QCloseEvent>
#include <QtWidgets/QMessageBox>


#include <QtQuick/QQuickView>
#include <QtQuickWidgets/QQuickWidget>


#include  "GUIMainWindow.h"
#include <gui/settings/GUISettingsDialog.h>
#include <gui/settings/GUISettingsLanguage.h>

#include <gui/c-ring/GUICringWidget.h>
#include <gui/operations/GUICringOperationsSequencer.h>
#include <gui/operations/GUICringOperationsCoating.h>
#include <gui/operations/GUICringOperationsPatching.h>
#include <gui/operations/GUICringOperationsSurfacePrep.h>
#include <gui/operations/GUICringOperationsWrapping.h>

#include <api/api-hmi/APIHmiOperation.h>
#include <api/api-hmi/APIHmiOperationCoating.h>
#include <api/api-hmi/APIHmiOperationPatching.h>
#include <api/api-hmi/APIHmiOperationSurfacePrep.h>
#include <api/api-hmi/APIHmiOperationWrapping.h>


GUIMainWindow::GUIMainWindow(QWidget *parent)
    :QMainWindow(parent),
    fExitAction(0),
    fToolsMenu(0),
    fFileMenu(0),
    fTranslator_MainWindow(0),
    fUserButton(0),
    fStackWidget(0),
    fMainToolbar(0)
{
    QResource::registerResource("gui-qt.rcc");
    setWindowIcon(QIcon(":/images/kmlogo.png"));
    // setWindowIcon(QIcon(":/images/ferrotech.png"));
    InitGui();
    qApp->installTranslator(&fTranslator_MainWindow);
    qApp->installTranslator(&fTranslator_SettingsDialog);
    qApp->installTranslator(&fTranslator_StyleSettings);
    qApp->installTranslator(&fTranslator_LanguageSettings);
    RetranslateUi();
    UpdateStyle();
}

GUIMainWindow::~GUIMainWindow()
{
    //
}


void GUIMainWindow::closeEvent(QCloseEvent *event)
{
    // QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Quit",
    //                                                            tr("Are you sure?\n"),
    //                                                            QMessageBox::No | QMessageBox::Yes,
    //                                                            QMessageBox::Yes);
    // if (resBtn == QMessageBox::Yes)
    // {
           event->accept();
           QMainWindow::closeEvent(event);
           QApplication::quit();
    // }
    // else
    // {
    //     event->ignore();
    // }

}


void GUIMainWindow::Close()
{
	// QMessageBox::StandardButton resBtn = QMessageBox::question(this, "Quit",
	// 	tr("Are you sure?\n"),
	// 	QMessageBox::No | QMessageBox::Yes,
	// 	QMessageBox::Yes);
	// if (resBtn == QMessageBox::Yes)
	// {
	// 	QApplication::quit();
	// }

    QApplication::quit();

}


void
GUIMainWindow::InitGui()
{
	InitMenus();
	InitCentralWidget();
	InitToolbar();
}


void
GUIMainWindow::InitMenus()
{
    // Exit Action
    fExitAction = new QAction(this);
    fExitAction->setIcon(QIcon(":/images/poweroff.png"));
    fExitAction->setShortcut(QKeySequence::Close);

    // File Menu
    fFileMenu = new QMenu(menuBar());
    menuBar()->addMenu(fFileMenu);
    fFileMenu->addAction(fExitAction);

    // Tools
    fToolsMenu = new QMenu(menuBar());
    menuBar()->addMenu(fToolsMenu);

    // View
    fViewMenu = new QMenu(menuBar());
    menuBar()->addMenu(fViewMenu);
    fViewMenu->menuAction()->setVisible(true);

    // User Button
    fUserButton = new QToolButton(this);
    fUserButton->setIcon(QIcon(":/images/user.png"));
    fUserButton->setVisible(true);
    menuBar()->setCornerWidget(fUserButton, Qt::TopRightCorner);
}


void
GUIMainWindow::InitCentralWidget()
{

    fStackWidget = new QStackedWidget(this);
    fCentralPlaceholder = new GUICentralPlaceholder(this);

    fStackWidget->insertWidget(0, fCentralPlaceholder);
    this->setCentralWidget( fStackWidget);

    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    // FSM
    fFsmDock = new QDockWidget(tr("FSM MODULE"), this);
    fFsmGui = new GUIFsmGui(this);
    fFsmDock->setWidget(fFsmGui);
    fFsmDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, fFsmDock);
    fViewMenu->addAction(fFsmDock->toggleViewAction());
    connect(fFsmGui, &GUIFsmGui::OpenStateDialog, this, &GUIMainWindow::OpenStateDialog);

    // Sensor Module
    fSensorDock = new QDockWidget(tr("MOCK SENSOR MODULE"), this  );
    fSensorModule = new  GUISensorWidget();
    fSensorDock->setWidget(fSensorModule);
    fSensorDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,  fSensorDock );
    fViewMenu->addAction(fSensorDock->toggleViewAction() );
    // fSensorDock->hide();

    // Alarm Module
    fAlarmDock = new QDockWidget(tr("ALARM MODULE"), this);
    fAlarmGui = new  GUIAlarmGui();
    fAlarmDock->setWidget(fAlarmGui);
    fAlarmDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, fAlarmDock);
    fViewMenu->addAction(fAlarmDock->toggleViewAction());

    // Logging Module
    fLogDock = new QDockWidget(tr("LOGGING MODULE"), this);
    fLogModule = new GUILoggerGui(this);
    fLogDock->setWidget(fLogModule);
    fLogDock->setAllowedAreas(Qt::BottomDockWidgetArea);
    addDockWidget(Qt::BottomDockWidgetArea, fLogDock);
    fViewMenu->addAction(fLogDock->toggleViewAction());

    // C-Ring Module
    fCRingWidget = new GUICringWidget(this);
    fCRingDock = new QDockWidget(tr("C-RING MODULE"), this);
    fCRingDock->setWidget(fCRingWidget);
    fViewMenu->addAction(fCRingDock->toggleViewAction());
    fCRingDock->setFloating(true);
    fCRingDock->hide();

    // Sequencer
    fOperationsSequencer = new GUICringOperationsSequencer(this);
    fOperationsSequencerDock = new QDockWidget(tr("SEQUENCER MODULE"), this);
    fOperationsSequencerDock->setWidget(fOperationsSequencer);
    addDockWidget(Qt::RightDockWidgetArea, fOperationsSequencerDock);
    fViewMenu->addAction(fOperationsSequencerDock->toggleViewAction());
    fOperationsSequencerDock->hide();

    // Coating
    fOperationsCoating = new GUICringOperationsCoating(std::make_shared<APIHmiOperationCoating>(), this);
    fOperationsCoatingDock = new QDockWidget(tr("COATING MODULE"), this);
    fOperationsCoatingDock->setWidget(fOperationsCoating);
    fViewMenu->addAction(fOperationsCoatingDock->toggleViewAction());
    fOperationsCoatingDock->setFloating(true);
    fOperationsCoatingDock->hide();

    // Patching
    fOperationsPatching = new GUICringOperationsPatching(std::make_shared<APIHmiOperationPatching>(), this);
    fOperationsPatchingDock = new QDockWidget(tr("PATCHING MODULE"), this);
    fOperationsPatchingDock->setWidget(fOperationsPatching);
    fViewMenu->addAction(fOperationsPatchingDock->toggleViewAction());
    fOperationsPatchingDock->setFloating(true);
    fOperationsPatchingDock->hide();

    // SurfacePrep
    fOperationsSurfacePrep = new GUICringOperationsSurfacePrep(std::make_shared<APIHmiOperationSurfacePrep>(), this);
    fOperationsSurfacePrepDock = new QDockWidget(tr("SURFACEPREP MODULE"), this);
    fOperationsSurfacePrepDock->setWidget(fOperationsSurfacePrep);
    fViewMenu->addAction(fOperationsSurfacePrepDock->toggleViewAction());
    fOperationsSurfacePrepDock->setFloating(true);
    fOperationsSurfacePrepDock->hide();

    // Wrapping
    fOperationsWrapping = new GUICringOperationsWrapping(std::make_shared<APIHmiOperationWrapping>(), this);
    fOperationsWrappingDock = new QDockWidget(tr("WRAPPING MODULE"), this);
    fOperationsWrappingDock->setWidget(fOperationsWrapping);
    fViewMenu->addAction(fOperationsWrappingDock->toggleViewAction());
    fOperationsWrappingDock->setFloating(true);
    fOperationsWrappingDock->hide();


}


void
GUIMainWindow::InitToolbar()
{
   fMainToolbar = new QToolBar(this);
   fMainToolbar->setMovable(false);
   fMainToolbar->hide();
   this->addToolBar(Qt::LeftToolBarArea, fMainToolbar);
}


void
GUIMainWindow::RetranslateUi()
{
        static QString
            TEXT__m_settingsAction = tr("&Settings"),
            TEXT__m_settingsAction__TOOLTIP = tr("Open the settings-dialog"),
            TEXT__TOOLS_menu = tr("Tools"),
            TEXT__m_userButton_TOOLTIP = tr("User profile"),
            TEXT__FILE_menu = tr("File"),
            TEXT__VIEW_menu = tr("&View"),
            TEXT__FILE_exitApp = tr("Exit"),
            TEXT_TOOLBAR_dut = tr("DUT Select Panel"),
            TEXT_TOOLBAR_signal = tr("RF Signal Generator Panel"),
            TEXT_TOOLBAR_relayMatrix = tr("RF Relay Matrix Panel"),
            TEXT_TOOLBAR_temperature = tr("Temperature Chamber Control Panel"),
            TEXT_TOOLBAR_instrumentSetup = tr("Instrument Setup Panel"),
            TEXT_TOOLBAR_EPCJigSetup = tr("EPC Jig Setup Panel");
        ;


    QSettings settings;
    settings.beginGroup("LanguageSettings");
    QString currentLanguage = settings.value("currentLanguage").toString();
    switch (LanguageChoice_fromString(currentLanguage))
    {
    case Norwegian:
        fTranslator_MainWindow.load("MainWindow_Norsk.qm", ":/translations");
        fTranslator_SettingsDialog.load("SettingsDialog_Norsk.qm", ":/translations");
        fTranslator_StyleSettings.load("StyleSettings_Norsk.qm", ":/translations");
        fTranslator_LanguageSettings.load("LanguageSettings_Norsk.qm", ":/translations");
        break;
    case English:
        fTranslator_MainWindow.load("MainWindow_English.qm", ":/translations");
        fTranslator_SettingsDialog.load("SettingsDialog_English.qm", ":/translations");
        fTranslator_StyleSettings.load("StyleSettings_English.qm", ":/translations");
        fTranslator_LanguageSettings.load("LanguageSettings_English.qm", ":/translations");
        break;
    case UnknownLanguage:
        default:
        fTranslator_MainWindow.load("", "");
        fTranslator_SettingsDialog.load("", "");
        fTranslator_StyleSettings.load("", "");
        fTranslator_LanguageSettings.load("", "");
        break;
    }

    fExitAction->setText(TEXT__FILE_exitApp);
    fToolsMenu->setTitle(TEXT__TOOLS_menu);
    fFileMenu->setTitle(TEXT__FILE_menu);
    fViewMenu->setTitle(TEXT__VIEW_menu);
    fUserButton->setToolTip(TEXT__m_userButton_TOOLTIP);
}


void
GUIMainWindow::UpdateStyle()
{
    QSettings settings;
    settings.beginGroup("StyleSettings");
    QString style = settings.value("currentStyle").toString();
    settings.endGroup();

    if (style == "Native Windows")
    {
        qApp->setStyleSheet("");
    }
    else
    {
        QFileInfo style(":/styles/ferrotech.qmm");
        if (!style.exists())
        {
            G_ERROR("Stylesheet does not exist");
            return;
        }
        QFile f(style.filePath());
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            G_ERROR("Stylesheet wont open");
            return;
        }
        QString styleContent = f.readAll();
        qApp->setStyleSheet(styleContent);
    }
}




void
GUIMainWindow::CreatePanel(QWidget *w)
{
    QDialog* dialog = new QDialog(this);
    QVBoxLayout*  lay = new QVBoxLayout;
    lay->addWidget(w);
    lay->setContentsMargins(0, 0, 0, 0);
    dialog->setLayout(lay);
    dialog->show();
}



void
GUIMainWindow::OpenStateDialog(string node)
{
    //Open FSM tree GUI:
	GUIFsmGui* fsmGui = new GUIFsmGui(false, this);
	fsmGui->ShowStateChildren(node);
	connect(fsmGui, SIGNAL(OpenStateDialog(string)), this, SLOT(OpenStateDialog(string)));
	CreatePanel(fsmGui);
}

