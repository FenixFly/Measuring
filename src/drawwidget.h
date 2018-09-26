#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class DrawWidget :
	public QWidget
{
	Q_OBJECT
private:
	QGraphicsScene * graphicsScene;
	QGraphicsView * graphicsView;
public : 
	explicit DrawWidget(QWidget * parent = 0);
	void setBackgroundImage(QImage* image);
};