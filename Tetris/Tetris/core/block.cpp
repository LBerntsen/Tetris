// Local class header file
#include "core/block.h"

// QT header files
#include <stdlib.h>
#include <time.h>

#include <QDebug>

Block::Block(int aTileSize, int aNumCols, int aNumRows, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList)
{
	mTileSize = aTileSize;
	mNumCols = aNumCols;
	mNumRows = aNumRows;
	mScene = aScene;
	mGridRowList = aGridRowList;

}

Block::~Block()
{
	
}

void
Block::start()
{
//mBlock = mScene->addRect(0, 0, mTileSize, mTileSize, QPen(), QBrush(QColor(randomColor())));
//mBlock->setX(mTileSize * 5);
//mBlock->setY(mTileSize);
//mBlock->setZValue(1);

	
	for (int i = 1; i < 11; i++)
	{
		for (int c = 1; c < 21; c = c++)
		{
			mScene->addRect(mTileSize * i, mTileSize * c, mTileSize, mTileSize, QPen(), QBrush(randomColor()));
		}
	}

}

void
Block::removeRow(int aRow)
{
	qDebug() << "Removed row " << aRow;
}

void
Block::checkRows()
{
	bool obscured = true;
	int obscuredNumber = 0;
	int rowNumber = 0;

	for (int i = mNumRows - 2; i > 1; i--)
	{
		obscuredNumber = 0;
		rowNumber = i;
		for (int c = 1; c < mNumCols - 1; c++)
		{
			obscured = mGridRowList.at(i)->at(c)->isObscured();
			obscuredNumber++;
			if (obscured == false)
				obscuredNumber = 0;
			else
				qDebug() << "Obscured   " << "Row: " << i << "Col: " << c;
		}
		if (obscuredNumber == mNumCols - 2)
		{
			qDebug() << "Remove row: " << i;
			removeRow(rowNumber);
		}
	}
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
Block::keyLeftReciever()
{
	QPointF blockPos = mBlock->pos();
	int posX = 0;

	if (blockPos.x() == mTileSize)
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

	posX = blockPos.x() + mTileSize;
	blockPos.setX(posX);
	mBlock->setPos(blockPos);
	return 0;
}
