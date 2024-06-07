// Local class header file
#include "core/block1.h"
#include "core/tile.h"

// QT header files
#include <stdlib.h>
#include <time.h>

#include <QDebug>

////
#include "core/Blocks/square.h"
#include "core/Blocks/block.h"
///

Block1::Block1(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList)
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

Block1::~Block1()
{
	
}

void
Block1::start()
{
	newBlock();

	//T/ESst
	Square *t = new Square(mTileSize, mGridRowList, mNumRows, mNumCols);
	t->startBlock(mScene, 0, mTileSize * (mNumCols / 2) + mTileSize*2, mTileSize*5);
	mBlock = t;
	////
}

void
Block1::resetGame()
{

}

void
Block1::newBlock()
{
	mTiles.clear();

	QColor color = randomColor();
	Tile *tile = new Tile(mTileSize * (mNumCols / 2), mTileSize, 0, 0, mTileSize, color);
	mTiles.append(tile);
	mScene->addItem(tile->getTile());

	mTimer->start(mTimerInterval);
}

QColor
Block1::randomColor()
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
Block1::keyLeftReciever()
{
	mBlock->keyLeftReciever();
}

int
Block1::keyRightReciever()
{
	mBlock->keyRightReciever();
}

void
Block1::keyDownReciever()
{
	mBlock->keyDownReciever();
}