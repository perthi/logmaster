// mediaplayer.hpp
// karl eirik bang fossberg

#ifndef MEDIAPLAYER_HPP
#define MEDIAPLAYER_HPP

#include <string>
#include <QtGStreamer/QGst/Bus>
#include <QtGStreamer/QGst/Pipeline>
#include <QtGStreamer/QGst/Ui/VideoWidget>
#include <QtGStreamer/QGst/Message>

class MediaPlayer : public QGst::Ui::VideoWidget
{
    Q_OBJECT


public:
    MediaPlayer(QWidget *p_parent = nullptr);
    ~MediaPlayer();

private:
    void onBusMessage(const QGst::MessagePtr &message);

private:

    QGst::PipelinePtr m_pipeline;
    QGst::BusPtr m_bus;

    
    uint m_latency;
    std::string m_url;
    std::string m_parsestring;

};

#endif // MEDIAPLAYER_HPP
