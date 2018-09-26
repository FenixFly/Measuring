#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) 
	: QMainWindow(parent) 
{
	drawWidget = new DrawWidget(this);
	this->setCentralWidget(drawWidget);

	toolbar = new Toolbar(this);
	this->addToolBar(toolbar);

	connect(
		this->toolbar, SIGNAL(signalImageOpened(QImage*)),
		this, SLOT(slotSetBackgroundImage(QImage*)));
}

void MainWindow::slotSetBackgroundImage(QImage * image)
{
	drawWidget->setBackgroundImage(image);
}
