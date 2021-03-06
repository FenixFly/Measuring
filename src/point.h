#pragma once
#include <QGraphicsItem>
#include <QObject>
#include "enums.h"

class MyPoint :
	public QObject, public QGraphicsItem
{
	Q_OBJECT
private:
	QPointF screenPosition;
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public:
	enum { Type = 100 };
	int type() const override { return Type; }

	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:
	void setScreenPos(QPointF newPosition);
	QPointF getScreenPos() const;
	explicit MyPoint(int x = 0, int y = 0, QObject* parent = 0);
signals:
	void pointMoved();
};