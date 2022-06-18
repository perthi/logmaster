// GUICringOperationsSliderBar.cpp
// karl eirik bang fossberg

#include "GUICringOperationsSliderBar.h"
#include <configuration/KFHMIControl.h>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

GUICringOperationsSliderBar::GUICringOperationsSliderBar(
    const KFHMIControl &indicator,
    const int &startingValue,
    QWidget *pParent)
    : QWidget(pParent)
    , m_currentValue(startingValue)
    , m_minValue(indicator.fMinValue)
    , m_maxValue(indicator.fMaxValue)
    , m_unit(indicator.fCaption.fCaptionMin)
{
    m_pRootLayout  = std::make_unique<QVBoxLayout>();
    m_pLabelLayout = std::make_unique<QHBoxLayout>();

    m_pCaptionLabel = std::make_unique<QLabel>(indicator.fCaption.fCaption.c_str());
    m_pLeftLabel    = std::make_unique<QLabel>(QString::number(m_minValue) + " " + QString(m_unit.c_str()));
    m_pRightLabel   = std::make_unique<QLabel>(QString::number(m_maxValue) + " " + QString(m_unit.c_str()));
    m_pCenterLabel  = std::make_unique<QLabel>(QString::number(m_currentValue) + " " + QString(m_unit.c_str()));

    m_pSliderCustom = std::make_unique<GUIGraphicalSlider>(m_currentValue);
    connect(m_pSliderCustom.get(), &GUIGraphicalSlider::signalUpdateSlider, this, &GUICringOperationsSliderBar::slotUpdateSlider);

    m_pRootLayout.get()->addWidget(m_pCaptionLabel.get(), 0, Qt::AlignLeft);
    m_pLabelLayout.get()->addWidget(m_pLeftLabel.get(),   0, Qt::AlignLeft);
    m_pLabelLayout.get()->addWidget(m_pCenterLabel.get(), 0, Qt::AlignCenter);
    m_pLabelLayout.get()->addWidget(m_pRightLabel.get(),  0, Qt::AlignRight);

    m_pRootLayout.get()->addLayout(m_pLabelLayout.get());
    m_pRootLayout.get()->addWidget(m_pSliderCustom.get());

    setLayout(m_pRootLayout.get());
}

GUICringOperationsSliderBar::~GUICringOperationsSliderBar()
{
    //
}

void
GUICringOperationsSliderBar::slotUpdateSlider(const int &value)
{
    m_currentValue = ScaleSliderValue(value);
    m_pCenterLabel.get()->setText(QString::number(m_currentValue) + " " + QString(m_unit.c_str()));
    emit signalSliderValue(m_currentValue);
}

int
GUICringOperationsSliderBar::ScaleSliderValue(const int &input)
{
    int delta = (m_maxValue - m_minValue);
    return (m_minValue + ((input * delta) / 1000.0f));
}