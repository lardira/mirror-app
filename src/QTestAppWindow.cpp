#include "QTestAppWindow.h"

QTestAppWindow::QTestAppWindow(const QSize& size = {500, 500})
{
	setMinimumSize(size);
	showScreenButton.setText("Play/Start");

	centeringLayout.addLayout(&mainLayout);
	mainLayout.addWidget(&showScreenButton);
	mainLayout.addWidget(&screen);

	mainLayout.setAlignment(Qt::AlignCenter);
	centeringLayout.setAlignment(Qt::AlignCenter);

	this->setCentralWidget(&centralWidget);
	this->setLayout(&centeringLayout);
	screen.show();

	connect(&showScreenButton, &QPushButton::clicked, this, &QTestAppWindow::OnPlayButton);
}

void QTestAppWindow::OnPlayButton()
{
	isPlaying = !isPlaying;
	isPlaying ? screen.StartRecording(): screen.StopRecording();
}