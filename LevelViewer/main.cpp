/*
	Created by Kirko <kirko1029@gmail.com>
	Started June 19, 2017
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QCoreApplication::setOrganizationName("Kirko");
	QCoreApplication::setApplicationName("Level Viewer");
	QCoreApplication::setApplicationVersion("1.0.0");

	MainWindow window;
	window.show();

	return app.exec();
}
