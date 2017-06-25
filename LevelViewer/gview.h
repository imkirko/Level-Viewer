#pragma once

#include <QGraphicsView>

class GView : public QGraphicsView
{
	Q_OBJECT

	public:
	GView(QWidget *parent);

	private:
	QString getCurFile();
};
