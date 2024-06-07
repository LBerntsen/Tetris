// Local class header file
#include "core/block.h"
#include "core/tile.h"

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
	mTiles.clear();

	QColor color = randomColor();
	Tile *tile = new Tile(mTileSize * (mNumCols / 2), mTileSize, 0, 0, mTileSize, color);
	mTiles.append(tile);
	mScene->addItem(tile->getTile());

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
Block::keyLeftReciever()
{
	QPointF blockPos = mTiles[0]->getTile()->pos();
	int posX = 0;

	if (blockPos.x() == mTileSize)
		return 0;

	if (mGridRowList.at(mTiles[0]->getYListIndex())->at(mTiles[0]->getXListIndex() - 1)->isObscured())
		return 0;

	posX = blockPos.x() - mTileSize;
	blockPos.setX(posX);
	mTiles[0]->getTile()->setPos(blockPos);
	return 0;
}

int
Block::keyRightReciever()
{
	QPointF blockPos = mTiles[0]->getTile()->pos();
	int posX = 0;

	if (blockPos.x() == mTileSize * (mNumCols - 2))
		return 0;
	
	if (mGridRowList.at(mTiles[0]->getYListIndex())->at(mTiles[0]->getXListIndex() + 1)->isObscured())
		return 0;

	posX = blockPos.x() + mTileSize;
	blockPos.setX(posX);
	mTiles[0]->getTile()->setPos(blockPos);
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
	int y = mTiles[0]->getTile()->y();

	//COMBINE IFS

	if (mGridRowList.at(mTiles[0]->getYListIndex() + 1)->at(mTiles[0]->getXListIndex())->isObscured())
	{
		mTimer->stop();

		///TEMP PREP FOR SHAPES
		QList<int> xList;
		QList<int> yList;
		QList<QGraphicsItem *> tileList;

		xList.append(mTiles[0]->getXListIndex());
		yList.append(mTiles[0]->getYListIndex());
		tileList.append(mTiles[0]->getTile());
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

		xList.append(mTiles[0]->getXListIndex());
		yList.append(mTiles[0]->getYListIndex());
		tileList.append(mTiles[0]->getTile());
		///

		emit sigPlaceTiles(xList, yList, tileList);

		return 0;
	}

	mTiles[0]->getTile()->setY(y + mTileSize);
}