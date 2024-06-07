//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "core/blockshape.h"
#include "core/tile.h"

#include <QColor>
#include <QTimer>
#include <QGraphicsItemGroup>

BlockShape::BlockShape(int aTileSize, int aHeight, int aWidth, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols)
{
    mTileSize = aTileSize;
    mHeight = aHeight;
    mWidth = aWidth;
    mNumRows = aNumRows;
    mNumCols = aNumCols;
    mGridRowList = aGridRowList;
    mTimer = new QTimer(this);
    //connect(mTimer, &QTimer::timeout, this, &BlockShape::moveBlockDown);
}

BlockShape::~BlockShape()
{

}

void
BlockShape::startBlock(GameScene *aScene, int aTimerInterval, int aX, int aY)
{
    QColor color = randomColor();
    createBlock(aScene, color, aX, aY);
    //mTimer->start(aTimerInterval);
}

int
BlockShape::keyLeftReciever()
{
    QPointF tilePos = mTileGroup->pos();
    int posX = 0;

    if (tilePos.x() == mTileSize)
        return 0;

    for (int i = 0; i < mTiles.size(); i++)
    {
        if(mGridRowList.at(getYListIndex())->at(getXListIndex() - 1)->isObscuredBy(mTileGroup))
            return 0;
    }

    posX = tilePos.x() - mTileSize;
    tilePos.setX(posX);
    mTileGroup->setPos(tilePos);
    return 0;
}

int
BlockShape::keyRightReciever()
{
    QPointF tilePos = mTileGroup->pos();
    int posX = 0;

    if (tilePos.x() + (mWidth - 1) * mTileSize == mTileSize * (mNumCols - 2))
        return 0;

    if (mGridRowList.at(getYListIndex())->at(getXListIndex() + 1)->isObscuredBy(mTileGroup))
        return 0;

    posX = tilePos.x() + mTileSize;
    tilePos.setX(posX);
    mTileGroup->setPos(tilePos);
    return 0;
}

void
BlockShape::keyDownReciever()
{
    int y = mTileGroup->y();

    //COMBINE IFS

    if (mGridRowList.at(getYListIndex() + mHeight)->at(getXListIndex())->isObscuredBy(mTileGroup))
    {
        placeTiles();
        return;
    }
    else if (y + (mHeight - 1) * mTileSize == (mNumRows - 2) * mTileSize)
    {
        placeTiles();
        return;
    }

    mTileGroup->setY(y + mTileSize);
}

void
BlockShape::placeTiles()
{
    mTimer->stop();

    QList<int> xList;
    QList<int> yList;
    QList<QGraphicsItem *> tileList;

    for(int i = 0; i < mTiles.size(); i++)
    {
        xList.append(mTiles[i]->getXListIndex());
        yList.append(mTiles[i]->getYListIndex());
        tileList.append(mTiles[i]->getTile());
    }

    emit sigPlaceTiles(xList, yList, tileList);
}

QColor
BlockShape::randomColor()
{
    srand(time(NULL));
    QColor color;

    switch(rand() % 5 + 1)
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
        default:
            color = QColor(Qt::black);
            break;
    }

    return color;
}

int
BlockShape::getXListIndex() const
{
    return mTileGroup->x() / mTileSize;
}

int
BlockShape::getYListIndex() const
{
    return mTileGroup->y() / mTileSize;
}
