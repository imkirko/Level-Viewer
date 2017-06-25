#include "subwindows.h"
#include "windowmanager.h"
#include "gview.h"
#include "gscene.h"
#include <QMessageBox>
#include <QFileInfo>

SubWindow::SubWindow(QWidget *parent)
	: QMdiSubWindow(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
}

StartWindow::StartWindow(QWidget *parent)
	: SubWindow(parent)
{}

SceneWindow::SceneWindow(QWidget *parent)
	: SubWindow(parent)
{}

bool SceneWindow::loadFile(const QString &fileName)
{
	curFile = fileName;
	setWindowTitle(QFileInfo(curFile).fileName());

	// Try to open file
	QFile file(curFile);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, tr("Error"),
			tr("Can't read file %1:\n%2.")
			.arg(curFile)
			.arg(file.errorString()));

		close(); 

		return false;
	}

	GView *view = new GView(this);
	setWidget(view);

	// Check if valid file type
	// todo: check contents rather than file suffix to see if file is valid
	QString suffix = QFileInfo(curFile).suffix();
	if (suffix == "nw")
	{
		LevelScene *scene = new LevelScene;
		view->setScene(scene);
	}
	else if (suffix == "gmap")
	{
		GmapScene *scene = new GmapScene;
		view->setScene(scene);
	}
	else
	{
		QMessageBox::warning(this, tr("Error"),
			tr("Invalid file type '%1'")
			.arg(suffix));

		close();

		return false;
	}

	((WindowManager*)parentWidget())->addSubWindow(this);

	return true;
}

QString SceneWindow::getCurFile()
{
	return curFile;
}
 