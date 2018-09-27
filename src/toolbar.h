#pragma once
#include <QToolBar>
#include "enums.h"

class Toolbar :
	public QToolBar
{
	Q_OBJECT
private:
	void addButtonOpenImage();
	void addButtonsFigures();
public:
	explicit Toolbar(QWidget *parent);
private slots:
	void slotOpenImage();
signals:
	void signalImageOpened(QImage*);
	void signalMode(FMODE mode);
};