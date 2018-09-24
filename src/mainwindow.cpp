#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent) 
	: QMainWindow(parent) 
{
	drawWidget = new DrawWidget(this);

	this->setCentralWidget(drawWidget);
}