#include "point.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

void MyPoint::setScreenPos(QPointF newPosition)
{
	screenPosition = newPosition;
	update();
}

QPointF MyPoint::getScreenPos() const
{
	return screenPosition;
}

QRectF MyPoint::boundingRect() const
{
	return QRectF(
		-5, -5,
		10, 10);
}

void MyPoint::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawRect(
		-5, -5,
		10, 10);
	painter->drawPoint(0, 0);
	std::cout << "draw  "
		<< "position "
		<< screenPosition.x() << " "
		<< screenPosition.y() << "\n";
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
		<< this->scenePos().x() << " "
		<< this->scenePos().y() << "\n";
	screenPosition = this->scenePos();
	emit pointMoved();
	update();
}

MyPoint::MyPoint(int x, int y, QObject* parent)
	: QObject(parent), QGraphicsItem()
{
	setFlag(ItemIsMovable);
	setFlag(ItemSendsScenePositionChanges);
	setFlag(ItemSendsGeometryChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(3);
	setPos(x, y);
	screenPosition = QPoint(x, y);
}
