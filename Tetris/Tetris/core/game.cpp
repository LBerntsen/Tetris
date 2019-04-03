#include "core/game.h"
#include "core/app.h"

#include <qDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

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
	int x = 0;
	int y = 0;
	for (int row = 0; row < aRows; row++)
	{
		for (int col = 0; col < aCols; col++)
		{
			mScene->addRect(x, y, aTileSize, aTileSize);
			x = x + aTileSize;
		}
		y = y + aTileSize;
		x = 0;
	}
	mSize.setHeight(aRows * aTileSize);
	mSize.setWidth(aCols * aTileSize);
}

QSize
Game::getMapSize() const
{
	return mSize;
}