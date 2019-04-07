#include "core/game.h"
#include "core/app.h"
#include "core/block.h"
#include "core/gameScene.h"

#include <qDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPointF>

Game::Game()
{
	mScene = new GameScene;
	mBlock = new Block(getTileSize(), getNumCols());
	makeGrid(getTileSize(), getNumRows(), getNumCols());

	connect(mScene, SIGNAL(sigKeyLeftPressed()), mBlock, SLOT(keyLeftReciever()));
	connect(mScene, SIGNAL(sigKeyRightPressed()), mBlock, SLOT(keyRightReciever()));
}


Game::~Game()
{

}

GameScene *
Game::getScene()
{
	return mScene;
}

void
Game::makeGrid(int aTileSize, int aRows, int aCols)
{
	QColor tileColor;
	tileColor = Qt::white;

	int x = 0;
	int y = 0;
	for (int row = 0; row < aRows; row++)
	{
		for (int col = 0; col < aCols; col++)
		{
			if ((col == 0) || (col == aCols - 1) || (row == 0) || (row == aRows - 1))
				tileColor = Qt::darkGray;
			else {
				tileColor = Qt::white;
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

void
Game::gameStart()
{
	mBlock->start(mScene);
}

QSize
Game::getMapSize() const
{
	return mSize;
}

int
Game::getTileSize() const
{
	return 30;
}

int
Game::getNumRows() const
{
	return 22;
}

int
Game::getNumCols() const
{
	return 12;
}