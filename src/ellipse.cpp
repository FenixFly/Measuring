#include "ellipse.h"
#include <QPainter>

QRectF MyEllipse::boundingRect() const
{
	qreal extra = 5.0f;

	return QRectF(start->pos(), QSizeF(end->pos().x() - start->pos().x(),
		end->pos().y() - start->pos().y()))
		.normalized()
		.adjusted(-extra, -extra, extra, extra);
}

void MyEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{

}

MyEllipse::MyEllipse(MyPoint * _start, MyPoint * _end):
	start(_start), end(_end)
{
	setFlag(ItemIsFocusable);
	setFlag(ItemIsSelectable);
	setFlag(ItemSendsGeometryChanges);
	setFlag(ItemSendsScenePositionChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-300);
	
	QObject::connect(this->start, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));
	QObject::connect(this->end, SIGNAL(pointMoved()), this, SLOT(slotUpdate()));
}

void MyEllipse::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (hasFocus())
		painter->setPen(QPen(QColor(255, 0, 0)));
	else
		painter->setPen(QPen(QColor(0, 0, 0)));
	painter->drawEllipse(QRectF(start->pos(), end->pos()));
	float square = abs((end->pos().x() - start->pos().x()))
		* 3.14159265f / 4.f;
	painter->drawText(
		QPointF(
			start->pos().x() + (end->pos().x() - start->pos().x())*0.18f,
			start->pos().y() + (end->pos().y() - start->pos().y())*0.18f),
		QString::number(square, 'G', 5));
}

void  MyEllipse::slotUpdate()
{
	update();
}