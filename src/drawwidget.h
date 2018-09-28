#pragma once
#include <QWidget>
#include <QGraphicsView>
#include "enums.h"
#include "scene.h"

class DrawWidget :
	public QWidget
{
	Q_OBJECT
private:
	FMODE currentMode;
	Scene * graphicsScene;
	QGraphicsView * graphicsView;
protected:
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
public : 
	explicit DrawWidget(QWidget * parent = 0);
	void setBackgroundImage(QImage* image);
public slots:
	void slotSetMode(FMODE mode);
};