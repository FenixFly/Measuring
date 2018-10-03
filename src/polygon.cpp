#include "polygon.h"
#include <QPainter>

void MyPolygon::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{

}

QPainterPath MyPolygon::shape() const
{
	QPainterPath path;
	if (!points.empty())
	{
		path.moveTo(points[0]);
		for (int i = 1; i < points.size(); i++)
			path.lineTo(points[i]);
		path.lineTo(points[0]);
	}
	return path;
}

QRectF MyPolygon::boundingRect() const
{
	qreal extra = 5.0f;
	if (!points.empty())
	{
		float xmin = points[0].x();
		float ymin = points[0].y();
		float xmax = points[0].x();
		float ymax = points[0].y();
		for (int i = 0; i < points.size(); i++)
		{
			xmin = (points[i].x() < xmin) ? points[i].x() : xmin;
			ymin = (points[i].y() < ymin) ? points[i].y() : ymin;
			xmax = (points[i].x() > xmax) ? points[i].x() : xmax;
			ymax = (points[i].y() > ymax) ? points[i].y() : ymax;
		}

		return QRectF(xmin, ymin, xmax - xmin, ymax - ymin)
			.normalized()
			.adjusted(-extra, -extra, extra, extra);
	}
	return QRectF(0, 0, 10, 10);
}

MyPolygon::MyPolygon()
{
	setFlag(ItemIsFocusable);
	setFlag(ItemIsSelectable);
	setFlag(ItemSendsGeometryChanges);
	setFlag(ItemSendsScenePositionChanges);
	setCacheMode(DeviceCoordinateCache);
	setZValue(-300);
}

void MyPolygon::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	if (!points.empty())
	{
		if (hasFocus())
			painter->setPen(QPen(QColor(255, 0, 0)));
		else
			painter->setPen(QPen(QColor(0, 0, 0)));
		QPainterPath path;
		path.moveTo(points[0]);
		for (int i = 1; i < points.size(); i++)
			path.lineTo(points[i]);
		path.lineTo(points[0]);
		painter->drawPath(path);
	}
}

void MyPolygon::slotUpdate()
{
	update();
}