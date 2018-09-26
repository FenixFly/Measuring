#pragma once
#include <QToolBar>

class Toolbar :
	public QToolBar
{
	Q_OBJECT
private:
	void addButtonOpenImage();
public:
	explicit Toolbar(QWidget *parent);
private slots:
	void slotOpenImage();
signals:
	void signalImageOpened(QImage*);
};