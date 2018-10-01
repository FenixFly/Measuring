#pragma once
#include "point.h"

class MyEllipse :
	public QObject, public QGraphicsItem
{
	Q_OBJECT
private:
	QRectF boundingRect() const;
	MyPoint * start;
	MyPoint * end;
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:
	MyEllipse(MyPoint* _start, MyPoint * _end);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	public slots:
	void slotUpdate();
};