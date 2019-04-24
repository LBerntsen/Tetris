// Local class header file
#include "core/block.h"

// QT header files
#include <stdlib.h>
#include <time.h>

#include <QDebug>

Block::Block(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList)
{
	mTileSize = aTileSize;
	mNumCols = aNumCols;
	mNumRows = aNumRows;
	mTimerInterval = aTimerInterval;
	mScene = aScene;
	mGridRowList = aGridRowList;

	mTimer = new QTimer(this);
	connect(mTimer, SIGNAL(timeout()), this, SLOT(moveBlockDown()));
}

Block::~Block()
{
	
}

void
Block::start()
{
	makeBlockRowList(mNumRows, mNumCols);
	newBlock();
}

void
Block::manageRows()
{
	int row = 0;
	int rowRemoved = 0;
	bool removedARow = false;

	for (int i = mNumRows - 2; i > 1; i--)
	{
		row = checkRow(i);
	
		if (row != 0 && row != mNumRows)
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
	else if(!removedARow)
		newBlock();
}

int
Block::checkRow(int aRow)
{
	bool obscured = false;
	int obscuredTile = 0;
	
	for (int i = 1; i < mNumCols - 1; i++)
	{
		QGraphicsItem *item;
		item = mGridRowList.at(aRow)->at(i);
		if(item && item->isObscured())
			obscuredTile++;
	}

	if (obscuredTile == mNumCols - 2)
		return aRow;
	else if (obscuredTile != mNumCols - 2)
		return 0;
}

int
Block::removeRow(int aRow)
{
	qDebug() << "Removed row " << aRow;
	
	for (int i = 0; i < mBlockRowList.at(aRow)->size(); i++)
	{
		mBlock = mBlockRowList.at(aRow)->at(i);
		mScene->removeItem(mBlock);
		mBlockRowList.at(aRow)->replace(i, NULL);
	}

	return aRow;
}

void
Block::moveRowDown(int aRemoved)
{
	for (int rowIndex = aRemoved; rowIndex > 1; rowIndex--)
	{
		QList<QGraphicsItem *>* deleteRowPointer = mBlockRowList.at(rowIndex);

		for (int i = 1; i < mNumCols - 1; i++)
		{
			QGraphicsItem* item = mBlockRowList.at(rowIndex - 1)->at(i);
			if(item != NULL)
			{
				item->setY(item->y() + mTileSize);
			}
		}

		mBlockRowList.replace(rowIndex, mBlockRowList.at(rowIndex - 1));
		qDeleteAll(*deleteRowPointer);
		delete deleteRowPointer;
	}

}

void
Block::makeBlockRowList(int aNumRows, int aNumCols)
{

	for (int row = 0; row < aNumRows; row++)
	{
		QList<QGraphicsItem*>* colList = new QList<QGraphicsItem*>;
		for (int col = 0; col < aNumCols; col++)
		{
			if (col != 0 || col != aNumCols - 1)
			{
				colList->append(NULL);
			} 
		}
		mBlockRowList.append(colList);
	}
}

void
Block::newBlock()
{
	mBlock = mScene->addRect(0, 0, mTileSize, mTileSize, QPen(), QBrush(QColor(randomColor())));
	mBlock->setX(mTileSize * 5);
	mBlock->setY(mTileSize);
	mBlock->setZValue(1);

	mTimer->start(mTimerInterval);
}

QColor
Block::randomColor()
{
	qsrand(time(NULL));
	
	QColor color;
	int random;
	random = qrand() % 5 + 1;

	switch (random)
	{
	case 1:
		color = QColor(Qt::magenta);
		break;
	case 2:
		color = QColor(Qt::red);
		break;
	case 3:
		color = QColor(Qt::green);
		break;
	case 4:
		color = QColor(Qt::blue);
		break;
	case 5:
		color = QColor(Qt::yellow);
		break;
	}

	return color;
}

int
Block::getYListIndex()
{
	int y = mBlock->y();
	y = y / mTileSize;

	return y;
}

int
Block::getXListIndex()
{
	int x = mBlock->x();
	x = x / mTileSize;
	
	return x;
}

int
Block::keyLeftReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	if (blockPos.x() == mTileSize)
		return 0;
	
	if (mGridRowList.at(getYListIndex())->at(getXListIndex() - 1)->isObscured())
		return 0;

	posX = blockPos.x() - mTileSize;
	blockPos.setX(posX);
	mBlock->setPos(blockPos);
	return 0;
}

int
Block::keyRightReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	if (blockPos.x() == mTileSize * (mNumCols - 2))
		return 0;
	
	if (mGridRowList.at(getYListIndex())->at(getXListIndex() + 1)->isObscured())
		return 0;

	posX = blockPos.x() + mTileSize;
	blockPos.setX(posX);
	mBlock->setPos(blockPos);
	return 0;
}

void
Block::keyDownReciever()
{
	moveBlockDown();
}

int
Block::moveBlockDown()
{
	int y = mBlock->y();

	if (mGridRowList.at(getYListIndex() + 1)->at(getXListIndex())->isObscured())
	{
		mTimer->stop();

		mBlockRowList.at(getYListIndex())->replace(getXListIndex(), mBlock);
		manageRows();
		return 0;
	}
	else if (y == (mNumRows - 2) * mTileSize)
	{
		mTimer->stop();

		mBlockRowList.at(getYListIndex())->replace(getXListIndex(), mBlock);
		manageRows();
		return 0;
	}

	mBlock->setY(y + mTileSize);
}