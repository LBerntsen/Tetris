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
	mMoveDownSeconds = 1000;
	makeGrid(getTileSize(), getNumRows(), getNumCols());
	mBlock = new Block(getTileSize(), getNumCols(), getNumRows(), mScene, mGridRowList);

	connect(mScene, SIGNAL(sigKeyLeftPressed()), mBlock, SLOT(keyLeftReciever()));
	connect(mScene, SIGNAL(sigKeyRightPressed()), mBlock, SLOT(keyRightReciever()));
	connect(mScene, SIGNAL(sigKeyTestPressed()), this, SLOT(keyTestReciever()));
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
		QList<QGraphicsItem *> *colList = new QList<QGraphicsItem *>;
		for (int col = 0; col < aCols; col++)
		{
			if ((col == 0) || (col == aCols - 1) || (row == 0) || (row == aRows - 1))
				tileColor = Qt::darkGray;
			else {
				tileColor = Qt::white;
			}
			QGraphicsRectItem *mTile = new QGraphicsRectItem;
			mTile = mScene->addRect(x, y, aTileSize, aTileSize, QPen(), QBrush(QColor(tileColor)));
			mTile->setZValue(-1);
			if (col != 0 || col != aCols - 1)
			{
				colList->append(mTile);
			}
			x = x + aTileSize;
		}
		mGridRowList.append(colList);
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
	mBlock->startMoveDownTimer(mMoveDownSeconds);
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

int
Game::keyTestReciever()
{
	qDebug() << "Test button pressed!";
	mBlock->checkRows();
	return 0;
}