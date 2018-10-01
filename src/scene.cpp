#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include "point.h"
#include "line.h"
#include "angle.h"
#include <iostream>

Scene::Scene(QObject * parent) : 
	QGraphicsScene(parent)
{
	itemToDraw = nullptr;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

	switch (currentMode)
	{
	case FMODE::NONE:
		break;
	case FMODE::LINE:
		createLine(event);
		break;
	case FMODE::ANGLE:
		createAngle(event);
		break;
	case FMODE::ELLIPSE:
		break;
	}


	QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
	switch (currentMode)
	{
	case FMODE::NONE:
		break;
	case FMODE::LINE:
		moveLine(event);
		break;
	case FMODE::ANGLE:
		break;
	case FMODE::ELLIPSE:
		break;
	}


	QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
	switch (currentMode)
	{
	case FMODE::NONE:
		break;
	case FMODE::LINE:
		itemToDraw = nullptr;
		break;
	case FMODE::ANGLE:
		releaseAngle(event);
		break;
	case FMODE::ELLIPSE:
		break;
	}
	QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::createLine(QGraphicsSceneMouseEvent * event)
{
	MyPoint* point = new MyPoint(event->scenePos().x(), event->scenePos().y());
	this->addItem(point);
	MyPoint* point2 = new MyPoint(event->scenePos().x(), event->scenePos().y());
	this->addItem(point2);
	MyLine * line = new MyLine(point, point2);
	this->addItem(line);
	itemToDraw = point2;
}

void Scene::moveLine(QGraphicsSceneMouseEvent * event)
{
	if (itemToDraw == nullptr)
		createLine(event);
	MyPoint * poin = static_cast<MyPoint*>(itemToDraw);
	poin->setScreenPos(event->scenePos());
	poin->mouseMoveEvent(event);
}

void Scene::createAngle(QGraphicsSceneMouseEvent * event)
{
	if (itemToDraw == nullptr)
	{
		MyPoint* point = new MyPoint(event->scenePos().x(), event->scenePos().y());
		this->addItem(point);
		MyPoint* point2 = new MyPoint(event->scenePos().x(), event->scenePos().y());
		this->addItem(point2);
		MyAngle * angle = new MyAngle(point, point2);
		this->addItem(angle);
		itemToDraw = angle;
	}
	else
	{
		MyPoint * point3 = new MyPoint(event->scenePos().x(), event->scenePos().y());
		this->addItem(point3);
		MyAngle* angle = dynamic_cast<MyAngle*>(itemToDraw);
		angle->setEndPoint(point3);
		connect(point3, SIGNAL(pointMoved()), angle, SLOT(slotUpdate()));
		itemToDraw = point3;

	}

}

void Scene::releaseAngle(QGraphicsSceneMouseEvent * event)
{	
	if (itemToDraw != nullptr)
	{
		if (itemToDraw->type() == 100)
			itemToDraw = nullptr;
	}
}
