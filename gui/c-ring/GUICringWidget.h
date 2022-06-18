// GUICringWidget.h
// karl eirik bang fossberg

#ifndef GUI_CRING_WIDGET_H
#define GUI_CRING_WIDGET_H

#include <vector>

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include <utilities/GDefinitions.h>


class APIHmiCRing180;
class APIHmiCRing360;
class GUICringController;
class GUICringButtonGroup;
class GUICringQuadView180;
class GUICringQuadView360;
class GUICringQuadView;

/*
** GUICringWidget
** This widget communicates with the API through its slots, which are trigggered
** through the signals sendt from the different widgets. The C-Ring Controls are
** specialized subclasses of the Base-controller class. The QuadView class is
** specialized in two minor subclasses and contains a general implementation of
** the graphical UI elements. The current implementation also contains the
** widgets implemented in order to demostrate the LED and Motor controls of
** the connected Nucleo Card. The grahical elements are redrawn every 500ms, or
** when receiving an updated position from the API Callback.
** /KE
*/
class GUICringWidget : public QWidget
{
    Q_OBJECT

public:
    API GUICringWidget(QWidget *pParent  = nullptr);
    API ~GUICringWidget();

private:
    APIHmiCRing180* m_p180API = nullptr;
    APIHmiCRing360* m_p360API = nullptr;

    QGridLayout *m_pRootLayout = nullptr;
    GUICringController *m_pControllerA = nullptr;
    GUICringController *m_pControllerB = nullptr;

    GUICringQuadView *m_180Quad = nullptr;
    GUICringQuadView *m_360Quad = nullptr;
};
#endif // GUI_CRING_WIDGET_H