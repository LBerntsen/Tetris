//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "square.h"
#include "core/tile.h"
#include "core/gameScene.h"

#include <QColor>
#include <QGraphicsRectItem>

Square::Square(int aTileSize, QList<QList<QGraphicsItem *> *> aGridRowList, GameScene *aScene, int aNumRows, int aNumCols, int aTimerInterval) : BlockShape(aTileSize, aGridRowList, aScene, aNumRows, aNumCols, aTimerInterval)
{

}

Square::~Square()
{

}

void Square::createBlock(QColor aColor)
{
    Tile *tile1 = new Tile(0, 0, mTileSize, aColor);
    Tile *tile2 = new Tile(1, 0, mTileSize, aColor);
    Tile *tile3 = new Tile(0, 1, mTileSize, aColor);
    Tile *tile4 = new Tile(1, 1, mTileSize, aColor);

    mTiles.append(tile1);
    mTiles.append(tile2);
    mTiles.append(tile3);
    mTiles.append(tile4);
}