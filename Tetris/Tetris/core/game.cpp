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
	makeGrid(getTileSize(), 22, 12);

	connect(mScene, SIGNAL(sigKeyLeftPressed()), this, SLOT(keyLeftReciever()));
	connect(mScene, SIGNAL(sigKeyRightPressed()), this, SLOT(keyRightReciever()));
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
	mBlock = mScene->addRect(60, 30, 30, 30, QPen(), QBrush(QColor(Qt::blue)));
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

void
Game::keyLeftReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	posX = blockPos.x() - getTileSize();
	blockPos.setX(posX);
	qDebug() << "Left";
	mBlock->setPos(blockPos);
}

void
Game::keyRightReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	posX = blockPos.x() + getTileSize();
	blockPos.setX(posX);
	qDebug() << "Right";
	mBlock->setPos(blockPos);
}