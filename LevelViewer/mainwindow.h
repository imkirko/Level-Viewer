#pragma once

#include <QMainWindow>
#include <QMdiArea>
#include <QToolBar>

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	private:
	void closeEvent(QCloseEvent *event);

	void restoreSettings();
	void completeWindow();

	QMdiArea *mdiArea;
};
