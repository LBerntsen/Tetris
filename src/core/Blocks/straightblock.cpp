//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "straightblock.h"
#include "core/tile.h"

#include <QColor>
#include <QGraphicsRectItem>

StraightBlock::StraightBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval) : BlockShape(aTileSize, aGridRowList, aScene, aNumRows, aNumCols, aTimerInterval)
{

}

StraightBlock::~StraightBlock()
{

}

void
StraightBlock::createBlock(QColor aColor)
{
    Tile *tile1 = new Tile(0, 0, mTileSize, aColor);
    Tile *tile2 = new Tile(0, 1, mTileSize, aColor);
    Tile *tile3 = new Tile(0, 2, mTileSize, aColor);
    Tile *tile4 = new Tile(0, 3, mTileSize, aColor);

    mTiles.append(tile1);
    mTiles.append(tile2);
    mTiles.append(tile3);
    mTiles.append(tile4);
}

void StraightBlock::setPivotPoint()
{
    mTileGroup->setTransformOriginPoint(QPointF(mTileSize, mTileSize * 2));
}

