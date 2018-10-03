#include "toolbar.h"
#include <QFileDialog>

Toolbar::Toolbar(QWidget * parent) :
	QToolBar(parent)
{
	addButtonOpenImage();
	addButtonsFigures();
}

void Toolbar::addButtonOpenImage()
{
	QAction * openImageAction = new QAction("Open Image", this);
	this->addAction(openImageAction);
	connect(openImageAction, SIGNAL(triggered()), this, SLOT(slotOpenImage()));
}

void Toolbar::addButtonsFigures()
{
	// Button cursor
	QAction * cursorAction = new QAction("Cursor", this);
	this->addAction(cursorAction);
	connect(cursorAction, &QAction::triggered,
		[=]() {	emit signalMode(FMODE::NONE); });

	// Button line
	QAction * lineAction = new QAction("Line", this);
	this->addAction(lineAction);
	connect(lineAction, &QAction::triggered,
		[=]() {	emit signalMode(FMODE::LINE); });

	// Button angle
	QAction * angleAction = new QAction("Angle", this);
	this->addAction(angleAction);
	connect(angleAction, &QAction::triggered,
		[=]() {	emit signalMode(FMODE::ANGLE); });

	// Button ellipse
	QAction * ellipseAction = new QAction("Ellipse", this);
	this->addAction(ellipseAction);
	connect(ellipseAction, &QAction::triggered,
		[=]() {	emit signalMode(FMODE::ELLIPSE); });

	// Button polygon
	QAction * polygonAction = new QAction("Polygon", this);
	this->addAction(polygonAction);
	connect(polygonAction, &QAction::triggered,
		[=]() {	emit signalMode(FMODE::POLYGON); });

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