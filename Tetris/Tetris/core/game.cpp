#include "core/game.h"
#include "core/app.h"
#include "core/block.h"
#include "core/gameScene.h"

#include <qDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPointF>
#include <QList>

Game::Game()
{
	mScene = new GameScene;
	mBlock = new Block(getTileSize(), getNumCols(), mScene);
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
		QList<QGraphicsRectItem *> *colList = new QList<QGraphicsRectItem *>;
		for (int col = 0; col < aCols; col++)
		{
			if ((col == 0) || (col == aCols - 1) || (row == 0) || (row == aRows - 1))
				tileColor = Qt::darkGray;
			else {
				tileColor = Qt::white;
			}
			QGraphicsRectItem *mCol = new QGraphicsRectItem;
			mCol = mScene->addRect(x, y, aTileSize, aTileSize, QPen(), QBrush(QColor(tileColor)));
			colList->append(mCol);
			x = x + aTileSize;
		}
		mRowList.append(colList);
		y = y + aTileSize;
		x = 0;
	}
	mSize.setHeight((aRows + 1) * aTileSize);
	mSize.setWidth((aCols + 1) * aTileSize);
}

void
Game::gameStart()
{
	mBlock->start();
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