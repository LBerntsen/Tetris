//
// Created by Lukas Berntsen on 07/06/2024.
//

#include "tile.h"

#include <QGraphicsRectItem>
#include <QBrush>

Tile::Tile(int aXIndex, int aYIndex, int aTileSize, QColor aColor)
{
    mTileSize = aTileSize;
    mTile = new QGraphicsRectItem(0, 0, mTileSize, mTileSize);
    mTile->setX(aXIndex * mTileSize);
    mTile->setY(aYIndex * mTileSize);
    mTile->setZValue(1);
    mTile->setBrush(QBrush(aColor));
}

Tile::~Tile()
{

}

QGraphicsRectItem *
Tile::getTile() const
{
    return mTile;
}

int
Tile::getXListIndex() const
{
    return mTile->scenePos().x() / mTileSize;
}

int
Tile::getYListIndex() const
{
    return mTile->scenePos().y() / mTileSize;
}



