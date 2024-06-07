//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "core/Blocks/block.h"
#include "core/tile.h"
#include "core/gameScene.h"

#include <QColor>
#include <QGraphicsRectItem>

Block::Block(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval) : BlockShape(aTileSize, aGridRowList, aScene, aNumRows, aNumCols, aTimerInterval)
{

}

Block::~Block()
{

}

void
Block::createBlock(QColor aColor)
{
    Tile *tile = new Tile(0, 0, mTileSize, aColor);
    mTiles.append(tile);
}