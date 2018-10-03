#pragma once
#include "point.h"

class MyPolygon :
	public QObject, public QGraphicsItem
{
	Q_OBJECT
private:
	QPainterPath shape() const;
	QRectF boundingRect() const;
	QList<QPointF> points;
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:
	void addPoint(QPointF point) { points.push_back(point); }
	QPointF getLastPos() { return points[points.size() - 1]; }
	MyPolygon();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	public slots:
	void slotUpdate();
};