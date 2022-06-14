#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <QWidget>
#include <QMediaRecorder>
#include <QDebug>
#include <QCamera>
#include <QBoxLayout>
#include <QCameraViewFinder>
#include <QCameraInfo>
#include <QLabel>

class Screen : public QWidget
{
public:
	Screen(QWidget* parent);
	~Screen();

	void StartRecording();
	void StopRecording();
private:
	QCamera* camera;
	QCameraViewfinder* viewfinder;
	QHBoxLayout layout{this};
};

#endif // !SCREEN_H

