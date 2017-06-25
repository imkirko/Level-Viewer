#pragma once

#include <QMdiArea>
#include <QFile>

class WindowManager : public QMdiArea
{
	Q_OBJECT

	public:
	WindowManager();
	bool addSceneWindow(const QString &fileName);
	void addStartWindow();

	public slots:
	void closeFile();
	void addToRecent(const QString &fileName);
};
