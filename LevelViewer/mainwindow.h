#pragma once

#include <QMainWindow>
#include <QMdiArea>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	private:
	void closeEvent(QCloseEvent *event);

	void restoreSettings();
	void createBaseWidgets();
	void createActions();
	void openTestLevel();

	QMenuBar *menuBar;
	QMdiArea *mdiArea;

	QMenu *fileMenu;
	QAction *openFileAction;
	QAction *closeFileAction;
	QMenu *fileExportMenu;
	QAction *exportPngAction;

	QMenu *helpMenu;
	QAction *aboutAction;
};
