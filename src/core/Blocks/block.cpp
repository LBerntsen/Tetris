//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "core/Blocks/block.h"
#include "core/tile.h"
#include "core/gameScene.h"

#include <QColor>
#include <QGraphicsRectItem>

Block::Block(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols) : BlockShape(aTileSize, 1, 1, aGridRowList, aNumRows, aNumCols)
{

}

Block::~Block()
{

}

void
Block::createBlock(GameScene *aScene, QColor aColor, int aX, int aY)
{
    Tile *tile = new Tile(aX, aY, 0, 0, mTileSize, aColor);
    mTiles.append(tile);
    mTileGroup = new QGraphicsItemGroup;

    for(int i = 0; i < mTiles.size(); i++)
        mTileGroup->addToGroup(mTiles[i]->getTile());

    mTileGroup->setX(aX);
    mTileGroup->setY(aY);
    aScene->addItem(mTileGroup);
}