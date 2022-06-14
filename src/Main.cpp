#include <QApplication>

#include "QTestAppWindow.h"

int main(int argc, char* argv)
{
	QApplication app{ argc, &argv };

	const QSize windowSize{ 800, 500 };
	QTestAppWindow mainWindow{windowSize};
	mainWindow.show();

	return app.exec();
}