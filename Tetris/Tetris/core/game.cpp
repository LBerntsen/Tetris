#include "core/game.h"
#include "core/app.h"

#include <qDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>

Game::Game()
{
	mScene = new QGraphicsScene;
	makeGrid(30, 22, 12);
}


Game::~Game()
{

}

QGraphicsScene *
Game::getScene()
{
	return mScene;
}

void
Game::makeGrid(int aTileSize, int aRows, int aCols)
{
	QColor tileColor;
	tileColor = Qt::black;

	int x = 0;
	int y = 0;
	for (int row = 0; row < aRows; row++)
	{
		for (int col = 0; col < aCols; col++)
		{
			if ((col == 0) || (col == aCols - 1) || (row == 0) || (row == aRows - 1))
				tileColor = Qt::darkGray;
			else {
				tileColor = Qt::black;
			}
			mScene->addRect(x, y, aTileSize, aTileSize, QPen(), QBrush(QColor(tileColor)));
			x = x + aTileSize;
		}
		y = y + aTileSize;
		x = 0;
	}
	mSize.setHeight((aRows + 1) * aTileSize);
	mSize.setWidth((aCols + 1) * aTileSize);
}

QSize
Game::getMapSize() const
{
	return mSize;
}