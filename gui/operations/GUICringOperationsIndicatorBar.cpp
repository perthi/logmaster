// GUICringOperationsIndicatorBar.cpp
// karl eirik bang fossberg

#include "GUICringOperationsIndicatorBar.h"

GUICringOperationsIndicatorBar::GUICringOperationsIndicatorBar(
    const KFHMIIndicator &HMIIndicator,
    QWidget *pParent)
    : QWidget(pParent)
    , m_HMIIndicator(HMIIndicator)
{

    std::string capMin = std::to_string(m_HMIIndicator.fMinValue) + " " +  m_HMIIndicator.fCaption.fCaptionMin;
    std::string capMax = std::to_string(m_HMIIndicator.fMaxValue) + " " +  m_HMIIndicator.fCaption.fCaptionMax;

    m_pRootLayout  = std::make_unique<QVBoxLayout>();
    m_pLabelLayout = std::make_unique<QHBoxLayout>();

    m_pCaptionLabel = std::make_unique<QLabel>(m_HMIIndicator.fCaption.fCaption.c_str());
    m_pLeftLabel    = std::make_unique<QLabel>(capMin.c_str());
    m_pRightLabel   = std::make_unique<QLabel>(capMax.c_str());

    m_pIndicatorBar = std::make_unique<GUIGraphicalIndicator>();

    m_pRootLayout.get()->addWidget(m_pCaptionLabel.get(), 0, Qt::AlignLeft);
    m_pLabelLayout.get()->addWidget(m_pLeftLabel.get(),   0, Qt::AlignLeft);
    m_pLabelLayout.get()->addWidget(m_pRightLabel.get(),  0, Qt::AlignRight);

    m_pRootLayout.get()->addLayout(m_pLabelLayout.get());
    m_pRootLayout.get()->addWidget(m_pIndicatorBar.get());

    setLayout(m_pRootLayout.get());
}

GUICringOperationsIndicatorBar::~GUICringOperationsIndicatorBar()
{
    //
}

void
GUICringOperationsIndicatorBar::slotUpdatePosition(const int &value)
{
    m_pIndicatorBar.get()->SetPosition(value);
}