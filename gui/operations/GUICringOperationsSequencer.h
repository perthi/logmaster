// GUICringOperationsSequencer.h
// karl eirik bang fossberg

#ifndef GUI_CRING_OPERATIONS_SEQUENCER_H
#define GUI_CRING_OPERATIONS_SEQUENCER_H

#include <string>
#include <memory>
#include <vector>

#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include <common/FSM_Definitions.h>

class KFSequenceBase;
class GUICringOperationsSequencer
    : public QWidget
    , public FSMNode_Operation
{
    Q_OBJECT

public:
    GUICringOperationsSequencer(QWidget *pParent = nullptr);
    ~GUICringOperationsSequencer();
    virtual int API ExcecLocal(const string action) override;

private:
    void LockSequence();
    void UnlockSequence();
    void Play();
    void Pause();
    void Stop();
    void Reset();


// private:
// template<typename T> void AddSequence(T arg);

private slots:
    void slotPlayPauseToggle();
    void slotStopRestartToggle();
    void slotListIndexChanged(int index);

private:
    std::vector<std::shared_ptr<KFSequenceBase>> m_sequences;

    std::unique_ptr<QGridLayout> pRootLayout;
    std::unique_ptr<QLabel> pCaptionLabel;
    std::unique_ptr<QPushButton> m_pPlayPause;
    std::unique_ptr<QPushButton> m_pStopRestart;

    std::shared_ptr<QComboBox> m_pSequenceList;

    bool m_isPlaying;
    bool m_isStopped;
    bool m_sequenceLocked;

    QChar m_playSymbol;
    QChar m_stopSymbol;
    QChar m_restartSymbol;
    QString m_pauseSymbol;


    int m_currentSequenceIndex;

};

#endif // GUI_CRING_OPERATIONS_SEQUENCER_H