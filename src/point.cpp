#include "point.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

QRectF MyPoint::boundingRect() const
{
	return QRectF(
		screenPosition.x() - 5, screenPosition.y() - 5,
		10, 10);
}

void MyPoint::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawRect(
		screenPosition.x() - 5, screenPosition.y() - 5,
		10, 10);
	painter->drawPoint(screenPosition.x(), screenPosition.y());
}

void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	std::cout << "pressed " 
		<< "position " 
		<< event->scenePos().x() << " "
		<< event->scenePos().y() << "\n";
	update();
}

void MyPoint::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsItem::mouseMoveEvent(event);
	std::cout << "moved "
		<< "position "
		<< event->scenePos().x() << " "
		<< event->scenePos().y() << "\n";
	update();
}

MyPoint::MyPoint(int x, int y, QObject* parent)
	: QObject(parent), QGraphicsItem()
{
	setFlag(ItemIsMovable);
	setFlag(ItemSendsGeometryChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-1);
	screenPosition = QPoint(x, y);
}
