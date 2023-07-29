#include "myvideosurface.h"
#include <QVideoFrameFormat>
#include <QVideoFrame>
#include <QDebug>
#include<QMediaPlayer>
MyVideoSurface::MyVideoSurface(QObject *parent)
{

}

QList<QVideoFrameFormat::PixelFormat> MyVideoSurface::supportedPixelFormats(QVideoFrame::HandleType handleType) const
{
    if(handleType == QVideoFrame::NoHandle)
    {
        return QList<QVideoFrameFormat::PixelFormat>() << QVideoFrameFormat::Format_ARGB8888
                                                 << QVideoFrameFormat::Format_XRGB8888
                                                 << QVideoFrameFormat::Format_ARGB8888_Premultiplied
                                                 << QVideoFrameFormat::Format_BGRA8888
                                                 << QVideoFrameFormat::Format_XBGR8888;
    }
    else
    {
        return QList<QVideoFrameFormat::PixelFormat>();
    }
}


bool MyVideoSurface::isFormatSupported(const QVideoFrameFormat &format) const
{
    // imageFormatFromPixelFormat: 返回与视频帧像素格式等效的图像格式
    //pixelFormat: 返回视频流中的像素格式
    return QVideoFrameFormat::imageFormatFromPixelFormat(format.pixelFormat()) != QImage::Format_Invalid;
}

//将视频流中像素格式转换成格式对等的图片格式
bool MyVideoSurface::start(const QVideoFrameFormat &format)
{
    if(isFormatSupported(format) && !format.frameSize().isEmpty())
    {
        //QAbstractVideoSurface::start(format);
        return true;
    }
    return false;
}


//捕获每一帧视频，每一帧都会到present
bool MyVideoSurface::present(const QVideoFrame &frame)
{
    if(!frame.isValid())
    {
        //stop();
        return false;
    }
    if(frame.isMapped())
    {
        emit frameAvailable(frame);
    }
    else
    {
        QVideoFrame f(frame);
        f.map(QVideoFrame::ReadOnly);
        emit frameAvailable(f);
    }

    return true;
}
