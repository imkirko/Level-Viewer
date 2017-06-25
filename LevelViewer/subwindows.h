#pragma once

#include <QMdiSubWindow>
#include <QFile>
#include <QFileInfo>

class SubWindow : public QMdiSubWindow
{
	Q_OBJECT

	public:
	SubWindow(QWidget *parent);
};

class StartWindow : public SubWindow
{
	public:
	StartWindow(QWidget *parent);
};

class SceneWindow : public SubWindow
{
	public:
	SceneWindow(QWidget *parent);

	bool loadFile(const QString &fileName);
	QString getCurFile();

	private:
	QString curFile;
	//QFileInfo curFileInfo;
};
