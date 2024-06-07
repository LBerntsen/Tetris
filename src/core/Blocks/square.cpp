//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "square.h"
#include "core/tile.h"
#include "core/gameScene.h"

#include <QColor>
#include <QGraphicsRectItem>

Square::Square(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, int aNumRows, int aNumCols) : BlockShape(aTileSize, 2, 2, aGridRowList, aNumRows, aNumCols)
{

}

Square::~Square()
{

}

void Square::createBlock(GameScene *aScene, QColor aColor, int aX, int aY)
{
    Tile *tile1 = new Tile(aX, aY, 0, 0, mTileSize, aColor);
    Tile *tile2 = new Tile(aX, aY, 1, 0, mTileSize, aColor);
    Tile *tile3 = new Tile(aX, aY, 0, 1, mTileSize, aColor);
    Tile *tile4 = new Tile(aX, aY, 1, 1, mTileSize, aColor);

    mTiles.append(tile1);
    mTiles.append(tile2);
    mTiles.append(tile3);
    mTiles.append(tile4);

    mTileGroup = new QGraphicsItemGroup;

    for(int i = 0; i < mTiles.size(); i++)
        mTileGroup->addToGroup(mTiles[i]->getTile());

    mTileGroup->setX(aX);
    mTileGroup->setY(aY);

    aScene->addItem(mTileGroup);
}