#include "angle.h"
#include <QPainter>
#include <iostream>

MyAngle::MyAngle(MyPoint * _start, MyPoint * _mid) :
	start(_start), mid(_mid)
{
	setFlag(ItemSendsGeometryChanges);
	setFlag(ItemSendsScenePositionChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-300);

	this->setLine(QLineF(start->getScreenPos(), mid->getScreenPos()));

	QObject::connect(this->start, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));
	QObject::connect(this->mid, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));

	end = nullptr;
}

QRectF MyAngle::boundingRect() const
{
	qreal extra = (pen().width() + 20) / 2.0;
	if (end == nullptr)
	{
		return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
			line().p2().y() - line().p1().y()))
			.normalized()
			.adjusted(-extra, -extra, extra, extra);
	}
	else
	{
		int xmin = std::min(start->x(), std::min(mid->x(), end->x()));
		int ymin = std::min(start->y(), std::min(mid->y(), end->y()));
		int xmax = std::max(start->x(), std::max(mid->x(), end->x()));
		int ymax = std::max(start->y(), std::max(mid->y(), end->y()));
		return QRectF(xmin, ymin, xmax-xmin, ymax-ymin)
			.normalized().adjusted(-extra, -extra, extra, extra);
	}
	
}

int MyAngle::calculateAngle()
{
	float ax = mid->x() - start->x();
	float ay = mid->y() - start->y();
	float bx = mid->x() - end->x();
	float by = mid->y() - end->y();
	float alen = sqrt(ax*ax + ay*ay);
	float blen = sqrt(bx*bx + by*by);
	double d = acos((ax * bx + ay * by) / (alen * blen))* 180.0 / 3.14159265;
	return d;
}

void MyAngle::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->drawLine(
		this->line());
	if (end != nullptr)
	{
		painter->drawLine(
			mid->x(), mid->y(),
			end->x(), end->y());
		painter->drawText(mid->pos(), 
			QString("   ").append(QString::number(calculateAngle())));
	}
	
}

void MyAngle::slotUpdate()
{
	this->setLine(QLineF(start->getScreenPos(), mid->getScreenPos()));
	update();
}
