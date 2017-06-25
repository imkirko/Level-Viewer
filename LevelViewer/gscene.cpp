#include "gscene.h"
#include <QDebug>

GScene::GScene()
{
	setBackgroundBrush(QColor(10, 10, 10));
}

LevelScene::LevelScene()
{
	qDebug() << "Level Scene" << endl;
}

GmapScene::GmapScene()
{
	qDebug() << "Gmap Scene" << endl;
}
