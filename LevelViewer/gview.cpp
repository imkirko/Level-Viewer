#include "subwindows.h"
#include "gview.h"
#include "gscene.h"

GView::GView(QWidget *parent)
	: QGraphicsView(parent)
{
	setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
}

QString GView::getCurFile()
{
	return ((SceneWindow*)parentWidget())->getCurFile();
}
