#include "line.h"
#include <QPainter>
#include <iostream>

QRectF MyLine::boundingRect() const
{
	qreal extra = (pen().width() + 20) / 2.0;

	return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
		line().p2().y() - line().p1().y()))
		.normalized()
		.adjusted(-extra, -extra, extra, extra);
}

void MyLine::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	QGraphicsLineItem::mouseMoveEvent(event);
	
	start->setScreenPos(line().p1());
	end->setScreenPos(line().p2());
	start->update();
	end->update();
}

MyLine::MyLine(MyPoint* _start, MyPoint * _end) :
	start(_start), end(_end)
{
	setFlag(ItemSendsGeometryChanges);
	setFlag(ItemSendsScenePositionChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-300);

	this->setLine(QLineF(start->getScreenPos(), end->getScreenPos()));

	QObject::connect(this->start, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));
	QObject::connect(this->end, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));
}

void MyLine::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	std::cout << "moved "
		<< "line "
		<< start->getScreenPos().x() << " "
		<< start->getScreenPos().y() << " " 
		<< end->getScreenPos().x() << " "
		<< end->getScreenPos().y() << "\n";

	std::cout << " " << line().dx() << " " << line().dy() << "\n";

	painter->drawLine(
		this->line());
	painter->drawText(
		QRectF(end->getScreenPos().x() - line().dx()/2, end->getScreenPos().y() - line().dy() / 2, 40, 40),
		QString::number(line().length(), 'G', 5));
}

void MyLine::slotUpdate()
{
	this->setLine(QLineF(start->getScreenPos(), end->getScreenPos()));
	update();
}
