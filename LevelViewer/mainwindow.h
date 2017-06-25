#pragma once

#include "windowmanager.h"
#include <QMainWindow>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
	MainWindow();

	void openFile(const QString &fileName);

	private:
	void closeEvent(QCloseEvent *event);
	void readSettings();
	void createActions();
	void createStatusBar();

	QMenuBar *menuBar;
	QStatusBar *windowStatusBar;
	WindowManager *windowManager;

	QMenu *fileMenu;
	QAction *openFileAction;
	QAction *closeFileAction;
	QMenu *fileExportMenu;
	QAction *exportPngAction;

	QMenu *helpMenu;
	QAction *aboutAction;

	private slots:
	void promptForFile();
	void viewAboutPage();
};
