/*
	Created by Kirko <kirko1029@gmail.com>
	Started June 19, 2017
*/

#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QCoreApplication::setOrganizationName("Kirko");
	QCoreApplication::setApplicationName("Level Viewer");
	QCoreApplication::setApplicationVersion("1.0.0");

	QCommandLineParser parser;
	parser.setApplicationDescription("View your levels a");
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("file", "File to open");
	parser.process(app);

	MainWindow window;
	if (!parser.positionalArguments().isEmpty())
	{
		window.openFile(parser.positionalArguments().first());
	}
	window.show();

	return app.exec();
}
