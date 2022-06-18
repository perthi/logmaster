// GUICringAbsolute360.h
// karl eirik bang fossberg

#ifndef GUI_CRING_ABSOLUTE_360_H
#define GUI_CRING_ABSOLUTE_360_H

#include "GUICringAbsolutePos.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <memory>

class GUICringAbsolute360 : public GUICringAbsolutePos
{

public:
    GUICringAbsolute360()
        : GUICringAbsolutePos()
    {
        QHBoxLayout *pLayout = new QHBoxLayout();
        m_pRevolutions       = std::make_unique<QLabel>("0");
        m_pRevolutionsLabel  = std::make_unique<QLabel>("revolutions");
        pLayout->addWidget(m_pRevolutions.get());
        pLayout->addWidget(m_pRevolutionsLabel.get());
        m_pLayout.get()->addLayout(pLayout, 4, 1);
    }

    ~GUICringAbsolute360()
    {
        //
    }

    virtual void slotUpdateRevolutionsInternal(int revolutions) override
    {
        m_pRevolutions.get()->setText(QString::number(revolutions));
    };

private:
    std::unique_ptr<QLabel> m_pRevolutions;
    std::unique_ptr<QLabel> m_pRevolutionsLabel;
};

#endif // GUI_CRING_ABSOLUTE_360_H
