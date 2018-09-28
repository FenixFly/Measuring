#include <QMouseEvent>
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

	graphicsScene = new Scene();
	graphicsScene->setSceneRect(0, 0, 600, 480);
	graphicsView = new QGraphicsView(graphicsScene, this);
	graphicsView->setMinimumSize(600, 480);
	graphicsView->setFrameRect(QRect(0, 0, 600, 480));
	
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
	graphicsScene->setMode(currentMode);
	std::cout << "Figure mode changed to " 
		<< QVariant::fromValue(currentMode).toString().toStdString() << "\n";
}
