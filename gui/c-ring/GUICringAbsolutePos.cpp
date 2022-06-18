// GUICringAbsolutePos.cpp
// karl eirik bang fossberg

#include "GUICringAbsolutePos.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

#include <protocol/KFProtocolEnums.h>

#include <memory>

GUICringAbsolutePos::GUICringAbsolutePos(QWidget *pParent)
    : QWidget(pParent)
    , m_translation(0.0f)
    , m_rotation(0.0f)
{

    m_pLayout = std::make_unique<QGridLayout>();

    std::unique_ptr<QSpinBox> m_pXWrite  = std::make_unique<QSpinBox>();
    std::unique_ptr<QSpinBox> m_pYWrite  = std::make_unique<QSpinBox>();
    std::unique_ptr<QSpinBox> m_pXRead   = std::make_unique<QSpinBox>();
    std::unique_ptr<QSpinBox> m_pYRead   = std::make_unique<QSpinBox>();
    std::unique_ptr<QLabel> m_pXLabel    = std::make_unique<QLabel>("x");
    std::unique_ptr<QLabel> m_pYLabel    = std::make_unique<QLabel>("y");
    std::unique_ptr<QLabel> m_pXUnit     = std::make_unique<QLabel>("mm");
    std::unique_ptr<QLabel> m_pYUnit     = std::make_unique<QLabel>("degrees");
    std::unique_ptr<QPushButton> m_pSend = std::make_unique<QPushButton>("apply");

    m_pXWrite.get()->setMinimum(-999999);
    m_pXWrite.get()->setMaximum(999999);
    m_pXWrite.get()->setKeyboardTracking(false);
    m_pXWrite.get()->setButtonSymbols(QAbstractSpinBox::NoButtons);

    m_pYWrite.get()->setMinimum(-99999);
    m_pYWrite.get()->setMaximum(99999);
    m_pYWrite.get()->setKeyboardTracking(false);
    m_pYWrite.get()->setButtonSymbols(QAbstractSpinBox::NoButtons);

    m_pXRead.get()->setMinimum(-99999);
    m_pXRead.get()->setMaximum(99999);
    m_pXRead.get()->setReadOnly(true);
    m_pXRead.get()->setEnabled(false);
    m_pXRead.get()->setButtonSymbols(QAbstractSpinBox::NoButtons);

    m_pYRead.get()->setMinimum(-99999);
    m_pYRead.get()->setMaximum(99999);
    m_pYRead.get()->setReadOnly(true);
    m_pYRead.get()->setEnabled(false);
    m_pYRead.get()->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // Connection:
    // Values from the textfield to the rest of the application
    connect(m_pXWrite.get(), QOverload<int>::of(&QSpinBox::valueChanged), this, &GUICringAbsolutePos::slotSetTranslationAbsolute);
    connect(m_pYWrite.get(), QOverload<int>::of(&QSpinBox::valueChanged), this, &GUICringAbsolutePos::slotSetRotationAbsolute);

    // Connection:
    // Incoming values to the textfield
    connect(this, &GUICringAbsolutePos::signalUpdateTextfieldTranslation, m_pXRead.get(),  &QSpinBox::setValue);
    connect(this, &GUICringAbsolutePos::signalUpdateTextfieldRotation,    m_pYRead.get(),  &QSpinBox::setValue);

    // Connnection:
    // Send Absolute Values when Apply is triggered
    connect(m_pSend.get(), &QPushButton::released, this, &GUICringAbsolutePos::slotApplyAbsolutePosition);

    m_pLayout->addWidget(m_pXLabel.release(), 0, 0);
    m_pLayout->addWidget(m_pXWrite.release(), 0, 1);
    m_pLayout->addWidget(m_pXRead.release(),  0, 2);
    m_pLayout->addWidget(m_pXUnit.release(),  0, 3);
    m_pLayout->addWidget(m_pYLabel.release(), 1, 0);
    m_pLayout->addWidget(m_pYWrite.release(), 1, 1);
    m_pLayout->addWidget(m_pYRead.release(),  1, 2);
    m_pLayout->addWidget(m_pYUnit.release(),  1, 3);
    m_pLayout->addWidget(m_pSend.release(),   2, 1, 2, 2);

    setLayout(m_pLayout.get());
}

GUICringAbsolutePos::~GUICringAbsolutePos()
{
    //
}

void
GUICringAbsolutePos::slotSetTranslationAbsolute(double relValue)
{
    m_translation = relValue;
}

void
GUICringAbsolutePos::slotSetRotationAbsolute(double relValue)
{
    m_rotation = relValue;
}

void
GUICringAbsolutePos::slotUpdateTextfieldTranslation(double translation)
{
    emit signalUpdateTextfieldTranslation(translation);
    // printf("Textfield updated\n");
}
void
GUICringAbsolutePos::slotUpdateTextfieldRotation(double rotation)
{
    emit signalUpdateTextfieldRotation(rotation);
    // printf("Textfield updated\n");
}

void
GUICringAbsolutePos::slotApplyAbsolutePosition()
{
    emit signalApplyAbsolutePositionInternal(m_translation, m_rotation);
}
