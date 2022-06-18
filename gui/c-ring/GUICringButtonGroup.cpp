// GUICringButtonGroup.cpp
// karl eirik bang fossberg

#include "GUICringButtonGroup.h"

#include <QtWidgets/QSizePolicy>

GUICringButtonGroup::GUICringButtonGroup(QBoxLayout::Direction direction,
    std::vector<int> &indices,
    QWidget *pParent)
    : QWidget(pParent)
    , m_negated(false)
    , m_indices(indices)
    , m_direction(direction)
    , m_pLayout(nullptr)
{
    if ((direction == QVBoxLayout::RightToLeft) || (direction == QVBoxLayout::TopToBottom))
    {
        m_negated = true;
    }

    m_pLayout = new QBoxLayout(direction);
    for (std::vector<int>::iterator it = m_indices.begin();
         it != m_indices.end();
         ++it)
    {
        GUICringPushButton *tmp = new GUICringPushButton(m_negated ? (-*it) : (*it));
        tmp->setFixedSize(40, 30);
        m_pLayout->addWidget(tmp);

        connect(tmp, &GUICringPushButton::signalButtonPushed, this, &GUICringButtonGroup::slotHandleButtonPush);
    }

    // END BUTTON
    QPushButton *pEnd = new QPushButton(SetText());
    pEnd->setFixedSize(40, 30);
    pEnd->setAutoRepeat(true);
    m_pLayout->addWidget(pEnd);

    connect(pEnd, &QPushButton::pressed, this, &GUICringButtonGroup::slotHandleContinous);

    setLayout(m_pLayout);
}

GUICringButtonGroup::~GUICringButtonGroup()
{
    //
}

void
GUICringButtonGroup::slotHandleButtonPush(int index)
{
    emit signalRelative(m_direction, index);
}

void
GUICringButtonGroup::slotHandleContinous()
{
    emit signalContinous((int)m_direction);
}

QChar
GUICringButtonGroup::SetText()
{
    // this is unicode to get the fancy arrows
    switch(m_direction)
    {
        case QBoxLayout::LeftToRight: return QChar(0x1405); // RIGHT ARROW
        case QBoxLayout::RightToLeft: return QChar(0x140A); // LEFT ARROW
        case QBoxLayout::TopToBottom: return QChar(0x1401); // DOWN ARROW
        case QBoxLayout::BottomToTop: return QChar(0x1403); // UP ARROW
        default:                      return QChar('?'); // questionmark. undefinded behaviour.
    }
}

