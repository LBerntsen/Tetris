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

bool
Game::checkRows()
{
	bool obscured = true;
	int obscuredNumber = 0;

	for (int i = getNumRows() - 2; i > 1; i--)
	{
		obscuredNumber = 0;
		for (int c = 1; c < getNumCols() - 1; c++)
		{
			obscured = mRowList.at(i)->at(c)->isObscured();
			obscuredNumber++;
			if (obscured == false)
				obscuredNumber = 0;
			else
				qDebug() << "Obscured   " << "Row: " << i << "Col: " << c;
		}
		if (obscuredNumber == getNumCols() - 2)
		{
			qDebug() << "Remove row: " << i;
			return true; //Remove row
		}
	}
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
	checkRows();
	return 0;
}