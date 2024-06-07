#include "core/game.h"
#include "core/app.h"
#include "core/blockshape.h"
#include "core/gameScene.h"

#include <qDebug>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QList>

///
#include "core/Blocks/square.h"
/// ////
Game::Game()
{
	mScene = new GameScene;
	mTimerInterval = 1000;
	makeGrid(getTileSize(), getNumRows(), getNumCols());

	connect(mScene, &GameScene::sigKeyLeftPressed, this, &Game::keyLeftReciever);
	connect(mScene, &GameScene::sigKeyRightPressed, this, &Game::keyRightReciever);
	connect(mScene, &GameScene::sigKeyDownPressed, this, &Game::keyDownReciever);
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
			mTile = mScene->addRect(0, 0, aTileSize, aTileSize, QPen(), QBrush(QColor(tileColor)));
			mTile->setX(x);
			mTile->setY(y);
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
	makeBlockRowList(getNumRows(), getNumCols());
	newBlock();
}

void
Game::restart()
{
	//Reset
	//Start
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
	return 16;
}

int
Game::getNumCols() const
{
	return 12;
}

int
Game::keyLeftReciever()
{
	mBlock->keyLeftReciever();
}

int
Game::keyRightReciever()
{
	mBlock->keyRightReciever();
}

void
Game::keyDownReciever()
{
	mBlock->keyDownReciever();
}

void
Game::placeTilesReciever(QList<int> aXListIndexes, QList<int> aYListIndexes, QList<QGraphicsItem *> aBlockTiles)
{
	for (int i = 0; i < aXListIndexes.size(); i++)
	{
		placeTile(aXListIndexes[i], aYListIndexes[i], aBlockTiles[i]);

		if (aBlockTiles[i]->y() / getTileSize() == 1)
		{
			emit sigGameOver();
			return;
		}
	}

	manageRows();
}


void
Game::makeBlockRowList(int aNumRows, int aNumCols)
{
	for(int row = 0; row < aNumRows; row++)
	{
		QList<QGraphicsItem *> *colList = new QList<QGraphicsItem *>;
		for(int col = 0; col < aNumCols; col++)
		{
			if(col != 0 || col != aNumCols - 1)
			{
				colList->append(NULL);
			}
		}
		mBlockRowList.append(colList);
	}
}

void
Game::placeTile(int aXListIndex, int aYListIndex, QGraphicsItem *aBlockTile)
{
	QList<QGraphicsItem *> *list = mBlockRowList.at(aYListIndex);
	list->replace(aXListIndex, aBlockTile);
}

void
Game::manageRows()
{
	int row = 0;
	int rowRemoved = 0;
	bool removedARow = false;

	for (int i = getNumRows() - 2; i > 1; i--)
	{
		row = checkRow(i);

		if (row != 0 && row != getNumRows())
		{
			rowRemoved = removeRow(row);
			moveRowDown(rowRemoved);
			removedARow = true;
			break;
		}
	}

	if (removedARow)
	{
		removedARow = false;
		manageRows();
	}
	else
		newBlock();
}

int
Game::checkRow(int aRow)
{
	int obscuredTile = 0;

	for (int i = 1; i < getNumCols() - 1; i++)
	{
		QGraphicsItem *item = mGridRowList.at(aRow)->at(i);
		if(item && item->isObscured())
			obscuredTile++;
	}

	if (obscuredTile == getNumCols() - 2)
		return aRow;
	else if (obscuredTile != getNumCols() - 2)
		return 0;
}

int
Game::removeRow(int aRow)
{
	qDebug() << "Removed row " << aRow;

	QList<QGraphicsItem *> *deleteRowPointer = mBlockRowList.at(aRow);
	qDeleteAll(*deleteRowPointer);

	return aRow;
}

void
Game::moveRowDown(int aRemoved)
{
	for (int rowIndex = aRemoved; rowIndex > 1; rowIndex--)
	{
		for (int i = 1; i < getNumCols() - 1; i++)
		{
			QGraphicsItem* item = mBlockRowList.at(rowIndex - 1)->at(i);
			if(item != NULL)
			{
				item->setY(item->y() + getTileSize());
			}
		}
		mBlockRowList.replace(rowIndex, mBlockRowList.at(rowIndex - 1));
	}
}

void
Game::newBlock()
{
	Square *t = new Square(getTileSize(), mGridRowList, getNumRows(), getNumCols());
	t->startBlock(mScene, 0, getTileSize() * (getNumCols() / 2), getTileSize());
	mBlock = t;
	connect(t, &BlockShape::sigPlaceTiles, this, &Game::placeTilesReciever);
}
