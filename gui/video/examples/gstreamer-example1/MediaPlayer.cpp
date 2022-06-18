// mediaplayer.cpp
// karl eirik bang fossberg

#include <iostream>
#include <string>
#include <boost/format.hpp>

#include <QtWidgets/QApplication>
#include <QtGStreamer/QGst/Bin>
#include <QtGStreamer/QGst/Parse>
#include <QtGStreamer/QGst/Pipeline>
#include <QtGStreamer/QGlib/Connect>
#include <QtGStreamer/QGlib/Error>
#include "MediaPlayer.h"

MediaPlayer::MediaPlayer(QWidget *p_parent)
    : QGst::Ui::VideoWidget(p_parent)
    , m_latency(50)
    , m_url("rtsp://192.168.0.100:8554/stream")
{

        // string to parse and feed into parse::launch
    m_parsestring = "playbin latency=" + std::to_string(m_latency) + " uri=" + m_url;


    // video pipeline creation
    m_pipeline = QGst::Parse::launch(m_parsestring.c_str()).dynamicCast<QGst::Pipeline>();
    m_pipeline->setState(QGst::StatePlaying);
    this->setVideoSink(m_pipeline);

    // monitoring
    m_bus = m_pipeline->bus();
    m_bus->addSignalWatch();
    QGlib::connect(m_bus, "message", this, &MediaPlayer::onBusMessage);


}

MediaPlayer::~MediaPlayer()
{
    if(m_pipeline)
    {
        m_pipeline->setState(QGst::StateNull);
        stopPipelineWatch();
    }
}


void
MediaPlayer::onBusMessage(const QGst::MessagePtr &message)
{
    switch(message->type())
    {
     case QGst::MessageEos:
         if(m_pipeline)
         {
             m_pipeline->setState(QGst::StateNull);
         }
         break;
     case QGst::MessageInfo:
     case QGst::MessageError:
         qCritical() << message.staticCast<QGst::ErrorMessage>()->error();
         break;
        
    default:
        break;
    }

    {

        std::string tmp_typename = message->typeName().toStdString();
        std::string tmp_source   = message->source()->name().toStdString();
        std::cout << boost::format("[%-24s][%-16s]")
            % tmp_source
            % tmp_typename
                  << std::endl;

        
    }
}
