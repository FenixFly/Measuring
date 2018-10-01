#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) 
	: QMainWindow(parent) 
{
	drawWidget = new DrawWidget(this);
	this->setCentralWidget(drawWidget);

	toolbar = new Toolbar(this);
	this->addToolBar(toolbar);
	
	connectToolbarSignals();
}

void MainWindow::slotSetBackgroundImage(QImage * image)
{
	drawWidget->setBackgroundImage(image);
}

void MainWindow::connectToolbarSignals()
{
	connect(this->toolbar, SIGNAL(signalMode(FMODE)),
		this->drawWidget, SLOT(slotSetMode(FMODE)));
	connect(this->toolbar, SIGNAL(signalImageOpened(QImage*)),
		this, SLOT(slotSetBackgroundImage(QImage*)));
}
