#pragma once
#include <QGraphicsScene>
#include "enums.h"

class Scene :
	public QGraphicsScene
{
	FMODE currentMode;
	QGraphicsItem* itemToDraw;
public:
	explicit Scene(QObject* parent = 0);
	void setMode(FMODE mode) { currentMode = mode; }
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	void createLine(QGraphicsSceneMouseEvent *event);
	void moveLine(QGraphicsSceneMouseEvent *event);
};