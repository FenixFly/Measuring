#pragma once
#include <QGraphicsLineItem>
#include "point.h"

class MyLine :
	public QObject, public QGraphicsLineItem
{
	Q_OBJECT
private:
	QRectF boundingRect() const;
	MyPoint * start;
	MyPoint * end;
protected:
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:
	MyLine(MyPoint* _start, MyPoint * _end);
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:	
	void slotUpdate();
};