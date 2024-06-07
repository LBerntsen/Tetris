//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "core/blockshape.h"
#include "core/tile.h"
#include "core/gameScene.h"

#include <QColor>
#include <QTimer>
#include <QGraphicsItemGroup>

BlockShape::BlockShape(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval)
{
    mTileSize = aTileSize;
    mNumRows = aNumRows;
    mNumCols = aNumCols;
    mGridRowList = aGridRowList;
    mScene = aScene;
    mTimerInterval = aTimerInterval;

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &BlockShape::keyDownReciever);
}

BlockShape::~BlockShape()
{

}

void
BlockShape::startBlock()
{
    QColor color = randomColor();
    createBlock(color);
    createGroup();
    setPivotPoint();
    mTimer->start(mTimerInterval);
}

void
BlockShape::keyLeftReciever()
{
    for (int i = 0; i < mTiles.size(); i++)
    {
        Tile *tile = mTiles[i];
        QGraphicsItem *tileToCheck = mGridRowList.at(tile->getYListIndex())->at(tile->getXListIndex() - 1);
        int x = tile->getTile()->scenePos().x();
        if (tileToCheck->isObscured())
        {
            bool isBlocked = true;
            for (int c = 0; c < mTiles.size(); c++)
            {
                if (tileToCheck->isObscuredBy(mTiles[c]->getTile()))
                    isBlocked = false;
            }
            if (isBlocked)
            {
                return;
            }
        }
        else if (x - mTileSize == 0)
        {
            return;
        }
    }
    mTileGroup->setX(mTileGroup->x() - mTileSize);
}

void
BlockShape::keyRightReciever()
{
    for(int i = 0; i < mTiles.size(); i++)
    {
        Tile *tile = mTiles[i];
        QGraphicsItem *tileToCheck = mGridRowList.at(tile->getYListIndex())->at(tile->getXListIndex() + 1);
        int x = tile->getTile()->scenePos().x();
        if(tileToCheck->isObscured())
        {
            bool isBlocked = true;
            for(int c = 0; c < mTiles.size(); c++)
            {
                if(tileToCheck->isObscuredBy(mTiles[c]->getTile()))
                    isBlocked = false;
            }
            if(isBlocked)
            {
                return;
            }
        }
        else if(x + mTileSize == (mNumCols - 1) * mTileSize)
        {
            return;
        }
    }
    mTileGroup->setX(mTileGroup->x() + mTileSize);
}

void
BlockShape::keyDownReciever()
{
    for(int i = 0; i < mTiles.size(); i++)
    {
        Tile *tile = mTiles[i];
        QGraphicsItem *tileToCheck = mGridRowList.at(tile->getYListIndex() + 1)->at(tile->getXListIndex());
        int y = tile->getTile()->scenePos().y();
        if(tileToCheck->isObscured())
        {
            bool isBlocked = true;
            for(int c = 0; c < mTiles.size(); c++)
            {
                if (tileToCheck->isObscuredBy(mTiles[c]->getTile()))
                    isBlocked = false;
            }
            if(isBlocked)
            {
                placeTiles();
                return;
            }
        }
        else if(y + mTileSize == (mNumRows - 1) * mTileSize)
        {
            placeTiles();
            return;
        }
    }
    mTileGroup->setY(mTileGroup->y() + mTileSize);
}

void
BlockShape::rotateCCW()
{
    mTileGroup->setRotation(mTileGroup->rotation() - 90);
    for (int i = 0; i < mTiles.size(); i++)
    {
        mTiles[i]->rotateCW();
    }
}

void
BlockShape::rotateCW()
{
    mTileGroup->setRotation(mTileGroup->rotation() + 90);
    for(int i = 0; i < mTiles.size(); i++)
    {
        mTiles[i]->rotateCCW();
    }
}

void
BlockShape::createGroup()
{
    mTileGroup = new QGraphicsItemGroup;

    for (int i = 0; i < mTiles.size(); i++)
        mTileGroup->addToGroup(mTiles[i]->getTile());

    mTileGroup->setX(mTileSize * (mNumCols / 2));
    mTileGroup->setY(mTileSize);

    mScene->addItem(mTileGroup);
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
        mTileGroup->removeFromGroup(mTiles[i]->getTile());
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
