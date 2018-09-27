#pragma once
#include <QMainWindow>
#include "drawwidget.h"
#include "toolbar.h"

class MainWindow :
	public QMainWindow
{
	Q_OBJECT
public : 
	explicit MainWindow(QWidget * parent = 0);
private:
	DrawWidget* drawWidget;
	Toolbar* toolbar;

	void connectToolbarSignals();
public slots:
	void slotSetBackgroundImage(QImage*);
};