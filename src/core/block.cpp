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
	newBlock();
}

void
Block::resetGame()
{

}

void
Block::newBlock()
{
	mBlock = mScene->addRect(0, 0, mTileSize, mTileSize, QPen(), QBrush(QColor(randomColor())));
	mBlock->setX(mTileSize * (mNumCols / 2));
	mBlock->setY(mTileSize);
	mBlock->setZValue(1);

	mTimer->start(mTimerInterval);
}

QColor
Block::randomColor()
{
	srand(time(NULL));
	
	QColor color;
	int random;
	random = rand() % 5 + 1;

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

	//COMBINE IFS

	if (mGridRowList.at(getYListIndex() + 1)->at(getXListIndex())->isObscured())
	{
		mTimer->stop();

		///TEMP PREP FOR SHAPES
		QList<int> xList;
		QList<int> yList;
		QList<QGraphicsItem *> tileList;

		xList.append(getXListIndex());
		yList.append(getYListIndex());
		tileList.append(mBlock);
		///

		emit sigPlaceTiles(xList, yList, tileList);

		return 0;
	}
	else if (y == (mNumRows - 2) * mTileSize)
	{
		mTimer->stop();

		///TEMP PREP FOR SHAPES
		QList<int> xList;
		QList<int> yList;
		QList<QGraphicsItem *> tileList;

		xList.append(getXListIndex());
		yList.append(getYListIndex());
		tileList.append(mBlock);
		///

		emit sigPlaceTiles(xList, yList, tileList);

		return 0;
	}

	mBlock->setY(y + mTileSize);
}