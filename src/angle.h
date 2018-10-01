#pragma once
#include <QGraphicsLineItem>
#include "point.h"

class MyAngle :
	public QObject, public QGraphicsLineItem
{
	Q_OBJECT
private:
	QRectF boundingRect() const;
	MyPoint * start;
	MyPoint * mid;
	MyPoint * end;
	int calculateAngle();
public:
	MyAngle(MyPoint* _start, MyPoint * _mid);
	void setEndPoint(MyPoint * _end) {	end = _end; }
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:
	void slotUpdate();
};