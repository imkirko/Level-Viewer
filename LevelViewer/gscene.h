#pragma once

#include <QGraphicsScene>

class GScene : public QGraphicsScene
{
	public:
	GScene();
};

class LevelScene : public GScene
{
	public:
	LevelScene();
};

class GmapScene : public GScene
{
	public:
	GmapScene();
};
