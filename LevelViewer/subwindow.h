#pragma once

#include <QMdiSubWindow>

class SubWindow : public QMdiSubWindow
{
	Q_OBJECT

	public:
	SubWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
};
