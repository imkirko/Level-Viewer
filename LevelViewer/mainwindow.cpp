#include "mainwindow.h"
#include "subwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	restoreSettings();
	connect(this, SIGNAL(close), this, SLOT(closeEvent));

	// Complete window
	createActions();
	createBaseWidgets();
}

void MainWindow::restoreSettings()
{
	resize(500, 400); // Default size

	QSettings settings;
	settings.beginGroup("windowState");
	restoreGeometry(settings.value("geometry").toByteArray());
	restoreState(settings.value("state").toByteArray());
	settings.endGroup();
}

void MainWindow::createActions()
{
	openFileAction = new QAction(tr("&Open"), this);
	closeFileAction = new QAction(tr("&Close"), this);
	exportPngAction = new QAction(tr("&PNG"), this);
	aboutAction = new QAction(tr("&About"), this);
}

void MainWindow::createBaseWidgets()
{
	// Central
	mdiArea = new QMdiArea(this);
	mdiArea->setViewMode(QMdiArea::TabbedView);
	mdiArea->setTabsClosable(true);
	mdiArea->setTabsMovable(true);
	setCentralWidget(mdiArea);

	// Menu
	menuBar = new QMenuBar(this);
	setMenuBar(menuBar);
	fileMenu = menuBar->addMenu("&File");
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(closeFileAction);
	fileExportMenu = fileMenu->addMenu("&Export");
	fileExportMenu->addAction(exportPngAction);
	helpMenu = menuBar->addMenu("&Help");
	helpMenu->addAction(aboutAction);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	// Save Window State
	QSettings settings;
	settings.beginGroup("windowState");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("state", saveState());
	settings.endGroup();
}

void MainWindow::openTestLevel()
{
	// open subwindow with test level
	// will do loading file stuff later
}