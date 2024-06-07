//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "blockmanager.h"
#include "shape.h"

#include <QTimer>
#include <QColor>

BlockManager::BlockManager(int aTileSize, int aNumCols, int aNumRows, int aTimerInterval, GameScene *aScene, QList<QList<QGraphicsItem *> *> aGridRowList)
{
    mTileSize = aTileSize;
    mNumCols = aNumCols;
    mNumRows = aNumRows;
    mTimerInterval = aTimerInterval;
    mScene = aScene;
    mGridRowList = aGridRowList;

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &BlockManager::moveBlockDown);
}

BlockManager::~BlockManager()
{

}

void
BlockManager::start()
{
    newBlock();
}

void
BlockManager::reset()
{

}

void
BlockManager::newBlock()
{
    //TODO: Clear gamle block
    //delete mBlock;

    //QColor color = randomColor();
    //////////
}



