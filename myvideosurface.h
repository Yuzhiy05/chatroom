#ifndef MYVIDEOSURFACE_H
#define MYVIDEOSURFACE_H

//#include <QAbstractVideoSurface>
#include <QVideoSink>
#include <QVideoFrame>
#include <QVideoFrameFormat>


class MyVideoSurface : public Qvideo //QAbstractVideoSurface
{
    Q_OBJECT
public:
    MyVideoSurface(QObject *parent = 0);

    //支持的像素格式
    QList<QVideoFrameFormat::PixelFormat> supportedPixelFormats(QVideoFrame::HandleType handleType = QVideoFrame::NoHandle) const; //override;

    //检测视频流的格式是否合法，返回bool
    bool isFormatSupported(const QVideoFrameFormat &format) const ;
    bool start(const QVideoFrameFormat &format) ;
    bool present(const QVideoFrame &frame) ;
    QRect videoRect() const;
    void updateVideoRect();
    void paint(QPainter *painter);

//private:
//    QWidget      * widget_;
//    QImage::Format imageFormat_;
//    QRect          targetRect_;
//    QSize          imageSize_;
//    QVideoFrame    currentFrame_;

signals:
    void frameAvailable(QVideoFrame);

};

#endif // MYVIDEOSURFACE_H
