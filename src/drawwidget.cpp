#include "drawwidget.h"
#include "point.h"
#include "line.h"
#include <iostream>

void DrawWidget::mousePressEvent(QMouseEvent * event)
{

}

void DrawWidget::mouseMoveEvent(QMouseEvent * event)
{

}

DrawWidget::DrawWidget(QWidget * parent) : QWidget(parent)
{
	this->setMinimumSize(600, 480);

	graphicsScene = new QGraphicsScene();
	graphicsScene->setSceneRect(0, 0, 600, 480);
	graphicsView = new QGraphicsView(graphicsScene, this);
	graphicsView->setMinimumSize(600, 480);
	graphicsView->setFrameRect(QRect(0, 0, 600, 480));

	MyPoint* point = new MyPoint(0, 0);
	graphicsScene->addItem(point);
	MyPoint* point2 = new MyPoint(200, 100);
	graphicsScene->addItem(point2);

	MyLine * line = new MyLine(point, point2);
	graphicsScene->addItem(line);

	MyPoint* point3 = new MyPoint(200, 0);
	graphicsScene->addItem(point3);
	MyPoint* point4 = new MyPoint(0, 100);
	graphicsScene->addItem(point4);

	MyLine * line2 = new MyLine(point3, point4);
	graphicsScene->addItem(line2);

}

void DrawWidget::setBackgroundImage(QImage * image)
{
	QBrush background = QBrush(*image);
	graphicsScene->setSceneRect(
		0,
		0,
		image->size().width(),
		image->size().height());
	
	graphicsScene->setBackgroundBrush(background);
	graphicsScene->update();
}

void DrawWidget::slotSetMode(FMODE mode)
{
	currentMode = mode;
	std::cout << "Figure mode changed to " 
		<< QVariant::fromValue(currentMode).toString().toStdString() << "\n";
}
