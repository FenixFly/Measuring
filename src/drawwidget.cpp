#include "drawwidget.h"
#include "point.h"

DrawWidget::DrawWidget(QWidget * parent) : QWidget(parent)
{
	this->setMinimumSize(600, 480);

	graphicsScene = new QGraphicsScene();
	graphicsScene->setSceneRect(0, 0, 600, 480);
	graphicsView = new QGraphicsView(graphicsScene, this);
	graphicsView->setMinimumSize(600, 480);

	MyPoint* point = new MyPoint(0, 0);
	graphicsScene->addItem(point);
}