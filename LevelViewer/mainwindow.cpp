#include "mainwindow.h"
#include "windowmanager.h"
#include <QSettings>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow()
	: windowManager(new WindowManager)
{
	setCentralWidget(windowManager);

	createActions();
	createStatusBar();
	readSettings();

	setUnifiedTitleAndToolBarOnMac(true);
	connect(this, SIGNAL(close), this, SLOT(closeEvent));

	statusBar()->showMessage(tr("Ready"), 2000);
}

// Create and apply actions
void MainWindow::createActions()
{
	// todo: connect to other class
	openFileAction = new QAction(tr("&Open"), this);
	connect(openFileAction, SIGNAL(triggered()), this, SLOT(promptForFile()));
	closeFileAction = new QAction(tr("&Close"), this);
	connect(closeFileAction, SIGNAL(triggered()), windowManager, SLOT(closeFile()));
	exportPngAction = new QAction(tr("&PNG"), this);
	//connect(exportPngAction, SIGNAL(triggered()), this, SLOT(empty));
	aboutAction = new QAction(tr("&About"), this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(viewAboutPage()));

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

// Create and set status bar
void MainWindow::createStatusBar()
{
	windowStatusBar = new QStatusBar(this);
	setStatusBar(windowStatusBar);
}

// Load user preferences and other crap
void MainWindow::readSettings()
{
	QSettings settings;
	settings.beginGroup("windowState");
	const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();

	if (geometry.isEmpty())
	{
		resize(500, 400);
	}
	else
	{
		restoreGeometry(geometry);
		restoreState(settings.value("state").toByteArray());
	}
}

// Window is closing
void MainWindow::closeEvent(QCloseEvent *event)
{
	// Save Window State
	QSettings settings;
	settings.beginGroup("windowState");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("state", saveState());
}

// Let user pick file
void MainWindow::promptForFile()
{
	QString fileName = QFileDialog::getOpenFileName(
		this,
		"Open level or map",
		"",
		"Levels (*.nw *.gmap);;All Files (*)",
		Q_NULLPTR
		//QFileDialog::DontUseNativeDialog
	);

	if (!fileName.isEmpty())
	{
		openFile(fileName);
	}
}

// Try to open file
void MainWindow::openFile(const QString &fileName)
{
	bool loaded = windowManager->addSceneWindow(fileName);

	if (loaded)
		statusBar()->showMessage("File loaded", 2000);
	else
		statusBar()->showMessage("Error loading file", 2000);
}

void MainWindow::viewAboutPage()
{
	QMessageBox::about(this, tr("About"), tr("Level Viewer\nVersion 1.0.0\nCreated by Kirko"));
}
