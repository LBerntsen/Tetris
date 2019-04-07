// Local class header file
#include "core/block.h"

// QT header files
#include <stdlib.h>
#include <time.h>

#include <QDebug>

Block::Block(int aTileSize, int aNumCols)
{
	tileSize = aTileSize;
	numCols = aNumCols;
}

Block::~Block()
{
	
}

void
Block::start(GameScene *aScene)
{
	mBlock = aScene->addRect(0, 0, tileSize, tileSize, QPen(), QBrush(QColor(randomColor())));
	mBlock->setX(tileSize * 5);
	mBlock->setY(tileSize);
}

QColor
Block::randomColor()
{
	qsrand(time(NULL));
	
	QColor color;
	int random;
	random = qrand() % 5;

	qDebug() << random;

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
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	if (blockPos.x() == tileSize)
		return 0;

	posX = blockPos.x() - tileSize;
	blockPos.setX(posX);
	mBlock->setPos(blockPos);
}

int
Block::keyRightReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	if (blockPos.x() == tileSize * (numCols - 2))
		return 0;

	posX = blockPos.x() + tileSize;
	blockPos.setX(posX);
	mBlock->setPos(blockPos);
}