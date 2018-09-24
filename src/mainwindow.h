#pragma once
#include <QMainWindow>
#include "drawwidget.h"

class MainWindow :
	public QMainWindow
{
	Q_OBJECT
public : 
	explicit MainWindow(QWidget * parent = 0);
private:
	DrawWidget* drawWidget;
};