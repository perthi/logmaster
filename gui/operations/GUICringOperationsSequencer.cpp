// GUICringOperationsSequencer.cpp
// karl eirik bang fossberg

#include "GUICringOperationsSequencer.h"


#include <sequence/KFSequenceBase.h>
#include <sequence/KFSequenceTemplate.h>
#include <sequence/KFSequenceCoating.h>
#include <sequence/KFSequenceWrapping.h>
#include <sequence/KFSequenceSurfacePrep.h>
#include <sequence/KFSequencePatching.h>


GUICringOperationsSequencer::GUICringOperationsSequencer(
    QWidget *pParent)
    : QWidget(pParent)
    , FSMNode_Operation("Sequencer")
    , m_isPlaying(false)
    , m_isStopped(true)
    , m_currentSequenceIndex(0)
{
    StartComponent();

    m_playSymbol    = QChar(0x25B6);
    m_stopSymbol    = QChar(0x25A0);
    m_restartSymbol = QChar(0x21BA);
    m_pauseSymbol   = QString(QChar(0x25AE)).append(QChar(0x25AE));
    pRootLayout     = std::make_unique<QGridLayout>();
    pCaptionLabel   = std::make_unique<QLabel>("Sequencer");
    m_pPlayPause    = std::make_unique<QPushButton>(m_playSymbol);
    m_pStopRestart  = std::make_unique<QPushButton>(m_stopSymbol);
    m_pSequenceList = std::make_shared<QComboBox>();

    // m_pPlayPause.get()->setFixedSize(30, 30);
    // m_pStopRestart.get()->setFixedSize(30, 30);

    // m_sequences.push_back(std::make_shared<KFSequenceTemplate>());
    m_sequences.push_back(std::make_shared<KFSequenceCoating>());
    m_sequences.push_back(std::make_shared<KFSequenceWrapping>());
    m_sequences.push_back(std::make_shared<KFSequenceSurfacePrep>());
    m_sequences.push_back(std::make_shared<KFSequencePatching>());

    for(size_t i = 0; i < m_sequences.size(); i++)
    {
        m_pSequenceList.get()->addItem(m_sequences[i].get()->GetSequenceName().c_str(), {int(i)});
        AddChild(m_sequences[i]);
    }


    connect(m_pPlayPause.get(),   &QPushButton::clicked, this, &GUICringOperationsSequencer::slotPlayPauseToggle);
    connect(m_pStopRestart.get(), &QPushButton::clicked, this, &GUICringOperationsSequencer::slotStopRestartToggle);
    connect(m_pSequenceList.get(), QOverload<int>::of(&QComboBox::activated),this, &GUICringOperationsSequencer::slotListIndexChanged);

    pRootLayout.get()->addWidget(pCaptionLabel.release(), 0, 0);
    pRootLayout.get()->addWidget(m_pPlayPause.get(),      1, 0);
    pRootLayout.get()->addWidget(m_pStopRestart.get(),    1, 1);
    pRootLayout.get()->addWidget(m_pSequenceList.get(),   1, 2, 1, 8);

    m_pStopRestart.get()->setEnabled(false);
    setLayout(pRootLayout.release());
}

GUICringOperationsSequencer::~GUICringOperationsSequencer()
{
    //
}

int API
GUICringOperationsSequencer::ExcecLocal(const string action)
{
    // This is purely an interface to the sequence chosen, this is to support the
    // main fsm.
    m_sequences.at(m_currentSequenceIndex)->ExcecLocal(action);
    return FSM_RET_SUCCESS;
}

void
GUICringOperationsSequencer::slotStopRestartToggle()
{
    if(m_isStopped)
    {
        Stop();
    }
    else
    {
        Reset();
    }
}

void
GUICringOperationsSequencer::slotPlayPauseToggle()
{
    if(m_isPlaying)
    {
        Pause();
    }
    else
    {
        Play();
    }
}

void
GUICringOperationsSequencer::slotListIndexChanged(int index)
{
    m_currentSequenceIndex = index;
}


void
GUICringOperationsSequencer::LockSequence()
{
    m_sequenceLocked = true;
    m_pSequenceList.get()->setEnabled(false);

}

void
GUICringOperationsSequencer::UnlockSequence()
{
    m_sequenceLocked = false;
    m_pSequenceList.get()->setEnabled(true);
}

void
GUICringOperationsSequencer::Play()
{
    if(m_sequenceLocked)
    {
        ExcecLocal("CONTINUE");
    } else
    {
        LockSequence();
        ExcecLocal("GO_READY");
    }

    m_pPlayPause.get()->setText(m_pauseSymbol);
    m_isPlaying = true;

    m_pStopRestart.get()->setEnabled(true);
}

void
GUICringOperationsSequencer::Pause()
{
    m_pPlayPause.get()->setText(m_playSymbol);
    m_isPlaying = false;
    ExcecLocal("PAUSE");
}

void
GUICringOperationsSequencer::Stop()
{
    m_pStopRestart.get()->setText(m_restartSymbol);
    m_isStopped = false;

    m_pPlayPause.get()->setEnabled(false);

    ExcecLocal("ABORT");
}

void
GUICringOperationsSequencer::Reset()
{
    m_pStopRestart.get()->setText(m_stopSymbol);
    m_pStopRestart.get()->setEnabled(false);

    m_pPlayPause.get()->setText(m_playSymbol);
    m_pPlayPause.get()->setEnabled(true);

    m_isStopped = true;
    m_isPlaying = false;

    UnlockSequence();
    ExcecLocal("RESET");
}
