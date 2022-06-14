#ifndef QTEST_APP_WINDOW_H
#define QTEST_APP_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>

#include "Screen.h"

class QTestAppWindow : public QMainWindow
{
public:
	QTestAppWindow(const QSize& size);
private:
	void OnPlayButton();

	bool isPlaying = false;
	QWidget centralWidget{ this };
	QVBoxLayout mainLayout{&centralWidget };
	QHBoxLayout centeringLayout{ &centralWidget };
	QPushButton showScreenButton{ &centralWidget };
	Screen screen{ &centralWidget };
};

#endif // !QTEST_APP_WINDOW_H
