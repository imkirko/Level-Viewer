#include "windowmanager.h"
#include "subwindows.h"
#include <QDebug>

WindowManager::WindowManager()
{
	setViewMode(QMdiArea::TabbedView);
	setTabsClosable(true);
	setTabsMovable(true);
	setBackground(QColor(250, 250, 250));
}

bool WindowManager::addSceneWindow(const QString &fileName)
{
	// Save basic scene data here.
	// Create SceneWindow->subwindow->QMdiSubWindow->QGraphicsView where file will be loaded
	// QGraphicsScene->QGraphicItem are going to be
	SceneWindow *levelWindow = new SceneWindow(this);
	return levelWindow->loadFile(fileName);
}

void WindowManager::addStartWindow()
{}

void WindowManager::closeFile()
{
	QMdiSubWindow *curSub = currentSubWindow();
	if (curSub)
	{
		curSub->close();
	}
}

void WindowManager::addToRecent(const QString &fileName)
{}