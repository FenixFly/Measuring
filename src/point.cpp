#include "point.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

void MyPoint::setScreenPos(QPointF newPosition)
{
	screenPosition = newPosition;
	setPos(newPosition);
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
}

void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
	update();
}

void MyPoint::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsItem::mouseMoveEvent(event);
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
