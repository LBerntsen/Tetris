//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "jblock.h"
#include "core/tile.h"

#include <QColor>
#include <QGraphicsRectItem>

JBlock::JBlock(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval) : BlockShape(aTileSize, aGridRowList, aScene, aNumRows, aNumCols, aTimerInterval)
{

}

JBlock::~JBlock()
{

}

void
JBlock::createBlock(QColor aColor)
{
    Tile *tile1 = new Tile(0, 0, mTileSize, aColor);
    Tile *tile2 = new Tile(0, 1, mTileSize, aColor);
    Tile *tile3 = new Tile(1, 1, mTileSize, aColor);
    Tile *tile4 = new Tile(1, 2, mTileSize, aColor);

    mTiles.append(tile1);
    mTiles.append(tile2);
    mTiles.append(tile3);
    mTiles.append(tile4);
}

void JBlock::setPivotPoint()
{
    mTileGroup->setTransformOriginPoint(QPointF(mTileSize * 1.5, mTileSize * 1.5));
}

