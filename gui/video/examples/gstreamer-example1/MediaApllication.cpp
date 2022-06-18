// mediaapplication.cpp
// karl eirik bang fossberg

#include "MediaApllication.h"
#include "MediaPlayer.h"


MediaApplication::MediaApplication(QWidget *p_parent)
    : QWidget(p_parent)
{

    m_pPlayer = new MediaPlayer(this);

    m_pLayout = new QVBoxLayout;
    m_pLayout->setContentsMargins(0, 0, 0, 0);

    m_pLayout->addWidget(m_pPlayer);
    setLayout(m_pLayout);



    setWindowTitle("QtStreamer minimal (working) example");
    resize(800, 600);
};

MediaApplication::~MediaApplication()
{

    delete m_pPlayer;
    m_pPlayer = nullptr;

    delete m_pLayout;
    m_pLayout = nullptr;

};
