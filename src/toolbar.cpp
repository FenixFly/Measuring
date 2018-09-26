#include "toolbar.h"
#include <QFileDialog>

Toolbar::Toolbar(QWidget * parent) :
	QToolBar(parent)
{
	addButtonOpenImage();
}

void Toolbar::addButtonOpenImage()
{
	QAction * openImageAction = new QAction("Open Image", this);
	this->addAction(openImageAction);
	connect(openImageAction, SIGNAL(triggered()), this, SLOT(slotOpenImage()));
}

void Toolbar::slotOpenImage()
{
	QString fname = QFileDialog::getOpenFileName(
		this, tr("Load Binary File"));
	if (fname.isEmpty())
		return;
	QImage image(fname);

	emit signalImageOpened(&image);
}