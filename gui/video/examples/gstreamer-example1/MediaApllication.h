// mediaapplication.hpp
// karl eirik bang fossberg

#ifndef MEDIAAPPLICATION_HPP
#define MEDIAAPPLICATION_HPP


#include <QtWidgets/QWidget>

#include <QtWidgets/QBoxLayout>
//#include "mediaplayer.hpp"

class MediaPlayer;


class MediaApplication : public QWidget
{

    Q_OBJECT


public:
    MediaApplication(QWidget *p_parent = nullptr);
    ~MediaApplication();


private:
    MediaPlayer *m_pPlayer;
    QVBoxLayout *m_pLayout;

};

#endif // MEDIAAPPLICATION_HPP
