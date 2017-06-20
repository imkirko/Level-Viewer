#include "mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), mdiArea(new QMdiArea(this))
{
	// Window basics
	resize(500, 400);

	mdiArea->setViewMode(QMdiArea::TabbedView);
	mdiArea->setTabsClosable(true);
	mdiArea->setTabsMovable(true);
	setCentralWidget(mdiArea);

	// Restore
	restoreSettings();

	// Continue to fill widgets
	completeWindow();
}

// Set window to how user left it
// TODO: allow user to disable this
void MainWindow::restoreSettings()
{
	QSettings settings;
	settings.beginGroup("windowState");
	restoreGeometry(settings.value("geometry").toByteArray());
	restoreState(settings.value("state").toByteArray());
	settings.endGroup();
}

// continue to add widgets and crap to window
void MainWindow::completeWindow()
{
	connect(this, SIGNAL(close), this, SLOT(closeEvent));
}

// Window is closing, do required actions
void MainWindow::closeEvent(QCloseEvent *event)
{
	QSettings settings;
	settings.beginGroup("windowState");
	settings.setValue("geometry", saveGeometry());
	settings.setValue("state", saveState());
	settings.endGroup();
}