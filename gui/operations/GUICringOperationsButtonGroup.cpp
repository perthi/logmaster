// GUICringOperationsButtonGroup.cpp
// karl eirik bang fossberg

#include "GUICringOperationsButtonGroup.h"

#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <algorithm>
#include <memory>

#include <gui/common/GUICringPushButton.h>

GUICringOperationsButtonGroup::GUICringOperationsButtonGroup(
    const KFHMIStepNavigator &navigator,
    QWidget *pParent)
    : QWidget(pParent)
    , m_navigator(navigator)
{
    m_pRootLayout                             = std::make_unique<QVBoxLayout>();
    m_pButtonLayout                           = std::make_unique<QHBoxLayout>();
    std::unique_ptr<QHBoxLayout> pLabelLayout = std::make_unique<QHBoxLayout>();


    pLabelLayout.get()->addWidget(new QLabel(navigator.fCaption.fCaptionMax.c_str()), 0, Qt::AlignLeft);
    pLabelLayout.get()->addWidget(new QLabel(navigator.fCaption.fCaptionMin.c_str()), 0, Qt::AlignRight);

    // Continous Motion Negative
    std::unique_ptr<QPushButton> pContNegative = std::make_unique<QPushButton>(QChar(0x140A));

    connect(pContNegative.get(), &QPushButton::pressed, this, &GUICringOperationsButtonGroup::slotStartContinousNegative);
    connect(pContNegative.get(), &QPushButton::released, this, &GUICringOperationsButtonGroup::slotInternalStop);
    m_pButtonLayout.get()->addWidget(pContNegative.release());

    // ButtonRow Negative
    std::vector<int> indices = navigator.fSteps;
    std::vector<int> indicesReversed;
    for (size_t i = indices.size(); i != 0; i--)
    {
        indicesReversed.push_back(-indices[(i - 1)]);
    }
    AddVector(indicesReversed);

    // Stop Button
    std::unique_ptr<QPushButton> pStop = std::make_unique<QPushButton>("Stop");
    connect(pStop.get(), &QPushButton::released, this, &GUICringOperationsButtonGroup::slotInternalStop);
    m_pButtonLayout.get()->addWidget(pStop.release());

    // ButtonRow Positive
    AddVector(indices);

    // Continous Motion Positive
    std::unique_ptr<QPushButton> pContPositive = std::make_unique<QPushButton>(QChar(0x1405));
    connect(pContPositive.get(), &QPushButton::pressed, this, &GUICringOperationsButtonGroup::slotStartContinousPositive);
    connect(pContPositive.get(), &QPushButton::released, this, &GUICringOperationsButtonGroup::slotInternalStop);
    m_pButtonLayout.get()->addWidget(pContPositive.release());

    m_pRootLayout.get()->addLayout(pLabelLayout.release());
    m_pRootLayout.get()->addLayout(m_pButtonLayout.release());
    setLayout(m_pRootLayout.release());
}

GUICringOperationsButtonGroup::~GUICringOperationsButtonGroup()
{
    //
}

void
GUICringOperationsButtonGroup::AddVector(std::vector<int> indices)
{
    for (std::vector<int>::iterator it = indices.begin(); it != indices.end(); ++it)
    {
        std::unique_ptr<GUICringPushButton> tmp = std::make_unique<GUICringPushButton>(*it);
        connect(tmp.get(), &GUICringPushButton::signalButtonPushed, this, &GUICringOperationsButtonGroup::slotInternalPositionIncrement);
        m_pButtonLayout.get()->addWidget(tmp.release());
    }
}

void
GUICringOperationsButtonGroup::slotInternalPositionIncrement(const int &value)
{
    emit signalPositionIncrement(value);
}

void
GUICringOperationsButtonGroup::slotInternalStop()
{
    emit signalStop();
}


void
GUICringOperationsButtonGroup::slotStartContinousPositive()
{
    emit signalStartContiuous(eDIRECTION::POSITIVE);
}

void
GUICringOperationsButtonGroup::slotStartContinousNegative()
{
    emit signalStartContiuous(eDIRECTION::NEGATIVE);
}
