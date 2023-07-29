#pragma once

#include <QObject>
#include <QAudioInput>
#include <QIODevice>
#include <QAudioSink>
class AudioInput : public QObject
{
	Q_OBJECT
private:
    QAudioSink *audio;
	QIODevice* inputdevice;
	char* recvbuf;
public:
	AudioInput(QObject *par = 0);
	~AudioInput();
private slots:
	void onreadyRead();
	void handleStateChanged(QAudio::State);
	QString errorString();
	void setVolumn(int);
public slots:
	void startCollect();
	void stopCollect();
signals:
	void audioinputerror(QString);
};
